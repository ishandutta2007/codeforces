#line 1 "/home/ftiasch/Documents/shoka/util.h"
#include <bits/stdc++.h>

#define ALL(v) (v).begin(), (v).end()

using Long = long long;
using u64 = uint64_t;

struct IO {
  IO() { std::ios::sync_with_stdio(false); }

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
};

template <typename T>
using MinPQ = std::priority_queue<T, std::vector<T>, std::greater<T>>;
#line 2 "/tmp/tmp-565589QCQYgAcH8Jct.cpp"

#line 4 "/tmp/tmp-565589QCQYgAcH8Jct.cpp"

IO io;

struct Solve {
  Solve(int n) : tree(n) {
    for (int i = 0; i < n - 1; ++i) {
      int a = io.read() - 1;
      int b = io.read() - 1;
      tree[a].push_back(b);
      tree[b].push_back(a);
    }
    result = dfs(-1, 0).second;
  }

  std::pair<int, int> dfs(int p, int u) {
    auto &children = tree[u];
    if (~p) {
      children.erase(std::find(ALL(children), p));
    }
    if (children.size() == 0) {
      return {1, 0};
    }
    if (children.size() == 1) {
      int size = dfs(u, children[0]).first;
      return {1 + size, size - 1};
    }
    auto [s0, r0] = dfs(u, children[0]);
    auto [s1, r1] = dfs(u, children[1]);
    return {1 + s0 + s1, std::max(s0 - 1 + r1, r0 + s1 - 1)};
  }

  int result;
  std::vector<std::vector<int>> tree;
};
int main() {
  int T = io.read();
  while (T--) {
    int n = io.read();
    std::cout << Solve{n}.result << std::endl;
  }
}