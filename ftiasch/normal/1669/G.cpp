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

template <typename T> using Vector2D = std::vector<std::vector<T>>;

template <typename T = int> Vector2D<T> vector_2d(int n, int m) {
  return Vector2D<T>(n, std::vector<T>(m));
}

template <typename T = int> Vector2D<T> vector_2d(int n, int m, T d) {
  return Vector2D<T>(n, std::vector<T>(m, d));
}

using Long = long long;
using u64 = uint64_t;

template <typename T>
using MinPQ = std::priority_queue<T, std::vector<T>, std::greater<T>>;
#line 2 "/tmp/tmp-4448KLL3BXuEPSNt.cpp"

#line 4 "/tmp/tmp-4448KLL3BXuEPSNt.cpp"

int main() {
  std::ios::sync_with_stdio(false);
  int T = read();
  while (T--) {
    int n = read();
    int m = read();
    auto s = read_vector<std::string>(n);
    std::vector<int> bot(m, n - 1);
    for (int i = n; i--;) {
      for (int j = 0; j < m; ++j) {
        if (s[i][j] == 'o') {
          bot[j] = i - 1;
        } else if (s[i][j] == '*') {
          s[i][j] = '.';
          s[bot[j]--][j] = '*';
        }
      }
    }
    for (int i = 0; i < n; ++i) {
      std::cout << s[i] << "\n";
    }
  }
}