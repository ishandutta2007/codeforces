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
const int N = 1e3 + 10;
double check(double x, double y, double u, double vx, double vy)
{
	double l = 1e-10, r = INF;
	int cnt = 100;
	while (cnt--)
	{
		double mid = (l + r) / 2;
		double tx = (x - vx * mid) / mid;
		double ty = (y - vy * mid) / mid;
		if (tx*tx + ty * ty <= u * u) r = mid;
		else l = mid;
	}
	return l;
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	double ax, ay, bx, by;
	double u, t;
	double vx, vy, wx, wy;
	cin >> ax >> ay >> bx >> by >> u >> t >> vx >> vy >> wx >> wy;
	double ans = 0;
	double x = bx - ax, y = by - ay;
	ans = check(x, y, u, vx, vy);
	if (ans <= t)
	{
		printf("%.15f\n", ans);
		return 0;
	}
	int oo = 100;
	double d = acos(0.0) / oo;
	ans = INF;
	for (int i = 0; i < 4 * oo; i++)
	{
		double l, r;
		l = d * i;
		r = i + d;
		int cnt = 300;
		while (cnt--)
		{
			double mid = (l + r) / 2;
			double midmid = (mid + r) / 2;
			double t1 = check(x - (cos(mid)*u + vx)*t, y - (sin(mid)*u + vy)*t, u, wx, wy);
			double t2 = check(x - (cos(midmid)*u + vx)*t, y - (sin(midmid)*u + vy)*t, u, wx, wy);
			if (t1 > t2) l = mid;
			else r = midmid;
			ans = min(ans, t1);
		}
	}
	printf("%.15f\n", ans + t);
	return 0;
}