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
#line 2 "/tmp/tmp-91229MFV00qWWdlj1.cpp"

int main() {
  IO io;
  int T = io.read();
  while (T--) {
    int n = io.read();
    int m = io.read();
    auto a0 = io.read_vector(m);
    std::vector<int> dp_min(m);
    dp_min[0] = a0[0];
    for (int j = 1; j < m; ++j) {
      dp_min[j] = dp_min[j - 1] + a0[j];
    }
    auto dp_max = dp_min;
    for (int i = 1; i < n; ++i) {
      int a0 = io.read();
      dp_min[0] += a0;
      dp_max[0] += a0;
      for (int j = 1; j < m; ++j) {
        int a = io.read();
        dp_min[j] = std::min(dp_min[j - 1], dp_min[j]) + a;
        dp_max[j] = std::max(dp_max[j - 1], dp_max[j]) + a;
      }
    }
    std::cout << (((n + m) & 1) && dp_min[m - 1] <= 0 && 0 <= dp_max[m - 1]
                      ? "YES"
                      : "NO")
              << "\n";
  }
}