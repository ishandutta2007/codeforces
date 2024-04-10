// author: erray
#include <bits/stdc++.h>
 
using namespace std;
 
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int n, m;
  cin >> n >> m;
  const long long inf = (long long) 1e15;
  vector<vector<long long>> sp(n, vector(n, inf));
  vector<array<int, 3>> edges(m);
  for (int i = 0; i < m; ++i) {
    int x, y, w;
    cin >> x >> y >> w;
    --x, --y;
    edges[i] = {x, y, w};
    sp[x][y] = sp[y][x] = w;
  }

  for (int i = 0; i < n; ++i) {
    sp[i][i] = 0;
  }

  for (int k = 0; k < n; ++k) {
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < n; ++j) {
        sp[i][j] = min(sp[i][j], sp[i][k] + sp[k][j]);
      }
    }
  }

  vector<vector<long long>> neg(n, vector(n, inf));
  int q;
  cin >> q;
  while (q--) {
    int x, y, w;
    cin >> x >> y >> w;
    --x, --y;
    neg[x][y] = neg[y][x] = -w; 
  }

  vector<vector<long long>> neg_sp(n, vector(n, inf));
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      for (int k = 0; k < n; ++k) {
        neg_sp[i][j] = min(neg_sp[i][j], sp[i][k] + neg[k][j]);
      }
    }
  }
  
  int ans = 0;
  for (auto[v, u, w] : edges) {
    bool ok = false;
    for (int i = 0; i < n; ++i) {
      ok |= (neg_sp[v][i] + sp[i][u] <= -w);
    }
    ans += ok;
  }
  cout << ans << '\n';
}