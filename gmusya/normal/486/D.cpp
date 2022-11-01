#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

typedef long long ll;
typedef vector <int> vi;
typedef vector <vi> vvi;

const ll MOD = 1e9 + 7;

int d, n;
vi used, a;
vvi g;
vector <ll> var;

void dfs(int v, int r, int p = -1) {
  var[v] = 1;
  for (int u : g[v]) {
    if (u == p)
      continue;
    if (used[u])
      continue;
    if (a[u] + d < a[r])
      continue;
    dfs(u, r, v);
    var[v] = (var[v] * (var[u] + 1)) % MOD;
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> d >> n;
  a.resize(n);
  for (int i = 0; i < n; i++)
    cin >> a[i];
  g.resize(n);
  for (int i = 1; i < n; i++) {
    int u, v;
    cin >> u >> v;
    u--, v--;
    g[u].push_back(v);
    g[v].push_back(u);
  }
  ll ans = 0;
  used.resize(n);
  vector <int> p(n);
  iota(p.begin(), p.end(), 0);
  sort(p.begin(), p.end(), [&](int u, int v) {
    return a[u] > a[v];
  });
  for (int i : p) {
    var.assign(n, 0);
    dfs(i, i);
    ans += var[i];
    if (ans >= MOD)
      ans -= MOD;
    used[i] = 1;
  }
  cout << ans;
  return 0;
}