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
  int n;
  scanf("%d", &n);
  n *= 2;
  vector<int> values(n);
  for (int i = 0; i < n; ++i)
    scanf("%d", &values[i]);
  sort(values.begin(), values.end());
  lint result = (lint)(values[n / 2 - 1] - values[0]) *
    (values[n - 1] - values[n / 2]);
  for (int i = 1; i + n / 2 - 1 < n - 1; ++i) {
    result = min(result, (lint)(values[n - 1] - values[0]) *
                 (values[i + n / 2 - 1] - values[i]));
  }
  printf("%lld\n", result);
  return 0;
}