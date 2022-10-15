// author: erray
#include<bits/stdc++.h>
 
using namespace std;

class dsu {
  public:
  vector<int> par, ct;
  dsu(int n) {
    par.resize(n);
    ct.resize(n, 1);
    iota(par.begin(), par.end(), 0);
  }
  inline int get(int v) {
    return par[v] = (v == par[v] ? v : get(par[v]));
  }
  inline bool unite(int x, int y) {
    x = get(x);
    y = get(y);
    if (x == y) return false;
    ct[x] += ct[y];
    par[y] = x;
    return true;
  }
};
 
int main () {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int T;
  cin >> T;
  while (T--) {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> g(n);
    dsu d(n);
    for (int i = 0; i < m; ++i) {
      int x, y;
      cin >> x >> y;
      --x, --y;
      d.unite(x, y);
      g[x].push_back(y);
      g[y].push_back(x);
    }

    if (d.ct[d.get(0)] != n) {
      cout << "NO\n";
      continue;
    }

    cout << "YES\n";
    queue<int> que;
    vector<int> c(n, -1);

    auto white = [&](int v) {
      c[v] = 1;
      for (auto u : g[v]) {
        if (c[u] == -1) {
          c[u] = 0;
          que.push(u);
        }
      }  
    };

    white(0);
    vector<int> ans;

    while (!que.empty()) {
      int v = que.front();
      que.pop();
      for (auto u : g[v]) {
        if (c[u] == -1) {
          white(u);
        }
      }
    }
    
    for (int i = 0; i < n; ++i) {
      if (c[i] == 1) {
        ans.push_back(i);
      }
    }

    cout << (int) ans.size() << '\n';
    for (auto e : ans) {
      cout << e + 1 << ' ';
    }
    cout << '\n';
  }
}