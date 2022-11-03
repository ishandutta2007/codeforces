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
bool dcmp(double a)
{
	if (a < 0) a = -a;
	return a < 0.00000001;
}
struct Circle
{
	int x, y, r;
	Circle(int x = 0, int y = 0, int r = 0)
	{
		this->x = x;
		this->y = y;
		this->r = r;
	}
	bool inway(Circle& c)
	{
		int x1 = x, y1 = y, r1 = r;
		int x2 = c.x, y2 = c.y, r2 = c.r;
		int d = (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2);
		return d <= (r1 - r2) * (r1 - r2);
	}

	bool contain(Circle& c)
	{
		int x1 = x, y1 = y, r1 = r;
		int x2 = c.x, y2 = c.y, r2 = c.r;
		if (r1 < r2) return false;
		int d = (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2);
		return d <= (r1 - r2) * (r1 - r2);
	}
	bool exway(Circle& c)
	{
		int x1 = x, y1 = y, r1 = r;
		int x2 = c.x, y2 = c.y, r2 = c.r;
		int d = (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2);
		return d >= (r1 + r2) * (r1 + r2);
	}
	bool intersect(Circle& c)
	{
		return !inway(c) && !exway(c);
	}
};
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int x1, y1, r1, R1;
	int x2, y2, r2, R2;
	cin >> x1 >> y1 >> r1 >> R1;
	cin >> x2 >> y2 >> r2 >> R2;
	Circle c1(x1, y1, r1), c2(x1, y1, R1), c3(x2, y2, r2), c4(x2, y2, R2);
	int ans = 0;
	if (!c1.intersect(c3) && !c1.intersect(c4))
		ans++;
	if (!c2.intersect(c3) && !c2.intersect(c4))
		ans++;
	if (!c3.intersect(c1) && !c3.intersect(c2))
		ans++;
	if (!c4.intersect(c1) && !c4.intersect(c2))
		ans++;
	if ((c1.exway(c3) || c1.contain(c3)) && c4.contain(c1))
		ans--;
	if ((c2.exway(c3) || c2.contain(c3)) && c4.contain(c2))
		ans--;
	if ((c3.exway(c1) || c3.contain(c1)) && c2.contain(c3))
		ans--;
	if ((c4.exway(c1) || c4.contain(c1)) && c2.contain(c4))
		ans--;
	printf("%d\n", ans);
	return 0;
}