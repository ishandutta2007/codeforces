// Awwawa! Dis cold yis ratten buy tEMMIE!
#include <bits/stdc++.h>
#define ll long long
#define maxn 200005 /*rem*/
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

int n, a[20];
ll dp[maxn], win[20][20];

int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    scanf("%d", a + i);
  }
  ll ans = 0;
  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++)
      if (i != j) {
        int d = ksm(a[i] + a[j], mod - 2);
        win[i][j] = (ll)a[i] * d % mod;
      }
  for (int s = 1; s < (1 << n); s++) {
    dp[s] = 1;

    for (int t = (s - 1) & s; t; t = (t - 1) & s) {
      ll w2 = 1;
      for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
          if ((t & (1 << i)) && (s & (1 << j)) && (t & (1 << j)) == 0) {
            w2 = w2 * win[i][j] % mod;
          }
      dp[s] = (dp[s] - dp[t] * w2) % mod;
    }

    ll w = dp[s];
    for (int i = 0; i < n; i++)
      for (int j = 0; j < n; j++)
        if ((s & (1 << i)) && (s & (1 << j)) == 0)
          w = w * win[i][j] % mod;
    ans = (ans + __builtin_popcount(s) * w) % mod;
  }
  if (ans < 0)
    ans += mod;
  printf("%lld\n", ans);
}