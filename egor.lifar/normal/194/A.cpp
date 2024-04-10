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
  int n, k;
  scanf("%d %d", &n, &k);
  if(k >= 3*n) {
    printf("0\n");
    return 0;
  }
  printf("%d", 3 * n - k);


  return 0;
}