#include <bits/stdc++.h>
using namespace std;
const double EPS = 1e-8, oo = 1e18, PI = acos(-1.0);

struct point
{
	double x, y;
	point(double _x, double _y) : x(_x), y(_y) {}
};

struct line
{
	double a, b, c;
	
	line(double _a, double _b, double _c) : a(_a), b(_b), c(_c) {}
	
	line(point u, point v)
	{
		a = u.y - v.y;
		b = v.x - u.x;
		c = - a * u.x - b * u.y;
	}
	
	point intersect(line u)
	{
		if (isParallel(u)) return point(oo, oo);
		double dx = - c * u.b + b * u.c;
		double dy = - a * u.c + c * u.a;
		double d = a * u.b - b * u.a;
		return point(dx / d, dy / d);
	}
	
	int isParallel(line u)
	{
		return fabs(a * u.b - b * u.a) < EPS;
	}
};

int main()
{
  ios::sync_with_stdio(0);
  int x, y, xx, yy, n, a, b, c;
  cin >> x >> y >> xx >> yy >> n;
  line l(point(x, y), point(xx, yy));
  
  int ans = 0;
  for (int i = 0; i < n; i++)
  {
    cin >> a >> b >> c;
    line road(a, b, c);
    point p = road.intersect(l);
    if (p.x > oo / 2) continue;
    ans += (p.x - x) * (p.x - xx) <= 0 && (p.y - y) * (p.y - yy) <= 0;
  }
  
  cout << ans << endl;
}