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
  int n, m;
  cin >> n >> m;
  vector<vector<int>> a(n);
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++)
    {
      int x;
      cin >> x;
      a[i].push_back(x - 1);
    }

  int c[22][22] = {0};
  for (int i = 0; i <= 20; i++)
    for (int j = 0; j <= i; j++)
      c[i][j] = j ? c[i - 1][j - 1] + c[i - 1][j] : 1;

  long long fact[22];
  for (int i = 0; i <= 20; i++)
    fact[i] = i ? fact[i - 1] * i % BASE : 1;

  long long ans = 0;
  for (int j = 0; j < m; j++)
  {
    vector<int> cnt(n + 1);
    for (int i = 0; i < n; i++)
      cnt[a[i][j]]++;

    int used = 0;
    long long bad = 1;
    for (int i = 0; i <= n; i++)
      if (used + cnt[i] > i)
      {
        bad = 0;
        break;
      }
      else
      {
        long long ways = c[i - used][cnt[i]] * fact[cnt[i]] % BASE;
        bad = bad * ways % BASE;
        used += cnt[i];
      }

    ans = (ans + fact[n] - bad + BASE) % BASE;
  }

  ans = ans * power(fact[n], BASE - 2) % BASE;
  cout << ans << endl;
}