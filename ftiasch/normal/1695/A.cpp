#line 1 "/home/ftiasch/Documents/shoka/util.h"
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
};

template <typename T>
using MinPQ = std::priority_queue<T, std::vector<T>, std::greater<T>>;
#line 2 "/tmp/tmp-91229AqCYMJtQ7qVb.cpp"

int main() {
  IO io;
  int T = io.read();
  while (T--) {
    int n = io.read();
    int m = io.read();
    std::pair<int, std::pair<int, int>> best{INT_MIN, {0, 0}};
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < m; ++j) {
        int a = io.read();
        best = std::max(best, {a, {i, j}});
      }
    }
    auto [x, y] = best.second;
    std::cout << std::max(1 + x, n - x) * std::max(1 + y, m - y) << "\n";
  }
}