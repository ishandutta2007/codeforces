// Awwawa! Dis cold yis ratten buy tEMMIE!
#include <bits/stdc++.h>
#define ll long long
#define maxn 205 /*rem*/
#define mod 1000000007
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

int n, g[maxn][maxn];
ll inv[maxn], prob[maxn][maxn];

int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= n; j++) {
      g[i][j] = n + 1;
      if (i == j)
        g[i][i] = 0;
    }
  for (int i = 1; i < n; i++) {
    int u, v;
    scanf("%d%d", &u, &v);
    g[u][v] = g[v][u] = 1;
  }
  for (int k = 1; k <= n; k++)
    for (int i = 1; i <= n; i++)
      for (int j = 1; j <= n; j++)
        g[i][j] = min(g[i][j], g[i][k] + g[k][j]);
  for (int i = 1; i <= n; i++)
    inv[i] = ksm(i, mod - 2);
  for (int i = 1; i <= n; i++)
    prob[i][0] = 1;
  for (int i = 1; i <= n; i++)
    prob[0][i] = 0;
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= n; j++)
      prob[i][j] = (prob[i - 1][j] + prob[i][j - 1]) * inv[2] % mod;

  ll ans = 0;
  for (int i = 1; i <= n; i++)
    for (int j = i + 1; j <= n; j++) {
      for (int k = 1; k <= n; k++) {
        int r = (g[i][k] - g[j][k] + g[i][j]) / 2;
        ans = (ans + prob[r][g[i][j] - r]) % mod;
      }
    }
  ans = ans * inv[n] % mod;
  printf("%lld\n", ans);
}