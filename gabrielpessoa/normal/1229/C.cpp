#include <bits/stdc++.h>
using namespace std;

#define int long long

const int ms = 1e5+5;
const int inf = 0x3f3f3f3f;
const int mod = 1e9+7;
const int sq = 400;

int ans = 0;
vector<int> g[ms];
int deg[ms];

main() {
  cin.tie(0); ios::sync_with_stdio(0);
  int n, m;
  cin >> n >> m;
  for(int i = 0; i < m; i++) {
    int u, v;
    cin >> u >> v;
    if(v < u) swap(u, v);
    g[u].push_back(v);
    deg[v]++;
  }
  for(int i = 1; i <= n; i++) {
    for(int j : g[i]) {
      ans += g[j].size();
    }
  }
  cout << ans << '\n';
  int q;
  cin >> q;
  for(int i = 1; i <= q; i++) {
    int u;
    cin >> u;
    ans -= deg[u] * g[u].size();
    for(int v : g[u]) {
      deg[v]--;
      ans += deg[v] - g[v].size();
      g[v].push_back(u);
      deg[u]++;
    }
    g[u].clear();
    cout << ans << '\n';
  }
}