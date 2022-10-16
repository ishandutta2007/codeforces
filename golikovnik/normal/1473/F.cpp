#include <bits/stdc++.h>
 
using namespace std;
using i64 = int64_t;
 
template <class T>
bool smin(T& x, T y) {
  if (y < x) {
    x = y;
    return true;
  }
  return false;
}

template <class cap_t>
struct dinic {
  struct edge {
    int from;
    int to;
    cap_t cap;
    cap_t flow{};

    bool ok() const {
      return flow < cap;
    }
  };

  int n;
  vector<vector<int>> graph;
  vector<edge> edges;
  vector<int> d;

  dinic(int n_) : n(n_), graph(n) {}

  void add_edge(int from, int to, cap_t cap) {
    int sz = int(edges.size());
    edges.push_back({from, to, cap});
    graph[from].push_back(sz);
    graph[to].push_back(sz ^ 1);
    edges.push_back({to, from, 0});
  }

  bool bfs() {
    d.assign(n, -1);
    d[0] = 0;
    queue<int> q;
    q.push(0);
    while (!q.empty()) {
      auto v = q.front();
      q.pop();
      for (auto ei : graph[v]) {
        auto& e = edges[ei];
        if (e.ok() && d[e.to] < 0) {
          d[e.to] = d[v] + 1;
          q.push(e.to);
        }
      }
    }
    return d[n - 1] >= 0;
  }

  cap_t solve() {
    cap_t ans = 0;
    while (bfs()) {
      vector<vector<int>::iterator> ptr(n);
      for (int i = 0; i < n; ++i) ptr[i] = graph[i].begin();
      auto dfs = [&](auto&& dfs, int v, cap_t cMin) -> cap_t {
        if (v == n - 1) return cMin;
        for (; ptr[v] != graph[v].end(); ++ptr[v]) {
          auto ei = *ptr[v];
          auto& e = edges[ei];
          if (e.ok() && d[e.to] == d[v] + 1) {
            auto push = dfs(dfs, e.to, min(cMin, e.cap - e.flow));
            if (push) {
              e.flow += push;
              edges[ei ^ 1].flow -= push;
              return push;
            }
          }
        }
        return 0;
      };
      while (auto r = dfs(dfs, 0, numeric_limits<cap_t>::max())) {
        ans += r;
      }
    }
    return ans;
  }
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  
  int n;
  cin >> n;
  vector<int> a(n), b(n);
  for (auto& x : a) cin >> x;
  for (auto& x : b) cin >> x;

  i64 const INF = i64(1e18);
  dinic<i64> graph(n + 2);
  int const max = 100;
  vector<bool> used(max + 1);
  for (int i = 0; i < n; ++i) {
    fill(used.begin(), used.end(), false);
    for (int j = i - 1; j >= 0; --j) {
      if (a[i] % a[j] == 0) {
        bool need = true;
        for (int x = a[j]; x <= max; x += a[j]) {
          if (used[x]) need = false;
        }
        if (need) {
          graph.add_edge(i + 1, j + 1, INF);
          used[a[j]] = true;
        }
      }
    }
  }
  i64 ans = 0;
  for (int i = 0; i < n; ++i) {
    if (b[i] > 0) {
      ans += b[i];
      graph.add_edge(0, i + 1, b[i]);
    } else {
      graph.add_edge(i + 1, n + 1, -b[i]);
    }
  }
  cout << ans - graph.solve() << '\n';
}