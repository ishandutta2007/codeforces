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
  vector<int> values(n);
  for (int i = 0; i < n; ++i)
    scanf("%d", &values[i]);
  const int max_value = *max_element(values.begin(), values.end());
  const int nbit = max_value > 0 ? 1 + __lg(max_value) : 0;
  vector<int> prev_one(nbit, -1), next_one(nbit, 0);
  map<int, int> last_appearance;
  lint result = (lint)n * (n + 1) / 2LL;
  for (int i = 0; i < n; ++i) {
    int range_left = 0, range_right = n - 1;
    for (int b = 0; b < nbit; ++b) {
      while (next_one[b] <= i ||
             (next_one[b] < n && !(values[next_one[b]] & (1<<b)))) {
        ++next_one[b];
      }
      if (!(values[i] & (1<<b))) {
        range_left = max(range_left, prev_one[b] + 1);
        range_right = min(range_right, next_one[b] - 1);
      } else {
        prev_one[b] = i;
      }
    }
    if (last_appearance.find(values[i]) != last_appearance.end())
      range_left = max(range_left, last_appearance[values[i]] + 1);
    last_appearance[values[i]] = i;
    result -= (lint)(i - range_left + 1) * (range_right - i + 1);
  }
  printf("%lld\n", result);
  return 0;
}