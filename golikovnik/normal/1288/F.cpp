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

#include <ext/pb_ds/priority_queue.hpp>

template <typename cap_t, typename flow_t,
    typename cost_t, typename dist_t>
struct mcmf {
  struct edge {
    int from;
    int to;
    cap_t cap;
    cost_t cost;
    cap_t flow{};

    edge(int from_, int to_, cap_t cap_, cost_t cost_) :
        from(from_), to(to_), cap(cap_), cost(cost_) {}

    bool ok() const {
      return flow < cap;
    }
  };
  struct ans_t {
    flow_t flow;
    dist_t cost;
  };

  dist_t const INF = numeric_limits<dist_t>::max() / 3;

  int n;
  vector<edge> edges;
  vector<vector<int>> graph;
  vector<dist_t> d;
  vector<int> par;
  vector<dist_t> pi;

  explicit mcmf(int n_) : n(n_), graph(n), d(n), par(n), pi(n) {}

  void add_edge(int from, int to, cap_t cap, cost_t cost) {
    graph[from].push_back((int) edges.size());
    edges.emplace_back(from, to, cap, cost);
    graph[to].push_back((int) edges.size());
    edges.emplace_back(to, from, 0, -cost);
  }

  bool setPiAcyclic(int s) {
    {
      fill(pi.begin(), pi.end(), 0);
      bool ok = true;
      for (auto e : edges) if (e.ok() && pi[e.to] > pi[e.from] + e.cost) ok = false;
      if (ok) return true;
    }
    
    fill(pi.begin(), pi.end(), INF);
    pi[s] = 0;
    vector<int> deg(n);
    for (auto e : edges) if (e.ok()) ++deg[e.to];
    queue<int> q;
    for (int i = 0; i < n; ++i) if (deg[i] == 0) q.push(i);
    while (!q.empty()) {
      auto v = q.front(); q.pop();
      for (auto ei : graph[v]) {
        auto e = edges[ei];
        if (!e.ok()) continue;
        smin(pi[e.to], pi[v] + e.cost);
        if (--deg[e.to] == 0) q.push(e.to);
      }
    }
    for (auto e : edges) if (e.ok() && pi[e.to] > pi[e.from] + e.cost) return false;
    return true;
  }

  void setPi(int s) {
    if (setPiAcyclic(s)) return;
    
    fill(pi.begin(), pi.end(), INF);
    pi[s] = 0;
    bool ch = true;
    while (ch) {
      ch = false;
      for (int v = 0; v < n; ++v) {
        for (int ei : graph[v]) {
          edge& e = edges[ei];
          if (e.ok() && smin(pi[e.to], pi[v] + e.cost)) {
            ch = true;
          }
        }
      }
    }
  }

  ans_t solve(int source, int sink, flow_t mflow = numeric_limits<flow_t>::max()) {
    setPi(source);

    ans_t ans{};

    auto expath = [&] {
      fill(d.begin(), d.end(), INF);
      __gnu_pbds::priority_queue<pair<dist_t, int>, greater<>> st;
      vector<typename decltype(st)::point_iterator> its(n);
      st.push({0, source});
      d[source] = 0;
      while (!st.empty()) {
        auto[dv, v] = st.top();
        st.pop();
        for (int ei : graph[v]) {
          edge& e = edges[ei];
          auto nd = dv + pi[v] - pi[e.to] + e.cost;
          if (e.ok() && smin(d[e.to], nd)) {
            if (its[e.to] == st.end()) {
              its[e.to] = st.push({nd, e.to});
            } else {
              st.modify(its[e.to], {nd, e.to});
            }
            par[e.to] = ei;
          }
        }
      }
      for (int i = 0; i < n; ++i) {
        pi[i] = min(pi[i] + d[i], INF);
      }
      return d[sink] != INF;
    };

    while (ans.flow < mflow && expath()) {
      flow_t push = mflow - ans.flow;
      dist_t cost = 0;
      for (int cur = sink; cur != source; ) {
        auto const& e = edges[par[cur]];
        smin(push, e.cap - e.flow);
        cost += e.cost;
        cur = e.from;
      }
      ans.flow += push;
      ans.cost += cost * push;
      for (int cur = sink; cur != source; ) {
        auto& e = edges[par[cur]];
        e.flow += push;
        edges[par[cur] ^ 1].flow -= push;
        cur = e.from;
      }
    }
    return ans;
  }
};

int main() {
#ifdef GOLIKOV
  assert(freopen("in", "rt", stdin));
  auto _clock_start = chrono::high_resolution_clock::now();
#endif
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int L, R, m, r, b;
  cin >> L >> R >> m >> r >> b;
  mcmf<int, int, int, int> graph(4 + L + R);
  string s, t;
  cin >> s >> t;

  int const S = L + R;
  int const T = S + 1;
  int const gS = T + 1;
  int const gT = T + 2;

  int sumd = 0;

  auto add_edge = [&](int u, int v, int lc, int rc, int cost) {
    int id = int(graph.edges.size());
    graph.add_edge(u, v, rc - lc, cost);
    graph.add_edge(gS, v, lc, cost);
    graph.add_edge(u, gT, lc, cost);
    sumd += lc;
    return id;
  };

  vector<int> idR(m), idB(m);

  for (int i = 0; i < m; ++i) {
    int u, v;
    cin >> u >> v;
    --u, --v;
    idR[i] = add_edge(u, L + v, 0, 1, r);
    idB[i] = add_edge(L + v, u, 0, 1, b);
  }

  int const INF = int(1e6);

  for (int v = 0; v < L; ++v) {
    if (s[v] == 'U') {
      add_edge(S, v, 0, INF, 0);
      add_edge(v, T, 0, INF, 0);
    } else if (s[v] == 'B') {
      add_edge(v, T, 1, INF, 0);
    } else {
      assert(s[v] == 'R');
      add_edge(S, v, 1, INF, 0);
    }
  }

  for (int v = 0; v < R; ++v) {
    if (t[v] == 'U') {
      add_edge(S, L + v, 0, INF, 0);
      add_edge(L + v, T, 0, INF, 0);
    } else if (t[v] == 'B') {
      add_edge(S, L + v, 1, INF, 0);
    } else {
      assert(t[v] == 'R');
      add_edge(L + v, T, 1, INF, 0);
    }
  }

  add_edge(T, S, 0, INF, 0);

  auto result = graph.solve(gS, gT);
  if (result.flow != sumd) {
    cout << -1 << '\n';
    return 0;
  }
  cout << result.cost << '\n';
  for (int i = 0; i < m; ++i) {
    auto& re = graph.edges[idR[i]];
    auto& be = graph.edges[idB[i]];
    if (re.flow > 0) {
      assert(be.flow <= 0);
      cout << 'R';
    } else if (be.flow > 0) {
      assert(re.flow <= 0);
      cout << 'B';
    } else {
      cout << 'U';
    }
  }
  cout << '\n';

#ifdef GOLIKOV
  cerr << "Executed in " << chrono::duration_cast<chrono::milliseconds>(
      chrono::high_resolution_clock::now()
          - _clock_start).count() << "ms." << endl;
#endif
  return 0;
}