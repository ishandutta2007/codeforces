#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long ll;
typedef vector <int> vi;
typedef vector <vi> vvi;

int n;
vi sz;
vvi g;
vector <ll> d;

void dfs0(int v, int p = -1) {
  sz[v] = 1;
  for (int u : g[v]) {
    if (u == p)
      continue;
    d[u] = d[v] + 1;
    dfs0(u, v);
    sz[v] += sz[u];
  }
}

void dfs1(int v, int p = -1) {
  for (int u : g[v]) {
    if (u == p)
      continue;
    d[u] = d[v];
    d[u] -= sz[u];
    d[u] += n - sz[u];
    dfs1(u, v);
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> n;
  g.resize(n);
  for (int i = 1; i < n; i++) {
    int u, v;
    cin >> u >> v;
    u--, v--;
    g[u].push_back(v);
    g[v].push_back(u);
  }
  sz.resize(n), d.resize(n);
  d[0] = 1;
  dfs0(0);
  for (int i = 1; i < n; i++)
    d[0] += d[i];
  dfs1(0);
  cout << *max_element(d.begin(), d.end());
  return 0;
}