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

struct DSU {
  int n;
  vector<int> dsu;

  DSU(int n_) : n(n_), dsu(n, -1) {}

  int find(int v) {
    return dsu[v] < 0 ? v : dsu[v] = find(dsu[v]);
  }

  bool unite(int u, int v) {
    u = find(u), v = find(v);
    if (u == v) return false;
    if (-dsu[u] > -dsu[v]) swap(u, v);
    dsu[v] += dsu[u];
    dsu[u] = v;
    return true;
  }

  bool same(int u, int v) {
    return find(u) == find(v);
  }

  int size(int v) {
    return -dsu[find(v)];
  }
};

void solve(int) {
  int n, m;
  cin >> n >> m;
  vector<pair<int, int>> edges;
  DSU dsu(n);
  for (int i = 0; i < m; ++i) {
    int u, v;
    string s;
    cin >> u >> v >> s;
    --u, --v;
    if (s[0] == 'c') {
      dsu.unite(u, v);
    } else {
      edges.emplace_back(u, v);
    }
  }

  vector<int> id(n, -1);
  vector<int> sz;
  int curc = 0;
  for (int i = 0; i < n; ++i) {
    if (dsu.dsu[i] < 0) {
      id[i] = curc++;
      sz.push_back(dsu.size(i));
    }
  }
  for (int i = 0; i < n; ++i) {
    id[i] = id[dsu.find(i)];
  }

  vector<vector<int>> graph(curc);
  
  for (auto[u, v] : edges) {
    u = id[u], v = id[v];
    graph[u].push_back(v);
    graph[v].push_back(u);
  }

  int cnt[2]{};
  bool fail = false;

  int ans = 0;
  vector<int> color(curc, -1);

  auto dfs = [&](auto&& self, int v, int c) -> void {
    color[v] = c;
    cnt[c] += sz[v];
    for (int u : graph[v]) {
      if (color[u] < 0) {
        self(self, u, c ^ 1);
      } else if (color[u] == color[v]) {
        fail = true;
      }
    }
  };  

  for (int i = 0; i < curc; ++i) {
    if (color[i] < 0) {
      cnt[0] = cnt[1] = 0;
      dfs(dfs, i, 0);
      if (fail) {
        cout << -1 << '\n';
        return;
      }
      ans += max(cnt[0], cnt[1]);
    }
  }

  cout << ans << '\n';
}

int main() {
#ifdef GOLIKOV
  assert(freopen("in", "rt", stdin));
  auto _clock_start = chrono::high_resolution_clock::now();
#endif
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int _tests;
  cin >> _tests;
  for (int _tt = 1; _tt <= _tests; ++_tt) {
    solve(_tt);
  }

#ifdef GOLIKOV
  cerr << "Executed in " << chrono::duration_cast<chrono::milliseconds>(
      chrono::high_resolution_clock::now()
          - _clock_start).count() << "ms." << endl;
#endif
  return 0;
}