// author: erray
#include <bits/stdc++.h>

#ifdef DEBUG
  #include "debug.h"
#else
  #define debug(...) void(37)
#endif

using namespace std;

struct BinaryLift {
  vector<vector<int>> g;
  vector<vector<int>> lift;
  vector<int> d;
  int n, lg;
  BinaryLift(int _n) : n(_n), lg(__lg(n) + 1) {
    g.resize(n);
    lift.resize(lg, vector<int>(n));
    d.resize(n);
  }
  void add_edge(int v, int u) {
    g[v].push_back(u);
    g[u].push_back(v);
  }
  void build() {
    function<void(int)> Dfs = [&](int v) {
      for (auto u : g[v]) {
        if (lift[0][v] != u) {
          lift[0][u] = v;
          d[u] = d[v] + 1; 
          Dfs(u);
        }
      }
    };
    Dfs(0);
    for (int j = 1; j < int(lift.size()); ++j) {
      for (int i = 0; i < n; ++i) {
        lift[j][i] = lift[j - 1][lift[j - 1][i]];
      }
    }
    debug(lift, d);
  }
  int depth(int v) {
    return d[v];
  }
  int up(int v, int k) {
    assert(d[v] >= k);
    for (int j = lg - 1; j >= 0; --j) {
      if (k & (1 << j)) {
        v = lift[j][v];
      }
    }
    return v;
  }
  int lca(int v, int u) {
    if (d[v] > d[u]) {
      swap(v, u);
    }
    u = up(u, d[u] - d[v]);
    if (v == u) {
      return v;
    }
    for (int j = lg - 1; j >= 0; --j) {
      if (lift[j][v] != lift[j][u]) {
        v = lift[j][v];
        u = lift[j][u];
      }
    }
    return lift[0][v];
  }
  bool onPath(int v, int u) {
    return up(v, d[v] - d[u]) == u;
  }
};

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int N;
  cin >> N;
  BinaryLift bl(N);
  for (int i = 0; i < N - 1; ++i) {
    int X, Y;
    cin >> X >> Y;
    --X, --Y;
    bl.add_edge(X, Y);
  }
  bl.build();
  int Q;
  cin >> Q;
  while (Q--) {
    int K;
    cin >> K;
    vector<int> A(K);
    for (int i = 0; i < K; ++i) {
      cin >> A[i];
      --A[i];
    }
    if (K <= 2) {
      cout << "YES\n";
      continue;
    }

    sort(A.begin(), A.end(), [&](int x, int y) {
      return bl.depth(x) > bl.depth(y);
    });
    int next = -1;
    bool ok = true;
    for (int i = 0; i < K; ++i) {
      if (!bl.onPath(A[0], A[i])) {
        if (next == -1) {
          next = A[i];
        } else {
          ok &= bl.onPath(next, A[i]);
        }
      } else if (next != -1) {
        ok &= !bl.onPath(next, A[i]) || A[i] == bl.lca(A[0], next);
      }
    }
    cout << (ok ? "YES" : "NO") << '\n';
  }
}