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
  int y, k, n;
  scanf("%d %d %d", &y, &k, &n);
  int m = y+(k - (y % k));
  int r =0;
  while(m <= n) {
    if(m % k == 0) {
      printf("%d ", m - y);
      r++;
    }
    m+= k;
  }
  if(r == 0){
    printf("-1");
  }
  return 0;
}