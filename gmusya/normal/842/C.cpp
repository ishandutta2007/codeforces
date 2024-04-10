#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

typedef vector <int> vi;
typedef vector <vi> vvi;

vi a;
vi ans;
vvi g;
vector <set <int>> dp0, dp1;

void dfs(int v, int p = -1) {
  if (p == -1) {
    dp0[v].insert(a[v]);
    dp1[v].insert(0);
  } else {
    dp1[v] = dp0[p];
    for (int x : dp1[p])
      dp1[v].insert(__gcd(a[v], x));
    for (int x : dp0[p])
      dp0[v].insert(__gcd(a[v], x));
  }
  ans[v] = max(*dp0[v].rbegin(), *dp1[v].rbegin());
  for (int u : g[v])
    if (u != p)
      dfs(u, v);
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
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
  dp0.resize(n), dp1.resize(n), ans.resize(n);
  dfs(0);
  for (int i = 0; i < n; i++)
    cout << ans[i] << ' ';
  return 0;
}