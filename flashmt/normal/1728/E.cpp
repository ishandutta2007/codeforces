#include <bits/stdc++.h>
#ifdef LOCAL
#include "Debug.h"
#else
#define debug(...) 42
#endif
using namespace std;

int gcd(int a, int b, long long &x, long long &y)
{
  if (b == 0)
  {
    x = 1;
    y = 0;
    return a;
  }
  long long x1, y1;
  int d = gcd(b, a % b, x1, y1);
  x = y1;
  y = x1 - y1 * (a / b);
  return d;
}

// a * x0 + b * y0 = c
// x = x0 + k * (b / g), y = y0 - k * (a / g)
int diophantine(int a, int b, int c, long long &x0, long long &y0, long long &g)
{
  g = gcd(abs(a), abs(b), x0, y0);
  if (c % g)
    return 0;
  x0 *= c / g;
  y0 *= c / g;
  if (a < 0)
    x0 = -x0;
  if (b < 0)
    y0 = -y0;
  return 1;
}

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n;
  cin >> n;
  vector<int> a;
  vector<long long> f(n + 1);
  for (int i = 0; i < n; i++)
  {
    int x, y;
    cin >> x >> y;
    f[0] += x;
    a.push_back(y - x);
  }
  sort(rbegin(a), rend(a));
  int maxGain = 0;
  for (int i = 0; i < n; i++)
  {
    f[i + 1] = f[i] + a[i];
    if (f[i + 1] > f[i])
      maxGain = i + 1;
  }

  int m;
  cin >> m;
  for (int i = 0; i < m; i++)
  {
    long long u, v;
    cin >> u >> v;
    long long x, y, g;
    if (!diophantine(u, v, n, x, y, g))
    {
      cout << -1 << '\n';
      continue;
    }

    long long uu = u / g, vv = v / g;
    long long maxY;
    if (x >= 0) maxY = y + (x / vv) * uu;
    else maxY = y - ((-x + vv - 1) / vv) * uu;

    if (maxY < 0)
    {
      cout << -1 << '\n';
      continue;
    }

    int minY = maxY % uu * v;
    maxY *= v;
    long long ans = f[minY];
    long long lcm = uu * v;
    if (lcm <= n && minY <= maxGain)
    {
      long long step = (maxGain - minY) / lcm;
      for (auto j : {step, step + 1})
      {
        long long cand = minY + j * lcm;
        if (cand <= n)
          ans = max(ans, f[cand]);
      }
    }
    cout << ans << '\n';
  }
}