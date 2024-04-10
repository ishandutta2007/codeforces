#include <bits/stdc++.h>
using namespace std;
const int BASE = 998244353;

long long power(long long x, long long y)
{
  if (!y)
    return 1;
  long long res = power(x, y >> 1);
  res = res * res % BASE;
  if (y & 1)
    res = res * x % BASE;
  return res;
}

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n, a[300300];
  cin >> n;
  for (int i = 0; i < n * 2; i++)
    cin >> a[i];
  sort(a, a + n * 2);

  long long ways = 1;
  for (int i = 1; i <= n; i++)
    ways = ways * (n * 2 - i + 1) % BASE * power(i, BASE - 2) % BASE;

  long long ans = 0;
  for (int i = 0; i < n * 2; i++)
    if (i < n) ans = (ans - a[i] + BASE) % BASE;
    else ans = (ans + a[i]) % BASE;
  ans = ans * ways % BASE;

  cout << ans << endl;
}