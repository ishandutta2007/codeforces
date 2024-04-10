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
  DSU() { } 
  int get(int v) {
    return par[v] = (v == par[v] ? v : get(par[v]));
  }

  bool unite(int x, int y) {
    x = get(x);
    y = get(y);
    if (x == y) {
      return false;
    }
    par[x] = y;
    return true;
  }
};

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int N, M;
  cin >> N >> M;
  vector<array<int, 3>> E(M);
  for (int i = 0; i < M; ++i) {
    cin >> E[i][0] >> E[i][1] >> E[i][2];
    --E[i][0], --E[i][1];  
  }

  array<DSU, 30> d;
  fill(d.begin(), d.end(), DSU(N));
  for (int b = 0; b < 30; ++b) {
    vector<bool> bad(N);
    for (auto[v, u, w] : E) {
      if ((w >> b) & 1) {
        d[b].unite(v, u);
      }
    }
  }


  vector<bool> one(N, false);
  for (int b = 1; b < 30; ++b) {
    vector<vector<int>> g(N);
    vector<bool> bad(N, false);
    for (auto[v, u, w] : E) {
      if (w % 2 == 0) {
        bad[v] = bad[u] = true;
      }
    }
    
    for (int i = 0; i < N; ++i) {
      g[d[b].get(i)].push_back(i); 
      if (bad[i]) {
        bad[d[b].get(i)] = true;
      }
    }

    for (int i = 0; i < N; ++i) {
      if (bad[i]) {
        for (auto e : g[i]) {
          one[e] = true;
          bad[e] = true;
        }
      }
    }
    debug(b, bad);
  }

  int Q;
  cin >> Q;
  while (Q--) {
    int V, U;
    cin >> V >> U;
    --V, --U;
    bool zero = false;
    for (int i = 0; i < 30; ++i) {
      if (d[i].get(V) == d[i].get(U)) {
        zero = true;
      }
    }
    cout << (!zero + (!one[V] && !zero)) << '\n'; 
  }
}