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
  cin >> n;
  int k = n- 10;
  int a[100];
  for(int i =0; i < 11; i++){
    a[4 * i + 0] = i + 1;
    a[4 * i + 1] = i + 1;
    a[4 * i + 2] = i + 1;
    a[4 * i + 3] = i + 1; 
  }
  for(int i = 0; i < 2; i++){
    a[44 + 4 * i + 0] = 10;
    a[44 + 4 * i + 1] = 10;
    a[44 + 4 * i + 2] = 10;
    a[44 + 4 * i + 3] = 10;
  }
  a[52] = 10;
  a[53] = 10;
  a[54] = 10;
  int s = 0;
  for(int i =0; i < 55; i++){
    if(a[i] == k) {
      s++;
    }
  }
  cout << s << "\n";
  return 0;
}