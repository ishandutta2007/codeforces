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

int n, c[maxn], b[maxn], q, x, d[maxn], s[maxn];
int dp[110][10100];
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++)
    scanf("%d", c + i);
  for (int i = 1; i < n; i++)
    scanf("%d", b + i);
  scanf("%d", &q);
  scanf("%d", &x);
  s[1] = x;
  d[1] = x;
  for (int i = 2; i <= n; i++) {
    d[i] = d[i - 1] + b[i - 1];
    s[i] = s[i - 1] + d[i];
  }
  dp[0][0] = 1;
  int sc = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j <= sc; j++)
      for (int k = 0; k <= c[i + 1]; k++)
        if (j + k >= s[i + 1]) {
          dp[i + 1][j + k] = (dp[i + 1][j + k] + dp[i][j]) % mod;
        }
    sc += c[i + 1];
  }
  int ans = 0;
  for (int j = 0; j <= sc; j++)
    ans = (ans + dp[n][j]) % mod;
  printf("%d\n", ans);
}