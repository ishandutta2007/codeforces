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
#line 2 "/tmp/tmp-478690fRHLJeJyVhoZ.cpp"

#include <bits/stdc++.h>

const int C = 26;

int main() {
  IO io;
  int T = io.read();
  while (T--) {
    int n = io.read();
    std::array<int, C> count{};
    for (int i = 0; i < 2 * n + 1; ++i) {
      auto s = io.read<std::string>();
      for (char c : s) {
        count[c - 'a'] ^= 1;
      }
    }
    std::cout << static_cast<char>(
                     'a' +
                     (std::find(count.begin(), count.end(), 1) - count.begin()))
              << "\n";
  }
}