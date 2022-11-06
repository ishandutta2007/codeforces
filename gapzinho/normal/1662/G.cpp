#include <bits/stdc++.h>
using namespace std;

#define int long long

using ull = uint64_t;
using ii = pair<int, int>;
using iii = tuple<int, int, int>;
using i4 = tuple<int, int, int, int>;
using ll = long long;
using ld =  long double;
const int inf = 0x3f3f3f3f;
const int mod = 998244353;
const int ms = 1e6+5;

int sz[ms];
vector<int> g[ms];

int dfsSubtree(int u, int p) {
  sz[u] = 1;
  int ans = 0;
  for(auto v : g[u]) {
    if(v != p) {
      ans += dfsSubtree(v, u);
      sz[u] += sz[v];
    }
  }
  return ans + sz[u];
}


int getCentroid(int u, int p, int size) {
  for(auto v : g[u]) {
    if(v != p && sz[v] * 2 >= size) 
      return getCentroid(v, u, size);
  }
  return u;
}

int itens[ms];
bitset<1000005> dp;

void solve() {
  int n;
  cin >> n;
  for(int i = 1; i < n; i++) {
    int u;
    cin >> u;
    u--;
    g[u].emplace_back(i);
    g[i].emplace_back(u);
  }
  dfsSubtree(0, -1);
  int c = getCentroid(0, -1, n);
  int ans = dfsSubtree(c, -1);
  for(int v : g[c]) {
    itens[sz[v]]++;
  }
  dp[0] = 1;
  for(int v = 1; v <= n; v++) {
    while(itens[v] > 2) {
      itens[v] -= 2;
      itens[v*2]++;
    }
    if(itens[v]) {
      dp = dp | (dp << v);
      if(itens[v] > 1) {
        dp = dp | (dp << v);
      }
    }
  }
  n--;
  for(int i = n/2; i >= 0; i--) {
    if(dp[i]) {
      cout << ans + i * (n-i) << endl;
      return;
    }
  }
}

int32_t main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << fixed << setprecision(10);
   #ifdef ONLINE_JUDGE
    // freopen("boysgirls.in", "r", stdin);
    // freopen("boysgirls.out", "w", stdout);
  #endif
  int t = 1;
  // cin >> t;
  while (t--) {
    solve(); 
  }
  return 0;
}