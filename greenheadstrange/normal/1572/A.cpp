// Awwawa! Dis cold yis ratten buy tEMMIE!
#include <bits/stdc++.h>
#define ll long long
#define maxn 200005 /*rem*/
#define mod 998244353
#define db double
#define vi vector<int>
#define pb push_back
#define mp make_pair
#define pi pair<int, int>
#define fi first
#define se second

template <typename T> bool chkmax(T &x, T y) {
  return x < y ? x = y, true : false;
}
template <typename T> bool chkmin(T &x, T y) {
  return x > y ? x = y, true : false;
}

using namespace std;

ll ksm(ll a, ll b) {
  if (!b)
    return 1;
  ll ns = ksm(a, b >> 1);
  ns = ns * ns % mod;
  if (b & 1)
    ns = ns * a % mod;
  return ns;
}

int n, dp[maxn], deg[maxn];
vi adj[maxn];
void solve() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    adj[i].clear();
    deg[i] = 0;
  }
  for (int i = 1; i <= n; i++) {
    int k;
    scanf("%d", &k);
    for (int j = 0; j < k; j++) {
      int x;
      scanf("%d", &x);
      adj[x].push_back(i);
      deg[i]++;
    }
  }

  for (int i = 1; i <= n; i++)
    dp[i] = -1;
  queue<int> q;
  for (int i = 1; i <= n; i++)
    if (deg[i] == 0) {
      q.push(i);
      dp[i] = 1;
    }
  while (!q.empty()) {
    int u = q.front();
    q.pop();
    for (auto v : adj[u]) {
      --deg[v];
      dp[v] = max(dp[v], dp[u] + (u > v));
      if (deg[v] == 0) {
        q.push(v);
      }
    }
  }
  int ans = -1;
  for (int i = 1; i <= n; i++) {
    if (deg[i] != 0) {
      puts("-1");
      return;
    }
    ans = max(ans, dp[i]);
  }
  printf("%d\n", ans);
}

int main() {
  int T;
  scanf("%d", &T);
  for (int i = 0; i < T; i++)
    solve();
}