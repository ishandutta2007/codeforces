#line 1 "sol.cpp"
#include <algorithm>
#include <cstdint>
#include <cstdio>
#include <functional>
#include <iostream>
#include <map>
#include <vector>

using i64 = int64_t;

void solve(std::vector<i64> &dp, const std::vector<i64> &sum, int w, int r0,
           int l, int r, int vl, int vr) {
  if (l <= r) {
    int m = (l + r) >> 1;
    std::pair<i64, int> best{-1, -1};
    for (int i = vl; i <= vr && i <= m; ++i) {
      best = std::max(best, {dp[r0 + i * w] + sum[m - i], i});
    }
    solve(dp, sum, w, r0, m + 1, r, best.second, vr);
    solve(dp, sum, w, r0, l, m - 1, vl, best.second);
    dp[r0 + m * w] = best.first;
  }
}

int main() {
  int n, m;
  while (scanf("%d%d", &n, &m) == 2) {
    std::map<int, std::vector<int>> items;
    int max_v = 0;
    for (int i = 0, w, v; i < n; ++i) {
      scanf("%d%d", &w, &v);
      items[w].push_back(v);
      max_v = std::max(max_v, v);
    }
    std::vector<i64> dp(m + 1), sum(m + 1);
    for (auto &&iterator : items) {
      const int w = iterator.first;
      const int m1 = m / w;
      auto &values = iterator.second;
      std::sort(values.begin(), values.end(), std::greater<int>());
      sum[0] = 0;
      for (int i = 0; i < m1; ++i) {
        sum[i + 1] = sum[i] + (i < (int)values.size() ? values[i] : 0);
      }
      for (int r = 0; r < w && r <= m; ++r) {
        int m2 = (m - r) / w;
        solve(dp, sum, w, r, 0, m2, 0, m2);
      }
    }
    std::cout << dp[m] << "\n";
  }
}