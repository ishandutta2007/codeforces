#include <bits/stdc++.h>

using namespace std;

using i64 = int64_t;

template <typename T>
struct dinic {
  struct edge {
    int from;
    int to;
    T cap;
    T flow{};

    bool ok() const {
      return flow < cap;
    }
  };
  int n;
  vector<edge> edges;
  vector<int> d;
  vector<int> q;
  vector<vector<int>> graph;

  dinic(int n_) : n(n_), graph(n) {}

  void add_edge(int from, int to, int cap) {
    int i = (int) edges.size();
    edges.push_back({from, to, cap});
    graph[from].push_back(i);
    edges.push_back({to, from, 0});
    graph[to].push_back(i ^ 1);
  }

  bool bfs() {
    d.assign(n, -1);
    q.assign(n, 0);
    d[0] = 0;
    int qt = 1;
    for (int qh = 0; qh < qt; ++qh) {
      auto v = q[qh];
      for (auto ei : graph[v]) {
        auto& e = edges[ei];
        if (e.ok() && d[e.to] < 0) {
          d[e.to] = d[v] + 1;
          q[qt++] = e.to;
        }
      }
    }
    return d.back() >= 0;
  }

  T max_flow() {
    T result = 0;
    while (bfs()) {
      vector<vector<int>::iterator> ptr(n);
      for (int i = 0; i < n; ++i) {
        ptr[i] = graph[i].begin();
      }
      function<T(int, T)> dfs = [&](int v, T cur_cap) {
        if (v == n - 1) {
          return cur_cap;
        }
        for (; ptr[v] != graph[v].end(); ++ptr[v]) {
          auto ei = *ptr[v];
          auto& e = edges[ei];
          if (e.ok() && d[e.to] == d[v] + 1) {
            auto push = dfs(e.to, min(cur_cap, e.cap - e.flow));
            if (push) {
              e.flow += push;
              edges[ei ^ 1].flow -= push;
              return push;
            }
          }
        }
        return 0;
      };
      while (auto push = dfs(0, numeric_limits<T>::max())) {
        result += push;
      }
    }
    return result;
  }
};

int main() {
#ifdef GOLIKOV
  freopen("in", "rt", stdin);
#endif
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, m;
  cin >> n >> m;
  vector<int> a(n), b(n);
  int sa = 0, sb = 0;
  for (int& x : a) {
    cin >> x;
    sa += x;
  }
  for (int& x : b) {
    cin >> x;
    sb += x;
  }
  if (sa != sb) {
    cout << "NO\n";
    return 0;
  }
  dinic<int> flow_graph(n + n + 2);
  auto const inf = numeric_limits<int>::max();
  for (int i = 0; i < n; ++i) {
    flow_graph.add_edge(0, i + 1, a[i]);
    flow_graph.add_edge(n + i + 1, n + n + 1, b[i]);
    flow_graph.add_edge(i + 1, n + i + 1, inf);
  }
  for (int i = 0; i < m; ++i) {
    int u, v;
    cin >> u >> v;
    --u, --v;
    flow_graph.add_edge(u + 1, n + v + 1, inf);
    flow_graph.add_edge(v + 1, n + u + 1, inf);
  }
  auto flw = flow_graph.max_flow();
  if (flw != sb) {
    cout << "NO\n";
    return 0;
  }
  cout << "YES\n";
  vector<vector<int>> res(n, vector<int>(n));
  for (auto& e : flow_graph.edges) {
    if (e.flow && e.cap && e.from && e.to != n + n + 1) {
      res[e.from - 1][e.to - n - 1] += e.flow;
    }
  }
  for (auto& r : res) {
    for (auto x : r) {
      cout << x << ' ';
    }
    cout << '\n';
  }
  return 0;
}