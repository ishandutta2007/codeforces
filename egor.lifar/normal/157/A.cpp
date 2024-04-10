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
  int n, a[100][100];
  scanf("%d", &n);
  for(int i =0; i<n; i++){
    for(int j =0; j<n; j++){
      scanf("%d", &a[i][j]);
    }
  }
  int k =0;
   for(int i =0; i<n; i++){
    for(int j =0; j<n; j++){
      int s =0;
      int s2 =0;
      for(int g =0; g<n; g++){
         s+=a[g][j];
      }
      for(int g =0; g<n; g++){
         s2+=a[i][g];
      }
      if(s > s2){
        k++;
      }
    }
  }
  printf("%d", k);
  return 0;
}