

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
   int n, m, a[200000], l[200000], r[200000];
   scanf("%d %d", &n, &m);
   int b = 0;
   for(int i = 0; i<n; i++) {
      scanf("%d", &a[i]);
      if(a[i] == -1) {
        b+=1;
      }
   }  
   for(int i = 0; i<m; i++) {
      scanf("%d %d", &l[i], &r[i]);
      if((b < ((r[i] - l[i] +1) / 2)) || ((r[i] - l[i] + 1) % 2 == 1) || (n-b<((r[i] - l[i] +1) / 2) )) {
        printf("0\n");
      } else {
        printf("1\n");
      }
   }
   return 0;
}