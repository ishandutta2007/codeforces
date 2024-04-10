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
  string a, b;
  cin >>a >> b;
  if(a.size() != b.size()){
    printf("NO");
    return 0;
  }
  int k = a.size();
  int l = 0;
  for(int i =0; i<k; i++) {
     if(a[i] != b[i]){
      l++;
     }
  }
  if(l != 2){
    printf("NO");
    return 0;
  }
  char c[2], d[2];
  int j =0;
  for(int i =0; i<k; i++) {
     if(a[i] != b[i]){
       c[j] = a[i];
       d[j] = b[i];
       j++;
     }
  }
  if(c[0] == d[1] && c[1] == d[0]){
    printf("YES");
  }else{
    printf("NO");
  }
  return 0;
}