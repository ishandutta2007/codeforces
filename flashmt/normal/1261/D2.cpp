#include <bits/stdc++.h>
using namespace std;
const int BASE = 998244353;

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

  long long fact[200200], invFact[200200];
  int n, m, a[200200];

  cin >> n >> m;
  if (m == 1)
  {
    cout << 0 << endl;
    return 0;
  }

  for (int i = 0; i < n; i++)
    cin >> a[i];

  int cntDif = 0;
  for (int i = 0; i < n; i++)
    cntDif += a[i] != a[(i + 1) % n];

  for (int i = 0; i <= n; i++)
  {
    fact[i] = i ? fact[i - 1] * i % BASE : 1;
    invFact[i] = power(fact[i], BASE - 2);
  }

  long long ans = 0;
  for (int i = 0; i * 2 <= cntDif; i++)
  {
    long long ways = fact[cntDif] * invFact[i] % BASE;
    ways = ways * invFact[i] % BASE * invFact[cntDif - i * 2] % BASE;
    ways = ways * power(m - 2, cntDif - i * 2) % BASE;
    ways = ways * power(m, n - cntDif) % BASE;
    ans = (ans + ways) % BASE;
  }

  long long total = power(m, n);
  ans = (total - ans + BASE) * power(2, BASE - 2) % BASE;
  cout << ans << endl;
}