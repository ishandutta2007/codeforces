// Awwawa! Dis cold yis ratten buy tEMMIE!
#include <bits/stdc++.h>
#define ll long long
#define maxn 1000005 /*rem*/
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

ll inv2 = ksm(2, mod - 2);
ll inv6 = ksm(6, mod - 2);
ll comb(ll x, int y) {
  ll ans = 1;
  for (int i = 0; i < y; i++)
    ans = ans * (x - i) % mod;
  if (y == 2)
    return ans * inv2 % mod;
  else if (y == 3)
    return ans * inv6 % mod;
  return -1;
}

int n;
ll dp[maxn], twobr[maxn], way3[maxn], stwobr[maxn];
ll solve(int n) {
  ll ans = 0;
  for (int i = 1; i < n; i++)
    ans = (ans + twobr[i] * stwobr[n - 1 - i]) % mod;
  return ans;
}

int main() {
  scanf("%d", &n);
  dp[0] = 1;
  twobr[0] = 1;
  way3[0] = 1;
  for (int i = 1; i <= n; i++) {
    dp[i] = comb(dp[i - 1] + 2, 2);
    twobr[i] = comb(dp[i - 1] + 1, 2);
    way3[i] = comb(dp[i - 1] + 3, 3);
  }
  for (int i = 1; i <= n; i++) {
    stwobr[i] = twobr[i];
  }
  for (int i = n; i >= 2; i--) {
    twobr[i] = (twobr[i] - twobr[i - 1] + mod) % mod;
  }
  ll ans = (solve(n) + 2 * (way3[n] - way3[n - 1]) - 1) % mod;
  if (ans < 0)
    ans = ans + mod;
  printf("%lld\n", ans);
}