#include <bits/stdc++.h>
using namespace std;
const int BASE = int(1e9) + 7;

long long c[1010][1010], fact[1010];

int main()
{
  int n, x, pos;
  cin >> n >> x >> pos;

  int l = 0, r = n, less = 0, greater = 0;
  while (l < r)
  {
    int m = (l + r) / 2;
    if (pos >= m)
    {
      less++;
      l = m + 1;
    }
    else
    {
      greater++;
      r = m;
    }
  }

  if (!less)
  {
    cout << 0 << endl;
    return 0;
  }

  for (int i = 0; i <= n; i++)
    fact[i] = i ? fact[i - 1] * i % BASE : 1;
  for (int i = 0; i <= n; i++)
    for (int j = 0; j <= i; j++)
      c[i][j] = j ? (c[i - 1][j] + c[i - 1][j - 1]) % BASE : 1;

  long long ans = c[x - 1][less - 1] * c[n - x][greater] % BASE;
  ans = ans * fact[less - 1] % BASE;
  ans = ans * fact[greater] % BASE;
  ans = ans * fact[n - less - greater] % BASE;
  cout << ans << endl;
}