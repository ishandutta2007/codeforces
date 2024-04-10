#line 1 "/home/ftiasch/Documents/shoka/util.h"
#include <bits/stdc++.h>

#define ALL(v) (v).begin(), (v).end()

using Long = long long;
using u64 = uint64_t;

struct IO {
  IO() { std::ios::sync_with_stdio(false); }

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
#line 2 "/tmp/tmp-565589bIh3Gui4xFS8.cpp"

int main() {
  IO io;
  int T = io.read();
  while (T--) {
    int n = io.read();
    auto a = io.read_vector(n);
    if (n & 1) {
      std::cout << "NO\n";
    } else {
      std::ranges::sort(a);
      std::vector<int> b(n);
      for (int i = 0; i < n; ++i) {
        b[i] = a[(i & 1 ? (n >> 1) : 0) + (i >> 1)];
      }
      bool ok = true;
      for (int i = 1; i < n; i += 2) {
        ok &= b[i - 1] < b[i] && b[i] > b[(i + 1) % n];
      }
      if (ok) {
        std::cout << "YES\n";
        for (int i = 0; i < n; ++i) {
          std::cout << b[i] << " \n"[i + 1 == n];
        }
      } else {
        std::cout << "NO\n";
      }
    }
  }
}