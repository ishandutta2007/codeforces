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
#line 2 "/tmp/tmp-418191bbPy3eqzjAxM.cpp"

#line 4 "/tmp/tmp-418191bbPy3eqzjAxM.cpp"

int solve(int l1, int r1, int l2, int r2) {
  if (std::max(l1, l2) <= std::min(r1, r2)) {
    return std::max(l1, l2);
  }
  return l1 + l2;
}

int main() {
  std::ios::sync_with_stdio(false);
  int T = read();
  while (T--) {
    int l1 = read();
    int r1 = read();
    int l2 = read();
    int r2 = read();
    std::cout << solve(l1, r1, l2, r2) << "\n";
  }
}