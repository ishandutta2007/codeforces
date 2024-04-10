#include "bits/stdc++.h"
using namespace std;
#define int long long
void solution() {
  int n, m, k;
  cin >> n >> m >> k;
  vector<int> x(n + 1);
  for (int i = 1; i <= n; i ++)
    cin >> x[i];
  int cnt = 0;
  vector<map<int, int>> id(n + 1);
  vector<vector<pair<int, int>>> g(k * 2 + 5);
  id[1][1] = ++cnt;
  id[n][m] = ++cnt;
  for (int i = 0; i < k; i ++) {
    int a, b, c, d, h;
    cin >> a >> b >> c >> d >> h;
    if (!id[a][b]) id[a][b] = ++ cnt;
    if (!id[c][d]) id[c][d] = ++ cnt;
    g[id[a][b]].emplace_back(id[c][d], -h);
  }
  for (int i = 1; i <= n; i ++) {
    auto it = id[i].begin();
    int prv, pid;
    if (it != id[i].end()) {
      prv = it->first;
      pid = it->second;
      it ++;
    }
    while (it != id[i].end()) {
      g[pid].emplace_back(it->second, abs(it->first - prv) * x[i]);
      g[it->second].emplace_back(pid, abs(it->first - prv) * x[i]);
      prv = it->first;
      pid = it->second;
      it ++;
    }
  }
  const int inf = 1e18;
  vector<int> dist(cnt + 1, inf);
  int u, du;
  vector<bool> inq(cnt + 1);
  queue<int> Q;
  int blk = 50;
  Q.push(1);
  dist[1] = 0;
  inq[1] = 1;
  while (Q.size()) {
    blk --;
    if (!blk) {
      if (clock() > 1.2 * CLOCKS_PER_SEC) {
        break;
      }
      blk = 50;
    }
    u = Q.front();
    Q.pop();
    inq[u] = 0;
    for (auto [v, w] : g[u]) if (dist[v] > dist[u] + w) {
      dist[v] = dist[u] + w;
      if (!inq[v]) {
        inq[v] = 1;
        Q.push(v);
      }
    }
  }
  if (Q.size()) { 
    fill(dist.begin(), dist.end(), inf);
    dist[1] = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
    q.push({0, 1});
    while (q.size()) {
      du = q.top().first;
      u = q.top().second;
      q.pop();
      if (du != dist[u]) continue;
      for (auto [v, w] : g[u]) {
        if (dist[v] > dist[u] + w) {
          dist[v] = dist[u] + w;
          q.push({dist[v], v});
        }
      }
    }

  }
  if (dist[id[n][m]] == inf) cout << "NO ESCAPE";
  else cout << dist[id[n][m]];
}
signed main() {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int tc = 1;
#ifdef DEBUG
  freopen("input.txt", "r", stdin); 
#endif
  cin >> tc; 
  while (tc --) { solution(); cout << "\n"; }
}