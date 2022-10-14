#line 1 "/home/ftiasch/Documents/shoka/util.h"
#include <bits/stdc++.h>

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

#define ALL(v) (v).begin(), (v).end()

template <typename T> std::vector<std::vector<T>> vector_2d(int n, int m) {
  return std::vector<std::vector<T>>(n, std::vector<T>(m));
}

template <typename T> std::vector<std::vector<T>> vector_2d(int n, int m, T d) {
  return std::vector<std::vector<T>>(n, std::vector<T>(m, d));
}

using Long = long long;
using u64 = uint64_t;

template <typename T>
using MinPQ = std::priority_queue<T, std::vector<T>, std::greater<T>>;
#line 2 "/tmp/tmp-169394jap6O2RtdX4c.cpp"

#line 4 "/tmp/tmp-169394jap6O2RtdX4c.cpp"

int main() {
  std::ios::sync_with_stdio(false);
  int T = read();
  while (T--) {
    int n = read();
    int x = read();
    auto w = read_vector(n);
    if (std::accumulate(ALL(w), 0) == x) {
      std::cout << "NO\n";
    } else {
      std::cout << "YES\n";
      for (int i = 0, s = 0; i < n; ++i) {
        s += w[i];
        if (s == x) {
          std::swap(w[i], w[i + 1]);
          break;
        }
      }
      for (int i = 0; i < n; ++i) {
        std::cout << w[i] << " \n"[i + 1 == n];
      }
    }
  }
}