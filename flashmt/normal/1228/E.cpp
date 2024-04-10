#include <bits/stdc++.h>
using namespace std;
const int BASE = 1e9 + 7;

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
  int n, k;
  cin >> n >> k;

  long long ans = 0, c = 1;
  for (int i = 0; i <= n; i++)
  {
    if (i)
      c = c * (n - i + 1) % BASE * power(i, BASE - 2) % BASE;
    long long ways = (power(k, n - i) - power(k - 1, n - i) + BASE) % BASE * power(k - 1, i) % BASE;
    ways = power(ways, n) * c % BASE;
    if (i % 2) ans = (ans - ways + BASE) % BASE;
    else ans = (ans + ways) % BASE;
  }

  cout << ans << endl;
}