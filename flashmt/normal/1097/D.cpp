#include <bits/stdc++.h>
using namespace std;
const int BASE = 1e9 + 7;

long long inv[60];

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

vector<pair<long long, int>> factorize(long long n)
{
  vector<pair<long long, int>> p;
  for (int i = 2; 1LL * i * i <= n; i++)
    if (n % i == 0)
    {
      int cnt = 0;
      while (n % i == 0)
      {
        n /= i;
        cnt++;
      }
      p.push_back({i, cnt});
    }
  if (n > 1)
    p.push_back({n, 1});
  return p;
}

long long calc(long long x, int y, int k)
{
  vector<long long> prob(y + 1, 0);
  prob[y] = 1;
  while (k--)
  {
    vector<long long> newProb(y + 1, 0);
    for (int i = 0; i <= y; i++)
      for (int j = 0; j <= i; j++)
        newProb[j] = (newProb[j] + prob[i] * inv[i + 1]) % BASE;
    prob = newProb;
  }

  long long res = 0, v = 1;
  for (int i = 0; i <= y; i++)
  {
    res = (res + v * prob[i]) % BASE;
    v = v * x % BASE;
  }
  return res;
}

int main()
{
  long long n;
  int k;
  cin >> n >> k;
  auto p = factorize(n);

  for (int i = 0; i < 60; i++)
    inv[i] = power(i, BASE - 2);

  long long ans = 1;
  for (auto u : p)
    ans = ans * calc(u.first, u.second, k) % BASE;
  cout << ans << endl;
}