#line 1 "/home/ftiasch/Documents/shoka/util.h"
#include <bits/stdc++.h>

#define ALL(v) (v).begin(), (v).end()

using Long = long long;
using u64 = uint64_t;

struct IO {
  IO() { std::ios::sync_with_stdio(false); }

  template <typename T = int> T read() const {
    T v;
    std::cin >> v;
    return v;
  }

  template <typename T = int> std::vector<T> read_vector(size_t n) const {
    std::vector<T> v(n);
    for (size_t i = 0; i < n; ++i) {
      v[i] = read<T>();
    }
    return v;
  }
};

template <typename T>
using MinPQ = std::priority_queue<T, std::vector<T>, std::greater<T>>;
#line 2 "/tmp/tmp-144689T8FMCyNRq67X.cpp"

int solve(int n, std::vector<int> a) {
  int i = 0;
  while (i < n && !a[i]) {
    i++;
  }
  if (i == n) {
    return 0;
  }
  int j = n;
  while (!a[j - 1]) {
    j--;
  }
  return std::count(a.begin() + i, a.begin() + j, 0) ? 2 : 1;
}

int main() {
  IO io;
  int T = io.read();
  while (T--) {
    int n = io.read();
    auto a = io.read_vector(n);
    std::cout << solve(n, std::move(a)) << std::endl;
  }
}