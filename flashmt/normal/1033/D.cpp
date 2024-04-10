#include <bits/stdc++.h>
using namespace std;
const int BASE = 998244353;

long long power(int x, int y)
{
  long long res = 1;
  while (y--)
    res *= x;
  return res;
}

int main()
{
  int n;
  cin >> n;
  map<long long, int> factors, special;
  while (n--)
  {
    long long x;
    cin >> x;

    int found = 0;
    for (int i = 4; i >= 2; i--)
    {
      int p = int(pow(x, 1. / i) + .5);
      if (power(p, i) == x)
      {
        factors[p] += i;
        found = 1;
        break;
      }
    }

    if (!found)
      special[x]++;
  }

  long long ans = 1;
  for (auto [x, cnt] : special)
  {
    int found = 0;
    for (auto [p, _] : factors)
      if (x % p == 0)
      {
        factors[p] += cnt;
        factors[x / p] += cnt;
        found = 1;
        break;
      }

    if (found)
      continue;

    for (auto [y, _] : special)
      if (y != x)
      {
        long long g = gcd(x, y);
        if (g > 1)
        {
          factors[g] += cnt;
          factors[x / g] += cnt;
          found = 1;
          break;
        }
      }

    if (!found)
      ans = ans * (cnt + 1) * (cnt + 1) % BASE;
  }

  for (auto [_, cnt] : factors)
    ans = ans * (cnt + 1) % BASE;

  cout << ans << endl;
}