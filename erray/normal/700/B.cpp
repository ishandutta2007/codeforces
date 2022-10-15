// author: erray
#include<bits/stdc++.h>
 
using namespace std;
 
int main () {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int n, k;
  cin >> n >> k;
  k *= 2;
  vector<vector<int>> g(n);
  vector<bool> mark(n);
  for (int i = 0; i < k; ++i) {
    int x;
    cin >> x;
    mark[x - 1] = true;
  }
  for (int i = 0; i < n - 1; ++i) {
    int x, y;
    cin >> x >> y;
    --x; --y;
    g[x].push_back(y);
    g[y].push_back(x);  
  }
  vector<int> ct(n);
  function<void(int, int)> dfs = [&](int v, int pr) {
    ct[v] = mark[v];
    for (auto u : g[v]) {
      if (u == pr) continue;
      dfs(u, v);
      ct[v] += ct[u];
    }
  };
  dfs(0, -1);
  long long ans = 0;
  for (auto el : ct) {
    ans += min(el, k - el);
  }
  cout << ans << '\n';
}