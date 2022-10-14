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
#line 2 "/tmp/tmp-565589cS6GdBnnj3wh.cpp"

#line 4 "/tmp/tmp-565589cS6GdBnnj3wh.cpp"

int main() {
  IO io;
  int T = io.read();
  while (T--) {
    int n = io.read();
    auto p = io.read_vector(n);
    if (n == 1) {
      std::cout << -1 << "\n";
    } else {
      std::set<int> e;
      for (int i = 1; i <= n; ++i) {
        e.insert(i);
      }
      std::vector<int> q(n);
      int s = 0;
      while (s + 3 < n) {
        auto i = e.begin();
        if (p[s] == *i) {
          i++;
        }
        q[s++] = *i;
        e.erase(i);
      }
      for (int i = s; i < n; ++i) {
        q[i] = *e.begin();
        e.erase(e.begin());
      }
      while (true) {
        bool ok = true;
        for (int i = s; i < n; ++i) {
          ok &= p[i] != q[i];
        }
        if (ok) {
          break;
        }
        std::next_permutation(q.begin() + s, q.end());
      }
      for (int i = 0; i < n; ++i) {
        std::cout << q[i] << " \n"[i + 1 == n];
      }
    }
  }
}