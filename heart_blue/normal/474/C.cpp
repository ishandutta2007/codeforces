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
#define MAX(a,b) ((a) > (b) ? (a) : (b))
#define MIN(a,b) ((a) < (b) ? (a) : (b))
#define MEM(a,b) memset((a),(b),sizeof(a))
const LL INF = 1e9 + 7;
const int N = 1e5 + 10;
class Point
{
private:
	int x, y;
public:
	Point(int _x = 0, int _y = 0)
	{
		x = _x, y = _y;
	}
	void init()
	{
		cin >> x >> y;
	}
	Point operator - (Point &p)
	{
		return Point(x - p.x, y - p.y);
	}
	Point operator + (Point &p)
	{
		return Point(x + p.x, y + p.y);
	}
	bool operator == (Point p)
	{
		return x == p.x && y == p.y;
	}
	bool operator != (Point &p)
	{
		return !(*this == p);
	}
	bool operator < (Point &p)
	{
		if (x != p.x) return x < p.x;
		else return y < p.y;
	}
	int operator *(Point p)
	{
		return x * p.x + y * p.y;
	}
	int length()
	{
		return x*x + y*y;
	}
	int dist(Point &p1)
	{
		return (*this - p1).length();
	}
	void next(Point &p)
	{
		Point ret = *this - p;
		*this = Point(-ret.y, ret.x) + p;
	}
};

bool isrect(Point p1, Point p2, Point p3, Point p4)
{

	vector<Point> vp = { p1,p2,p3,p4 };
	sort(vp.begin(), vp.end());
	if (vp[0] == vp[1] || vp[1] == vp[2] || vp[2] == vp[3]) return false;
	int flag = 0;
	do
	{
		if ((vp[0] - vp[1])*(vp[0] - vp[2]) == 0)
		{
			flag = 1;
			break;
		}
	} while (next_permutation(vp.begin(), vp.end()));
	if (!flag) return false;
	p1 = vp[0], p2 = vp[1], p3 = vp[2], p4 = vp[3];
	if (p1.dist(p2) != p1.dist(p3)) return false;
	return (p2 - p1 == p4 - p3);
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int ncase;
	cin >> ncase;
	while (ncase--)
	{
		Point p1, p2, p3, p4;
		Point o1, o2, o3, o4;
		p1.init(), o1.init();
		p2.init(), o2.init();
		p3.init(), o3.init();
		p4.init(), o4.init();
		int ans = INF;
		for (int i = 0; i < 4; i++)
		{
			for (int j = 0; j < 4; j++)
			{
				for (int k = 0; k < 4; k++)
				{
					for (int t = 0;t < 4; t++)
					{
						if (isrect(p1, p2, p3, p4))
						{
							ans = min(ans, i + j + k + t);
						}
						p4.next(o4);
					}
					p3.next(o3);
				}
				p2.next(o2);
			}
			p1.next(o1);
		}
		if (ans == INF) ans = -1;
		cout << ans << endl;
	}
	return 0;
}