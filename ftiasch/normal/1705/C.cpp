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
#line 2 "/tmp/tmp-9007097yx5Y14JnfUL.cpp"

int main() {
  IO io;
  int T = io.read();
  while (T--) {
    int n = io.read();
    int c = io.read();
    int q = io.read();
    auto s = io.read<std::string>();
    std::vector<Long> end(c + 1), l(c);
    end[0] = s.size();
    for (int i = 0; i < c; ++i) {
      l[i] = io.read<Long>() - 1;
      Long r = io.read<Long>();
      end[i + 1] = end[i] + (r - l[i]);
    }
    while (q--) {
      Long k = io.read<Long>() - 1;
      for (int i = c; i--;) {
        if (k >= end[i]) {
          k = l[i] + k - end[i];
        }
      }
      std::cout << s[k] << "\n";
    }
  }
}