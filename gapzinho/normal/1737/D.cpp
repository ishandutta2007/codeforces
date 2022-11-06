#include <bits/stdc++.h>
using namespace std;
 
#define int long long
 
using ull = uint64_t;
using ii = pair<int, int>;
using iii = pair<int, ii>;
// using i4 = tuple<int, int, int, int>;
using i4 = pair<ii, ii>;
using ll = long long;
const int inf = 0x3f3f3f3f3f3f3f3f;
const int ms = 505;

int dist[ms][ms];
vector<int> g[ms];
int minW[ms];

void bfs(int u, int t) {
  queue<int> q;
  dist[t][u] = 0;
  q.emplace(u);
  while(!q.empty()) {
    int x = q.front();;
    q.pop();;
    for(int y : g[x]) {
      if(dist[t][y] > dist[t][x]+1) {
        dist[t][y] = dist[t][x]+1;
        q.emplace(y);
      }
    }
  }
}

void solve() {
  memset(dist, 0x3f, sizeof dist);
  int n, m;
  cin >> n >> m;
  for(int i = 1; i <= n; i++) {
    g[i].clear();
  }
  memset(minW, 0x3f, sizeof minW);
  vector<pair<ii, int>> eds(m);
  for(auto &[e, w] : eds) {
    cin >> e.first >> e.second >> w;
    g[e.first].emplace_back(e.second);
    g[e.second].emplace_back(e.first);
    minW[e.first] = min(minW[e.first], w);
    minW[e.second] = min(minW[e.second], w);
  }
  for(int i = 1; i <= n; i++) {
    bfs(i, i);
  }
  int ans = inf;
  for(int i = 1; i <= n; i++) {
    for(int j = 1; j <= n; j++) {
      if(minW[j] == inf) continue;
      int cst = (dist[1][i] + dist[n][i] + dist[i][j] + 2);
      // cout << "? " << minW[j] << " " << cst << endl;
      // cout << i << endl;
      // // cout << "?? " << dist[1][i] << " " << dist[n][i] << " " << dist[i][j] << endl;
      ans = min(ans, cst*minW[j]);
    }
  }
  for(auto &[e, w] : eds) {
    int cst = min(dist[e.first][1] + dist[e.second][n], dist[e.first][n] + dist[e.second][1]) + 1;
    ans = min(ans, cst*w);
  }
  cout << ans << '\n';
}
 
 
int32_t main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << fixed << setprecision(10);
  int t = 1;
  cin >> t;
  for(int i = 1; i <= 500; i++) {
    
  }
  for(int T = 1; T <= t; T++) {
    // cout << "Case #" << T << ": ";
    solve(); 
  }
  return 0;
}