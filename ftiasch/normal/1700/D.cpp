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
#line 2 "D_River_Locks.cpp"

int main() {
  IO io;
  int n = io.read();
  auto v = io.read_vector(n);
  Long sum = 0, min_t = 0;
  for (int i = 1; i <= n; ++i) {
    sum += v[i - 1];
    min_t = std::max(min_t, (sum + (i - 1)) / i);
  }
  int q = io.read();
  while (q--) {
    int t = io.read();
    std::cout << ((t < min_t) ? -1 : (sum + t - 1) / t) << "\n";
  }
}