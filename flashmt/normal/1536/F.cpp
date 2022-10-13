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
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n;
  cin >> n;

  vector<long long> fact(n + 1), invFact(n + 1);
  for (int i = 0; i <= n; i++)
  {
    fact[i] = i ? fact[i - 1] * i % BASE : 1;
    invFact[i] = power(fact[i], BASE - 2);
  }

  auto c = [&](int n, int k)
  {
    return fact[n] * invFact[k] % BASE * invFact[n - k] % BASE;
  };

  long long ans = 0;
  for (int step = (n + 1) / 2; step <= n; step++)
    if (step % 2 == 0)
    {
      long long ways = c(step, n - step); // first cell is filled
      if (step < n)
        ways = (ways + c(step - 1, n - step - 1)) % BASE; // first cell is empty
      ans = (ans + ways * fact[step]) % BASE;
    }
  ans = ans * 2 % BASE;
  cout << ans << endl;
}