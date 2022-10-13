#include <bits/stdc++.h>
using namespace std;

int main()
{
  ios::sync_with_stdio(0);
  int n, l[6], r[6];
  cin >> n;
  for (int i = 0; i < n; i++) cin >> l[i] >> r[i];
  
  double ans = 0;
  for (int win = 1; win <= 10000; win++)
  {
    for (int mask = 1; mask < 1 << n; mask++)
    {
      int ok = 1;
      double way0 = 1, way1 = 0;
      for (int i = 0; i < n; i++)
        if (mask >> i & 1)
        { 
          if (l[i] > win || r[i] < win) ok = 0;
        }
        else
        {
          double newWay0 = 0, newWay1 = 0;
          if (r[i] > win) 
            newWay1 += way0 * (r[i] - max(l[i], win + 1) + 1);
          if (l[i] < win) 
          {
            newWay0 += way0 * (min(r[i], win - 1) - l[i] + 1);
            newWay1 += way1 * (min(r[i], win - 1) - l[i] + 1);
          }
          way0 = newWay0;
          way1 = newWay1;
        }
      
      if (!ok) continue;
      ans += way1 * win;
      if (__builtin_popcount(mask) > 1) ans += way0 * win;
    }
  }
  
  for (int i = 0; i < n; i++) ans /= (r[i] - l[i] + 1);
  cout << fixed << setprecision(12) << ans << endl;
}