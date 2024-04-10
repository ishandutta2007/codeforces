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
  scanf("%d", &n);
  int k =0;
  for(int i =0; i<n; i++){
      for(int i =k; i<k + n/2; i++){
        printf("%d %d ", i+1, n * n - i);
      }
      k+=n/2;
      printf("\n");
  }
  return 0;
}