#include <algorithm>
#include <array>
#include <bitset>
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
#include <memory>
#include <numeric>
#include <queue>
#include <random>
#include <set>
#include <stack>
#include <unordered_map>
#include <vector>

using namespace std;

typedef long long lint;

int solve(int x, int y) {
  int res;
  if (x > y) res = x + y;
  else {
    int r = y % x;
    res = y - r / 2;
  }
  assert(y % res == res % x);
  return res;
}

int main() {
  int nt;
  scanf("%d", &nt);
  for (int t = 0; t < nt; ++t) {
    int x, y;
    scanf("%d %d", &x, &y);
    printf("%d\n", solve(x, y));
  }
  return 0;
}