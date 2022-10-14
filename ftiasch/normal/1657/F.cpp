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
#line 2 "sol.cpp"

#include <bits/stdc++.h>

const int N = 400'000;

int n, m, parent[N], depth[N];
char buffer[N + 1];
std::vector<int> tree[N];
std::vector<char> candidates[N];

void prepare(int u) {
  for (int v : tree[u]) {
    if (v != parent[u]) {
      parent[v] = u;
      depth[v] = depth[u] + 1;
      prepare(v);
    }
  }
}

void add_candidate(int u, char c) {
  if (candidates[u].size() < 2 &&
      std::find(candidates[u].begin(), candidates[u].end(), c) ==
          candidates[u].end()) {
    candidates[u].push_back(c);
  }
}

void add_path_candidate(int x, int y, const std::string &s) {
  int i = 0, j = s.size();
  while (x != y) {
    if (depth[x] > depth[y]) {
      add_candidate(x, s[i++]);
      x = parent[x];
    } else {
      add_candidate(y, s[--j]);
      y = parent[y];
    }
  }
  add_candidate(x, s[i]);
}

Tarjan::Graph graph;

void add(int u, int v, char c) {
  int i = std::find(candidates[v].begin(), candidates[v].end(), c) -
          candidates[v].begin();
  if (i == 2) {
    graph[u].push_back(u ^ 1);
  } else {
    int vv = v << 1 | i;
    graph[u].push_back(vv);
    graph[vv ^ 1].push_back(u ^ 1);
  }
}

void add_path(int u, int x, int y, const std::string &s) {
  int i = 0, j = s.size();
  while (x != y) {
    if (depth[x] > depth[y]) {
      add(u, x, s[i++]);
      x = parent[x];
    } else {
      add(u, y, s[--j]);
      y = parent[y];
    }
  }
  add(u, x, s[i]);
}

int main() {
  scanf("%d%d", &n, &m);
  for (int i = 0, a, b; i < n - 1; ++i) {
    scanf("%d%d", &a, &b);
    a--;
    b--;
    tree[a].push_back(b);
    tree[b].push_back(a);
  }
  std::vector<std::tuple<int, int, std::string>> cons(m);
  for (int i = 0, x, y; i < m; ++i) {
    scanf("%d%d%s", &x, &y, buffer);
    cons[i] = {x - 1, y - 1, buffer};
  }
  parent[0] = -1;
  depth[0] = 0;
  prepare(0);
  for (const auto &[x, y, s] : cons) {
    add_path_candidate(x, y, s);
    add_path_candidate(y, x, s);
  }
  for (int i = 0; i < n; ++i) {
    for (char c = 'a'; c <= 'z'; ++c) {
      add_candidate(i, c);
    }
  }
  graph.resize((n + m) << 1);
  auto solve = [&] -> bool {
    for (int i = 0; i < m; ++i) {
      const auto &[x, y, s] = cons[i];
      int u = (n + i) << 1;
      add_path(u, x, y, s);
      add_path(u ^ 1, y, x, s);
    }
    Tarjan tarjan(graph);
    for (int i = 0; i < (n + m) << 1; ++i) {
      if (tarjan.scc_id[i] == tarjan.scc_id[i ^ 1]) {
        return false;
      }
    }
    puts("YES");
    for (int i = 0; i < n; ++i) {
      putchar(candidates[i][tarjan.scc_id[i << 1] > tarjan.scc_id[i << 1 | 1]]);
    }
    return true;
  };
  if (!solve()) {
    puts("NO");
  }
}