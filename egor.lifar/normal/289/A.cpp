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
   int n, k, l[100000] , r[100000];
   scanf("%d %d", &n, &k);
   for(int i =0; i<n; i++) {
        scanf("%d %d", &l[i], &r[i]);
   }
   int s=0;;
   for(int i=0; i<n; i++) {
      s+= r[i] - l[i] + 1;
   }
   int p = (k - s % k) % k;
   printf("%d", p);

   }