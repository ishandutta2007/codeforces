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
#line 2 "/tmp/tmp-368362bwVvu33hrtSr.cpp"

int main() {
  IO io;
  int n = io.read();
  int q = io.read();
  auto p = io.read_vector(n);
  std::vector<Long> s(n + 1);
  std::ranges::sort(p);
  for (int i = n; i--;) {
    s[i] = p[i] + s[i + 1];
  }
  while (q--) {
    int x = io.read();
    int y = io.read();
    std::cout << s[n - x] - s[n - x + y] << "\n";
  }
}