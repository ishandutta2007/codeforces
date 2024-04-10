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
  int n, a[100000];
  scanf("%d", &n);
  for(int i =0; i<n; i++){
    scanf("%d", &a[i]);
  }
  int s = n;
  s += a[0];
  for(int i =1; i<n; i++){
    s += abs(a[i] - a[i-1]);
  }
  s += n - 1;
  printf("%d\n", s);
  return 0;
}