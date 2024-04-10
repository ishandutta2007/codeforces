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
  int h[100000], m[100000];
  scanf("%d", &n);
  for(int i =0; i<n; i++){
    scanf("%d %d", &h[i], &m[i]);
  }
  int c = 0;
  int b[100];
  int j = 0;
  for(int i = 0; i<n; i++){
    if((i > 0 && h[i] == h[i-1] && m[i] == m[i-1]) || i == 0){
      c++;
    } else {
      b[j] = c;
      j++;
      c = 1; 
    }
  }
  b[j] = c;
  sort(b, b + j + 1);
  printf("%d", b[j]);
  return 0;
}