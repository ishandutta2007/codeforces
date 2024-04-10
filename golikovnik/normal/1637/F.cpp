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

  int n; cin >> n;
  vector<int> h(n);
  for (auto& x : h) cin >> x;
  vector<int> ord(n);
  iota(ord.begin(), ord.end(), 0);
  sort(ord.begin(), ord.end(), [&](int i, int j) {
    return h[i] > h[j];
  });
  vector<vector<int>> graph(n);
  for (int i = 1; i < n; ++i) {
    int u, v;
    cin >> u >> v;
    --u, --v;
    graph[u].push_back(v);
    graph[v].push_back(u);
  }
  int root = ord[0];
  vector<int> parent(n);
  auto dfs = [&](auto&& self, int v, int p = -1) -> void {
    parent[v] = p;
    for (int u : graph[v]) {
      if (u != p) {
        self(self, u, v);
      }
    }
  };
  dfs(dfs, root);
  ll ans = 2 * h[ord[0]];
  vector<bool> active(n);
  active[ord[0]] = true;
  vector<bool> isleaf(n);
  for (int i = 1; i < n; ++i) {
    int v = ord[i];
    if (active[v]) {
      continue;
    }
    int pv = v;
    while (!active[pv]) {
      active[pv] = true;
      pv = parent[pv];
    }
    if (!isleaf[pv]) {
      if (i > 1) {
        ans += h[v];
      }
    }
    isleaf[pv] = i == 1;
    isleaf[v] = true;
  }
  cout << ans << '\n';

#ifdef GOLIKOV
  cerr << "Executed in " << chrono::duration_cast<chrono::milliseconds>(
      chrono::high_resolution_clock::now()
          - _clock_start).count() << "ms." << endl;
#endif
  return 0;
}