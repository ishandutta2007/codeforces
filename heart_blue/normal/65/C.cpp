#include <cstdlib>
#include <cctype>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <vector>
#include <string>
#include <iostream>
#include <sstream>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <fstream>
#include <numeric>
#include <iomanip>
#include <bitset>
#include <list>
#include <stdexcept>
#include <functional>
#include <utility>
#include <ctime>
#include <cassert>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
#define MEM(a,b) memset((a),(b),sizeof(a))
const LL INF = 1e9 + 7;
const int N = 1e5 + 10;
const double eps = 1e-12;

inline int dcmp(const double x)
{
	if (abs(x) <= eps) return 0;
	else return x > 0 ? 1 : -1;
}
inline int dcmp(const double x, const double y)
{
	return dcmp(x - y);
}
class Point
{
public:
	double x, y, z;
	Point(double x, double y, double z);
	void init();
	bool operator == (const Point& p) const;
	bool operator < (const Point& p) const;
	Point operator + (const Point& p) const;
	Point operator -(const Point& p) const;
	Point operator *(const double a) const;
	Point operator /(const double a) const;
	double norm2() const;
	double norm() const;
	void output() const;
};
Point::Point(double x = 0, double y = 0, double z = 0)
{
	this->x = x;
	this->y = y;
	this->z = z;
}
void Point::init()
{
	scanf("%lf%lf%lf", &x, &y, &z);
}
bool Point::operator == (const Point& p) const
{
	return dcmp(x - p.x) == 0 && dcmp(y - p.y) == 0 && dcmp(z - p.z) == 0;
}
bool Point::operator < (const Point& p) const
{
	return false;
}
Point Point::operator + (const Point& p) const
{
	return Point(x + p.x, y + p.y, z + p.z);
}
Point Point::operator -(const Point& p) const
{
	return Point(x - p.x, y - p.y, z - p.z);
}
Point Point::operator *(const double a) const
{
	return Point(x * a, y * a, z * a);
}
Point Point::operator /(const double a) const
{
	return Point(x / a, y / a, z / a);
}
double Point::norm2() const
{
	return x * x + y * y + z * z;
}
double Point::norm() const
{
	return sqrt(x * x + y * y + z * z);
}
void Point::output() const
{
	printf("%.15f %.15f %.15f\n", x, y, z);
}
Point vp[N];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n;
	scanf("%d", &n);
	for (int i = 0; i <= n; i++)
	{
		vp[i].init();
	}
	double v1, v2;
	scanf("%lf%lf", &v1, &v2);
	Point p0;
	p0.init();
	double cur = 0;
	for (int i = 0; i < n; i++)
	{
		Point d = (vp[i + 1] - vp[i]);
		double l = 0, r = d.norm();
		d = d / d.norm();
		auto solve = [=](double x) -> double
		{
			Point pos = vp[i] + d * x;
			return max((p0 - pos).norm() / v1 -
				(cur + (pos - vp[i]).norm() / v2),
				0.0);
		};
		int cnt = 100;
		while (cnt--)
		{
			double mid1 = (l + r) / 2;
			double mid2 = (mid1 + r) / 2;
			double res1 = solve(mid1);
			double res2 = solve(mid2);
			if (abs(res1) < eps)
			{
				r = mid2;
				continue;
			}
			if (res1 > res2) l = mid1;
			else r = mid2;
		}
		if (solve(r) < eps)
		{
			puts("YES");
			Point pos = vp[i] + d * r;
			printf("%.15f\n", (p0 - pos).norm() / v1);
			pos.output();
			return 0;
		}
		cur += (vp[i + 1] - vp[i]).norm() / v2;
	}
	puts("NO");
	return 0;
}