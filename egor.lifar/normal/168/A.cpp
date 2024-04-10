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
  double n, x, y;
  scanf("%lf %lf %lf", &n, &x, &y);
  double w = n / 100;
  int z =0;
  double k = x + z;
  while(k / w < y){
    z++;
    k = x + z;
  }
  printf("%d", z);
  return 0;
}