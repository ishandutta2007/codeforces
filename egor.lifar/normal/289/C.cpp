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
    int n, k;
    scanf("%d %d", &n, &k);
    if(k>n) {
      printf("-1");
      return 0;
    }
    if(k == 1 ) {
      if(n>k) {
        printf("-1");
        return 0;
      } else {
         printf("a");
         return 0;
      }

    }
    for(int i =0; i<n-k+2; i++) {
       if(i % 2 == 0) {
         printf("a");
       } else {
         printf("b");
       }
    }
    char c ='c';
    for(int i=0; i<k-2; i++) {
        printf("%c", c);
        c+=1;
    }
    return 0;            
 }