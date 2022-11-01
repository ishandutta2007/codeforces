#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long ll;

const ll MOD = 1e9 + 7;

vector <int> colour;
vector <vector <int>> g;
vector <ll> dp0, dp1;

void dfs(int v) {
  dp0[v] = 1;
  dp1[v] = 0;
  for (int u : g[v]) {
    dfs(u);
    dp1[v] = dp1[v] * dp0[u] % MOD;
    dp1[v] = (dp1[v] + dp0[v] * dp1[u]) % MOD;
    dp0[v] = (dp0[v] * dp0[u]) % MOD;
  }
  if (colour[v])
    dp1[v] = dp0[v];
  else
    dp0[v] = (dp1[v] + dp0[v]) % MOD;
}

int main() {
  int n;
  cin >> n;
  g.resize(n);
  for (int v = 1; v < n; v++) {
    int u;
    cin >> u;
    g[u].push_back(v);
  }
  colour.resize(n);
  for (int v = 0; v < n; v++)
    cin >> colour[v];
  dp0.resize(n), dp1.resize(n);
  dfs(0);
  cout << dp1[0] << '\n';
  return 0;
}