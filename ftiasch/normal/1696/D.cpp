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
#line 2 "/tmp/tmp-144689jwNgCrUFRB5e.cpp"

int solve(int n, const std::vector<int> &a) {
  std::vector<std::pair<int, int>> suffix_min(n + 1), suffix_max(n + 1);
  suffix_min[n] = {n + 1, n};
  suffix_max[n] = {0, n};
  for (int i = n; i--;) {
    suffix_min[i] = std::min(std::make_pair(a[i], i), suffix_min[i + 1]);
    suffix_max[i] = std::max(std::make_pair(a[i], i), suffix_max[i + 1]);
  }
  int i = std::find(ALL(a), 1) - a.begin();
  int result = 0;
  while (i < n - 1) {
    result++;
    if (i == suffix_min[i].second) {
      i = suffix_max[i].second;
    } else {
      assert(i == suffix_max[i].second);
      i = suffix_min[i].second;
    }
  }
  return result;
}

int main() {
  IO io;
  int T = io.read();
  while (T--) {
    int n = io.read();
    auto a = io.read_vector(n);
    auto fwd = solve(n, a);
    std::reverse(ALL(a));
    auto bwd = solve(n, a);
    std::cout << fwd + bwd << "\n";
  }
}