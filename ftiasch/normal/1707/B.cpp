#line 1 "util.h"
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

template <typename T>
using MinPQ = std::priority_queue<T, std::vector<T>, std::greater<T>>;
#line 2 "/tmp/tmp-9007094b30unOU5ZC6.cpp"

int main() {
  IO io;
  int T = io.read();
  while (T--) {
    int n = io.read();
    int z = 0;
    auto a = io.read_vector(n);
    std::reverse(ALL(a));
    for (int _ = 0; _ < n - 1; ++_) {
      for (int i = 1; i < a.size(); ++i) {
        a[i - 1] -= a[i];
      }
      if (!z) {
        a.pop_back();
      }
      std::sort(ALL(a), std::greater<int>());
      if (z) {
        z--;
      }
      while (a.size() >= 2 && !a.back()) {
        z++;
        a.pop_back();
      }
    }
    std::cout << a[0] << "\n";
  }
}