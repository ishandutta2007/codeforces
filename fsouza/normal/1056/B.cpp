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

int main() {
  int n, m;
  scanf("%d %d", &n, &m);
  vector<int> count(m, 0);

  int nblock = n / m;
  for (int i = 1; i <= m; ++i) {
    count[(lint)i * i % m] += nblock;
  }
  for (int i = m * nblock + 1; i <= n; ++i) {
    count[(lint)i * i % m] += 1;
  }

  lint result = 0LL;
  for (int i = 0; i < m; ++i)
    result += (lint)count[i] * count[(m - i) % m];
  printf("%lld\n", result);

  return 0;
}