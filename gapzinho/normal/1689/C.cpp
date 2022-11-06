#include <bits/stdc++.h>
using namespace std;

#define int long long
const int inf = 1e18;
const int mod = 998244353;
using ull = uint64_t;
using ii = pair<int, int>;
using iii = tuple<int, int, int>;
using i4 = tuple<int, int, int, int>;
using ll = long long;
const int ms = 3e5+5;

vector<int> g[ms];
int dp[ms];
int sz[ms];

int dfs(int u, int p = -1) {
   sz[u] = 0;
   dp[u] = 0;
   vector<int> h;
   for(int v : g[u]) {
      if(v == p) continue;
      h.emplace_back(v);
      sz[u] += dfs(v, u) + 1;
   }
   if(h.empty()) dp[u] = 0;
   else if(h.size() == 1) dp[u] = sz[h[0]];
   else dp[u] = max(dp[h[0]] + sz[h[1]], dp[h[1]] + sz[h[0]]);
   return sz[u];
}

void solve() {
   int n;
   cin >> n;
   for(int i = 1; i <= n;i++) g[i].clear();
   for(int i = 1; i < n; i++) {
      int u, v;
      cin >> u >> v;
      g[u].emplace_back(v);
      g[v].emplace_back(u);
   }
   dfs(1);
   cout << dp[1] << '\n';
}

int32_t main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
   #ifdef ONLINE_JUDGE
    // freopen("boysgirls.in", "r", stdin);
    // freopen("boysgirls.out", "w", stdout);
  #endif
  int t = 1;
  cin >> t;
//   a[1] = 1;
//   for(int i = 1; i < ms; i++) {
//      for(int j = i*i; j < ms; j++) {
//         if(i == j) continue;
//         a[j] += a[i];
//      }
//   }
//   for(int i = 1; i <= t; i++) {
//      cout << a[i] << endl;
//   }
  while (t--) {
    solve(); 
  }
  return 0;
}