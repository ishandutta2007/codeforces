#include <bits/stdc++.h>
#ifdef LOCAL
#include "Debug.h"
#else
#define debug(...) 42
#endif
using namespace std;
const long long oo = 1LL << 60;

int main()
{
  int p1, p2, h, s;
  long long t1, t2;
  cin >> p1 >> t1 >> p2 >> t2 >> h >> s;

  vector<long long> cost(h + 1, oo);
  for (int i = 1; i <= h; i++)
    for (int j = 1; j <= h; j++)
    {
      int d = min(p1 * i + p2 * j - s * (i + j - 1), h);
      cost[d] = min(cost[d], max(i * t1, j * t2));
    }

  vector<long long> f(h + 1, oo);
  f[0] = 0;
  for (int i = 0; i < h; i++)
    for (int j = 1; j <= h; j++)
      f[min(i + j, h)] = min(f[min(i + j, h)], f[i] + cost[j]);

  long long ans = f[h];
  for (int i = 0; i < h; i++)
  {
    long long low = 1, high = max(t1, t2) * (h - i), res = high;
    while (low <= high)
    {
      long long mid = (low + high) / 2;
      long long damage = (p1 - s) * (mid / t1) + (p2 - s) * (mid / t2);
      if (damage >= h - i)
      {
        res = min(res, mid);
        high = mid - 1;
      }
      else low = mid + 1;
    }

    ans = min(ans, f[i] + res);
  }

  cout << ans << endl;
}