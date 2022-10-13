#include <bits/stdc++.h>
using namespace std;
const int MAX = 1e7;

int d[MAX + 5], seen[MAX + 5], f[200200][22];

int normalize(int x)
{
  int res = 1;
  while (x)
  {
    if (!d[x])
    {
      res *= x;
      break;
    }

    int p = d[x], cnt = 0;
    while (x % p == 0)
    {
      x /= p;
      cnt ^= 1;
    }
    if (cnt)
      res *= p;
  }

  return res;
}

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  for (int i = 2; i * i <= MAX; i++)
    if (!d[i])
      for (int j = i * i; j <= MAX; j += i)
        d[j] = i;

  int test;
  cin >> test;
  while (test--)
  {
    int n, k;
    cin >> n >> k;
    vector<int> prev(n + 1, 0), a(n + 1);
    for (int i = 1; i <= n; i++)
    {
      cin >> a[i];
      a[i] = normalize(a[i]);
      prev[i] = seen[a[i]];
      seen[a[i]] = i;
    }

    set<int> prevs; // maintain k + 1 largest prev
    prevs.insert(0);
    for (int i = 1; i <= n; i++)
    {
      if (prev[i])
      {
        prevs.insert(prev[i]);
        if (prevs.size() > k + 1)
          prevs.erase(prevs.begin());
      }

      for (int j = 0; j <= k; j++)
        f[i][j] = i;

      int cost = int(prevs.size()) - 1;
      for (int ii : prevs)
      {
        for (int j = cost; j <= k; j++)
          f[i][j] = min(f[i][j], f[ii][j - cost] + 1);
        cost--;
      }
    }

    int ans = n;
    for (int i = 0; i <= k; i++)
      ans = min(ans, f[n][i]);

    cout << ans << endl;

    for (int i = 1; i <= n; i++)
      seen[a[i]] = 0;
  }
}