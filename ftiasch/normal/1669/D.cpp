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
#line 2 "/tmp/tmp-44485j4VGeMisGy3.cpp"

#line 4 "/tmp/tmp-44485j4VGeMisGy3.cpp"

int main() {
  std::ios::sync_with_stdio(false);
  int T = read();
  while (T--) {
    int n = read();
    auto s = read<std::string>();
    bool ok = true;
    for (int i = 0; i < n;) {
      if (s[i] == 'W') {
        i++;
      } else {
        int j = i;
        std::array<bool, 2> color{};
        while (j < n && s[j] != 'W') {
          color[s[j] == 'R'] = true;
          j++;
        }
        ok &= color[0] && color[1];
        i = j;
      }
    }
    std::cout << (ok ? "YES" : "NO") << "\n";
  }
}