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

void solve(int) {
  int n, m;
  cin >> n >> m;
  vector<i64> a(n);
  for (int i = 0; i < n; ++i) {
    i64 x; cin >> x; a[i] += x;
  }
  for (int i = 0; i < n; ++i) {
    i64 x; cin >> x; a[i] -= x;
  }
  vector<vector<int>> graph(n);
  for (int i = 0; i < m; ++i) {
    int u, v;
    cin >> u >> v;
    --u, --v;
    graph[u].push_back(v);
    graph[v].push_back(u);
  }
  vector<int> d(n, -1);
  d[0] = 0;
  bool bipartite = true;
  auto dfs = [&](auto&& dfs, int v) -> void {
    for (int u : graph[v]) {
      if (d[u] < 0) {
        d[u] = d[v] ^ 1;
        dfs(dfs, u);
      } else if (d[u] != (d[v] ^ 1)) {
        bipartite = false;
      }
    }
  };
  dfs(dfs, 0);
  if (bipartite) {
    i64 s = 0;
    for (int i = 0; i < n; ++i) {
      if (d[i]) {
        s += a[i];
      } else {
        s -= a[i];
      }
    }
    cout << (s == 0 ? "YES" : "NO") << '\n';
  } else {
    int cntOdd = 0;
    for (auto x : a) cntOdd += !!(x % 2);
    cout << (cntOdd % 2 == 0 ? "YES" : "NO") << '\n';
  }
}

int main() {
#ifdef GOLIKOV
  assert(freopen("in", "rt", stdin));
  auto _clock_start = chrono::high_resolution_clock::now();
#endif
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int tests;
  cin >> tests;
  for (int _tt = 1; _tt <= tests; ++_tt) {
    solve(_tt);
  }

#ifdef GOLIKOV
  cerr << "Executed in " << chrono::duration_cast<chrono::milliseconds>(
      chrono::high_resolution_clock::now()
          - _clock_start).count() << "ms." << endl;
#endif
  return 0;
}