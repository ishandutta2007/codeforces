#include <algorithm>
#include <cassert>
#include <complex>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <climits>
#include <cmath>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <vector>

using namespace std;

typedef long long lint;

int main() {
  const int maxv = 2*1000000;
  vector<int> many(maxv+1, 0);
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) {
    int v;
    scanf("%d", &v);
    ++many[v];
  }
  int result = 0;
  for (int v = 0; v <= maxv; ++v) {
    if (v+1 <= maxv) many[v+1] += many[v]/2;
    many[v] %= 2;
    result += many[v];
  }
  printf("%d\n", result);
  
  return 0;
}