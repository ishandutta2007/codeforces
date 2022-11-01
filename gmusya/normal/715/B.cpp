#include <iostream>
#include <vector>
#include <set>

#define fi first
#define se second

using namespace std;

typedef long long ll;
typedef pair <int, int> pii;

const ll INF = 1e18;

ll dijkstra(int n, int st, int t, vector <pair <pii, int>> e) {
  vector <vector <pii>> g(n);
  for (auto &now : e) {
    int u = now.fi.fi, v = now.fi.se, w = now.se;
    g[u].push_back({v, w});
    g[v].push_back({u, w});
  }
  vector <ll> d(n, INF);
  d[st] = 0;
  set <pair <ll, int>> s;
  s.insert({d[st], st});
  while (!s.empty()) {
    int v = s.begin()->second;
    s.erase(s.begin());
    for (auto &now : g[v]) {
      int u = now.fi, w = now.se;
      if (d[v] + w < d[u]) {
        s.erase({d[u], u});
        d[u] = d[v] + w;
        s.insert({d[u], u});
      }
    }
  }
  return d[t];
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, m, l, s, t;
  cin >> n >> m >> l >> s >> t;
  vector <pair <pii, int>> e(m);
  for (int i = 0; i < m; i++) {
    int u, v, w;
    cin >> u >> v >> w;
    e[i] = {{u, v}, w};
  }
  {
    vector <pair <pii, int>> newe = e;
    for (auto &now : newe)
      if (!now.se)
        now.se = 1;
    if (dijkstra(n, s, t, newe) > l) {
      cout << "NO\n";
      return 0;
    }
  }
  {
    vector <pair <pii, int>> newe = e;
    for (auto &now : newe)
      if (!now.se)
        now.se = l + 1;
    if (dijkstra(n, s, t, newe) < l) {
      cout << "NO\n";
      return 0;
    }
  }
  cout << "YES\n";
  int L = 0, R = m - 1;
  while (L != R) {
    int M = (L + R) / 2;
    vector <pair <pii, int>> newe = e;
    for (int i = 0; i < m; i++) {
      if (e[i].se)
        continue;
      if (i <= M)
        newe[i].se = 1;
      else
        newe[i].se = l + 1;
    }
    ll len = dijkstra(n, s, t, newe);
    if (len == l) {
      for (auto &now : newe)
        cout << now.fi.fi << ' ' << now.fi.se << ' ' << now.se << '\n';
      return 0;
    }
    if (len > l)
      L = M + 1;
    else
      R = M;
  }
  vector <pair <pii, int>> newe = e;
  for (int i = 0; i < m; i++) {
    if (e[i].se)
      continue;
    if (i <= L)
      newe[i].se = 1;
    else
      newe[i].se = l + 1;
  }
  ll len = dijkstra(n, s, t, newe);
  newe[L].se += l - len;
  for (auto &now : newe)
    cout << now.fi.fi << ' ' << now.fi.se << ' ' << now.se << '\n';
  return 0;
}