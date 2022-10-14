#line 1 "util.h"
#include <bits/stdc++.h>

#define ALL(v) (v).begin(), (v).end()

using Long = long long;
using u64 = uint64_t;

struct IO {
  IO() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
  }

  template <typename T = int> T read() const {
    T v;
    std::cin >> v;
    return v;
  }

  template <typename T = int> std::vector<T> read_vector(size_t n) const {
    std::vector<T> v(n);
    for (size_t i = 0; i < n; ++i) {
      v[i] = read<T>();
    }
    return v;
  }

  template <typename T> std::ostream &operator<<(const T &o) {
    return std::cout << o;
  }
};

template <typename T>
using MinPQ = std::priority_queue<T, std::vector<T>, std::greater<T>>;
#line 2 "/tmp/tmp-900709GkJ0x1OgHRI0.cpp"

int main() {
  IO io;
  int T = io.read();
  while (T--) {
    int n = io.read();
    std::vector<std::array<int, 2>> dp(n);
    for (int i = 0; i < n; ++i) {
      int c = io.read() - 1;
      int current = dp[c][(i & 1) ^ 1] + 1;
      dp[c][i & 1] = std::max(dp[c][i & 1], current);
    }
    for (int i = 0; i < n; ++i) {
      std::cout << std::max(dp[i][0], dp[i][1]) << " \n"[i + 1 == n];
    }
  }
}