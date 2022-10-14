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
#line 2 "/tmp/tmp-4448VdEVsFaHSgFn.cpp"

#line 4 "/tmp/tmp-4448VdEVsFaHSgFn.cpp"

const int C = 11;
int main() {
  std::ios::sync_with_stdio(false);
  int T = read();
  while (T--) {
    int n = read();
    std::array<int, C> row{}, col{};
    std::array<std::array<int, C>, C> count{};
    for (int i = 0; i < n; ++i) {
      auto s = read<std::string>();
      int x = s[0] - 'a';
      int y = s[1] - 'a';
      row[x]++;
      col[y]++;
      count[x][y]++;
    }
    Long result = 0;
    for (int i = 0; i < C; ++i) {
      for (int j = 0; j < C; ++j) {
        result += 1LL * count[i][j] * (row[i] + col[j] - 2 * count[i][j]);
      }
    }
    std::cout << (result >> 1) << "\n";
  }
}