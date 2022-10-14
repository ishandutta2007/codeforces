#include <bits/stdc++.h>
using namespace std;

int n, a[200200], b[200200];

vector<int> factorize(int x)
{
  vector<int> primes;
  for (int i = 2; i * i <= x; i++)
    if (x % i == 0)
    {
      primes.push_back(i);
      while (x % i == 0)
        x /= i;
    }
  if (x > 1)
    primes.push_back(x);
  return primes;
}

int isGood(int x)
{
  for (int i = 1; i < n; i++)
    if (a[i] % x && b[i] % x)
      return 0;
  return 1;
}

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  cin >> n;
  for (int i = 0; i < n; i++)
    cin >> a[i] >> b[i];

  auto primesA = factorize(a[0]);
  auto primesB = factorize(b[0]);
  for (auto p : primesB)
    primesA.push_back(p);

  for (int p : primesA)
    if (isGood(p))
    {
      cout << p << endl;
      return 0;
    }

  cout << -1 << endl;
}