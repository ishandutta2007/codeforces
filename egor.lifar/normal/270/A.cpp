

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
   int t, a[180];
   scanf("%d", &t);
   for(int i = 0; i<t; i++) {
      scanf("%d", &a[i]);
      int j = 180;
      int k = 3;
      while(j / k < a[i]){
         j+=180;
         k++;
      }
      if(j % k == 0 && j / k == a[i]) {
         printf("YES\n");
      } else {
         printf("NO\n");
      }
   }

}