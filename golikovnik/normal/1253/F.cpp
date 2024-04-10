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

int main() {
#ifdef GOLIKOV
  assert(freopen("in", "rt", stdin));
  auto _clock_start = chrono::high_resolution_clock::now();
#endif
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, m, k, q;
  cin >> n >> m >> k >> q;
  vector<vector<pair<int, int>>> graph(n);
  for (int i = 0; i < m; ++i) {
    int u, v, w;
    cin >> u >> v >> w;
    --u, --v;
    graph[u].emplace_back(v, w);
    graph[v].emplace_back(u, w);
  }
  ll const INF = ll(1e16);
  vector<pair<ll, int>> dist(n, make_pair(INF, -1));
  set<pair<ll, int>> st;
  for (int v = 0; v < k; ++v) {
    dist[v] = make_pair(0ll, v);
    st.emplace(0, v);
  }
  vector<tuple<ll, int, int>> edges;
  while (!st.empty()) {
    int v = st.begin()->second;
    st.erase(st.begin());
    for (auto[u, w] : graph[v]) {
      if (dist[u].second >= 0) {
        edges.emplace_back(dist[v].first + w + dist[u].first, dist[v].second, dist[u].second);
      }
      if (dist[v].first + w < dist[u].first) {
        st.erase(make_pair(dist[u].first, u));
        dist[u] = dist[v];
        dist[u].first += w;
        st.emplace(dist[u].first, u);
      }
    }
  }
  sort(edges.begin(), edges.end());
  vector<vector<int>> qsFor(n);
  vector<pair<int, int>> qs(q);
  for (int it = 0; it < q; ++it) {
    int u, v;
    cin >> u >> v;
    --u, --v;
    qsFor[u].push_back(it);
    qsFor[v].push_back(it);
    qs[it] = make_pair(u, v);
  }
  vector<int> dsu(k, -1);

  vector<ll> ans(q, -1);
  auto find = [&](auto&& self, int v) -> int {
    return dsu[v] < 0 ? v : dsu[v] = self(self, dsu[v]);
  };

  for (auto[w, u, v] : edges) {
    // cerr << w << ' ' << u << ' ' << v << '\n';
    u = find(find, u);
    v = find(find, v);
    if (u == v) {
      continue;
    }
    if (qsFor[u].size() > qsFor[v].size()) {
      swap(u, v);
    }
    for (int i : qsFor[u]) {
      auto[x, y] = qs[i];
      x = find(find, x);
      y = find(find, y);
      if (ans[i] < 0 && minmax(x, y) == minmax(u, v)) {
        ans[i] = w;
      }
    }
    dsu[u] = v;
    qsFor[v].insert(qsFor[v].end(), qsFor[u].begin(), qsFor[u].end());
  }

  for (auto x : ans) {
    assert(x >= 0);
    cout << x << '\n';
  }

#ifdef GOLIKOV
  cerr << "Executed in " << chrono::duration_cast<chrono::milliseconds>(
      chrono::high_resolution_clock::now()
          - _clock_start).count() << "ms." << endl;
#endif
  return 0;
}