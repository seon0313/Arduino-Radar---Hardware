#include <Servo.h>

Servo servo;

int pos = 0;
bool vpos = false;
int trig = 7;
int echo = 6;

int speed = 4;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);

  servo.attach(8);
  pinMode(trig, OUTPUT);
  pinMode(echo, INPUT);
}

void loop() {
  servo.write(pos);

  long duration, distance;

  digitalWrite(trig, HIGH);
  delayMicroseconds(10);
  digitalWrite(trig, LOW);

  duration = pulseIn(echo,HIGH);
  distance = ((duration * 340)/10000)/2; // cm

  Serial.print(pos);
  Serial.print(" ");
  Serial.println(distance);

  if (vpos) pos-=speed;
  else pos+=speed;

  if (pos >= 180 || pos <= 0) vpos= !vpos;

  delay(30);
}
