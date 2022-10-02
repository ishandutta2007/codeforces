
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
   for(int i =1; i<=n-k-1; i++) {
     printf("%d ", i);
   }
   for(int i = n; i>=n-k; i--) {
     printf("%d ", i);
   }
   return 0;

     
}