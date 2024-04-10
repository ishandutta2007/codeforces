//  Copyright 2020 Nikita Golikov

#include <bits/stdc++.h>

using namespace std;

using i64 = int64_t;
using ui64 = uint64_t;

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

template <class T> auto constexpr type_max = numeric_limits<T>::max();

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
  static auto constexpr INF = type_max<cap_t>;
  int n;
  vector<edge> edges;
  vector<vector<int>> graph;
  vector<int> d;
  vector<int> q;

  explicit flow_graph(int n) : n(n), graph(n), q(n) {}

  void add_edge(int from, int to, cap_t cap) {
    auto i = (int) edges.size();
    graph[from].push_back(i);
    edges.push_back({from, to, cap});
    graph[to].push_back(i ^ 1);
    edges.push_back({to, from, 0});
  }

  bool bfs(cap_t push, int s, int t) {
    d.assign(n, -1);
    d[s] = 0;
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
    vector<vector<int>::iterator> ptr(n);
    for (int log = scale ? 30 : 0; log >= 0; --log) {
      while (bfs(1 << log, s, t)) {
        for (int i = 0; i != n; ++i) {
          ptr[i] = graph[i].begin();
        }
        auto dfs = [&](auto&& dfs, int v, cap_t cMin) -> cap_t {
          if (v == t) {
            return cMin;
          }
          for (; ptr[v] != graph[v].end(); ++ptr[v]) {
            auto ei = *ptr[v];
            auto& e = edges[ei];
            if (e.ok(1 << log) && d[e.to] == d[v] + 1) {
              auto pushed = dfs(dfs, e.to, min(cMin, e.cap - e.flow));
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
  vector<string> a(n);
  for (auto& x : a) cin >> x;
  auto ok = [&](int i, int j) {
    return 0 <= i && i < n && 0 <= j && j < m && a[i][j] == '#';
  };
  flow_graph<int, int> graph(n * m + 2);
  auto get_id = [&](int i, int j) {
    return m * i + j;
  };
  //  vertical - S, horizontal - T
  int const S = n * m;
  int const T = n * m + 1;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      if (!ok(i, j)) continue;
      if (!ok(i - 1, j)) {
        graph.add_edge(get_id(i, j), T, 1);
      } else {
        graph.add_edge(get_id(i, j), get_id(i - 1, j), 1);
      }
      if (!ok(i, j - 1)) {
        graph.add_edge(S, get_id(i, j), 1);
      } else {
        graph.add_edge(get_id(i, j - 1), get_id(i, j), 1);
      }
    }
  }
  cout << graph.max_flow(S, T, false) << '\n';

#ifdef GOLIKOV
  cerr << "Executed in " << chrono::duration_cast<chrono::milliseconds>(
      chrono::high_resolution_clock::now()
          - _clock_start).count() << "ms." << endl;
#endif
  return 0;
}