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
  int n;
  long long sum[200200] = {0};
  cin >> n;
  sum[0] = 1;
  for (int i = 1; i <= n; i++)
  {
    sum[i] = sum[i - 1];
    if (i >= 2)
      sum[i] = (sum[i] + sum[i - 2]) % BASE;
  }

  long long ans = sum[n];
  if (n >= 2)
    ans = (ans - sum[n - 2] + BASE) % BASE;
  ans = ans * power(power(2, n), BASE - 2) % BASE;
  cout << ans << endl;
}