// author: erray
#include <bits/stdc++.h>
#ifdef DEBUG
  #include "debug.h"
#else
  #define debug(...) void(37)
  #define here void(37)
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
    DSU d(N * 2);
    auto Add_edge = [&](int x, int y, int l) {
      if (l % 2 == 0) {
        d.unite(x, y);
        d.unite(x + N, y + N);
      } else {
        d.unite(x, y + N);
        d.unite(x + N, y);
      }
    };

    vector<array<int, 3>> E(N - 1);
    for (int i = 0; i < N - 1; ++i) {
      cin >> E[i][0] >> E[i][1] >> E[i][2];
      --E[i][0], --E[i][1];
      if (E[i][2] != -1) {
        Add_edge(E[i][0], E[i][1], __builtin_popcount(E[i][2]));
      }
    }

    for (int i = 0; i < M; ++i) {
      int X, Y, P;
      cin >> X >> Y >> P;
      --X, --Y;
      Add_edge(X, Y, P);
    }

    bool ok = true;
    for (int i = 0; i < N; ++i) {
      ok &= !d.same(i, i + N);
    }

    if (!ok) {
      cout << "NO\n";
    } else {
      cout << "YES\n";
      for (int i = 0; i < N - 1; ++i) {
        if (E[i][2] == -1) {
          int add = d.same(E[i][0], E[i][1] + N);
          E[i][2] = add;
          Add_edge(E[i][0], E[i][1], E[i][2]);
        }
        cout << E[i][0] + 1 << ' ' << E[i][1] + 1 << ' ' << E[i][2] << '\n';
      }
    }
  }
}