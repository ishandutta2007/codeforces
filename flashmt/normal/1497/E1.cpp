#include <bits/stdc++.h>
using namespace std;
const int MAX = 1e7;

int d[MAX + 5], seen[MAX + 5], a[200200];

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
    int ans = 1, bound = 1;
    for (int i = 1; i <= n; i++)
    {
      cin >> a[i];
      a[i] = normalize(a[i]);
      if (seen[a[i]] >= bound)
      {
        ans++;
        bound = i;
      }
      seen[a[i]] = i;
    }

    cout << ans << endl;

    for (int i = 1; i <= n; i++)
      seen[a[i]] = 0;
  }
}