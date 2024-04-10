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
  int a, b, x, y;
  cin >> x >> y >> a >> b;
  int k = 0;
  int p = 0;
 for(int i = b; i <= y; i++){
    for(int j = a; j <= x; j++){
      if(i < j){
        k++;
      }
    }
  }
  vector< pair < int, int > > v(k);
  for(int i = b; i <= y; i++){
    for(int j = a; j <= x; j++){
      if(i < j){
        v[p].first = j;
        v[p].second = i;
        p++;
      }
    }
  }
  printf("%d\n", k);
  sort(v.begin(), v.end());
  for(int i = 0; i < p; i++){
    printf("%d %d\n", v[i].first, v[i].second);
  }
  return 0;
}