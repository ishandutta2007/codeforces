#line 1 "/home/ftiasch/Documents/shoka/util.h"
#include <iostream>
#include <vector>
#include <queue>

#define ALL(v) (v).begin(), (v).end()

using Long = long long;
using u64 = uint64_t;

struct IO {
  IO() { std::cin.sync_with_stdio(false); }

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
};

template <typename T>
using MinPQ = std::priority_queue<T, std::vector<T>, std::greater<T>>;
#line 2 "/tmp/tmp-11630VdXbUpiWQxPn.cpp"

#include <bits/stdc++.h>

int main() {
  IO io;
  int T = io.read();
  while (T--) {
    int n = io.read();
    int m = io.read();
    auto s = io.read<std::string>();
    int w = 0;
    int result = n;
    for (int i = n; i--;) {
      w += s[i] == 'W';
      if (i + m < n) {
        w -= s[i + m] == 'W';
      }
      if (i + m <= n) {
        result = std::min(result, w);
      }
    }
    std::cout << result << "\n";
  }
}