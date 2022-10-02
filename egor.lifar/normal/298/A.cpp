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
    string s;
    int n;
    scanf("%d", &n);
    cin >> s;
    for(int i =0; i<n; i++) {
       if(s[i] != '.') {
           printf("%d ", i+1);
           break;
       }
    }
    for(int i=0; i<n; i++) {
       if(s[i] == 'L') {
          printf("%d", i);
          return 0;
          break;
       }
    }
    for(int i =n-1; i>=0; i--) {
       if(s[i] != '.') {
           printf("%d",i+2);
           break;
       }
    }
  
    return 0;            
 }