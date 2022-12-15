#include <bits/stdc++.h>
using namespace std;
 
#define int long long
 
typedef pair<int, int> ii;
typedef vector<int> vi;

const int ms = 5e5+5;

int arr[ms];
vector<ii> g[ms];
int dp[ms][2];
int vis[ms][2];
int T = 0;
int n, k;

int solve(int u, int par, int q) {
  if(vis[u][q] == T) return dp[u][q];
  int &ans = dp[u][q] = 0;
  // cout << "calling " << u << ' ' << par << ' ' << q << endl;
  vis[u][q] = T;
  vector<int> v;
  for(auto e : g[u]) {
    if(e.first == par) continue;
    v.push_back(e.second + solve(e.first, u, 1) - solve(e.first, u, 0));
    ans += solve(e.first, u, 0);
  }
  sort(v.begin(), v.end());
  reverse(v.begin(), v.end());
  for(int i = 0; i < v.size() && v[i] > 0 && i < k-q; i++) {
    ans += v[i];
  }
  // cout << u << ' ' << q << " = " << ans << endl;
  return ans;
}

main() {
  cin.tie(0); ios::sync_with_stdio(0);
  int q;
  cin >> q;
  while(q--) {
    ++T;
    cin >> n >> k;
    for(int i = 1; i <= n; i++) g[i].clear();
    for(int i = 1; i < n; i++) {
      int u, v, w;
      cin >> u >> v >> w;
      g[u].emplace_back(v, w);
      g[v].emplace_back(u, w);
    }
    cout << solve(1, -1, 0) << '\n';
  }
}