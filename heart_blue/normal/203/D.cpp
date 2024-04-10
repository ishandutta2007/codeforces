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
#include <random>
#include <cassert>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
#define MEM(a,b) memset((a),(b),sizeof(a))
const LL INF = 1e9 + 7;
const int N = 2e5 + 10;
const double eps = 1e-8;
double check(double x, double a, double b, double v)
{
	if (abs(v) < eps) return INF;
	if (v > 0) return (b - x) / v;
	else return (x - a) / -v;
}
bool cmp(double a, double b)
{
	return abs(a - b) < eps;
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	double a, b, m;
	cin >> a >> b >> m;
	double cx = a / 2, cy = m, cz = 0;
	double vx, vy, vz;
	cin >> vx >> vy >> vz;
	while (!cmp(cy, 0))
	{
		double t = min({ check(cx,0,a,vx),check(cy,0,m,vy),check(cz,0,b,vz) });
		cx += vx * t;
		cy += vy * t;
		cz += vz * t;
		if (cmp(cx, 0) || cmp(cx, a)) vx = -vx;
		if (cmp(cy, 0) || cmp(cy, m)) vy = -vy;
		if (cmp(cz, 0) || cmp(cz, b)) vz = -vz;
	}
	printf("%.15f %.15f\n", cx, cz);
	return 0;
}