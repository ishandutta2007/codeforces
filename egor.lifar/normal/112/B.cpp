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
  int n, x, y;
  cin >> n >> x >> y;
  int k = n/ 2;
  if((x == k && y == k) || (x == k+1 && y == k) || (x == k && y == k+1) ||(x == k+1 && y == k+1)){
    printf("NO");
  } else {
    printf("YES");
  }
  return 0;
}