#include <bits/stdc++.h>
using namespace std;
const int MAX = 2e7;

int sieve[MAX + 5], cache[MAX + 5];

int calc(int x)
{
  if (cache[x])
    return cache[x];
  int &res = cache[x];
  res = 1;
  while (x > 1)
  {
    if (!sieve[x])
    {
      res *= 2;
      break;
    }

    int p = sieve[x];
    while (x % p == 0)
      x /= p;
    res *= 2;
  }

  return res;
}

int solve(int c, int d, int g)
{
  return (g + d) % c ? 0 : calc((g + d) / c);
}

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  for (int i = 2; i * i <= MAX; i++)
    if (!sieve[i])
      for (int j = i * i; j <= MAX; j += i)
        sieve[j] = i;

  int test;
  cin >> test;
  while (test--)
  {
    int c, d, x;
    cin >> c >> d >> x;

    long long ans = 0;
    for (int i = 1; i * i <= x; i++)
      if (x % i == 0)
      {
        ans += solve(c, d, i);
        if (i * i < x)
          ans += solve(c, d, x / i);
      }

    cout << ans << '\n';
  }
}