// author: erray
#include <bits/stdc++.h>

#ifdef DEBUG
  #include "debug.h"
#else
  #define debug(...) void(37)
#endif

using namespace std;

struct DSU {
  vector<int> par, sz;
  DSU(int n) {
    par.resize(n);
    sz.resize(n, 1);
    iota(par.begin(), par.end(), 0);
  }
  inline int get(int v) {
    return par[v] = (v == par[v] ? v : get(par[v]));
  }
  inline bool unite(int x, int y) {
    x = get(x);
    y = get(y);
    if (x == y) return false;
    sz[x] += sz[y];
    par[y] = x;
    return true;
  }
  int size(int v) {
    return sz[get(v)];
  }
  bool same(int x, int y) {
    return get(x) == get(y);
  }
};

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int TT;
  cin >> TT;
  while (TT--) {
    int N, M;
    cin >> N >> M;
    vector<array<int, 3>> E(M);
    for (int i = 0; i < M; ++i) {
      cin >> E[i][0] >> E[i][1] >> E[i][2];
      --E[i][0], --E[i][1];
    }
    vector<bool> can(M, true);
    int ans = 0;
    for (int j = 30; j >= 0; --j) {
      DSU d(N);
      for (int i = 0; i < M; ++i) {
        if (can[i] && (~(E[i][2] >> j) & 1)) {
          d.unite(E[i][0], E[i][1]);  
        }
      }
      if (d.size(0) == N) {
        for (int i = 0; i < M; ++i) {
          if ((E[i][2] >> j) & 1) {
            can[i] = false;  
          }
        }
      } else {
        ans |= (1 << j);
      }
    }
    cout << ans << '\n';
  }
}