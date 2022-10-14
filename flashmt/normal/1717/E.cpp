#include <bits/stdc++.h>
#ifdef LOCAL
#include "Debug.h"
#else
#define debug(...) 42
#endif
using namespace std;
const int BASE = 1e9 + 7;

int main()
{
  int n;
  cin >> n;

  vector<long long> f(n + 1);
  for (int i = 2; i <= n; i++)
  {
    f[i] = i - 1;
    for (int j = 2; j * j <= i; j++)
      if (i % j == 0)
      {
        f[i] -= f[i / j];
        if (j * j < i)
          f[i] -= f[j];
      }
  }

  long long ans = 0;

  auto calc = [&](int sumAB, int gcdAB, int c)
  {
    return 1LL * c / gcd(c, gcdAB) * gcdAB % BASE * f[sumAB / gcdAB] % BASE;
  };

  for (int sumAB = 1; sumAB < n; sumAB++)
    for (int i = 1; i * i <= sumAB; i++)
      if (sumAB % i == 0)
      {
        ans = (ans + calc(sumAB, i, n - sumAB)) % BASE;
        if (i * i < sumAB)
          ans = (ans + calc(sumAB, sumAB / i, n - sumAB)) % BASE;
      }

  cout << ans << endl;
}