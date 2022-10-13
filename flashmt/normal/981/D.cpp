#include <bits/stdc++.h>
using namespace std;

int n, k;
long long a[55], f[55][55];

int isGood(long long target)
{
  memset(f, 0, sizeof f);
  f[0][0] = 1;
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= k; j++)
      for (int ii = 0; ii < i; ii++)
        f[i][j] |= f[ii][j - 1] && (((a[i] - a[ii]) & target) == target);
  return f[n][k];
}

int main()
{
  long long x;
  cin >> n >> k;
  for (int i = 1; i <= n; i++)
  {
    cin >> x;
    a[i] = a[i - 1] + x;
  }

  long long ans = 0;
  for (int bit = 60; bit >= 0; bit--)
  {
    ans |= 1LL << bit;
    if (!isGood(ans))
      ans ^= 1LL << bit;
  }
  cout << ans << endl;
}