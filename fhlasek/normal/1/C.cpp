/* Writen by Filip Hlasek 2012 */
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <string>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <iostream>

#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define FORD(i,a,b) for(int i=(a);i>=(b);i--)
#define REP(i,b) for(int i=0;i<b;i++)

using namespace std;

double det(double a, double b, double c, double d){ return a*d - b*c; }

#define EPS 1e-5

bool integer(double x){
  x=abs(x);
  double diff = min(x-(int)x,1-(x-(int)x));
  return diff < 2*EPS;
}

int main(int argc, char *argv[]){
  double ax,ay,bx,by,cx,cy; 
  cin >> ax >> ay >> bx >> by >> cx >> cy;
  double k = det(-by+cy,(cx-ax)/2,bx-cx,(cy-ay)/2)/det(-by+ay,-by+cy,bx-ax,bx-cx);
  double x = (ax+bx)/2 + k*(-by+ay); 
  double y = (ay+by)/2 + k*(bx-ax);
  double d = 2 * (ax * (by - cy) + bx * (cy - ay) + cx * (ay - by));
  x = ((ax * ax + ay * ay) * (by - cy) + (bx * bx + by * by) * (cy - ay) + (cx * cx + cy * cy) * (ay - by)) / d;
  y = ((ax * ax + ay * ay) * (cx - bx) + (bx * bx + by * by) * (ax - cx) + (cx * cx + cy * cy) * (bx - ax)) / d;

/*
  printf("x: %lf y: %lf\n", x, y);
  printf("%lf\n", (x - ax) * (x - ax) + (y - ay) * (y - ay));
  printf("%lf\n", (x - bx) * (x - bx) + (y - by) * (y - by));
  printf("%lf\n", (x - cx) * (x - cx) + (y - cy) * (y - cy));
*/

  double a1, a2, a3;
  a1 = atan2(ax-x, ay-y);
  a2 = atan2(bx-x, by-y);
  a3 = atan2(cx-x, cy-y);
  for(int n = 3; n <= 100; n++){
    if (integer(n * (a1-a2)/(2 * M_PI)) && integer(n * (a1-a3)/(2 * M_PI))){
      printf("%.9lf\n", n/2.0*((ax-x)*(ax-x)+(ay-y)*(ay-y))*sin(2 * M_PI/n));
      return 0;
    }
  }
  return 0;
}