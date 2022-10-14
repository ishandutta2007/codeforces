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
#line 2 "/tmp/tmp-144689dX2m1yyiimot.cpp"

std::vector<std::pair<int, Long>> expand(int m, int n,
                                         const std::vector<int> &as) {
  std::vector<std::pair<int, Long>> result;
  for (int a : as) {
    int count = 1;
    while (a % m == 0) {
      count *= m;
      a /= m;
    }
    if (result.empty() || result.back().first != a) {
      result.emplace_back(a, count);
    } else {
      result.back().second += count;
    }
  }
  return result;
}

int main() {
  IO io;
  int T = io.read();
  while (T--) {
    int n = io.read();
    int m = io.read();
    auto a = expand(m, n, io.read_vector(n));
    int k = io.read();
    auto b = expand(m, k, io.read_vector(k));
    std::cout << (a == b ? "Yes" : "No") << "\n";
  }
}