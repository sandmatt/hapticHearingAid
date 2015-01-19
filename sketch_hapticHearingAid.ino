/**All comments beginning with * are lines of code deleted to make up for a fault sound sensor.
*/


long counter = 0;
long sumValA = 0;
long sumValB = 0;

int vibPinA = 10;
int vibPinB = 9;

void setup()
{
  Serial.begin(9600);
  pinMode(vibPinA, OUTPUT);
  pinMode(vibPinB, OUTPUT);
}


void loop()
{
  counter = counter + 1;
  long valA;
  long valB;
  valA = analogRead(0);
  //*valB = analogRead(1);
  sumValA = sumValA + valA;
  //*sumValB = sumValB + valB;
  if (counter == 26) {
    //Divide 100 added values by 100, and save the value.
    sumValA = sumValA/25;
    //*sumValB = sumValB/100;
    Serial.println(sumValA);
    //update VibrationMotors
    updateVibrationTemp(sumValA);
    sumValA = 0;
    sumValB = 0;
    counter = 0;
  }
  delayMicroseconds(200);
}

//A, B
void updateVibration(long A, long B) {
  //*analogWrite(vibPinA, 255);
  //*analogWrite(vibPinB, 255);
  if (A > 40) {
    //*analogWrite(vibPinA, A/7);
  } else {
    //*analogWrite(vibPinA, 0);
  }
  if (B > 40) {
    //*analogWrite(vibPinB, B/7);
  } else {
    //*analogWrite(vibPinB, 0);
  }
}

void updateVibrationTemp(long A) {
  //To make up for one broken sensor
  //most values are between 350 and 700, so we should optimize for this
  if (A > 250) {
    analogWrite(vibPinA, A/5);
    analogWrite(vibPinB, A/7);
  } else if (A > 750) {
    analogWrite(vibPinA, 150);
    analogWrite(vibPinB, 110);
  } else {
    analogWrite(vibPinA, 0);
    analogWrite(vibPinB, 0);
  }
  //The difference in value needed to make A and B vibrate:
  //(This will vary depending on solder and motor quality)
  //A is 70
  //B is 50
}
