#include <bits/stdc++.h>
using namespace std;
const long long oo = 1LL << 60;

vector<long long> factorize(long long x)
{
  vector<long long> primes;
  for (int i = 2; 1LL * i * i <= x; i++)
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

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n, a[1000100];
  long long sum = 0;
  cin >> n;
  for (int i = 0; i < n; i++)
  {
    cin >> a[i];
    sum += a[i];
  }

  auto primes = factorize(sum);
  if (primes.empty()) // BRUH
  {
    cout << -1 << endl;
    return 0;
  }

  long long ans = oo;
  for (auto p : primes)
  {
    long long cost = 0, carry = 0, need = 0;
    int to = -1;
    for (int i = 0; i < n; i++)
    {
      if (to < 0)
      {
        cost += carry;
        carry += a[i];
        carry %= p;
      }
      else
      {
        cost += min(a[i] * 1LL, need) * (i - to);
        if (need > a[i]) need -= a[i];
        else
        {
          carry = (a[i] - need) % p;
          need = 0;
          to = -1;
        }
      }

      if (carry >= (p + 1) / 2)
      {
        to = i;
        need = p - carry;
        carry = 0;
      }
    }
    ans = min(ans, cost);
  }

  cout << ans << endl;
}