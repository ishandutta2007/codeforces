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
const int N = 1e7 + 10;
inline int sgn(int x)
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
bool check(Segment s, Point p)
{
	LL len1 = (p - s.p1).norm2();
	LL len2 = (p - s.p2).norm2();
	if (len1 > len2) swap(len1, len2);
	return len1 * 16 >= len2;
}
bool check(Segment s1, Segment s2, Segment s3)
{
	if (s1.p1 == s2.p2)
	{
		swap(s2.p1, s2.p2);
	}
	else if (s1.p2 == s2.p1)
	{
		swap(s1.p1, s1.p2);
	}
	else if (s1.p2 == s2.p2)
	{
		swap(s1.p1, s1.p2);
		swap(s2.p1, s2.p2);
	}
	else if (!(s1.p1 == s2.p1)) return false;
	if (!s1.contain(s3.p1)) swap(s3.p1, s3.p2);
	if (!s1.contain(s3.p1) || !s2.contain(s3.p2)) return false;
	if (dot(s2.p2 - s2.p1, s1.p2 - s1.p1) < 0) return false;
	if (cross(s2.p2 - s2.p1, s1.p2 - s1.p1) == 0) return false;
	if (!check(s1, s3.p1) || !check(s2, s3.p2)) return false;
	return true;
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int ncase;
	scanf("%d", &ncase);
	while (ncase--)
	{
		Segment s1, s2, s3;
		s1.init();
		s2.init();
		s3.init();
		if (check(s1, s2, s3) || check(s1, s3, s2) || check(s2, s3, s1))
			puts("YES");
		else puts("NO");
	}
	return 0;
}