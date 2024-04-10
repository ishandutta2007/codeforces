#include <bits/stdc++.h>
using namespace std;
const int MAX_PRIME = 9;

int n, a[100100];

vector<int> factorize(int n)
{
  vector<int> primes;
  for (int i = 2; i * i <= n; i++)
    if (n % i == 0)
    {
      while (n % i == 0)
        n /= i;
      primes.push_back(i);
    }
  if (n > 1)
    primes.push_back(n);
  return primes;
}

void solve(int id)
{
  vector<int> ans(n, 0), flag(n, 0);
  ans[id] = flag[id] = 1;
  vector<int> p[2] = {factorize(a[0]), factorize(a[id])};
  vector<int> candidates;
  for (int i = 0; i < 2; i++)
    for (auto prime : p[i])
      for (int j = 1; j < n; j++)
        if (!flag[j] && a[j] % prime)
        {
          candidates.push_back(j);
          flag[j] = 1;
          break;
        }

  int sz = candidates.size();
  for (int mask = 0; mask < 1 << sz; mask++)
  {
    int x = a[0], y = a[id];
    for (int i = 0; i < sz; i++)
      if (mask >> i & 1) y = __gcd(y, a[candidates[i]]);
      else x = __gcd(x, a[candidates[i]]);

    if (x == 1 && y == 1)
    {
      cout << "YES" << endl;
      for (int i = 0; i < sz; i++)
        ans[candidates[i]] = mask >> i & 1;
      for (int i = 0; i < n; i++)
        cout << ans[i] + 1 << ' ';
      exit(0);
    }
  }
}

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n;
  for (int i = 0; i < n; i++)
    cin >> a[i];

  for (int j = 1; j < min(n, MAX_PRIME + 1); j++)
    solve(j);

  cout << "NO" << endl;
}