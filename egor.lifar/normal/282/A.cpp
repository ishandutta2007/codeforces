

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
   scanf("%d", &n);
   int s = 0;
   for(int i = 0; i<n; i++){
      string c;
      cin >> c;
      if((c[0] == '+') || (c[2] == '+')) {
        s++;
      } else {
        s--;
      }
   }
   printf("%d\n", s);
   return 0;
}