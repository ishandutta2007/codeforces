#include <bits/stdc++.h>
using namespace std;
const int BASE = int(1e9) + 7;

int n, a[555];
long long f[555][555], g[555][555];

long long dp(int l, int r);

long long dp2(int l, int r)
{
  if (l == r) return 1;
  long long &res = g[l][r];
  if (res >= 0) return res;
  res = dp(l, r);
  for (int i = l + 1; i <= r; i++)
    if (a[i] > a[l])
      res = (res + dp(l, i - 1) * dp2(i, r)) % BASE;
  return res;
}

long long dp(int l, int r)
{
  if (r - l <= 1) return 1;
  long long &res = f[l][r];
  if (res >= 0) return res;
  return res = dp2(l + 1, r);
}

int main()
{
  ios::sync_with_stdio(0);
  cin >> n;
  for (int i = 1; i <= n; i++) cin >> a[i];
  memset(f, -1, sizeof f);
  memset(g, -1, sizeof g);
  cout << dp(1, n) << endl;
}