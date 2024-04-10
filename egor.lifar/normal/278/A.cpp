

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
   int n, s, t, a[100];
   scanf("%d", &n);
   for(int i = 1; i<=n; i++){
      scanf("%d", &a[i]);
   }
   scanf("%d %d", &s, &t);
   int x = 0, y= 0;
   if(t < s) {
     int  v = s;
      s = t;
      t = v;
   }
   for(int i = s; i<t; i++) {
      y+=a[i];

   }
   for(int i = 1; i<s; i++) {
      x+=a[i];
   }
   for(int i = t; i<=n; i++) {
      x+=a[i];
   }
   printf("%d", min(x, y));
}