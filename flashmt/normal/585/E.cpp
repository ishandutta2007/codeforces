#include <bits/stdc++.h>
using namespace std;
const int MAX = int(1e7);
const int BASE = int(1e9) + 7;

int a[500500], n, minDivisor[MAX + 10], cnt[MAX + 10];
long long nonEmptySubset[500500];
vector <int> primes[500500];

int main()
{
  ios::sync_with_stdio(0);
  cin >> n;
  for (int i = 0; i < n; i++)
    cin >> a[i];

  for (int i = 1; i <= MAX; i++)
    minDivisor[i] = i;

  for (int i = 2; i * i <= MAX; i++)
    if (minDivisor[i] == i)
      for (int j = i * i; j <= MAX; j += i)
        if (minDivisor[j] == j)
          minDivisor[j] = i;

  for (int i = 0; i <= n; i++)
    nonEmptySubset[i] = i ? (nonEmptySubset[i - 1] * 2 + 1) % BASE : 0;

  for (int i = 0; i < n; i++)
    for (int x = a[i]; x > 1; x /= minDivisor[x])
      if (primes[i].empty() || primes[i].back() != minDivisor[x])
        primes[i].push_back(minDivisor[x]);

  long long nonCoprimeSubset = 0;
  for (int i = 0; i < n; i++)
    for (int mask = 1; mask < 1 << primes[i].size(); mask++)
    {
      int divisor = 1, parity = 0;
      for (int j = 0; j < primes[i].size(); j++)
        if (mask >> j & 1)
        {
          parity ^= 1;
          divisor *= primes[i][j];
        }

      cnt[divisor]++;
      int ways = nonEmptySubset[cnt[divisor]] - nonEmptySubset[cnt[divisor] - 1];
      if (parity) nonCoprimeSubset += ways;
      else nonCoprimeSubset -= ways;
      nonCoprimeSubset = (nonCoprimeSubset + BASE) % BASE;
    }

  long long ans = nonCoprimeSubset * n % BASE;;
  for (int i = 0; i < n; i++)
    for (int mask = 1; mask < 1 << primes[i].size(); mask++)
    {
      int divisor = 1, parity = 0;
      for (int j = 0; j < primes[i].size(); j++)
        if (mask >> j & 1)
        {
          parity ^= 1;
          divisor *= primes[i][j];
        }

      if (parity) ans -= nonEmptySubset[cnt[divisor]];
      else ans += nonEmptySubset[cnt[divisor]];
      ans = (ans + BASE) % BASE;
    }

  cout << ans << endl;
}