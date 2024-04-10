#include <bits/stdc++.h>
using namespace std;
const int BASE = 998244353;

long long fact[200200], invFact[200200];

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

long long c(int n, int k)
{
  return fact[n] * invFact[k] % BASE * invFact[n - k] % BASE;
}

int main()
{
  for (int i = 0; i <= 200000; i++)
  {
    fact[i] = i ? fact[i - 1] * i % BASE : 1;
    invFact[i] = power(fact[i], BASE - 2);
  }

  int n, m;
  cin >> n >> m;
  long long ans = 0;
  if (n >= 3)
    ans = c(m, n - 1) * power(2, n - 3) % BASE * (n - 2) % BASE;
  cout << ans << endl;
}