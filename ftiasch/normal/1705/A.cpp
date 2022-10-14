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

template <typename T>
using MinPQ = std::priority_queue<T, std::vector<T>, std::greater<T>>;
#line 2 "/tmp/tmp-898297LULAOAtgTF0Y.cpp"

int main() {
  IO io;
  int T = io.read();
  while (T--) {
    int n = io.read();
    int x = io.read();
    auto h = io.read_vector(n << 1);
    std::sort(ALL(h));
    bool ok = true;
    for (int i = 0; i < n; ++i) {
      ok &= h[i] + x <= h[n + i];
    }
    std::cout << (ok ? "YES" : "NO") << "\n";
  }
}