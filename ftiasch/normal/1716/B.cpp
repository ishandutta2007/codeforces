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

template <typename T> using MinPQ = PQ<T, std::greater<T>>;
#line 2 "/tmp/tmp-21838zwbi5YQq1RTR.cpp"

int main() {
  IO io;
  int T = io.read();
  while (T--) {
    int n = io.read();
    std::vector<int> p(n);
    std::iota(ALL(p), 1);
    std::cout << n << "\n";
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < n; ++j) {
        std::cout << p[j] << " \n"[j + 1 == n];
      }
      if (i + 1 < n) {
        std::swap(p[i], p[i + 1]);
      }
    }
  }
}