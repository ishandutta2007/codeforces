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

template <typename T, typename Compare = std::less<T>>
struct PQ : public std::priority_queue<T, std::vector<T>, Compare> {
  T pop() {
    using Base = std::priority_queue<T, std::vector<T>, Compare>;
    auto t = Base::top();
    Base::pop();
    return t;
  }
};
#line 2 "/tmp/tmp-1152913E6D6wQHbFuos.cpp"

int main() {
  IO io;
  int n = io.read();
  int q = io.read();
  auto h = io.read_vector(n);
  std::vector<Long> fwd(n), bwd(n);
  for (int i = n - 2; i >= 0; --i) {
    fwd[i] = std::max(h[i] - h[i + 1], 0) + fwd[i + 1];
  }
  for (int i = 1; i < n; ++i) {
    bwd[i] = bwd[i - 1] + std::max(h[i] - h[i - 1], 0);
  }
  while (q--) {
    int s = io.read() - 1;
    int t = io.read() - 1;
    std::cout << (s < t ? fwd[s] - fwd[t] : bwd[s] - bwd[t]) << "\n";
  }
}