#include <bits/stdc++.h>
using namespace std;

long long getDivisor(long long p, long long q, int prime)
{
  int degP = 0, degQ = 0;
  while (p % prime == 0)
  {
    degP++;
    p /= prime;
  }
  while (q % prime == 0)
  {
    degQ++;
    q /= prime;
  }

  long long res = 1;
  for (int i = 0; i < degP - degQ + 1; i++)
    res *= prime;
  return res;
}

int main()
{
  int test;
  cin >> test;
  while (test--)
  {
    long long p, q;
    cin >> p >> q;
    if (p % q) cout << p << endl;
    else
    {
      long long ans = p, tmp = q;
      for (int i = 2; i * i <= tmp; i++)
        if (tmp % i == 0)
        {
          while (tmp % i == 0)
            tmp /= i;
          ans = min(ans, getDivisor(p, q, i));
        }

      if (tmp > 1)
        ans = min(ans, getDivisor(p, q, tmp));

      cout << p / ans << endl;
    }
  }
}