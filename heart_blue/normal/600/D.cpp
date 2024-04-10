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
const int N = 1e6 + 10;
const double eps = 1e-8;
const double pi = 2 * acos(0.0);
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
	long double x, y;
	Point(long double x, long double y);
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
	long double norm() const;
};
Point::Point(long double x = 0, long double y = 0)
{
	this->x = x;
	this->y = y;
}
void Point::init()
{
	scanf("%Lf%Lf", &x, &y);
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
long double Point::norm() const
{
	return sqrt(x * x + y * y);
}

double cross(const Point& p1, const Point& p2)
{
	return p1.x * p2.y - p1.y * p2.x;
}
double dot(const Point& p1, const Point& p2)
{
	return p1.x * p2.x + p1.y * p2.y;
}
double angle(Point& p1, Point& p2)
{
	return acos(dot(p1, p2) / p1.norm() / p2.norm());
}
class Circle
{
public:
	Point p;
	long double r;
	void init()
	{
		p.init();
		scanf("%Lf", &r);
	}
	Circle(double x = 0, double y = 0, double r = 0)
	{
		p = Point(x, y);
		this->r = r;
	}
	Circle(const Point& p, double r)
	{
		this->p = p;
		this->r = r;
	}
	Point getPointFromPolar(double theta)
	{
		return Point(p.x + r * cos(theta), p.y + r * sin(theta));
	}
	bool contain(const Point& A)
	{
		double d = (p - A).norm();
		return dcmp(d - r) <= 0;
	}
	int relationWithCircle(const Circle& c)
	{
		double d = (c.p - p).norm();
		if (dcmp(d, r + c.r) > 0) return 2; // 
		if (dcmp(d, r + c.r) == 0) return 1; // 
		if (dcmp(d, abs(r - c.r)) == 0) return -1; // 
		if (dcmp(d, abs(r - c.r)) < 0) return -2; // 
		return 0; // 
	}
	long double getIntersectAreaWithCircle(const Circle& c)
	{
		int key = relationWithCircle(c);
		if (key > 0) return 0;
		if (key < 0) return min(getarea(), c.getarea());
		long double d = (c.p - p).norm();
		long double r1 = this->r;
		long double r2 = c.r;
		long double a = acos((r1 * r1 + d * d - r2 * r2) / (2 * r1 * d));
		long double b = acos((r2 * r2 + d * d - r1 * r1) / (2 * r2 * d));
		return (r1 * r1 * a + r2 * r2 * b - r1 * r1 * sin(a) * cos(a) - r2 * r2 * sin(b) * cos(b));
	}
	int getIntersectPointWithCircle(const Circle& c, vector<Point>& vp)
	{
		int ret = 2 - abs(relationWithCircle(c));
		if (ret == 0) return 0;
		double theta = (c.p - p).angle();
		if (ret == 1)
		{
			vp.push_back(getPointFromPolar(theta));
			return ret;
		}
		double d = (c.p - p).norm();
		double r1 = this->r;
		double r2 = c.r;
		double delta = acos((r1 * r1 + d * d - r2 * r2) / 2 / r1 / d);
		Point p1 = getPointFromPolar(theta - delta);
		Point p2 = getPointFromPolar(theta + delta);
		vp.push_back(p1);
		vp.push_back(p2);
		return ret;
	}
	double getarea(double theta = pi * 2) const
	{
		while (dcmp(theta, 2 * pi) > 0) theta -= 2 * pi;
		while (dcmp(theta) < 0) theta += 2 * pi;
		//if (dcmp(theta, pi) > 0) theta = 2 * pi - theta;
		return theta * r * r / 2;
	}
	int getIntersectArcWithCircle(const Circle& c, pair<double, double>& key)
	{
		int ret = 2 - abs(relationWithCircle(c));
		if (ret == 0) return 0;
		double theta = (c.p - p).angle();
		if (ret == 1)
		{
			double delta = 1e-7;
			key = { theta - delta,theta + delta };
			return ret;
		}
		double d = (c.p - p).norm();
		double r1 = this->r;
		double r2 = c.r;
		double delta = acos((r1 * r1 + d * d - r2 * r2) / 2 / r1 / d);
		if (dcmp(delta) == 0) delta = 1e-7;
		key = { theta - delta,theta + delta };
		return ret;
	}
	double getIntersectAreaWithTriangle(Point p1, Point p2)
	{
		Point p0(0, 0);
		p1 = p1 - p;
		p2 = p2 - p;
		double d1 = p1.norm();
		double d2 = p2.norm();
		double d = cross(p1, p2) / (p1 - p2).norm();
		d = abs(d);
		Point v = p2 - p1;
		swap(v.x, v.y);
		v.x = -v.x;
		if (dcmp(cross(p2 - p1, p2 - (v * d / v.norm()))) != 0)
			v = v * -1;
		int flag = 1;
		if (dcmp(cross(p1, p2)) < 0) flag = -1;
		if (dcmp(d1, d2) > 0) swap(d1, d2), swap(p1, p2);
		int o1 = dcmp(cross(v, p1));
		int o2 = dcmp(cross(v, p2));
		if (dcmp(d1, r) <= 0 && dcmp(d2, r) <= 0)
		{
			return abs(cross(p1, p2)) / 2 * flag;
		}
		if (dcmp(d1, r) >= 0 && dcmp(d2, r) >= 0)
		{
			if (dcmp(d, r) >= 0)
			{
				return getarea(p1.angle() - p2.angle()) * flag;
			}
			else if (o1 * o2 < 0)
			{
				double delta = acos(d / r);
				if (o1 < 0) swap(p1, p2);
				double theta = v.angle();
				double theta1 = p1.angle();
				double theta2 = p2.angle();
				Point p3 = getPointFromPolar(theta + delta) - p;
				Point p4 = getPointFromPolar(theta - delta) - p;
				double ans = abs(cross(p3, p4)) / 2 + getarea(theta1 - theta2 - 2 * delta);
				return ans * flag;
			}
			else
			{
				return getarea(p1.angle() - p2.angle()) * flag;
			}
		}
		double delta = acos(d / r);
		double theta = v.angle();
		double a = p2.angle();
		double alpha;
		Point pp;
		if (o2 >= 0)
		{
			pp = getPointFromPolar(theta + delta) - p;
			alpha = a - (theta + delta);
		}
		else
		{
			pp = getPointFromPolar(theta - delta) - p;
			alpha = a - (theta - delta);
		}
		double ans = abs(cross(p1, pp)) / 2 + getarea(alpha);
		return ans * flag;
	}
};


int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	Circle c1, c2;
	c1.init();
	c2.init();
	printf("%.20Lf\n", c1.getIntersectAreaWithCircle(c2));
	return 0;
}