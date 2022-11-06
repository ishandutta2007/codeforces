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

lint get_cost(const vector<int> &a) {
  lint result = 0;
  for (int i = 0; i < (int)a.size(); ++i)
    for (int j = i + 1; j < (int)a.size(); ++j)
      result += (lint)(a[i] + a[j]) * (a[i] + a[j]);
  return result;
}

int main() {
  int nt;
  scanf("%d", &nt);
  for (int t = 0; t < nt; ++t) {
    int n;
    scanf("%d", &n);
    vector<int> a(n), b(n);
    for (int i = 0; i < n; ++i)
      scanf("%d", &a[i]);
    for (int i = 0; i < n; ++i)
      scanf("%d", &b[i]);
    const int max_sum = accumulate(a.begin(), a.end(), 0) +
      accumulate(b.begin(), b.end(), 0);
    vector<vector<int>> dp(n + 1, vector<int>(max_sum + 1, -2));
    dp[0][0] = -1;
    for (int i = 0; i < n; ++i)
      for (int s = 0; s <= max_sum; ++s) {
        if (dp[i][s] == -2) continue;

        dp[i + 1][s + a[i]] = 0;
        dp[i + 1][s + b[i]] = 1;
      }

    int best_diff = INT_MAX;
    int best_sum_a = -1;
    for (int sum_a = 0; sum_a <= max_sum; ++sum_a) {
      if (dp[n][sum_a] == -2) continue;
      int diff = abs(sum_a - (max_sum - sum_a));
      if (diff < best_diff) {
        best_diff = diff;
        best_sum_a = sum_a;
      }
    }

    int cur_i = n, cur_sum_a = best_sum_a;
    for (int rep = 0; rep < n; ++rep) {
      assert(dp[cur_i][cur_sum_a] != -2);
      if (dp[cur_i][cur_sum_a] == 0) {
        cur_sum_a -= a[cur_i - 1];

      } else {
        cur_sum_a -= b[cur_i - 1];

        swap(a[cur_i - 1], b[cur_i - 1]);
      }
      --cur_i;
    }
    lint total_cost = get_cost(a) + get_cost(b);
    printf("%lld\n", total_cost);
  }
  return 0;
}