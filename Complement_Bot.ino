#include <LiquidCrystal.h>
const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);
const int trigPin = 8;
const int echoPin = 7;
int LEDpin = 6;
long duration;
int distance;
int randNumber;

void setup() {
  pinMode(trigPin, OUTPUT); // Sets the trigPin as an Output
  pinMode(echoPin, INPUT); // Sets the echoPin as an Input
  pinMode(LEDpin, OUTPUT);
  Serial.begin(9600); // Starts the serial communication
  lcd.begin(16, 2);
  randomSeed(analogRead(0));
}
void loop() {

  // Clears the trigPin
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  // Sets the trigPin on HIGH state for 10 micro seconds
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  // Reads the echoPin, returns the sound wave travel time in microseconds
  duration = pulseIn(echoPin, HIGH);
  // Calculating the distance
  distance = duration * 0.034 / 2;
 // Serial.print("Distance: ");
  //Serial.println(distance);
  delay(500);
  randNumber = random(0, 4);
  if (distance < 20) {
    digitalWrite(LEDpin, HIGH);
    lcd.clear();
    switch (randNumber) {

      case 0:
        lcd.setCursor(1, 1);
        lcd.print("You look pretty!");
        lcd.scrollDisplayLeft();
     //   lcd.clear();
        delay(10000);
        break;

      case 1:
        lcd.setCursor(1, 1);
        lcd.print("I like ur style");
        lcd.scrollDisplayLeft();
    //    lcd.clear();
        delay(10000);
        break;

      case 2:
        lcd.setCursor(1, 1);
        lcd.print("You are special!");
        lcd.scrollDisplayLeft();
      //  lcd.clear();
        delay(10000);
        break;

      case 3:
        lcd.setCursor(1, 1);
        lcd.print("You inspire me!");
        lcd.scrollDisplayLeft();
       // lcd.clear();
        delay(10000);
        break;

      case 4:
        lcd.setCursor(1, 1);
        lcd.print("You are the best");
        lcd.scrollDisplayLeft();
        //lcd.clear();
        delay(10000);
        break;

    }
  }

  else {

    //lcd.clear();
    digitalWrite(LEDpin, LOW);
    lcd.setCursor(1, 1);
    lcd.print("Looking for Sentient Being.......");
    lcd.scrollDisplayLeft();
    delay(500);

  }
}
