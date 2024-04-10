#line 1 "/home/ftiasch/Documents/shoka/util.h"
#include <iostream>
#include <vector>

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
#line 2 "/tmp/tmp-453132Drqy3zGwAIAe.cpp"

#include <bits/stdc++.h>

int main() {
  IO io;
  int T = io.read();
  while (T--) {
    int n = io.read();
    int minq = INT_MAX, evens = 0;
    for (int a : io.read_vector(n)) {
      int q = __builtin_ctz(a);
      minq = std::min(minq, q);
      evens += q > 0;
    }
    int result;
    if (minq > 0) {
      result = minq + (evens - 1);
    } else {
      // has odds
      result = evens;
    }
    std::cout << result << "\n";
  }
}