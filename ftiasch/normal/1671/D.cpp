#line 1 "/home/ftiasch/Documents/shoka/util.h"
#include <bits/stdc++.h>

#define READ(T, V)                                                             \
  T V;                                                                         \
  std::cin >> V;

#define READ_VECTOR(T, V, n)                                                   \
  std::vector<T> V((n));                                                       \
  for (int i = 0; i < (n); ++i) {                                              \
    std::cin >> V[i];                                                          \
  }

#define ALL(v) (v).begin(), (v).end()

template <typename T> std::vector<std::vector<T>> vector_2d(int n, int m) {
  return std::vector<std::vector<T>>(n, std::vector<T>(m));
}

template <typename T> std::vector<std::vector<T>> vector_2d(int n, int m, T d) {
  return std::vector<std::vector<T>>(n, std::vector<T>(m, d));
}

using Long = long long;
using u64 = uint64_t;

template <typename T>
using MinPQ = std::priority_queue<T, std::vector<T>, std::greater<T>>;
#line 2 "/tmp/tmp-87900TgRjCCwm5x7r.cpp"

#line 4 "/tmp/tmp-87900TgRjCCwm5x7r.cpp"

int main() {
  std::ios::sync_with_stdio(false);
  READ(int, T);
  while (T--) {
    READ(int, n);
    READ(int, x);
    READ_VECTOR(int, a, n);
    std::vector<std::array<int, 3>> cost(n + 1);
    cost[0][0] = std::abs(1 - a[0]);
    cost[0][1] = std::abs(x - a[0]);
    cost[0][2] = std::abs(1 - x) + std::min(cost[0][0], cost[0][1]);
    for (int i = 1; i < n; ++i) {
      Long d = std::abs(a[i - 1] - a[i]);
      cost[i][0] = std::abs(a[i - 1] - 1) + std::abs(1 - a[i]) - d;
      cost[i][1] = std::abs(a[i - 1] - x) + std::abs(x - a[i]) - d;
      cost[i][2] = std::min(std::abs(a[i - 1] - 1) + std::abs(x - a[i]),
                            std::abs(a[i - 1] - x) + std::abs(1 - a[i])) +
                   std::abs(1 - x) - d;
    }
    cost[n][0] = std::abs(1 - a[n - 1]);
    cost[n][1] = std::abs(x - a[n - 1]);
    cost[n][2] = std::abs(1 - x) + std::min(cost[n][0], cost[n][1]);
    Long inf = (n + 1) * 200'000LL;
    using Dp = std::array<Long, 4>;
    Dp dp;
    std::ranges::fill(dp, inf);
    dp[0] = 0;
    for (int i = 1; i < n; ++i) {
      dp[0] += std::abs(a[i - 1] - a[i]);
    }
    for (int i = 0; i <= n; ++i) {
      Dp new_dp = dp;
      for (int mask = 0; mask < 4; ++mask) {
        for (int add = 1; add < 4; ++add) {
          if ((mask & add) == 0) {
            new_dp[mask | add] =
                std::min(new_dp[mask | add], dp[mask] + cost[i][add - 1]);
          }
        }
      }
      dp.swap(new_dp);
    }
    std::cout << dp[3] << "\n";
  }
}