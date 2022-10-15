// author: erray
#include <bits/stdc++.h>

#ifdef DEBUG
  #include "debug.h"
#else
  #define debug(...) void(37)
#endif

using namespace std;

struct DSU {
  vector<int> par;
  DSU(int n) {
    par.resize(n);
    iota(par.begin(), par.end(), 0);
  }

  int get(int v) {
    return par[v] = (v == par[v] ? v : get(par[v]));
  }

  int operator[](int v) {
    return get(v);
  }

  bool unite(int x, int y) {
    x = get(x);
    y = get(y);
    if (x == y) {
      return false;
    }
    par[y] = x;
    return true;
  }

  bool same(int x, int y) {
    return get(x) == get(y);
  }
};

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int N, M;
  cin >> N >> M;
  vector<array<int, 3>> E(M);
  for (int i = 0; i < M; ++i) {
    for (int j : {0, 1, 2}) {
      cin >> E[i][j];
      --E[i][j];
    }
  }
  debug(E);
  
  DSU d(N * 2);
  for (auto[foo, x, y] : E) {
    d.unite(x, y + N);
    d.unite(x + N, y);
  }

  bool ok = true;
  for (int i = 0; i < N; ++i) {
    ok &= !d.same(i, i + N);
  }
  if (!ok) {
    cout << "NO\n";
    return 0;
  }
  vector<int> o(N);
  for (int i = 0; i < N; ++i) {
    if (d.same(0, i)) {
      o[i] = 0;
    } else {
      o[i] = 1;
      d.unite(0, i + N);
      d.unite(N, i);
    }
  }
  debug(o);
  vector<vector<int>> g(N);
  vector<int> indeg(N);
  for (auto[t, v, u] : E) {
    if ((o[v] < o[u]) != t) {
      swap(v, u);
    }
    g[v].push_back(u);
    indeg[u]++;
  }


  vector<int> que;
  vector<int> pos(N);
  for (int i = 0; i < N; ++i) {
    if (indeg[i] == 0) {
      que.push_back(i);
    }
  }
  for (int i = 0; i < int(que.size()); ++i) {
    int v = que[i];
    pos[v] = i;
    for (auto u : g[v]) {
      if (--indeg[u] == 0) {
        que.push_back(u);
      }
    }
  }

  if (int(que.size()) < N) {
    cout << "NO\n";
    return 0;
  }
  cout << "YES\n";
  for (int i = 0; i < N; ++i) {
    cout << (o[i] ? 'L' : 'R') << ' ' << pos[i] << '\n';
  }
}