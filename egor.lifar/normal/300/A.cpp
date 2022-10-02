
#include <cstdio>
#include <string.h>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <vector>
#include <string>
#include <iostream>

using namespace std;

bool let(pair<int, int>a, pair<int, int>b) {
  return  -a.first < -b.first;
}
bool let2(pair<int, int>a, pair<int, int>b) {
  return a.second < b.second;
}

int main() {
  int n, a[100];
  scanf("%d", &n);
  for(int i =0; i<n; i++){
    scanf("%d", &a[i]);
  }
  int n1 = 0, n2 = 0, n3 = 0, s =0;
  int n11[100], n22[100], n33[100];
  for(int i =0; i<n; i++) {
    if(a[i] < 0) {
      s+=1;
    }
    if(a[i] > 0) {
      n22[n2] = a[i];
      n2+=1;
    }
    if(a[i] == 0) {
      n33[n3] = a[i];
      n3+=1;
    }
  }
  if(s % 2 == 0) {
    int p =0;
    if(n2 == 0) {
     for(int i =0; i<n; i++) {
      if(a[i] < 0) {
        if(p == 2) {
          n33[n3] = a[i];
          n3+=1;
          p+=1;
        } else {
          if(p >= 3) {
            n11[n1] = a[i];
            n1+=1;
          }else {
            n22[n2] = a[i];
            n2+=1;
            p+=1;
          }

      }
     }
    }
   } else {
    for(int i =0; i<n; i++) {
      if(a[i] < 0) {
        if(p == 0) {
          n33[n3] = a[i];
          n3+=1;
          p+=1;
        } else {
            n11[n1] = a[i];
            n1+=1;
          }

      } 
   }
   } 
   }else {
    int p =0;
    if(n2 == 0) {
     for(int i =0; i<n; i++) {
      if(a[i]<0) {
        if(p >= 2) {
         n11[n1] = a[i];
         n1+=1;
        } else {
           n22[n2] = a[i];
           n2+=1;
           p+=1;
        }
      }
    }
   }
    else {
     for(int i =0; i<n; i++) {
       if(a[i]<0) {
         n11[n1] = a[i];
         n1+=1;
     }
   }
  }
}
  printf("%d ", n1);
  for(int i =0; i<n1; i++) {
       printf("%d ", n11[i]);
  }
  printf("\n");
  printf("%d ", n2);
  for(int i =0; i<n2; i++) {
       printf("%d ", n22[i]);
  }
  printf("\n");
   printf("%d ", n3);
   for(int i =0; i<n3; i++) {
       printf("%d ", n33[i]);
   }
  printf("\n");
  return 0;
}