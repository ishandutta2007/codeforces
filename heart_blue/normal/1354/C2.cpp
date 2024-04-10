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
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
#define MEM(a,b) memset((a),(b),sizeof(a))
typedef long long LL;
typedef unsigned long long ULL;
const int N = 1e2 + 10;
const LL INF = 1e9 + 7;
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
	double x, y;
	Point(double x, double y);
	void init();
	bool operator == (const Point& p) const;
	bool operator < (const Point& p) const;
	Point operator + (const Point& p) const;
	Point operator -(const Point& p) const;
	Point operator *(const double a) const;
	Point operator /(const double a) const;
	Point rot(double theta) const;
	double angle() const;
	double norm2() const;
	double norm() const;
};
Point::Point(double x = 0, double y = 0)
{
	this->x = x;
	this->y = y;
}
void Point::init()
{
	scanf("%lf%lf", &x, &y);
}
bool Point::operator == (const Point& p) const
{
	return dcmp(x - p.x) == 0 && dcmp(y - p.y) == 0;
}
bool Point::operator < (const Point& p) const
{
	if (dcmp(x - p.x) != 0) return x < p.x;
	else return dcmp(y - p.y) < 0;
}
Point Point::operator + (const Point& p) const
{
	return Point(x + p.x, y + p.y);
}
Point Point::operator -(const Point& p) const
{
	return Point(x - p.x, y - p.y);
}
Point Point::operator *(const double a) const
{
	return Point(x * a, y * a);
}
Point Point::operator /(const double a) const
{
	return Point(x / a, y / a);
}
Point Point::rot(double theta) const
{
	return Point(x * cos(theta) - y * sin(theta), x * sin(theta) + y * cos(theta));
}
double Point::angle() const
{
	return atan2(y, x);
}
double Point::norm2() const
{
	return x * x + y * y;
}
double Point::norm() const
{
	return sqrt(x * x + y * y);
}
const double pi = acos(0.0) * 2;
double check(vector<int> &v, int n, double r, double theta)
{
	double lx = 0, rx = 0, ly = 0, ry = 0;
	for (auto& i : v)
	{
		double alpha = pi * i / n;
		Point p(cos(alpha) * r, sin(alpha) * r);
		p = p.rot(theta);
		lx = min(p.x, lx);
		rx = max(p.x, rx);
		ly = min(p.y, ly);
		ry = max(p.y, ry);
	}
	return max(rx - lx, ry - ly);
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int ncase;
	scanf("%d", &ncase);
	while (ncase--)
	{
		int n;
		cin >> n;
		vector<int> v;
		v.push_back(0);
		v.push_back(n);
		v.push_back(n / 2);
		v.push_back(3 * n / 2);
		for (int i = 0; i < 4; i++)
		{
			for (int j = -2; j <= 2; j++)
			{
				int x = (v[i] + j) % (2 * n);
				if (x < 0) x += 2 * n;
				v.push_back(x);
			}
		}
		sort(v.begin(), v.end());
		v.resize(unique(v.begin(), v.end()) - v.begin());
		double alpha = pi / n;
		double R = 0.5 / sin(alpha / 2);
		double l = 0, r = alpha / 2;
		int cnt = 200;
		while (cnt--)
		{
			double mid1 = (l + r) / 2;
			double mid2 = (mid1 + r) / 2;
			double res1 = check(v, n, R, mid1);
			double res2 = check(v, n, R, mid2);
			if (res1 > res2) l = mid1;
			else r = mid2;
		}
		printf("%.15f\n", check(v, n, R, r));
	}
	return 0;
}