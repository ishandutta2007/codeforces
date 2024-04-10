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
#line 2 "/tmp/tmp-311455c0n4EVXI9TBB.cpp"

#line 4 "/tmp/tmp-311455c0n4EVXI9TBB.cpp"

struct Solver {
  Solver(int n) : tree(n) {
    int root;
    for (int i = 0; i < n; ++i) {
      int p = read() - 1;
      if (p == i) {
        root = i;
      } else {
        tree[p].push_back(i);
      }
    }
    dfs(root, -1);
  }

  void dfs(int u, int id) {
    if (!~id) {
      id = plan.size();
      plan.emplace_back();
    }
    plan[id].push_back(u);
    if (!tree[u].empty()) {
      dfs(tree[u][0], id);
    }
    for (int i = 1; i < tree[u].size(); ++i) {
      dfs(tree[u][i], -1);
    }
  }

  void out() const {
    std::cout << plan.size() << "\n";
    for (auto &&p : plan) {
      std::cout << p.size() << "\n";
      for (int v : p) {
        std::cout << v + 1 << " ";
      }
      std::cout << "\n";
    }
  }

  std::vector<std::vector<int>> tree, plan;
};

int main() {
  std::ios::sync_with_stdio(false);
  int T = read();
  while (T--) {
    int n = read();
    Solver(n).out();
  }
}