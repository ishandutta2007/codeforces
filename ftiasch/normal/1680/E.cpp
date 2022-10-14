#line 1 "/home/ftiasch/Documents/shoka/util.h"
#include <bits/stdc++.h>

template <typename T = int> T read() {
  T v;
  std::cin >> v;
  return v;
}

template <typename T = int> std::vector<T> read_vector(size_t n) {
  std::vector<T> v(n);
  for (size_t i = 0; i < n; ++i) {
    v[i] = read<T>();
  }
  return v;
}

#define ALL(v) (v).begin(), (v).end()

template <typename T = int>
std::vector<std::vector<T>> vector_2d(int n, int m) {
  return std::vector<std::vector<T>>(n, std::vector<T>(m));
}

template <typename T = int>
std::vector<std::vector<T>> vector_2d(int n, int m, T d) {
  return std::vector<std::vector<T>>(n, std::vector<T>(m, d));
}

using Long = long long;
using u64 = uint64_t;

template <typename T>
using MinPQ = std::priority_queue<T, std::vector<T>, std::greater<T>>;
#line 2 "/tmp/tmp-418191RlLgBhvTJkjC.cpp"

#line 4 "/tmp/tmp-418191RlLgBhvTJkjC.cpp"

using DP = std::array<int, 4>;

bool subset(int a, int b) { return (a & b) == a; }

int main() {
  std::ios::sync_with_stdio(false);
  int T = read();
  while (T--) {
    int n = read();
    std::array<std::string, 2> s;
    s[0] = read<std::string>();
    s[1] = read<std::string>();
    std::vector<int> colmask(n);
    for (int i = 0; i < n; ++i) {
      colmask[i] = (s[0][i] == '*') | (s[1][i] == '*') << 1;
    }
    int from = 0;
    while (colmask[from] == 0) {
      from++;
    }
    int to = n - 1;
    while (colmask[to] == 0) {
      to--;
    }
    DP dp;
    int inf = 2 * n;
    dp[0] = inf;
    for (int mask = 1; mask < 4; ++mask) {
      dp[mask] = subset(colmask[from], mask) ? __builtin_popcount(mask) : inf;
    }
    for (int i = from + 1; i <= to; ++i) {
      DP new_dp;
      std::ranges::fill(new_dp, inf);
      for (int mask = 1; mask < 4; ++mask) {
        if (subset(colmask[i], mask)) {
          for (int pmask = 1; pmask < 4; ++pmask) {
            if (mask & pmask) {
              new_dp[mask] =
                  std::min(new_dp[mask], dp[pmask] + __builtin_popcount(mask));
            }
          }
        }
      }
      dp.swap(new_dp);
    }
    std::cout << *std::ranges::min_element(dp) - 1 << "\n";
  }
}