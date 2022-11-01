// July 31, 2020
// https://codeforces.com/contest/1388/problem/C

/*

*/


#include <bits/stdc++.h>

using namespace std;


const int N = 100005;

int n, m;
vector<vector<int>> g;
int a[N];
int h[N];

int pv[N];
int sum[N];
int happy[N];
int child_sum[N];

void dfs(int v, int p) {
  pv[v] = p;
  sum[v] = a[v];
  for (int u : g[v]) {
    if (u == p) {
      continue;
    }
    dfs(u, v);
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
  
  
  int tt;
  cin >> tt;
  while (tt--) {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
      cin >> a[i];
    }
    for (int i = 0; i < n; i++) {
      cin >> h[i];
    }
    g.clear();
    g.resize(n);
    for (int i = 0; i < n - 1; i++) {
      int u, v;
      cin >> u >> v;
      u--; v--;
      g[u].push_back(v);
      g[v].push_back(u);
    }
    dfs(0, -1);
    bool ok = true;
    fill(child_sum, child_sum + n, 0);
    for (int i = 0; i < n; i++) {
      if ((sum[i] + h[i]) % 2 != 0) {
        ok = false;
      }
      happy[i] = (sum[i] + h[i]) / 2;
      if (happy[i] < 0 || happy[i] > sum[i]) {
        ok = false;
      }
      if (pv[i] != -1) {
        child_sum[pv[i]] += happy[i];
      }
    }
    for (int i = 0; i < n; i++) {
      if (child_sum[i] > happy[i]) {
        ok = false;
      }
    }
    cout << (ok ? "yes" : "no") << '\n';
  }
  
  
  return 0;
}