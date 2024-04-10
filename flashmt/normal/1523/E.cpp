#include <bits/stdc++.h>
using namespace std;
const int BASE = 1e9 + 7;
const int N = 100100;

int n, k;
long long fact[N], invFact[N];
long long f[N];

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
  for (int i = 0; i < N; i++)
  {
    fact[i] = i ? fact[i - 1] * i % BASE : 1;
    invFact[i] = power(fact[i], BASE - 2);
  }

  int test;
  cin >> test;
  while (test--)
  {
    cin >> n >> k;
    int step = 2;
    memset(f, 0, sizeof f);
    f[1] = n;
    long long ans = 0;
    while (1)
    {
      int j = n - (step - 1) * (k - 1);
      if (step > j) f[step] = 0;
      else f[step] = fact[j] * invFact[j - step] % BASE;
      long long ways = (f[step - 1] * (n - step + 1) % BASE - f[step] + BASE) % BASE;;
      ans = (ans + ways * fact[n - step] % BASE * step) % BASE;
      if (step > j)
        break;
      step++;
    }

    ans = ans * invFact[n] % BASE;
    cout << ans << endl;
  }
}