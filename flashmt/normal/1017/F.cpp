#include <bits/stdc++.h>
using namespace std;
const int K = 20000;

int main()
{
  int n;
  unsigned int A, B, C, D;
  cin >> n >> A >> B >> C >> D;

  vector<int> primes;
  for (int i = 2; i < K; i++)
  {
    int isPrime = 1;
    for (int j = 2; j * j <= i; j++)
      if (i % j == 0)
        isPrime = 0;
    if (isPrime)
      primes.push_back(i);
  }

  auto get = [&](unsigned int i)
  {
    unsigned int res = 0, x = n;
    while (x >= i)
    {
      x /= i;
      res += x;
    }
    return res * (A * i * i * i + B * i * i + C * i + D);
  };

  vector<int> sieve(K);
  unsigned int ans = 0;
  for (int p : primes)
    ans += get(p);
  for (int i = 1; i * K <= n; i++)
  {
    int from = i * K, to = min(i * K + K - 1, n);
    for (int p : primes)
      for (int j = (from + p - 1) / p; j <= to / p; j++)
        sieve[j * p % K] = i;
    for (int j = from; j <= to; j++)
      if (sieve[j % K] != i)
        ans += get(j);
  }
  cout << ans << endl;
}