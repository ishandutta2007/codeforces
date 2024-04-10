#include <bits/stdc++.h>
using namespace std;

int d[1000100];

int normalize(int x)
{
  int res = 1;
  while (d[x])
  {
    int p = d[x], cnt = 0;
    while (x % p == 0)
    {
      x /= p;
      cnt ^= 1;
    }
    if (cnt)
      res *= p;
  }
  if (x > 1)
    res *= x;
  return res;
}

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  for (int i = 2; i <= 1000; i++)
    if (!d[i])
      for (int j = i * i; j <= 1000000; j += i)
        d[j] = i;

  int test;
  cin >> test;
  while (test--)
  {
    int n, x, maxCnt = 0;
    cin >> n;
    map<int, int> cnt;
    for (int i = 0; i < n; i++)
    {
      cin >> x;
      maxCnt = max(maxCnt, ++cnt[normalize(x)]);
    }

    int numEven = 0;
    for (auto [k, v] : cnt)
      if (k == 1 || v % 2 == 0)
        numEven += v;

    int q;
    cin >> q;
    while (q--)
    {
      long long w;
      cin >> w;
      if (!w) cout << maxCnt << '\n';
      else cout << max(maxCnt, numEven) << '\n';
    }
  }
}