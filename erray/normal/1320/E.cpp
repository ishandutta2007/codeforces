// author: erray
#include <bits/stdc++.h>
#undef DEBUG 
#undef _GLIBCXX_DEBUG
#ifdef DEBUG
  #include "debug.h"
#else
  #define debug(...) void(37)
#endif

using namespace std;

template<typename T, typename F = function<T(const T&, const T&)>> 
struct SparseTable {
  vector<vector<T>> a;
  vector<int> logs;
  int n;
  F op;
  SparseTable() { }
  SparseTable(vector<T> _a, F _op) : op(_op) {
    n = int(_a.size());
    int lg = 32 - __builtin_clz(n);
    a.resize(lg); 
    a[0] = _a;
    for (int j = 1; j < lg; ++j) {
      int size = n - (1 << j) + 1;
      a[j].resize(size);
      for (int i = 0; i < size; ++i) {
        a[j][i] = op(a[j - 1][i], a[j - 1][i + ((1 << (j - 1)))]);
      }
    }
    logs.resize(n + 1, -1);
    for (int i = 1; i <= n; ++i) {
      logs[i] = logs[(i >> 1)] + 1;
    }
  }
  T get(int l, int r) {
    assert(l >= 0 && r < n && l <= r);
    int lg = logs[r - l + 1];;
    return op(a[lg][l], a[lg][r + 1 - (1 << lg)]);
  }
};


struct DSU {
  vector<int> par;
  DSU(int n) {
    par.resize(n);
    iota(par.begin(), par.end(), 0);
  }

  int get(int v) {
    return par[v] = (par[v] == v ? v : get(par[v]));
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
};


int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int N;
  cin >> N;
  vector<vector<int>> g(N);
  for (int i = 0; i < N - 1; ++i) {
    int X, Y;
    cin >> X >> Y;
    --X, --Y;
    g[X].push_back(Y);
    g[Y].push_back(X);
  }
  debug(g);
  vector<int> tour;
  vector<int> tin(N);
  vector<int> tout(N);
  vector<int> d(N);
  function<void(int, int)> Dfs = [&](int v, int pr) {
    tin[v] = tout[v] = int(tour.size());
    tour.push_back(v);
    for (auto u : g[v]) {
      if (u != pr) {
        d[u] = d[v] + 1;
        Dfs(u, v);
        tout[v] = int(tour.size());        
        tour.push_back(v);
      }
    }
  };
  Dfs(0, -1);
  SparseTable st(tour, [&](int x, int y) {
    return (d[x] < d[y] ? x : y);
  });

  debug(tour);
  debug(tin, tout);
  debug(d);
  auto Lca = [&](int v, int u) {
    if (tin[v] > tin[u]) {
      swap(v, u);
    }
    if (tout[v] >= tout[u]) {
      return v;
    }
    return st.get(tout[v], tin[u]);
  };

  int Q;
  cin >> Q;
  vector<int> K(Q), M(Q);
  vector<vector<int>> V(Q), S(Q), U(Q);  
  for (int i = 0; i < Q; ++i) {
    cin >> K[i] >> M[i];
    V[i].resize(K[i]);
    S[i].resize(K[i]);
    U[i].resize(M[i]);
    for (int j = 0; j < K[i]; ++j) {
      cin >> V[i][j] >> S[i][j];
      --V[i][j];
      debug(V[i][j]);
    }
    for (int j = 0; j < M[i]; ++j) {
      cin >> U[i][j];
      --U[i][j];
    }
    debug(V[i], U[i]);
    vector<int> ids;
    ids.insert(ids.end(), U[i].begin(), U[i].end());
    ids.insert(ids.end(), V[i].begin(), V[i].end());
    debug(ids);
    sort(ids.begin(), ids.end(), [&](int x, int y) {
      return tin[x] < tin[y];
    });
    ids.erase(unique(ids.begin(), ids.end()), ids.end());
    int s = int(ids.size());
    for (int j = 0; j < s - 1; ++j) {
      ids.push_back(Lca(ids[j], ids[j + 1]));
    }
    sort(ids.begin(), ids.end(), [&](int x, int y) {
      return tout[x] - tin[x] < tout[y] - tin[y];
    });
    ids.erase(unique(ids.begin(), ids.end()), ids.end());
    vector<array<int, 3>> es;    
    set<array<int, 3>> t;
    for (auto v : ids) {
      auto it = t.lower_bound({tin[v], -1, -1});
      while (it != t.end() && (*it)[0] >= tin[v] && (*it)[1] <= tout[v]) {
        es.push_back({v, (*it)[2], d[(*it)[2]] - d[v]});        
        t.erase(it);
        it = t.lower_bound({tin[v], -1, -1});
      }
      t.insert({tin[v], tout[v], v});
    }
    
    debug(V, U, S);
    debug(ids);
    debug(es);
    int size = int(ids.size());
    sort(ids.begin(), ids.end());
    debug("sorted", ids);
    auto Id = [&](int x) {
      return int(lower_bound(ids.begin(), ids.end(), x) - ids.begin());
    };

    vector<vector<array<int, 2>>> mg(size);
    for (auto[v, u, w] : es) {
      v = Id(v);
      u = Id(u);
      mg[v].push_back({u, w});
      mg[u].push_back({v, w});
    }     
    debug(mg);
    using T = array<int, 4>;
    priority_queue<T, vector<T>, greater<T>> pq;
    vector<array<int, 2>> cur(size);
    for (int j = 0; j < size; ++j) {
      cur[j][0] = N + 5;
    }

    auto Add = [&](int phase, int type, int left, int v) {
      debug("add", phase, type, left, v);
      if (pair{phase, type} >= pair{cur[v][0], cur[v][1]}) {
        return;
      }   
      cur[v] = {phase, type};
      pq.push({phase, type, left, v});
    };

    for (int j = 0; j < K[i]; ++j) {
      debug(V[i][j], Id(V[i][j]));
      V[i][j] = Id(V[i][j]);
      Add(0, j, 0, V[i][j]); 
    }
  
    vector<bool> vis(size);
    while (!pq.empty()) {
      auto[phase, type, left, v] = pq.top();
      pq.pop();
      debug(phase, type, left, v);
      if (vis[v]) {
        continue;
      }
      vis[v] = true;
      for (auto[u, w] : mg[v]) {
        if (w <= left) {
          int new_left = left - w;
          Add(phase, type, new_left, u);
        } else {
          w -= left;
          int next = (w + S[i][type] - 1) / S[i][type];
          int my_left = next * S[i][type] - w;
          Add(phase + next, type, my_left, u); 
        }
      }
    }

    for (int j = 0; j < M[i]; ++j) {
      U[i][j] = Id(U[i][j]);
      cout << cur[U[i][j]][1] + 1 << ' ';
    }
    cout << '\n';
  }


}