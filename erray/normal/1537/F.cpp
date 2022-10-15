// author: erray
#include <bits/stdc++.h>
 
using namespace std;
 
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  while (tt--) {
    int n, m;
    cin >> n >> m;
    vector<int> v(n);
    for (int i = 0; i < n; ++i) {
      cin >> v[i];
    }
    vector<int> t(n);
    for (int i = 0; i < n; ++i) {
      cin >> t[i];
    }

    vector<vector<int>> g(n);
    for (int i = 0; i < m; ++i) {
      int x, y;
      cin >> x >> y;
      --x, --y;
      g[x].push_back(y);
      g[y].push_back(x);
    }

    bool bip = true;
    vector<int> id(n, -1);
    function<void(int)> Dfs = [&](int v) {
      for (auto u : g[v]) {
        bip &= (id[u] != id[v]);
        if (id[u] == -1) {
          id[u] = id[v] ^ 1;
          Dfs(u);
        }
      }
    };
    id[0] = 0;
    Dfs(0);
    if (bip) {
      long long sum = 0;
      for (int i = 0; i < n; ++i) {
        sum += (v[i] - t[i]) * (id[i] ? 1 : -1);
      }   
      cout << (sum == 0 ? "YES" : "NO") << '\n';
    } else {
      long long sum = 0;
      for (int i = 0; i < n; ++i) {
        sum += (v[i] - t[i]);
      }   
      cout << (sum % 2 == 0 ? "YES" : "NO") << '\n';
    }
  }
}