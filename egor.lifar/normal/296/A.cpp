#include <cstdio>
#include <string.h>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <vector>
#include <string>
#include <iostream>

using namespace std;


int main(){
   int n, a[100], b[1001];
   scanf("%d", &n);
   for(int i =0; i<n; i++) {
       scanf("%d", &a[i]);
   }
   for(int i =0; i<1001;  i++) {
       b[i] = 0;
   }
   for(int i =0; i<n; i++) {
      b[a[i]] +=1;
   }
   int r = b[0];
    for(int i =0; i<1001; i++) {
        r = max(b[i], r);
   }
   if(r>n / 2 +n%2) {
      printf("NO");
   } else {
      printf("YES");
   }
}