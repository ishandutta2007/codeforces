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
#include <random>
#include <chrono>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
#define MEM(a,b) memset((a),(b),sizeof(a))
const LL INF = 1e9 + 7;
const int N = 1e6 + 10;

inline int sgn(LL x)
{
	if (x > 0) return 1;
	if (x < 0) return -1;
	return 0;
}
struct Point
{
	LL x, y;
	Point(LL x = 0, LL y = 0)
	{
		this->x = x;
		this->y = y;
	}
	void init()
	{
		scanf("%lld%lld", &x, &y);
	}
	bool operator == (const Point& p) const
	{
		return x == p.x && y == p.y;
	}
	bool operator < (const Point& p) const
	{
		if (x != p.x) return x < p.x;
		else return y < p.y;
	}
	Point operator + (const Point& p) const
	{
		return Point(x + p.x, y + p.y);
	}
	Point operator -(const Point& p) const
	{
		return Point(x - p.x, y - p.y);
	}
	Point operator *(const int a) const
	{
		return Point(x * a, y * a);
	}
	Point operator /(const int a) const
	{
		return Point(x / a, y / a);
	}
	LL norm2() const
	{
		return x * x + y * y;
	}
	double norm() const
	{
		return sqrt(1.0 * x * x + y * y);
	}
};
LL cross(const Point& p1, const Point& p2)
{
	return p1.x * p2.y - p1.y * p2.x;
}
LL dot(const Point& p1, const Point& p2)
{
	return p1.x * p2.x + p1.y * p2.y;
}
struct Segment
{
	Point p1, p2;
	Segment(Point& p1, Point& p2)
	{
		this->p1 = p1;
		this->p2 = p2;
	}
	Segment(LL x1 = 0, LL y1 = 0, LL x2 = 0, LL y2 = 0)
	{
		p1 = Point(x1, y1);
		p2 = Point(x2, y2);
	}
	void init()
	{
		p1.init();
		p2.init();
	}
	bool contain(const Point& p) const
	{
		if (p1 == p || p2 == p) return true;
		if (cross(p1 - p, p2 - p) != 0) return false;
		return (dot(p1 - p, p2 - p) < 0);
	}
};
bool isTwoSegmentIntersect(const Segment& s1, const Segment& s2)
{
	if (s1.contain(s2.p1) || s1.contain(s2.p2) || s2.contain(s1.p1) || s2.contain(s1.p2))
		return true;
	if (sgn(cross(s1.p2 - s1.p1, s2.p1 - s1.p2)) * sgn(cross(s1.p2 - s1.p1, s2.p2 - s1.p2)) == -1 &&
		sgn(cross(s2.p2 - s2.p1, s1.p1 - s2.p2)) * sgn(cross(s2.p2 - s2.p1, s1.p2 - s2.p2)) == -1)
		return true;
	return false;
}



class ConvexPolygon;
class Polygon
{
public:
	static Point p0;
	static bool cmp(const Point& p1, const Point& p2);
	vector<Point> vp;

	void init(int n);
	Point& operator[](int i);
	int size();
	Point& back();
	Point& front();
	vector<Point>::iterator begin();
	vector<Point>::iterator end();
	ConvexPolygon getConvex();
	LL getArea2();
	double getArea();
	double getPerimeter();
};
class ConvexPolygon : public Polygon
{
public:
	bool isPointInConvex(const Point& p);
	bool isPointOnConvex(const Point& p);
	bool contain(const Point& p);
	bool containPoint(const Point& p);
};
Point Polygon::p0(0, 0);
bool Polygon::cmp(const Point& p1, const Point& p2)
{
	LL o = cross(p1 - p0, p2 - p0);
	if (o != 0) return o > 0;
	return (p1 - p0).norm2() < (p2 - p0).norm2();
}
Point& Polygon::operator[](int i)
{
	return vp[i];
}
int Polygon::size()
{
	return vp.size();
}
Point& Polygon::back()
{
	return vp.back();
}
Point& Polygon::front()
{
	return vp.front();
}
vector<Point>::iterator Polygon::begin()
{
	return vp.begin();
}
vector<Point>::iterator Polygon::end()
{
	return vp.end();
}
void Polygon::init(int n)
{
	vp.clear();
	vp.resize(n);
	for (int i = 0; i < vp.size(); i++)
		vp[i].init();
}
ConvexPolygon Polygon::getConvex()
{
	sort(vp.begin(), vp.end());
	p0 = vp[0];
	sort(vp.begin() + 1, vp.end(), this->cmp);
	ConvexPolygon ret;
	vector<Point>& v = ret.vp;
	for (int i = 0; i < vp.size(); i++)
	{
		while (v.size() >= 2 && cross(v[v.size() - 1] - v[v.size() - 2], vp[i] - v[v.size() - 2]) < 0)
			v.pop_back();
		v.push_back(vp[i]);
	}
	return ret;
}
LL Polygon::getArea2()
{
	LL ans = cross(vp.back(), vp.front());
	for (int i = 0; i + 1 < vp.size(); i++)
		ans += cross(vp[i], vp[i + 1]);
	return ans;
}
double Polygon::getArea()
{
	return getArea2() / 2.0;
}
double Polygon::getPerimeter()
{
	double ans = (vp.back() - vp.front()).norm();
	for (int i = 0; i + 1 < vp.size(); i++)
		ans += (vp[i] - vp[i + 1]).norm();
	return ans;
}
bool ConvexPolygon::isPointInConvex(const Point& p)
{
	int cnt1 = 0, cnt2 = 0;
	for (int i = 0; i < vp.size(); i++)
	{
		Point& p1 = vp[i];
		int o = i + 1;
		if (o == vp.size()) o = 0;
		Point& p2 = vp[o];
		int res = sgn(cross(p1 - p, p2 - p));
		if (res > 0) cnt1++;
		if (res < 0) cnt2++;
	}
	return cnt1 == vp.size() || cnt2 == vp.size();
}
bool ConvexPolygon::isPointOnConvex(const Point& p)
{
	for (int i = 0; i < vp.size(); i++)
	{
		Point& p1 = vp[i];
		int o = i + 1;
		if (o == vp.size()) o = 0;
		Point& p2 = vp[o];
		if (Segment(p1, p2).contain(p))
			return true;
	}
	return false;
}
bool ConvexPolygon::contain(const Point& p)
{
	return isPointInConvex(p) || isPointOnConvex(p);
}
bool ConvexPolygon::containPoint(const Point& p)
{
	if (vp.size() == 1)
	{
		return vp[0] == p;
	}
	Point p0 = vp.front();
	Point pe = vp.back();
	Point p1 = vp[1];
	if (p.x < p0.x) return false;
	if (Segment(p0, vp[1]).contain(p) || Segment(p0, pe).contain(p)) return true;
	if (cross(pe - p0, p - p0) >= 0) return false;
	if (cross(p1 - p0, p - p0) <= 0) return false;
	int l = 1, r = vp.size() - 1;
	int key = 0;
	while (l <= r)
	{
		int mid = (l + r) / 2;
		if (cross(vp[mid] - p0, p - p0) <= 0) key = mid, r = mid - 1;
		else l = mid + 1;
	}
	Point up = vp[key], lo = vp[key - 1];
	return cross(p - lo, up - lo) <= 0;
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	Polygon v1, v2, v3;
	int n, m;
	scanf("%d", &n);

	v1.init(n);
	scanf("%d", &m);
	map<Point, int> mc;
	v2.init(m);
	for (auto& p : v2.vp)
	{
		if (mc.count(p))
		{
			puts("NO");
			return 0;
		}
	}
	v1 = v1.getConvex();
	for (auto& p : v1.vp)
		v2.vp.push_back(p);
	v3 = v2.getConvex();
	if (v1.getArea2() < v3.getArea2() || v1.size() < v3.size())
	{
		puts("NO");
		return 0;
	}
	Segment s(v1.front(), *(v1.end() - 1));
	for (auto& p : v2.vp)
	{
		if (s.contain(p))
		{
			if (s.p1 == p || s.p2 == p) continue;
			puts("NO");
			return 0;
		}
	}
	puts("YES");
	return 0;
}