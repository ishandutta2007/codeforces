#include <bits/stdc++.h>
#ifdef LOCAL
#include "Debug.h"
#endif
using namespace std;

int main()
{
  vector<pair<int, int>> a;
  vector<int> allX, allY;
  for (int i = 0; i < 3; i++)
  {
    int x, y;
    cin >> x >> y;
    a.push_back({x, y});
    allX.push_back(x);
    allY.push_back(y);
  }

  sort(begin(allX), end(allX));
  sort(begin(allY), end(allY));
  int mx = allX[1], my = allY[1];
  vector<tuple<int, int, int, int>> segs;
  for (auto [x, y] : a)
  {
    if (x != mx)
      segs.push_back({x, y, mx, y});
    if (y != my)
      segs.push_back({mx, y, mx, my});
  }

  cout << size(segs) << endl;
  for (auto [x, y, xx, yy] : segs)
    cout << x << ' ' << y << ' ' << xx << ' ' << yy << endl;
}