#line 1 "/home/ftiasch/Documents/shoka/util.h"
#include <bits/stdc++.h>

#define ALL(v) (v).begin(), (v).end()

using Long = long long;
using u64 = uint64_t;

struct IO {
  IO() { std::ios::sync_with_stdio(false); }

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
#line 2 "C_Helping_the_Nature.cpp"

int main() {
  IO io;
  int T = io.read();
  while (T--) {
    int n = io.read();
    std::vector<Long> d(n + 1);
    int last = 0;
    for (int i = 0; i < n; ++i) {
      int a = io.read();
      d[i] = a - last;
      last = a;
    }
    d[n] = -last;
    Long result = 0;
    for (int i = 1; i < n; ++i) {
      result += std::abs(d[i]);
      if (d[i] < 0) {
        d[0] += d[i];
      }
    }
    result += std::abs(d[0]);
    std::cout << result << "\n";
  }
}