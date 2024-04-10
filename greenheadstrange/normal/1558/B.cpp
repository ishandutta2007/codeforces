// Awwawa! Dis cold yis ratten buy tEMMIE!
#include <bits/stdc++.h>
#define ll long long
#define maxn 4000005 /*rem*/
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

int n, m;
int dp[maxn], s[maxn];
int main() {
  scanf("%d%d", &n, &m);
  int ps = 0;
  for (int j = 1; j <= n; j++) {
    ps = (ps + s[j]) % m;
    if (j == 1)
      dp[j] = 1;
    else
      dp[j] = ps;
    s[j] = (s[j] + dp[j]) % m;
    for (int k = j; k <= n; k += j)
      s[k] = (s[k] + dp[j]) % m;
    for (int k = j + 1; k <= n; k += (j + 1))
      s[k] = (s[k] - dp[j]) % m;
    ps = (ps + dp[j] * 2ll) % m;
  }
  if (dp[n] < 0)
    dp[n] += m;
  printf("%d\n", dp[n]);
}