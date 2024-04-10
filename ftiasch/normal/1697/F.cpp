#line 1 "/home/ftiasch/Documents/shoka/tarjan.h"
#include <utility>
#include <vector>

class Tarjan {
public:
  using Graph = std::vector<std::vector<int>>;

  static Graph to_graph(int n, const std::vector<std::pair<int, int>> &edges) {
    Graph graph(n);
    for (auto &&[u, v] : edges) {
      graph[u].push_back(v);
    }
    return graph;
  }

  Tarjan(const Graph &graph_)
      : n(graph_.size()), dfn(n, -1), scc_id(n), low(n), graph(graph_) {
    int dfs_count = 0;
    std::vector<int> stack;
    for (int r = 0; r < n; ++r) {
      dfs(dfs_count, stack, r);
    }
  }

  Graph scc_graph() const {
    Graph result(number_of_scc);
    for (int u = 0; u < n; ++u) {
      for (int v : graph[u]) {
        if (scc_id[u] != scc_id[v]) {
          result[scc_id[u]].push_back(scc_id[v]);
        }
      }
    }
    return result;
  }

  int n, number_of_scc = 0;
  std::vector<int> dfn, scc_id;

private:
  void dfs(int &dfs_count, std::vector<int> &stack, int u) {
    if (dfn[u] == -1) {
      int tmp = dfn[u] = low[u] = dfs_count++;
      stack.push_back(u);
      for (int v : graph[u]) {
        dfs(dfs_count, stack, v);
        tmp = std::min(tmp, low[v]);
      }
      low[u] = tmp;
      if (dfn[u] == low[u]) {
        int v;
        do {
          v = stack.back();
          stack.pop_back();
          scc_id[v] = number_of_scc;
          low[v] = n;
        } while (u != v);
        number_of_scc++;
      }
    }
  }

  std::vector<int> low;
  const Graph &graph;
};
#line 2 "F_Too_Many_Constraints.cpp"

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
#line 4 "F_Too_Many_Constraints.cpp"

using Var = std::tuple<int, int, int>;

struct Graph : public std::vector<std::vector<int>> {
  Graph(int n, int k)
      : n(n), k(k), std::vector<std::vector<int>>((n * (k + 1)) << 1) {}

  int get_id(int x, int y, int t) {
    assert(0 <= x && x < n);
    assert(0 <= y && y <= k);
    assert(t == 0 || t == 1);
    return (x * (k + 1) + y) << 1 | t;
  }

  void add(Var u, Var v) {
    auto [ux, uy, ut] = u;
    auto [vx, vy, vt] = v;
    (*this)[get_id(ux, uy, ut)].push_back(get_id(vx, vy, vt));
    (*this)[get_id(vx, vy, vt ^ 1)].push_back(get_id(ux, uy, ut ^ 1));
  }

  int n, k;
};

int main() {
  IO io;
  int T = io.read();
  while (T--) {
    int n = io.read();
    int m = io.read();
    int k = io.read();
    Graph graph(n, k);
    for (int i = 0; i < n; ++i) {
      graph.add({i, 0, 1}, {i, 0, 0});
      for (int j = 0; j + 1 <= k; ++j) {
        graph.add({i, j, 1}, {i, j + 1, 1});
      }
      graph.add({i, k, 0}, {i, k, 1});
    }
    for (int i = 1; i < n; ++i) {
      for (int j = 1; j < k; ++j) {
        graph.add({i, j, 1}, {i - 1, j, 1});
      }
    }
    // a[i] >= x <=> (i, x - 1, 0)
    // a[i] <= x <=> (i, x, 1)
    while (m--) {
      int op = io.read();
      if (op == 1) {
        int i = io.read() - 1;
        int x = io.read();
        graph.add({i, x - 1, 0}, {i, x, 0});
      } else if (op == 2) {
        int i = io.read() - 1;
        int j = io.read() - 1;
        int l = io.read();
        for (int x = std::max(1, l - k); x <= k; ++x) {
          // a[i] >= x => a[j] <= l - x
          graph.add({i, x - 1, 0}, {j, std::max(l - x, 0), 1});
        }
      } else {
        int i = io.read() - 1;
        int j = io.read() - 1;
        int l = io.read();
        for (int x = 1; x <= std::min(k, l - 1); ++x) {
          // a[i] <= x => a[j] >= l - x
          graph.add({i, x, 1}, {j, std::min(l - x - 1, k), 0});
        }
      }
    }
    Tarjan tarjan(graph);
    bool valid = true;
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j <= k; ++j) {
        valid &= tarjan.scc_id[graph.get_id(i, j, 0)] !=
                 tarjan.scc_id[graph.get_id(i, j, 1)];
      }
    }
    if (valid) {
      std::vector<std::vector<int>> assignemnt(n, std::vector<int>(k + 1));
      for (int i = 0; i < n; ++i) {
        for (int j = 0; j <= k; ++j) {
          assignemnt[i][j] = tarjan.scc_id[graph.get_id(i, j, 0)] >
                             tarjan.scc_id[graph.get_id(i, j, 1)];
        }
      }
      for (int i = 0; i < n; ++i) {
        int x = 1;
        while (!assignemnt[i][x]) {
          x++;
        }
        std::cout << x << " \n"[i + 1 == n];
      }
    } else {
      std::cout << -1 << "\n";
    }
  }
}