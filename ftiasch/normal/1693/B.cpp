#line 1 "Documents/shoka/util.h"
#include <bits/stdc++.h>

#define ALL(v) (v).begin(), (v).end()

using Long = long long;
using u64 = uint64_t;

struct IO {
  IO() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
  }

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
#line 2 "/tmp/tmp-2623002vSlpAGNVOjY.cpp"

struct Solver {
  Solver(IO &io, int n) : children(n), l(n), r(n) {
    for (int i = 1; i < n; ++i) {
      int p = io.read() - 1;
      children[p].push_back(i);
    }
    for (int i = 0; i < n; ++i) {
      l[i] = io.read();
      r[i] = io.read();
    }
    dfs(0);
  }

  int dfs(int u) {
    Long sum = 0;
    for (int v : children[u]) {
      sum += dfs(v);
    }
    if (l[u] <= sum) {
      return std::min<Long>(sum, r[u]);
    }
    result++;
    return r[u];
  }

  int result = 0;
  std::vector<std::vector<int>> children;
  std::vector<int> l, r;
};

int main() {
  IO io;
  int T = io.read();
  while (T--) {
    int n = io.read();
    std::cout << Solver{io, n}.result << "\n";
  }
}