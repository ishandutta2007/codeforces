#include <bits/stdc++.h>
#ifdef LOCAL
#include "Debug.h"
#endif
using namespace std;
const int A = 1e6 + 5;
const int LOG = 20;

int sieve[A];

int factorize(int x)
{
  int res = 0;
  while (sieve[x])
  {
    int p = sieve[x], deg = 0;
    for (; x % p == 0; x /= p)
      deg++;
    res = gcd(res, deg);
  }
  if (x > 1)
    res = 1;
  return res;
}


int main()
{
  for (int i = 2; i * i < A; i++)
    if (!sieve[i])
      for (int j = i * i; j < A; j += i)
        sieve[j] = i;

  int n, m;
  cin >> n >> m;

  vector<bool> flag(LOG * A);
  vector<int> good(LOG);
  for (int i = 1; i < LOG; i++)
    for (int j = 1; j <= m; j++)
      if (!flag[i * j])
      {
        flag[i * j] = 1;
        good[i]++;
      }

  long long ans = 1;
  for (int i = 2; i <= n; i++)
    ans += good[factorize(i)];
  cout << ans << endl;
}