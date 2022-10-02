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
  int n;
  int a[100000];
  scanf("%d", &n);
  double s =0;
  for(int i = 0; i<n; i++) {
    scanf("%d", &a[i]);
    s+=a[i];
  }
  double  w = s / n;
  printf("%lf", w);


  return 0;
}