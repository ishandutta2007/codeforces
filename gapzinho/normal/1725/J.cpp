#include <bits/stdc++.h>
using namespace std;
 
#define int long long
 
using ull = uint64_t;
using ii = pair<int, int>;
using iii = pair<int, ii>;
using i4 = tuple<int, int, int, int>;
using ll = long long;
using ld =  long double;
const int inf = 0x3f3f3f3f3f3f3f3f;
 
const int ms = 3e5+5;
const int mod = 998244353;

vector<ii> g[ms];
int d1[ms], d2[ms];
int wpar[ms];

int ans = 0; 

void dfspre(int u, int par = -1) {
  vector<int> cur = {0, 0};
  for(auto [v, w] : g[u]) {
    if(v == par) continue;
    wpar[v] = w;
    dfspre(v, u);
    d1[u] = max(d1[u], d1[v] + w);
    d2[u] = max(d2[u], d2[v]);
    cur.emplace_back(d1[v]+w);
  }
  sort(cur.begin(), cur.end());
  reverse(cur.begin(), cur.end());
  d2[u] = max(d2[u], cur[0] + cur[1]);
}

void dfs(int u, int d1par = 0, int d2par = 0, int par = -1) {
  ans = max(ans, d2par + d2[u] + wpar[u]*2);
  vector<int> cur2 = {d2par, 0}, cur1 = {d1par, 0, 0, 0};
  for(auto [v, w] : g[u]) {
    if(v == par) continue;
    cur1.emplace_back(d1[v]+w);
    cur2.emplace_back(d2[v]);
  }
  sort(cur1.begin(), cur1.end());
  reverse(cur1.begin(), cur1.end());
  sort(cur2.begin(), cur2.end());
  reverse(cur2.begin(), cur2.end());
  for(auto [v, w] : g[u]) {
    if(v == par) continue;
    wpar[v] = w;
    int bstcur2Puro = cur2[0] == d2[v] ? cur2[1] : cur2[0];
    int bstcur1 = cur1[0] == d1[v]+w ? cur1[1] : cur1[0];
    int bstCur2 = cur1[0] == d1[v] + w ? cur1[1] + cur1[2] : (cur1[1] == d1[v] + w ? cur1[0] + cur1[2] : cur1[0] + cur1[1]);
    dfs(v, bstcur1 + w, max(bstCur2, bstcur2Puro), u);
  }
  ans = max(ans, cur1[0] + cur1[1] + cur1[2] + cur1[3]);
}

void solve() {
  int n;
  cin >> n;
  int tmp = 0;
  for(int i = 1; i < n; i++) {
    int u, v, w;
    cin >> u >> v >> w;
    g[u].emplace_back(v, w);
    g[v].emplace_back(u, w);
    tmp += 2*w;
  }
  dfspre(1);
  dfs(1);
  // cout << tmp << endl;
  cout << tmp - ans << '\n';
}
 
 
 
int32_t main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << fixed << setprecision(10);
  int t = 1;
  // cin >> t;
  for(int T = 1; T <= t; T++) {
    // cout << "Case #" << T << ": ";
    solve(); 
  }
  return 0;
}