#include <bits/stdc++.h>
using namespace std;

#define int long long

const int ms = 1e5+5;
const int inf = 0x3f3f3f3f;
const int mod = 1e9+7;

int par[ms], v[ms];
vector<int> g[ms];
vector<pair<int, int>> gcs[ms];
int ans = 0;

int gcd(int a, int b) {
  while(b) a %= b, swap(a, b);
  return a;
}

void dfs(int u) {
  for(auto x : gcs[par[u]]) {
    int k = gcd(x.first, v[u]);
    int q = x.second;
    if(!gcs[u].empty() && gcs[u][gcs[u].size() - 1].first == k) {
      gcs[u][gcs[u].size() - 1].second += q;
    } else {
      gcs[u].emplace_back(k, q);
    }
  }
  if(!gcs[u].empty() && gcs[u][gcs[u].size() - 1].first == v[u]) {
    gcs[u][gcs[u].size() - 1].second++;
  } else {
    gcs[u].emplace_back(v[u], 1);
  }
  for(int v : g[u]) {
    if(v != par[u]) {
      par[v] = u;
      dfs(v);
    }
  }
}

main() {
  cin.tie(0); ios::sync_with_stdio(0);
  int n;
  cin >> n;
  for(int i = 1; i <= n; i++) {
    cin >> v[i];
  }
  for(int i = 1; i < n; i++) {
    int u, v;
    cin >> u >> v;
    g[u].push_back(v);
    g[v].push_back(u);
  }
  dfs(1);
  for(int i = 1; i <= n; i++) {
    for(auto x : gcs[i]) {
      // cout << i << ' ' << x.first << ' ' << x.second << endl;
      ans = (ans + x.first*x.second) % mod;
    }
  }
  cout << ans << endl;
}