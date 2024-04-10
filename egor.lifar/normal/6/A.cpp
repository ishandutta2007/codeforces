#include <cstdio>
#include <string.h>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <vector>
#include <string>
#include <iostream>
 
using namespace std;

 
int main() {                         
  int a, b, c, d;
  scanf("%d %d %d %d", &a, &b, &c, &d);
  if((a + b > c & a + c > b && b + c > a) || (a + b > d & a + d > b && b + d > a) || (a + d > c & a + c > d && d + c > a) || (d + b > c & d + c > b && b + c > d) )  {
    printf("TRIANGLE");
    return 0;
  } else {
    if(a + b == c || a + b == d || a + c == b || a + c == d || a + d == c || a + d == b || b + c == a || b + c == d ||  b + d == a || b + d == c || c + d == a || c + d == b){
      printf("SEGMENT");
    } else {
      printf("IMPOSSIBLE");
    }
  }
  return 0;
}