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
#line 2 "/tmp/tmp-453132gxmxCUqbpFR8.cpp"

#include <bits/stdc++.h>

int main() {
  IO io;
  int T = io.read();
  while (T--) {
    int x = io.read();
    std::array<int, 2> r;
    for (int i = 31; i--;) {
      r[x >> i & 1] = 1 << i;
    }
    std::cout << (r[1] == x ? r[0] | r[1] : r[1]) << "\n";
  }
}