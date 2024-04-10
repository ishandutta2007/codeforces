#include <bits/stdc++.h>
using namespace std;
const int BASE = 998244353;

int sieve[1000100], divisors[1000100];
long long f[1000100];

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n;
  cin >> n;

  for (int i = 2; i <= 1000; i++)
    if (!sieve[i])
      for (int j = i * i; j <= 1000000; j += i)
        sieve[j] = i;

  divisors[1] = 1;
  for (int i = 2; i <= 1000000; i++)
  {
    int x = i;
    divisors[i] = 1;
    while (sieve[x])
    {
      int p = sieve[x], cnt = 0;
      while (x % p == 0)
      {
        x /= p;
        cnt++;
      }
      divisors[i] *= cnt + 1;
    }
    if (x > 1)
      divisors[i] *= 2;
  }

  f[1] = 1;
  for (int i = 2; i <= n; i++)
    f[i] = (f[i - 1] * 2 + divisors[i]) % BASE;

  cout << (f[n] - f[n - 1] + BASE) % BASE << endl;
}