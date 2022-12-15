#include <bits/stdc++.h>
using namespace std;

const int ms = 1e5+5;

vector<int> g[ms];
int par[ms];
double prob[ms];
double sum[ms];
double ans;

double dfs(int u, int p = -1) {
  sum[u] = 1.0;
  par[u] = p;
  for(int v : g[u]) {
    if(v != p) {
      dfs(v, u);
      sum[u] -= prob[v];
    }
  }
  ans += sum[u] * prob[u];
}

int main() {
  cin.tie(0); ios::sync_with_stdio(0);
  cout << fixed << setprecision(5);
	int n;
	cin >> n;
	for(int i = 0; i < n; i++) {
    cin >> prob[i];
    prob[i] = 1 - prob[i];
  }
  for(int i = 1; i < n; i++) {
    int u, v;
    cin >> u >> v;
    g[u].push_back(v);
    g[v].push_back(u);
  }
  dfs(0);
  int q;
  cin >> q;
  while(q--) {
    int u; double p;
    cin >> u >> p;
    p = 1 - p;
    ans += (p - prob[u]) * sum[u];
    if(~par[u]) {
      ans -= (p - prob[u]) * prob[par[u]];
      sum[par[u]] -= p - prob[u];
    }
    prob[u] = p;
    cout << ans << '\n';
  }
	return 0;
}