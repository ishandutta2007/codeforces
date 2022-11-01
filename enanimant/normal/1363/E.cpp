// May 31, 2020
// https://codeforces.com/contest/1363/problem/E

/*

*/


#include <bits/stdc++.h>

using namespace std;


const int INF = 1e9;
const int N = 200005;

int n;
vector<int> g[N];
int a[N], d[N], tgt[N];

int change[N][2];
long long ans = 0;

void dfs(int v, int p, int mn) {
  mn = min(mn, a[v]);
  change[v][0] = change[v][1] = 0;
  if (d[v] == 1 && tgt[v] == 0) {
    change[v][0]++;
  } else if (d[v] == 0 && tgt[v] == 1) {
    change[v][1]++;
  }
  for (int u : g[v]) {
    if (u == p) {
      continue;
    }
    dfs(u, v, mn);
    change[v][0] += change[u][0];
    change[v][1] += change[u][1];
  }
  int s = min(change[v][0], change[v][1]);
  ans += 2LL * s * mn;
  change[v][0] -= s;
  change[v][1] -= s;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  
#ifdef _DEBUG
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  freopen("debug_output.txt", "w", stderr);
#endif
  
  
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> a[i] >> d[i] >> tgt[i];
  }
  for (int i = 0; i < n - 1; i++) {
    int u, v;
    cin >> u >> v;
    u--; v--;
    g[u].push_back(v);
    g[v].push_back(u);
  }
  dfs(0, -1, INF);
  if (change[0][0] != 0 || change[0][1] != 0) {
    cout << "-1\n";
    return 0;
  }
  cout << ans << '\n';
  
  
  return 0;
}