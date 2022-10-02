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
  string a;
  cin >> a;
  int l = a.size();
  int s = 0;
  for(int i =0; i<l; i++){
    if(i == 0){
      a[0] == a[1];
    } 
    if(i % n == 0 && i > 2) {
       if(a[i-1] == a[i-2] && a[i-2] == a[i-3]){
        s++;
        a[i] = a[i-1];
       } else{
        a[i] = a[i+1];
       }
    }
  }
  printf("%d", s);
  return 0;
}