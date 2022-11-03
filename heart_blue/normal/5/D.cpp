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
const int N = 1e5 + 10;
double getdis(double& v, double maxv, double limit, double a, double d, double t)
{
	double t0 = min((maxv - v) / a, t);
	double t1 = t - t0;
	double dis = t0 * v + 0.5 * a * t0 * t0 + maxv * t1;
	v = v + a * t0;
	return dis;
}
double solve(double& v0, double maxv, double limit, double a, double d)
{
	double l = 0, r = INF;
	int cnt = 200;
	while (cnt--)
	{
		double mid = (l + r) / 2;
		double v = v0;
		double dis = getdis(v, maxv, limit, a, d, mid);
		if (dis > d)
		{
			r = mid;
			continue;
		}
		if (v < limit)
		{
			l = mid;
			continue;
		}
		double t = (v - limit) / a;
		dis += v * t - 0.5 * a * t * t;
		if (dis > d) r = mid;
		else l = mid;
	}
	double t = l;
	getdis(v0, maxv, limit, a, d, t);
	if (v0 < limit) return t;
	t += (v0 - limit) / a;
	v0 = limit;
	return t;
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	double a, v, l, d, w;
	scanf("%lf%lf%lf%lf%lf", &a, &v, &l, &d, &w);
	double v0 = 0;
	double ans = solve(v0, v, w, a, d);
	ans += solve(v0, v, 1e18, a, l - d);
	printf("%.15f\n", ans);
	return 0;
}