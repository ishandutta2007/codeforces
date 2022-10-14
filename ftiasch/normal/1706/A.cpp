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
#line 2 "/tmp/tmp-900709LZBOsaLu4dLr.cpp"

int main() {
  IO io;
  int T = io.read();
  while (T--) {
    int m = io.read();
    int n = io.read();
    std::string s(n, 'B');
    for (int i = 0; i < m; ++i) {
      int a = io.read();
      int x = a - 1;
      int y = n - a;
      if (x > y) {
        std::swap(x, y);
      }
      if (s[x] == 'A') {
        s[y] = 'A';
      } else {
        s[x] = 'A';
      }
    }
    std::cout << s << "\n";
  }
}