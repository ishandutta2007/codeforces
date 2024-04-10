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
#line 2 "/tmp/tmp-169394oYhWV5KBBlSB.cpp"

#line 4 "/tmp/tmp-169394oYhWV5KBBlSB.cpp"

const int N = 1'000'000;

int main() {
  std::ios::sync_with_stdio(false);
  std::vector<bool> ok(N + 1);
  ok[0] = true;
  for (int y = 2020; y <= 2021; ++y) {
    for (int j = y; j <= N; ++j) {
      if (ok[j - y]) {
        ok[j] = true;
      }
    }
  }
  int T = read();
  while (T--) {
    int n = read();
    std::cout << (ok[n] ? "YES" : "NO") << "\n";
  }
}