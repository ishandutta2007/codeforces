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
const int N = 2e5 + 10;
struct Point
{
	int x, y;
	Point(int x = 0, int y = 0)
	{
		this->x = x;
		this->y = y;
	}
	void init()
	{
		scanf("%d%d", &x, &y);
	}
	bool operator == (const Point& p) const
	{
		return x == p.x && y == p.y;
	}
	bool operator != (const Point& p) const
	{
		return x != p.x || y != p.y;
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
	int norm2() const
	{
		return x * x + y * y;
	}
	double norm() const
	{
		return sqrt(1.0 * x * x + y * y);
	}
	LL dis() const
	{
		return 1LL * abs(x) + 1LL * abs(y);
	}
};
pair<LL, vector<Point>> check1(Point& p1, Point& p2, Point& p3)
{
	Point pl(p1.x, min({ p1.y,p2.y,p3.y }));
	Point pr(p1.x, max({ p1.y,p2.y,p3.y }));
	Point pp2(p1.x, p2.y);
	Point pp3(p1.x, p3.y);
	LL len = (pl - pr).dis() + (p2 - pp2).dis() + (p3 - pp3).dis();
	vector<Point> vp;
	if (pl != pr) vp.push_back(pl), vp.push_back(pr);
	if (p2 != pp2) vp.push_back(p2), vp.push_back(pp2);
	if (p3 != pp3) vp.push_back(p3), vp.push_back(pp3);
	return { len,vp };
}
pair<LL, vector<Point>> check2(Point p1, Point p2, Point p3)
{
	swap(p1.x, p1.y);
	swap(p2.x, p2.y);
	swap(p3.x, p3.y);
	auto ret = check1(p1, p2, p3);
	auto& vp = ret.second;
	for (auto& p : vp)
		swap(p.x, p.y);
	return ret;
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	Point p1, p2, p3;
	p1.init();
	p2.init();
	p3.init();
	auto v = min({
		check1(p1,p2,p3),
		check1(p2,p1,p3),
		check1(p3,p1,p2),
		check2(p1,p2,p3),
		check2(p2,p1,p3),
		check2(p3,p1,p2),
		}).second;
	printf("%d\n", v.size() / 2);
	for (int i = 0; i < v.size(); i += 2)
	{
		printf("%d %d %d %d\n", v[i].x, v[i].y, v[i + 1].x, v[i + 1].y);
	}
	return 0;
}