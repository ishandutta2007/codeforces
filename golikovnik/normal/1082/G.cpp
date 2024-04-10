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

  explicit flow_graph(int n_) : n(n_), graph(n_) {}

  int add_edge(int from, int to, cap_t cap) {
    int i = int(edges.size());
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

int main() {
#ifdef GOLIKOV
  assert(freopen("in", "rt", stdin));
  auto _clock_start = chrono::high_resolution_clock::now();
#endif
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, m;
  cin >> n >> m;
  flow_graph<ll, ll> graph(n + 2);
  int const S = n;
  int const T = S + 1;
  for (int i = 0; i < n; ++i) {
    int x; cin >> x; graph.add_edge(i, T, 2 * x);
  }  
  vector<ll> d(n);
  for (int i = 0; i < m; ++i) {
    int u, v, w;
    cin >> u >> v >> w;
    --u, --v;
    graph.add_edge(u, v, w);
    graph.add_edge(v, u, w);
    d[u] += w;
    d[v] += w;
  }
  ll sd = 0;
  for (int v = 0; v < n; ++v) {
    sd += d[v];
    graph.add_edge(S, v, d[v]);
  }
  sd -= graph.max_flow(S, T, true);
  assert(sd % 2 == 0);
  cout << sd / 2 << '\n';

#ifdef GOLIKOV
  cerr << "Executed in " << chrono::duration_cast<chrono::milliseconds>(
      chrono::high_resolution_clock::now()
          - _clock_start).count() << "ms." << endl;
#endif
  return 0;
}