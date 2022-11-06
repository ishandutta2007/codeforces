#include <bits/stdc++.h>
using namespace std;

#define int long long
const int inf = 0x3f3f3f3f;
const int mod = 1e9+7;
using ull = uint64_t;
using ii = pair<int, int>;
using iii = tuple<int, int, int>;
using i4 = tuple<int, int, int, int>;
using ll = long long;
const int ms = 1e6+5;

set<int> eds[ms];
vector<ii> g[ms];
int id = 0;
int in[ms];
int out[ms];
int sz[ms];
int realSz[ms];


void dfs(int u, int p = -1) {
  in[u] = id++;
  sz[in[u]] = 1;
  for(auto [v, x] : g[u]) {
    if(v == p) continue;
    dfs(v, u);
    eds[x].emplace(in[v]);
    sz[in[u]] += sz[in[v]];
  }
  out[in[u]] = id;
  // cout << u << " => " << in[u] << " e " << out[in[u]] << " e  " << sz[in[u]] << endl; 
  // assert(out[in[u]] - in[u] == sz[in[u]]);
}



void solve() {
  int n;
  cin >> n;
  for(int i = 1; i < n; i++) {
    int u, v, x;
    cin >> u >> v >> x;
    g[u].emplace_back(v, x);
    g[v].emplace_back(u, x);
  }
  dfs(1);
  int ans = 0;
  for(int i = 1; i <= n; i++) {
    if(eds[i].empty()) continue;
    eds[i].emplace(0);
    eds[i].emplace(n);
    vector<ii> resps;
    for(int j : eds[i]) {
      if(j == n) break;
      realSz[j] = sz[j];
      int k = *eds[i].upper_bound(j);
      while(k < out[j]) {
        realSz[j] -= sz[k];
        resps.emplace_back(j, k);
        k = *eds[i].lower_bound(out[k]);
      }
    }
    for(auto [x, y] : resps) {
      // cout << i << ": " << x << " - " << y << " = " << realSz[x] << " e " << realSz[y] << endl;
      // cout << sz[x] << " e " << sz[y] << endl;
      ans += realSz[x]*realSz[y];
    }
  }
  cout << ans << endl;
}

int32_t main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
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