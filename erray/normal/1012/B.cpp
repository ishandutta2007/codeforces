// author: erray
#include<bits/stdc++.h>
 
using namespace std;
 
int main () {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int n, m, q;
  cin >> n >> m >> q;
  vector<vector<int>> g(n + m);
  for (int i = 0; i < q; ++i) {
    int x, y;
    cin >> x >> y;
    --x; --y;
    y += n;
    g[x].push_back(y);
    g[y].push_back(x);    
  }  
  vector<bool> vis(n + m);
  function<void(int)> dfs = [&](int v) {
    vis[v] = true;
    for (auto u : g[v]) {
      if (!vis[u]) {
        dfs(u);
      }  
    }
  };
  int ans = -1;
  for (int i = 0; i < n + m; ++i) {
    if (vis[i]) continue;
    dfs(i);
    ++ans;
  }
  cout << ans << '\n';
}