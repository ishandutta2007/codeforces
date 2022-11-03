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
const int N = 1e2 + 10;
const double eps = 1e-8;

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
int n;
Point vp[N];
pair<double, Point> solve(double x = 0, double y = 0, double z = 0)
{
	double maxv = 0;
	Point p(x, y, z);
	for (int i = 1; i <= n; i++)
	{
		maxv = max(maxv, (p - vp[i]).norm());
	}
	return { maxv,p };
}
pair<double, Point> solvez(double x = 0, double y = 0, double z = 0)
{
	double l = -1e4;
	double r = 1e4;
	pair<double, Point> ans = { 1e18,Point() };
	int cnt = 100;
	while (cnt--)
	{
		double mid1 = (l + r) / 2;
		double mid2 = (mid1 + r) / 2;
		auto res1 = solve(x, y, mid1);
		auto res2 = solve(x, y, mid2);
		if (res1 > res2) 
			l = mid1, ans = res2;
		else 
			r = mid2, ans = res1;
	}
	return ans;
}
pair<double, Point> solvey(double x = 0, double y = 0, double z = 0)
{
	double l = -1e4;
	double r = 1e4;
	pair<double, Point> ans = { 1e18,Point() };
	int cnt = 50;
	while (cnt--)
	{
		double mid1 = (l + r) / 2;
		double mid2 = (mid1 + r) / 2;
		auto res1 = solvez(x, mid1);
		auto res2 = solvez(x, mid2);
		if (res1 > res2)
			l = mid1, ans = res2;
		else 
			r = mid2, ans = res1;
	}
	return ans;
}
pair<double, Point> solvex(double x = 0, double y = 0, double z = 0)
{
	double l = -1e4;
	double r = 1e4;
	pair<double, Point> ans = { 1e18,Point() };
	int cnt = 50;
	while (cnt--)
	{
		double mid1 = (l + r) / 2;
		double mid2 = (mid1 + r) / 2;
		auto res1 = solvey(mid1);
		auto res2 = solvey(mid2);
		if (res1 > res2) 
			l = mid1, ans = res2;
		else 
			r = mid2, ans = res1;
	}
	return ans;
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
		vp[i].init();
	auto p = solvex().second;
	printf("%.10f %.10f %.10f\n", p.x, p.y, p.z);
	return 0;
}