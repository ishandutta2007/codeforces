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

template <typename T = int>
std::vector<std::vector<T>> vector_2d(int n, int m) {
  return std::vector<std::vector<T>>(n, std::vector<T>(m));
}

template <typename T = int>
std::vector<std::vector<T>> vector_2d(int n, int m, T d) {
  return std::vector<std::vector<T>>(n, std::vector<T>(m, d));
}

using Long = long long;
using u64 = uint64_t;

template <typename T>
using MinPQ = std::priority_queue<T, std::vector<T>, std::greater<T>>;
#line 2 "/tmp/tmp-97713PCY3x6IuEqpl.cpp"

#line 4 "/tmp/tmp-97713PCY3x6IuEqpl.cpp"

int main() {
  std::ios::sync_with_stdio(false);
  int T = read();
  while (T--) {
    int n = read();
    std::vector<int> p(n), q(n);
    for (int i = 0; i < n; ++i) {
      p[read() - 1] = i;
    }
    for (int i = 0; i < n; ++i) {
      q[i] = p[read() - 1];
    }
    Long result = 0, gap = n - 1;
    for (int u = 0; u < n; ++u) {
      if (~q[u]) {
        int v = u;
        int length = 0;
        do {
          int vv = q[v];
          q[v] = -1;
          v = vv;
          length++;
        } while (v != u);
        for (int i = 0; i < length; i += 2) {
          result += gap;
          gap -= 2;
        }
      }
    }
    std::cout << (result << 1) << "\n";
  }
}