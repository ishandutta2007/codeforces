#include <iostream>
#include <vector>
#include <queue>

typedef long long ll;

using namespace std;

const ll INF = 1e18;

int main () {
  ios::sync_with_stdio(false);
  cin.tie(0);
  ll ans = 0;
  int n;
  cin >> n;
  vector <vector <pair <ll, ll>>> g(n);
  for (int i = 1; i < n; i++) {
    ll u, v, w;
    cin >> u >> v >> w;
    u--, v--;
    ans += 2 * w;
    g[u].push_back({v, w});
    g[v].push_back({u, w});
  }
  queue <int> q;
  vector <ll> d(n, INF);
  d[0] = 0;
  q.push(0);
  while (!q.empty()) {
    int v = q.front();
    q.pop();
    for (auto &now : g[v]) {
      int u = now.first;
      ll w = now.second;
      if (d[v] + w < d[u]) {
        d[u] = d[v] + w;
        q.push(u);
      }
    }
  }
  ll ma = 0;
  for (int i = 0; i < n; i++)
    ma = max(ma, d[i]);
  cout << ans - ma;
  return 0;
}