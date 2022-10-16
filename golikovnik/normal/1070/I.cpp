//  Copyright 2021 Nikita Golikov

#include <bits/stdc++.h>

using namespace std;

using uint = unsigned int;
using ll = long long;
using ull = unsigned long long;

#ifdef GOLIKOV
    #define debug(x) cerr << (#x) << ":\t" << (x) << endl
#else
    #define debug(x) 238;
#endif

template <class A, class B>
bool smin(A &x, B &&y) {
  if (y < x) {
    x = y;
    return true;
  }
  return false;
}

template <class A, class B>
bool smax(A &x, B &&y) {
  if (x < y) {
    x = y;
    return true;
  }
  return false;
}

template <typename cap_t, typename flow_t>
struct flow_graph {
  struct edge {
    int from;
    int to;
    cap_t cap;
    cap_t flow{};

    bool ok(cap_t push) const {
      if constexpr (is_integral_v<cap_t>) {
        return flow + push <= cap;
      }
      return flow < cap;
    }
  };
  static auto constexpr INF = numeric_limits<cap_t>::max();
  int n;
  vector<edge> edges;
  vector<vector<int>> graph;
  vector<int> d;

  explicit flow_graph(int n) : n(n), graph(n) {}

  int add_edge(int from, int to, cap_t cap) {
    auto i = (int) edges.size();
    graph[from].push_back(i);
    edges.push_back({from, to, cap});
    graph[to].push_back(i ^ 1);
    edges.push_back({to, from, 0});
    return i;
  }

  bool bfs(cap_t push, int s, int t) {
    d.assign(n, -1);
    d[s] = 0;
    vector<int> q(n);
    q[0] = s;
    int qh = 0;
    int qt = 1;
    while (qh != qt) {
      auto v = q[qh++];
      for (auto ei : graph[v]) {
        auto& e = edges[ei];
        if (e.ok(push) && d[e.to] < 0) {
          d[e.to] = d[v] + 1;
          q[qt++] = e.to;
        }
      }
    }
    return d[t] >= 0;
  }

  flow_t max_flow(int s, int t, bool scale) {
    flow_t result = 0;
    for (int log = scale ? 30 : 0; log >= 0; --log) {
      while (bfs(1 << log, s, t)) {
        vector<vector<int>::iterator> ptr(n);
        for (int i = 0; i != n; ++i) {
          ptr[i] = graph[i].begin();
        }
        auto dfs = [&](auto&& self, int v, cap_t cMin) -> cap_t {
          if (v == t) {
            return cMin;
          }
          for (; ptr[v] != graph[v].end(); ++ptr[v]) {
            auto ei = *ptr[v];
            auto& e = edges[ei];
            if (e.ok(1 << log) && d[e.to] == d[v] + 1) {
              auto pushed = self(self, e.to, min(cMin, e.cap - e.flow));
              if (pushed) {
                e.flow += pushed;
                edges[ei ^ 1u].flow -= pushed;
                return pushed;
              }
            }
          }
          return 0;
        };
        while (auto pushed = dfs(dfs, s, INF)) {
          result += pushed;
        }
      }
    }
    return result;
  }
};

void solve() {
  int n, m, k;
  cin >> n >> m >> k;
  vector<pair<int, int>> edges(m);
  vector<int> deg(n);
  for (auto& [u, v] : edges) {
    cin >> u >> v;
    --u, --v;
    deg[u]++;
    deg[v]++;
  }
  int suma = 0;
  vector<int> a(n);
  for (int v = 0; v < n; ++v) {
    a[v] = 2 * max(0, deg[v] - k);
    suma += a[v];
  }
  flow_graph<int, int> graph(2 + n + m);
  int const S = n + m;
  int const T = S + 1;

  vector<vector<pair<int, int>>> idsForV(n);

  for (int v = 0; v < n; ++v) {
    graph.add_edge(S, v, a[v]);
    for (int i = 0; i < m; ++i) {
      if (edges[i].first == v || edges[i].second == v) {
        idsForV[v].emplace_back(graph.add_edge(v, n + i, 1), i);
      }
    }
  }
  for (int i = 0; i < m; ++i) {
    graph.add_edge(n + i, T, 1);
  }
  vector<int> ans(m);
  auto fl = graph.max_flow(S, T, false);
  if (fl == suma) {
    iota(ans.begin(), ans.end(), 1);
    int nxtid = m + 1;
    for (int v = 0; v < n; ++v) {
      int cnt = 0;
      for (auto[id, i] : idsForV[v]) {
        auto& e = graph.edges[id];
        if (e.flow > 0) {
          ans[i] = nxtid;
          if (++cnt == 2) {
            ++nxtid;
            cnt = 0;
          }
        }
      }
    }
  }
  for (auto x : ans) cout << x << ' ';
  cout << '\n';
}

int main() {
#ifdef GOLIKOV
  assert(freopen("in", "rt", stdin));
  auto _clock_start = chrono::high_resolution_clock::now();
#endif
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int t; cin >> t; while (t--) solve();

#ifdef GOLIKOV
  cerr << "Executed in " << chrono::duration_cast<chrono::milliseconds>(
      chrono::high_resolution_clock::now()
          - _clock_start).count() << "ms." << endl;
#endif
  return 0;
}