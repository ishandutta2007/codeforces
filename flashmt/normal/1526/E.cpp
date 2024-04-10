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
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n, k;
  cin >> n >> k;
  vector<int> a(n), rank(n + 1);
  for (int i = 0; i < n; i++)
  {
    cin >> a[i];
    rank[a[i]] = i;
  }
  rank[n] = -1;

  int cnt = 1;
  for (int i = 0; i < n - 1; i++)
    if (rank[a[i] + 1] > rank[a[i + 1] + 1])
      cnt++;

  for (int i = 0; i <= max(n, k); i++)
  {
    fact[i] = i ? fact[i - 1] * i % BASE : 1;
    invFact[i] = power(fact[i], BASE - 2);
  }

  long long ans = 0;
  for (int i = cnt; i <= min(n, k); i++)
    ans = (ans + c(k, i) * c(n - cnt, i - cnt)) % BASE;
  cout << ans << endl;
}