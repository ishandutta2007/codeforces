#include <iostream>
#include <vector>

typedef long long ll;

using namespace std;

ll sum = 0;
vector <ll> a;

void dfs1(int v, vector <bool> &used, vector <ll> &d, vector <ll> &sz, vector <vector <int>> &g) {
  sz[v] = a[v];
  used[v] = true;
  for (int u : g[v])
    if (!used[u]) {
      d[u] = d[v] + 1;
      dfs1(u, used, d, sz, g);
      sz[v] += sz[u];
    }
}

void dfs2(int v, vector <bool> &used, vector <ll> &sz, vector <ll> &f, vector <vector <int>> &g) {
  used[v] = true;
  for (int u : g[v])
    if (!used[u]) {
      f[u] = (f[v] + sum - 2 * sz[u]);
      dfs2(u, used, sz, f, g);
    }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  a.resize(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    sum += a[i];
  }
  vector <vector <int>> g(n);
  for (int i = 1; i < n; i++) {
    int u, v;
    cin >> u >> v;
    u--, v--;
    g[u].push_back(v);
    g[v].push_back(u);
  }
  vector <bool> used(n);
  vector <ll> d(n), sz(n);
  dfs1(0, used, d, sz, g);
  vector <ll> f(n);
  for (int v = 0; v < n; v++)
    f[0] += d[v] * a[v];
  used.assign(n, false);
  dfs2(0, used, sz, f, g);
  ll ans = 0;
  for (int v = 0; v < n; v++)
    ans = max(f[v], ans);
  cout << ans;
  return 0;
}