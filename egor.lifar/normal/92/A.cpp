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
  int n, m;
  cin >> n >> m;
  m = m % ((n + 1) * n / 2);
  int k = 0;
  while(((k + 1) * k / 2) <= m){
     k++;
  }
  cout << m - k * (k - 1) / 2;
  return 0;
}