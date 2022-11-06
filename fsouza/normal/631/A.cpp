#include <algorithm>
#include <cassert>
#include <climits>
#include <cmath>
#include <complex>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <functional>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <vector>

using namespace std;

typedef long long lint;

int main() {
  int n;
  scanf("%d", &n);
  int result = 0;
  for (int rep = 0; rep < 2; ++rep) {
    int orvalue = 0;
    for (int i = 0; i < n; ++i) {
      int v;
      scanf("%d", &v);
      orvalue |= v;
    }
    result += orvalue;
  }
  printf("%d\n", result);
  
  return 0;
}