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
#line 2 "E_Unordered_Swaps.cpp"

struct DepGraph : std::vector<std::vector<int>> {
  DepGraph(int m) : m(m), std::vector<std::vector<int>>(m), visited(m) {}

  void sort() {
    for (int i = 0; i < m; ++i) {
      if (!visited[i]) {
        dfs(i);
      }
    }
  }

  void dfs(int u) {
    for (int v : (*this)[u]) {
      if (!visited[v]) {
        dfs(v);
      }
    }
    visited[u] = true;
    order.push_back(u);
  }

  int m;
  std::vector<bool> visited;
  std::vector<int> order;
};

int main() {
  IO io;
  int n = io.read();
  int m = io.read();
  std::vector<int> p(n);
  for (int i = 0; i < n; ++i) {
    p[i] = io.read() - 1;
  }
  std::vector<std::vector<std::pair<int, int>>> swaps(n);
  for (int i = 0; i < m; ++i) {
    int a = io.read() - 1;
    int b = io.read() - 1;
    swaps[a].emplace_back(b, i);
    swaps[b].emplace_back(a, i);
  }
  std::vector<int> id(n, -1);
  DepGraph deps(m);
  for (int s = 0; s < n; ++s) {
    if (!~id[s]) {
      int count = 0;
      int i = s;
      do {
        id[i] = count++;
        i = p[i];
      } while (i != s);
      i = s;
      do {
        for (auto &p : swaps[i]) {
          p.first = (id[p.first] + count - id[i]) % count;
        }
        std::sort(ALL(swaps[i]));
        for (int j = swaps[i].size(); j-- > 1;) {
          deps[swaps[i][j].second].push_back(swaps[i][j - 1].second);
        }
        i = p[i];
      } while (i != s);
    }
  }
  deps.sort();
  for (int i = 0; i < m; ++i) {
    std::cout << deps.order[i] + 1 << " \n"[i + 1 == m];
  }
}