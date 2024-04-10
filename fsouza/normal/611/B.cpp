#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <complex>
#include <map>
#include <numeric>
#include <set>
#include <utility>
#include <vector>

#define INF 1000000000

using namespace std;

typedef long long lint;

int main() {
  lint a, b;
  cin >> a >> b;
  int result = 0;
  
  for (int size = 1; size <= 62; ++size) {
    lint maxval = (1LL<<size)-1;
    for (int bit = 0; bit < size-1; ++bit) {
      lint val = maxval - (1LL<<bit);
      if (a <= val && val <= b)
    ++result;
    }
  }

  printf("%d\n", result);
  
  return 0;
}