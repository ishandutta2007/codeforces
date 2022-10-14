#line 1 "util.h"
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
#line 2 "/tmp/tmp-696031N6E6rjhipNlM.cpp"

#line 4 "/tmp/tmp-696031N6E6rjhipNlM.cpp"

int solve(const std::string &s) {
  if (s.size() == 2) {
    return s[1] - '0';
  }
  return *std::ranges::min_element(s) - '0';
}

int main() {
  std::ios::sync_with_stdio(false);
  int T = read();
  while (T--) {
    auto s = read<std::string>();
    std::cout << solve(s) << "\n";
  }
}