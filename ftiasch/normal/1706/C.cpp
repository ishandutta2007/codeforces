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
#line 2 "/tmp/tmp-9007090VMy1270V2hq.cpp"

int main() {
  IO io;
  int T = io.read();
  while (T--) {
    int n = io.read();
    auto h = io.read_vector(n);
    using Entry = std::pair<Long, Long>;
    Entry premax{0, 0}, dp0{0, 0}, dp1{0, 0};
    for (int i = 1; i + 1 < n; ++i) {
      premax = std::max(premax, dp0);
      dp0 = {premax.first + 1,
             premax.second -
                 std::max(std::max(h[i - 1], h[i + 1]) + 1 - h[i], 0)};
      std::swap(dp0, dp1);
    }
    std::cout << -std::max({premax, dp0, dp1}).second << "\n";
  }
}