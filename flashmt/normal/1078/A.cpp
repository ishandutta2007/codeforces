#include <bits/stdc++.h>
using namespace std;

struct Point {
    double x, y;
    Point() { x = y = 0.0; }
    Point(double x, double y) : x(x), y(y) {}

    Point operator - (const Point& a) const { return Point(x-a.x, y-a.y); }

    double operator * (const Point& a) const { return x*a.x + y*a.y; } // dot product

    double norm() { return x*x + y*y; }

    double len() { return sqrt(norm()); }
};

int main()
{
  long long a, b, c, x0, y0, x1, y1;
  cin >> a >> b >> c >> x0 >> y0 >> x1 >> y1;
  Point u(x0, y0), v(x1, y1);

  vector<Point> fromU, fromV;
  if (b)
  {
    fromU.push_back(Point(x0, (-1. * c - a * x0) / b));
    fromV.push_back(Point(x1, (-1. * c - a * x1) / b));
  }
  if (a)
  {
    fromU.push_back(Point((-1. * c - b * y0) / a, y0));
    fromV.push_back(Point((-1. * c - b * y1) / a, y1));
  }

  double ans = abs(x0 - x1) + abs(y0 - y1);
  for (auto uu : fromU)
    for (auto vv : fromV)
      ans = min(ans, (u - uu).len() + (uu - vv).len() + (vv - v).len());
  cout << fixed << setprecision(12) << ans << endl;
}