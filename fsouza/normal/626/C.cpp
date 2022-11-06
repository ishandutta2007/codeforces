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
#include <unordered_map>
#include <vector>

using namespace std;

typedef long long lint;

inline bool possible(int x, int y, int z, int n, int m) {
  int take;

  take = min(n, x); n -= take, x -= take;
  take = min(m, z); m -= take, z -= take;

  return n+m <= y;
}

int main() {
  int n, m;
  scanf("%d %d", &n, &m);
  int x = 0, y = 0, z = 0, h = 0;
  while (!possible(x, y, z, n, m)) {
    ++h;
    if (h%2 == 0 && h%3 == 0) ++y;
    else if (h%2 == 0) ++x;
    else if (h%3 == 0) ++z;
  }
  printf("%d\n", h);

  return 0;
}