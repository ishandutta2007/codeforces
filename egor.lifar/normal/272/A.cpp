

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
  int s = 0;
  for(int i = 0; i<n; i++) {
     scanf("%d", &a[i]);
     s+=a[i];
  }
  int k = 0;
  if((s + 1) % (n+1) != 1) {
    k+=1;
  }
  if((s + 2) % (n+1) != 1) {
    k+=1;
  }
   if((s + 3) % (n+1) != 1) {
    k+=1;
  }
   if((s + 4) % (n+1) != 1) {
    k+=1;
  }
   if((s + 5) % (n+1) != 1) {
    k+=1;
  }
  printf("%d", k);
}