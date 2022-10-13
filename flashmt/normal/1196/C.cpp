#include <bits/stdc++.h>
using namespace std;

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int q;
  cin >> q;
  while (q--)
  {
    int n, x, y, u, r, d, l;
    int xMin = -1e5, xMax = 1e5, yMin = -1e5, yMax = 1e5;
    cin >> n;
    while (n--)
    {
      cin >> x >> y >> u >> r >> d >> l;
      if (!u)
        xMin = max(xMin, x);
      if (!d)
        xMax = min(xMax, x);
      if (!r)
        yMax = min(yMax, y);
      if (!l)
        yMin = max(yMin, y);
    }
    if (xMin > xMax || yMin > yMax) cout << 0 << '\n';
    else cout << 1 << ' ' << xMin << ' ' << yMin << '\n';
  }
}