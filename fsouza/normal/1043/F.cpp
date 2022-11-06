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

const int limit = 300000;

int main() {
  vector<int> div(limit + 1, -1);
  iota(div.begin(), div.end(), 0);
  for (int p = 2; p <= limit; ++p)
    if (div[p] == p)
      for (int m = 2 * p; m <= limit; m += p)
        if (div[m] == m)
          div[m] = p;

  int n;
  scanf("%d", &n);
  vector<int> seq(n);
  for (int i = 0; i < n; ++i)
    scanf("%d", &seq[i]);

  vector<bool> have(limit + 1, false);
  for (int i = 0; i < n; ++i) {
    int value = seq[i];
    int new_value = 1;

    while (value != 1) {
      int d = div[value];
      while (div[value] == d)
        value /= d;
      new_value *= d;
    }

    have[new_value] = true;
  }

  for (int v = 1; v <= limit; ++v)
    if (have[v])
      for (int u = 2 * v; u <= limit; u += v)
        have[u] = false;

  seq.clear();
  n = 0;
  for (int v = 1; v <= limit; ++v)
    if (have[v])
      ++n;

  vector<int> mult_count(limit + 1, 0);
  for (int v = 1; v <= limit; ++v)
    for (int u = v; u <= limit; u += v)
      if (have[u])
        mult_count[v] += 1;

  int result = INT_MAX;

  for (int v = 1; v <= limit; ++v) {
    if (!have[v]) continue;

    static vector<int> get_rid; get_rid.clear();

    {
      int value = v;
      while (value != 1) {
        int d = div[value];
        get_rid.push_back(d);
        value /= d;
      }
    }

    int np = get_rid.size();
    static vector<int> with_mask(1<<7), mask_mult(1<<7);
    for (int s = 0; s < (1<<np); ++s) {
      int not_multby = 1;
      for (int i = 0; i < np; ++i)
        if (s & (1<<i))
          not_multby *= get_rid[i];
      mask_mult[s] = not_multby;

      with_mask[s] = n;
      for (int s2 = s; s2 > 0; s2 = (s2 - 1) & s) {
        if (__builtin_popcount(s2) % 2 == 1)
          with_mask[s] -= (mask_mult[s2] > limit ? 0 : mult_count[mask_mult[s2]]);
        else
          with_mask[s] += (mask_mult[s2] > limit ? 0 : mult_count[mask_mult[s2]]);
      }
    }

    static vector<int> dp(1<<7);
    fill(dp.begin(), dp.end(), INT_MAX / 2);
    dp[0] = 0;
    for (int s = 1; s < (1<<np); ++s) {
      for (int s2 = s; s2 > 0; s2 = (s2 - 1) & s) {
        if (with_mask[s2]) {
          dp[s] = min(dp[s], 1 + dp[s ^ s2]);
        }
      }
    }
    result = min(result, 1 + dp[(1<<np) - 1]);
  }

  if (result >= INT_MAX / 3) result = -1;
  printf("%d\n", result);

  return 0;
}