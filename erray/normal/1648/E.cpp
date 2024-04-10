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
    return par[v] = (par[v] != v ? get(par[v]) : v);
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
  int TT;
  cin >> TT;
  while (TT--) {
    int N, M;
    cin >> N >> M;
    vector<int> A(M), B(M), C(M);
    for (int i = 0; i < M; ++i) {
      cin >> A[i] >> B[i] >> C[i];
      --A[i], --B[i];
    }
    vector<array<int, 2>> in(M);    
    for (int i = 0; i < M; ++i) {
      in[i] = {min(A[i], B[i]), max(A[i], B[i])};
    }
    sort(in.begin(), in.end());
    auto Used = [&](int x, int y) {
      return binary_search(in.begin(), in.end(), array{min(x, y), max(x, y)});
    };

    //WTF  
    vector<array<int, 3>> mst;
    {
      vector<array<int, 3>> es(M);
      for (int i = 0; i < M; ++i) {
        es[i] = {C[i], A[i], B[i]};
      }
      sort(es.begin(), es.end());
      DSU d(N);
      for (auto[c, v, u] : es) {
        if (d.unite(v, u)) {
          mst.push_back({v, u, c});
        }
      }
    }

    debug(mst);

    vector<int> ans(M);
    {
      vector<vector<array<int, 2>>> es(N);
      for (int i = 0; i < M; ++i) {
        es[A[i]].push_back({i, -1});
        es[B[i]].push_back({i, -1});
      }

      vector<vector<int>> vs(N);
      for (int i = 0; i < N; ++i) {
         vs[i].push_back(i);
      }
      
      vector<list<int>> dac(N);
      for (int i = 0; i < N; ++i) {
        dac[i].push_back(i);
      }
      DSU tree(N);
      DSU graph(N);
      vector<bool> vis(M);
      for (auto[v, u, c] : mst) {
        v = tree.get(v);
        u = tree.get(u);
        if (int(dac[v].size()) < int(dac[u].size())) {
          swap(v, u);
        }
        debug(v, u, c);


        auto Merge = [&](int x, int y) {
          x = graph.get(x);
          y = graph.get(y);
          debug(x, y, vs[x], vs[y]);
          for (auto v0 : vs[x]) {
            for (auto u0 : vs[y]) {
              if (!Used(v0, u0)) {
                if (int(vs[x].size()) < int(vs[y].size())) {
                  swap(x, y);
                }
                for (auto add : vs[y]) {
                  vs[x].push_back(add);
                }
                vs[y].clear();
                if (int(es[x].size()) < int(es[y].size())) {
                  swap(x, y);
                }
                for (auto[id, t] : es[y]) {
                  es[x].push_back({id, (vis[id] ? t : c)});
                  vis[id] = true;
                }
                for (auto[id, t] : es[y]) {
                  vis[id] = false;
                }
                graph.unite(x, y);
                if (vs[x].empty()) {
                  swap(vs[x], vs[y]);
                }
                if (es[x].empty()) {
                  swap(es[x], es[y]);
                }
                return true;
              }
            }
          }
          return false;
        };

        vector<int> push;
        debug(dac[u], dac[v]);
        for (auto gs : dac[u]) {
          debug(gs, dac[v]);
          int merged = 0;
          auto it = dac[v].begin();
          while (it != dac[v].end()) {
            auto pass = next(it);
            if (Merge(gs, *it)) {
              debug("merged", gs, *it, merged);
              if (merged > 0) {
                dac[v].erase(it);    
              }
              merged += 1; 
            }
            it = pass;
          }
          if (merged == 0) {
            push.push_back(gs);
          }
        }
        for (auto e : push) {
          dac[v].push_back(e);
        }
        debug(v, dac[v]);
        debug(vs);
        tree.unite(v, u);
      }


      vector<bool> first(M, true);
      int root = graph.get(0);
      debug(es[root]);
      for (auto[id, t] : es[root]) {
        if (!first[id]) {
          ans[id] = t;
        } else {
          first[id] = false;
        }
      }
    }

    for (int i = 0; i < M; ++i) {
      cout << ans[i] << ' ';
    }
    cout << '\n';
  }
}