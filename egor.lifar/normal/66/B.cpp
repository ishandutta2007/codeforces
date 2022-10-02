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
  int n, a[1000];
  cin >> n;
  for(int i =0; i<n; i++){
    cin >> a[i];
  }
  int b[1000];
  for(int i =0; i<n; i++){
    b[i] = 1;
    for(int j = i - 1; j>=-1; j--){
      if(a[j] >  a[j+1] || j == -1){
        b[i] += i - j - 1;
        break;
      }
    }
     for(int j = i + 1; j <= n; j++){
      if(a[j] >  a[j-1] || j == n ){
        b[i] += j - i - 1;
        break;
      }
    }
    
  }
  sort(b, b+n);
  cout << b[n-1];
  return 0;
}