

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
    int a[4];
    for(int i = 0; i<4; i++){
      scanf("%d", &a[i]);
    }
    sort(a, a+4);
    int k = 1;
    for(int i =1; i < 4; i++){
      if(a[i] > a[i-1]) {
        k++;
      }
    }
    printf("%d", (4-k));
    return 0;
}