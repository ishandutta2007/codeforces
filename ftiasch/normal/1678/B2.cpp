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
#line 2 "/tmp/tmp-41819Q0UcdrNj5PO8.cpp"

#line 4 "/tmp/tmp-41819Q0UcdrNj5PO8.cpp"

using Pair = std::pair<int, int>;
using DP = std::array<Pair, 2>;

int main() {
  std::ios::sync_with_stdio(false);
  int T = read();
  while (T--) {
    int n = read();
    auto s = read<std::string>();
    DP dp{Pair{(s[0] != '0') + (s[1] != '0'), 1},
          Pair{(s[0] != '1') + (s[1] != '1'), 1}};
    for (int i = 2; i < n; i += 2) {
      int cost0 = (s[i] != '0') + (s[i + 1] != '0');
      int cost1 = (s[i] != '1') + (s[i + 1] != '1');
      dp = {std::min(Pair{dp[0].first + cost0, dp[0].second},
                     Pair{dp[1].first + cost0, dp[1].second + 1}),
            std::min(Pair{dp[0].first + cost1, dp[0].second + 1},
                     Pair{dp[1].first + cost1, dp[1].second})};
    }
    auto result = std::min(dp[0], dp[1]);
    std::cout << result.first << " " << result.second << "\n";
  }
}