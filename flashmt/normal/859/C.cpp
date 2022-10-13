#include <bits/stdc++.h>
using namespace std;

int n, a[55], f[55][2];

int dp(int i, int isBob)
{
  if (i == n)
    return 0;
  int &res = f[i][isBob];
  if (res >= 0)
    return res;
  if (isBob) res = max(dp(i + 1, 1), dp(i + 1, 0) + a[i]);
  else res = min(dp(i + 1, 1), dp(i + 1, 0) + a[i]);
  return res;
}

int main()
{
  int sum = 0;
  cin >> n;
  for (int i = 0; i < n; i++)
  {
    cin >> a[i];
    sum += a[i];
  }
  memset(f, -1, sizeof f);

  int bob = dp(0, 1);
  cout << sum - bob << ' ' << bob << endl;
}