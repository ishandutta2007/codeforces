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
typedef unsigned long long ulint;

int main() {
  int n;
  scanf("%d", &n);
  vector<int> sizes(n);
  for (int i = 0; i < n; ++i)
    scanf("%d", &sizes[i]);

  ulint result = 0ULL;

  for (int i = 0; i < n; i += 2) {
    lint delta = 0LL;
    lint min_delta = 0LL;

    for (int j = i + 1; j < n; j += 2) {
      lint a = 1, b = sizes[i];
      a = max(a, -min_delta);

      a = max(a, -delta);
      b = min(b, sizes[j] - delta);

      if (a <= b)
        result += (ulint)(b - a + 1);

      //
      delta -= sizes[j];
      min_delta = min(min_delta, delta);
      if (j + 1 < n)
        delta += sizes[j + 1];
    }
  }

  printf("%llu\n", result);

  return 0;
}