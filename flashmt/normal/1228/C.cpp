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
  long long x, n;
  cin >> x >> n;

  vector<int> primes;
  for (int i = 2; i * i <= x; i++)
    if (x % i == 0)
    {
      primes.push_back(i);
      while (x % i == 0)
        x /= i;
    }
  if (x > 1)
    primes.push_back(x);

  long long ans = 1;
  for (int p : primes)
    if (n >= p)
    {
      long long x = p;
      int k = 1;
      while (n / x >= p)
      {
        x *= p;
        k++;
      }

      long long sum = 0;
      for (int i = k; i; i--)
      {
        long long cnt = n / x - sum;
        ans *= power(x % BASE, cnt);
        ans %= BASE;
        sum += cnt;
        x /= p;
      }
    }

  cout << ans << endl;
}