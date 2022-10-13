#include <bits/stdc++.h>
using namespace std;
const int oo = 27081993;

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n;
  cin >> n;
  vector<long long> a(n);
  for (auto &x : a)
    cin >> x;

  vector<int> sieve(1e6 + 1), primes;
  for (int i = 2; i <= 1e6; i++)
    if (!sieve[i])
    {
      primes.push_back(i);
      if (i <= 1000)
        for (int j = i * i; j <= 1e6; j += i)
          sieve[j] = 1;
    }

  int ans = oo;
  set<long long> checked;
  auto check = [&](long long d)
  {
    if (checked.count(d))
      return;
    checked.insert(d);

    long long res = 0;
    for (auto u : a)
    {
      if (u < d) res += d - u;
      else res += min(u % d, d - u % d);
      if (res >= ans)
        return;
    }
    ans = res;
  };

  check(2);
  mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
  while (clock() / CLOCKS_PER_SEC <= 0.8)
  {
    int x = rng() % n;
    for (long long v = a[x] - 1; v <= a[x] + 1; v++)
      if (v > 1)
      {
        long long cur = v;
        for (int p : primes)
          if (cur % p == 0)
          {
            check(p);
            while (cur % p == 0)
              cur /= p;
          }
        if (cur > 1)
          check(cur);
      }
  }

  cout << ans << endl;
}