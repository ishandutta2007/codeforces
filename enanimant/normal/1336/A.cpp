// April 15, 2020
// 

/*

*/


#include <bits/stdc++.h>

using namespace std;


const int N = 200005;

int n, k;
vector<int> g[N];

int sz[N];
int depth[N];
int sum[N];

void dfs(int v, int p) {
  sz[v] = 1;
  for (int u : g[v]) {
    if (u == p) {
      continue;
    }
    depth[u] = depth[v] + 1;
    dfs(u, v);
    sz[v] += sz[u];
  }
}

void dfs2(int v, int p) {
  for (int u : g[v]) {
    if (u == p) {
      continue;
    }
    dfs2(u, v);
    sum[v] += sum[u];
  }
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

#ifdef _DEBUG
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  freopen("debug_output.txt", "w", stderr);
#endif


  cin >> n >> k;
  for (int i = 0; i < n - 1; i++) {
    int u, v;
    cin >> u >> v;
    u--; v--;
    g[u].push_back(v);
    g[v].push_back(u);
  }
  depth[0] = 0;
  dfs(0, -1);
  vector<int> v;
  for (int i = 0; i < n; i++) {
    v.push_back(sz[i] - 1 - depth[i]);
  }
  sort(v.begin(), v.end());
  long long ans = 0;
  for (int i = k; i < n; i++) {
    ans += v[i];
  }
  cout << ans << '\n';


  return 0;
}