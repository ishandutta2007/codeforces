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
#line 2 "/tmp/tmp-3301312pjWhuaVT6Jo.cpp"

#line 4 "/tmp/tmp-3301312pjWhuaVT6Jo.cpp"

int solve(int a, int b) {
  if (a > b) {
    std::swap(a, b);
  }
  // 0 <= x <= a <= b
  // a + b <= 3 * x
  int x = (a + b + 2) / 3;
  if (x <= a) {
    return x;
  }
  // a < x <= b
  // b <= 2 * x
  x = (b + 1) >> 1;
  return x;
}

int solve3(int a, int b) {
  if (a > b) {
    std::swap(a, b);
  }
  return a + ((b - a + 1) >> 1);
}

int main() {
  std::ios::sync_with_stdio(false);
  int n = read();
  auto a = read_vector(n);
  std::vector<int> b(n);
  for (int i = 0; i < n; ++i) {
    b[i] = (a[i] + 1) >> 1;
  }
  std::ranges::nth_element(b, b.begin() + 2);
  int result = b[0] + b[1];
  for (int i = 1; i < n; ++i) {
    // max(A - x, 0) + max(B - x, 0) <= x
    result = std::min(result, solve(a[i - 1], a[i]));
  }
  for (int i = 2; i < n; ++i) {
    result = std::min(result, solve3(a[i - 2], a[i]));
  }
  std::cout << result << "\n";
}