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
  int N, M;
  cin >> N >> M;
  vector<array<int, 3>> E(M);
  vector<vector<int>> g_one(N);
  vector<vector<int>> g_two(N);
  for (int i = 0; i < M; ++i) {
    cin >> E[i][0] >> E[i][1]  >> E[i][2];
    --E[i][0], --E[i][1];
    auto &g = (E[i][2] == 1 ? g_one : g_two);
    g[E[i][0]].push_back(i);
    g[E[i][1]].push_back(i);
  }

  debug(g_one);
  debug(g_two);

  DSU d(M);
  vector<array<int, 2>> top(M);
  for (int i = 0; i < M; ++i) {
    top[i] = {E[i][0], E[i][1]};
  }

  vector<array<int, 2>> dir(M, array{-1, -1});
  vector<vector<int>> suc(M);
  for (int i = 0; i < N; ++i) {
    auto Use = [&](vector<int>& g) {
      while (int(g.size()) > 1) {
        int x = g.back();
        g.pop_back();
        int y = g.back();
        g.pop_back();
        suc[x].push_back(y);
        suc[y].push_back(x);
        if (!d.unite(x, y)) {
          int v = i;
          int lv = v;
          int prev = -1;
          while (dir[x] == array{-1, -1}) {
            int nv = E[x][0] ^ E[x][1] ^ lv;
            dir[x] = {lv, nv};
            debug("loop", x);
            lv = nv;
            if (int(suc[x].size()) <= (prev != -1)) {
              break;
            }
            int next = suc[x][(suc[x][0] == prev)];
            prev = x;
            x = next;
          }
        } 
      }   
    };
    Use(g_one[i]);
    Use(g_two[i]);
  }

  debug(g_one);
  debug(g_two);

  debug(suc);
  vector<bool> r(M);
  #ifdef DEBUG
    vector<array<int, 3>> es;
  #endif
  function<void(int, bool)> Dfs = [&](int v, bool in) {
    debug("vertex", v);
    auto Go = [&](vector<vector<int>>& g) {
      if (!g[v].empty()) {
        int x = g[v][0];
        if (dir[x] != array{-1, -1}) {
          return;
        }
        
        int lv = v;
        int prev = -1;
        while (dir[x] == array{-1, -1}) {
          int nv = E[x][0] ^ E[x][1] ^ lv;
          dir[x] = {lv, nv};
          r[x] = in;
          lv = nv;
          if (int(suc[x].size()) <= (prev != -1)) {
            break;
          }
          int next = suc[x][(suc[x][0] == prev)];
          prev = x;
          x = next;
        }

        debug(lv);
        if (lv != v) {
          Dfs(lv, in);
        } else {
          assert(false);
        }
        #ifdef DEBUG 
          es.push_back({v, lv, E[x][2]}); 
        #endif
        in ^= 1;
      }                  
    };
    Go(g_one);
    Go(g_two);
  };

  for (int i = 0; i < N; ++i) {
    Dfs(i, false);
  } 
  
  #ifdef DEBUG 
    for (auto[x, y, w] : es) {
      cout << x << ' ' << y << ' ' << w << '\n';
    }
    cerr << endl;
  #endif

  int res = 0;
  for (int i = 0; i < N; ++i) {
    if (!g_one[i].empty()) {
      res += 1;
      debug(i);
    }
  }

  debug(dir);
  cout << res << '\n';
  for (int i = 0; i < M; ++i) {
    cout << 1 + ((dir[i][0] == E[i][0]) ^ r[i]);
  }
  cout << '\n';

  #ifdef DEBUG 
    vector<int> eval(N);
    for (int i = 0; i < M; ++i) {
      if ((dir[i][0] == E[i][0]) ^ r[i]) {
        swap(E[i][0], E[i][1]);
      }
      cout << E[i][0] << ' ' << E[i][1] << ' ' << E[i][2] << '\n';
      eval[E[i][0]] += E[i][2];
      eval[E[i][1]] -= E[i][2];
    }
    debug(eval);
    for (int i = 0; i < N; ++i) {
      if (abs(eval[i]) == 1) {
        debug(i);
      }
    }

  #endif
}