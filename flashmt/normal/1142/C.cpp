#include <bits/stdc++.h>
using namespace std;
const int oo = 27081993;

struct Point
{
  long long x, y;

  bool operator<(const Point &u)
  {
    return x < u.x || (x == u.x && y < u.y);
  }
};

int cw(Point a, Point b, Point c)
{
  return a.x * (b.y - c.y) + b.x * (c.y - a.y) + c.x * (a.y - b.y) < 0;
}

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n, x, y;
  vector<Point> a;
  cin >> n;
  for (int i = 0; i < n; i++)
  {
    cin >> x >> y;
    a.push_back({x, y - 1LL * x * x});
  }

  sort(a.begin(), a.end());

  Point p1 = a[0], p2 = a.back();
  vector<Point> up(1, p1);
  for (int i = 1; i < a.size(); i++)
    if (i == a.size() - 1 || cw(p1, a[i], p2))
    {
      while (up.size() > 1 && !cw(up[up.size() - 2], up[up.size() - 1], a[i]))
        up.pop_back();
      up.push_back(a[i]);
    }

  int ans = up.size() - 1;
  for (int i = 0; i + 1 < up.size(); i++)
    if (up[i].x == up[i + 1].x) ans--;
    else break;

  cout << ans << endl;
}