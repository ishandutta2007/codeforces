#line 1 "sol.cpp"
#include <bits/stdc++.h>

const int N = 3'001;

int n;
std::pair<int, int> a[N], rmq[N][N];

using Tuple3 = std::tuple<int, int, int>;

int gap(int i) { return a[i - 1].first - a[i].first; }

Tuple3 solve() {
  std::sort(a, a + n, std::greater<std::pair<int, int>>());
  a[n].first = 0;
  // [0, i) [i, j) [j, k)
  // 0 < i < j < k <= n
  // a[i - 1] - a[i]
  // a[j - 1] - a[j]
  // a[k - 1] - a[k]
  for (int i = 1; i <= n; ++i) {
    rmq[i][i] = {gap(i), i};
    for (int j = i + 1; j <= n; ++j) {
      rmq[i][j] = std::max(rmq[i][j - 1], {gap(j), j});
    }
  }
  std::pair<Tuple3, Tuple3> best{{-1, -1, -1}, {-1, -1, -1}};
  for (int i = 1; i <= n; ++i) {
    // size = i
    for (int j = i + ((i + 1) >> 1); j <= n && j <= i + (i << 1); ++j) {
      int k_min = j + ((std::max(i, j - i) + 1) >> 1);
      int k_max = std::min(n, j + (std::min(i, j - i) << 1));
      if (k_min <= k_max) {
        auto [k_gap, k] = rmq[k_min][k_max];
        best = std::max(best, {{gap(i), gap(j), k_gap}, {i, j, k}});
      }
    }
  }
  return best.second;
}

int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) {
    scanf("%d", &a[i].first);
    a[i].second = i;
  }
  auto [i, j, k] = solve();
  std::vector<int> result(n, -1);
  for (int t = 0; t < i; ++t) {
    result[a[t].second] = 1;
  }
  for (int t = i; t < j; ++t) {
    result[a[t].second] = 2;
  }
  for (int t = j; t < k; ++t) {
    result[a[t].second] = 3;
  }
  for (int i = 0; i < n; ++i) {
    printf("%d%c", result[i], " \n"[i + 1 == n]);
  }
}