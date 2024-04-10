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
 
const int ms = 1e5+5;
const int mod = 1e9+7;

vector<ii> g[ms][2];
int d[ms][2];

void solve() {
  int n, m;
  cin >> n >> m;
  for(int i = 0; i < m; i++) {
    int u, v, w;
    cin >> u >> v >> w;
    g[u][0].emplace_back(v, w);
    g[v][1].emplace_back(u, w);
  }
  memset(d, 0x3f, sizeof d);
  d[1][0] = 0;
  priority_queue<iii, vector<iii>, greater<iii>> pq;
  pq.emplace(0, ii(1, 0));
  while(!pq.empty()) {
    auto [dist, vert] = pq.top();
    auto [u, typ] = vert;
    pq.pop();
    if(d[u][typ] < dist) continue;
    if(typ == 0 && d[u][1] > dist) {
      d[u][1] = dist;
      pq.emplace(dist, ii(u, 1));
    }
    for(auto [v, w] : g[u][typ]) {
      if(d[v][typ] > dist + w) {
        d[v][typ] = dist+w;
        pq.emplace(dist + w, ii(v, typ));
      }
    }
  }
  for(int i = 2; i <= n; i++) {
    cout << (d[i][1] == inf ? -1 : d[i][1]) << ' ';
  }
  cout << '\n';
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