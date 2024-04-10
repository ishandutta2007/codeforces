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
};
Point p1[N];
Point p2[N];
LL a[N];
bool check(LL U, LL D, LL L, LL R)
{
	if (L > R) swap(L, R);
	return U >= L * D && U <= R * D;
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n;
	scanf("%d", &n);
	int ans = 0;
	for (int i = 1; i <= n; i++)
	{
		p1[i].init();
		p2[i].init();
		a[i] = abs(p1[i].x - p2[i].x);
		a[i] *= a[i] * a[i];
		int flag = 1;
		LL summ = 0, sumx = 0, sumy = 0;
		for (int j = i; j > 1; j--)
		{
			summ += a[j];
			sumx += a[j] * (p1[j].x + p2[j].x);
			sumy += a[j] * (p1[j].y + p2[j].y);
			if (!check(sumx, summ * 2, p1[j - 1].x, p2[j - 1].x) ||
				!check(sumy, summ * 2, p1[j - 1].y, p2[j - 1].y))
			{
				flag = 0;
				break;
			}
		}
		if (flag) ans = i;
		else break;
	}
	printf("%d\n", ans);
	return 0;
}