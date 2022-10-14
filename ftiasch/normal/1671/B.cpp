#line 1 "/home/ftiasch/Documents/shoka/util.h"
#include <bits/stdc++.h>

#define CIN(T, V)                                                              \
  T V;                                                                         \
  std::cin >> V;

#define ALL(v) (v).begin(), (v).end()

template <typename T> std::vector<std::vector<T>> vector_2d(int n, int m) {
  return std::vector<std::vector<T>>(n, std::vector<T>(m));
}

template <typename T> std::vector<std::vector<T>> vector_2d(int n, int m, T d) {
  return std::vector<std::vector<T>>(n, std::vector<T>(m, d));
}

using Long = long long;

template <typename T>
using MinPQ = std::priority_queue<T, std::vector<T>, std::greater<T>>;
#line 2 "/tmp/tmp-91692R8GdNtTpJUL6.cpp"

#line 4 "/tmp/tmp-91692R8GdNtTpJUL6.cpp"

int main() {
  std::ios::sync_with_stdio(false);
  CIN(int, T);
  while (T--) {
    CIN(int, n);
    std::vector<int> a(n);
    for (int i = 0; i < n; ++i) {
      std::cin >> a[i];
      a[i] -= i;
    }
    using DP = std::array<bool, 3>;
    DP dp;
    std::ranges::fill(dp, true);
    for (int i = 1; i < n; ++i) {
      DP new_dp{};
      for (int y = -1; y <= 1; ++y) {
        for (int x = -1; x <= 1; ++x) {
          new_dp[1 + y] |= dp[1 + x] && a[i - 1] + x == a[i] + y;
        }
      }
      dp.swap(new_dp);
    }
    std::cout << (std::ranges::count(dp, true) ? "YES" : "NO") << "\n";
  }
}