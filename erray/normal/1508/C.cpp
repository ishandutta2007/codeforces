// author: erray
#include <bits/stdc++.h>
 
using namespace std;

struct dsu {
  vector<int> par, sz;
  dsu(int n) {
    par.resize(n);
    sz.resize(n, 1);
    iota(par.begin(), par.end(), 0);
  }
  inline int get(int v) {
    return par[v] = (v == par[v] ? v : get(par[v]));
  }
  int size(int v) {
    return sz[get(v)];
  }
  inline bool unite(int x, int y) {
    x = get(x);
    y = get(y);
    if (x == y) return false;
    sz[x] += sz[y];
    par[y] = x;
    return true;
  }
};
 
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int n, m;
  cin >> n >> m;
  vector<vector<int>> g(n);
  vector<array<int, 3>> es(m);
  int add = 0;
  for (int i = 0; i < m; ++i) {
    cin >> es[i][0] >> es[i][1] >> es[i][2];
    --es[i][0], --es[i][1];
    g[es[i][0]].push_back(es[i][1]);
    g[es[i][1]].push_back(es[i][0]);
    add ^= es[i][2];
  }
  for (int i = 0; i < n; ++i) {
    sort(g[i].begin(), g[i].end());
  }

  sort(es.begin(), es.end(), [&](auto x, auto y) {
    return x[2] < y[2];
  });
  dsu nes(n);
  vector<array<int, 3>> new_es;
  for (auto[v, u, w] : es) {
    if (nes.unite(v, u)) {
      new_es.push_back({v, u, w});
    }
  }
  swap(new_es, es);

  long long ec = 1LL * n * (n - 1) / 2;  
  if (ec - m > n - 1) {
    set<int> in;
    for (int i = 0; i < n; ++i) {
      in.insert(i);
    }
    dsu d(n);

    function<void(int)> Dfs = [&](int v) {
      in.erase(v);
      int go = -1;
      while (true) {
        auto next = in.lower_bound(go + 1);
        if (next == in.end()) {
          break;
        } 
        go = *next;
        if (binary_search(g[v].begin(), g[v].end(), go)) {
          continue;
        }
        d.unite(v, go);
        Dfs(go);
      }   
    };

    for (int i = 0; i < n; ++i) {
      if (in.count(i)) {
        Dfs(i);
      } 
    }


    long long ans = 0;
    for (auto[v, u, w] : es) {
      if (d.unite(v, u)) {
        ans += w;
      }
    }
    cout << ans << '\n';
  } else {
    long long ans = 0;
    vector<pair<int, int>> zero;
    for (int i = 0; i < n; ++i) {
      for (int j = i + 1; j < n; ++j) {
        if (!binary_search(g[i].begin(), g[i].end(), j)) {
          zero.emplace_back(i, j);
        }
      }
    }
    {
      dsu d(n);
      long long res = add;
      for (auto[v, u] : zero) {
        d.unite(v, u);
      }
      for (auto[v, u, w] : es) {
        if (d.unite(v, u)) {
          res += w;
        }
      }
      ans = res;
    }
    {
      for (int i = 0; i < int(zero.size()); ++i) {
        dsu d(n);
        for (int j = 0; j < int(zero.size()); ++j) {
          if (i != j) {
            d.unite(zero[j].first, zero[j].second);
          }
        }
        long long res = 0;
        for (auto[v, u, w] : es) {
          if (d.unite(v, u)) {
            res += w;
          }
        }
        ans = min(ans, res);
      } 
    }
    cout << ans << '\n';
  }
}