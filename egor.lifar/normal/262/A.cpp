

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
  int s = n;
  for(int i = 0; i<n; i++) {
     char a[100];
     scanf("%s", a);
     int m = strlen(a);
     int l = 0;
     for(int j = 0; j<m; j++ ){
       if(a[j] == '4' || a[j] == '7') {
         l+=1;
       }
     }
     if(l>k) {
        s--;
     }

  }
  printf("%d", s);


}