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
  int n, a[100];
  scanf("%d", &n);
  for(int i = 0; i < n; i++){
    scanf("%d", &a[i]);
  }
  sort(a, a + n);
  double w = 0;
  double p = acos(-1);
  int k;
  if(n % 2 == 1){
    w += p * a[0] * a[0];
    k = 2;
  } else {
    k = 1;
  }
  for(int i = k; i < n; i++){
    if(i % 2 == k % 2){
      w += p * (a[i] * a[i] - a[i - 1] * a[i - 1]);
    }
  }
  printf("%lf\n", w);
  return 0;
}