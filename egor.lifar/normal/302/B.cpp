

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
   int n, m, c[100000], t[100000], v[100000];
   int a[100000];
   scanf("%d %d", &n, &m);
   a[0] = 0;
   for(int i =0; i<n; i++) {
    scanf("%d %d", &c[i], &t[i]);
    if(i+1>0) {
      a[i+1] = a[i] + t[i] * c[i];
    }
   }
   for(int i = 0; i<m; i++) {
    scanf("%d", &v[i]);
   }
   int k = 0;
   for(int j =0; j<m; j++) {
      for(int i = k; i<=n; i++) {
        if(a[i] > v[j]-1) {
          printf("%d\n", i);
          k = i;
          break;
        } 
      }
   }
   return 0;
}