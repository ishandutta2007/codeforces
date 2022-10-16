//  Copyright 2021 Nikita Golikov

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

  int n, m, males, females;
  cin >> n >> m >> males >> females;
  if (abs(males - females) != 1) {
    cout << -1 << '\n';
    return 0;
  }
  vector<string> field(n);
  for (auto& r : field) cin >> r;
  vector<tuple<int, int, int>> t1, t2;
  {
    int r, c, t;
    cin >> r >> c >> t;
    --r, --c;
    if (males < females) {
      t1.emplace_back(r, c, t);
    } else {
      t2.emplace_back(r, c, t);
    }
  }
  for (int i = 0; i < males; ++i) {
    int r, c, t;
    cin >> r >> c >> t;
    --r, --c;
    t1.emplace_back(r, c, t);
  }
  for (int i = 0; i < females; ++i) {
    int r, c, t;
    cin >> r >> c >> t;
    --r, --c;
    t2.emplace_back(r, c, t);
  }
  auto good = [&](int r, int c) {
    return 0 <= r && r < n && 0 <= c && c < m && field[r][c] == '.';
  };
  vector dist(n, vector<vector<vector<int>>>(m));
  vector DX{1, 0, -1, 0};
  vector DY{0, 1, 0, -1};
  for (int r = 0; r < n; ++r) {
    for (int c = 0; c < m; ++c) {
      if (!good(r, c)) continue;
      vector cur(n, vector<int>(m, -1));
      cur[r][c] = 0;
      queue<pair<int, int>> q;
      q.emplace(r, c);
      while (!q.empty()) {
        auto[x, y] = q.front();
        q.pop();
        for (int i = 0; i < 4; ++i) {
          int nx = x + DX[i];
          int ny = y + DY[i];
          if (good(nx, ny) && cur[nx][ny] < 0) {
            cur[nx][ny] = cur[x][y] + 1;
            q.emplace(nx, ny);
          }
        }
      }
      dist[r][c] = cur;
    }
  }

  i64 const INF = i64(1e12);

  auto findDist = [&](tuple<int, int, int> who, int r, int c) {
    auto[hr, hc, hs] = who;
    auto d = dist[hr][hc][r][c];
    if (d < 0) {
      return 3 * INF;
    }
    return i64(d) * hs;
  };

  i64 left = -1;
  i64 right = INF;
  int side = t1.size();
  while (left + 1 != right) {
    auto mid = (left + right) / 2;
    flow_graph<int, int> graph(2 + side + 2 * n * m + side);
    for (int i = 0; i < side; ++i) {
      graph.add_edge(0, 2 + i, 1);
      graph.add_edge(2 + side + 2 * n * m + i, 1, 1);
    }
    for (int r = 0; r < n; ++r) {
      for (int c = 0; c < m; ++c) {
        if (!good(r, c)) continue;
        int id = r * m + c;
        graph.add_edge(2 + side + id, 2 + side + n * m + id, 1);
        for (int i = 0; i < side; ++i) {
          if (findDist(t1[i], r, c) <= mid) {
            graph.add_edge(2 + i, 2 + side + id, 1);
          }
          if (findDist(t2[i], r, c) <= mid) {
            graph.add_edge(2 + side + n * m + id, 2 + side + 2 * n * m + i, 1);
          }
        }
      }
    }
    (graph.max_flow(0, 1, false) == side ? right : left) = mid;
  }
  cout << (right == INF ? -1 : right) << '\n';

#ifdef GOLIKOV
  cerr << "Executed in " << chrono::duration_cast<chrono::milliseconds>(
      chrono::high_resolution_clock::now()
          - _clock_start).count() << "ms." << endl;
#endif
  return 0;
}