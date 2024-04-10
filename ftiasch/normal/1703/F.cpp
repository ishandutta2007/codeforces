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

  template <typename T> std::ostream &operator<<(const T &o) {
    return std::cout << o;
  }
};

template <typename T>
using MinPQ = std::priority_queue<T, std::vector<T>, std::greater<T>>;
#line 2 "/tmp/tmp-885806d82uCfwYmzsU.cpp"

int main() {
  IO io;
  int T = io.read();
  while (T--) {
    int n = io.read();
    std::vector<int> a(n + 1), count(n + 1);
    for (int i = 1; i <= n; ++i) {
      a[i] = io.read();
      count[i] = count[i - 1] + (a[i] < i);
    }
    Long result = 0;
    for (int j = 1; j <= n; ++j) {
      if (0 < a[j] && a[j] < j) {
        result += count[std::min(a[j] - 1, n)];
      }
    }
    std::cout << result << "\n";
  }
}