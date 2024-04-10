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
#line 2 "/tmp/tmp-565589Mdy1sPZXIq6r.cpp"

std::pair<int, int> check(int n, int m, const std::vector<std::string> &s,
                          int l) {
  int u0 = INT_MIN, u1 = INT_MAX, v0 = INT_MIN, v1 = INT_MAX;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      if (s[i][j] == 'B') {
        u0 = std::max(u0, i - j - l);
        u1 = std::min(u1, i - j + l);
        v0 = std::max(v0, i + j - l);
        v1 = std::min(v1, i + j + l);
      }
    }
  }
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      if (u0 <= i - j && i - j <= u1 && v0 <= i + j && i + j <= v1) {
        return {i, j};
      }
    }
  }
  return {-1, -1};
};

int main() {
  IO io;
  int T = io.read();
  while (T--) {
    int n = io.read();
    int m = io.read();
    auto s = io.read_vector<std::string>(n);
    int low = 0;
    int high = n + m;
    while (low < high) {
      int middle = (low + high) >> 1;
      if (~check(n, m, s, middle).first) {
        high = middle;
      } else {
        low = middle + 1;
      }
    }
    auto [x, y] = check(n, m, s, high);
    std::cout << x + 1 << " " << y + 1 << "\n";
  }
}