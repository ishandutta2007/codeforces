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
#line 2 "/tmp/tmp-41819tZPxG2TkAnxQ.cpp"

#line 4 "/tmp/tmp-41819tZPxG2TkAnxQ.cpp"

int solve(int n, std::vector<int> a) {
  std::ranges::sort(a);
  int zeros = std::ranges::count(a, 0);
  if (zeros) {
    return n - zeros;
  }
  // zeros == 0
  return (std::unique(a.begin(), a.end()) == a.end()) ? n + 1 : n;
}

int main() {
  std::ios::sync_with_stdio(false);
  int T = read();
  while (T--) {
    int n = read();
    auto a = read_vector(n);
    std::cout << solve(n, std::move(a)) << "\n";
  }
}