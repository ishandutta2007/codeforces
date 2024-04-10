#pragma comment(linker, "/STACK:102400000,102400000") 
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
const int N = 1e5 + 10;
LL gcd(LL n, LL m)
{
	return m == 0 ? n : gcd(m, n%m);
}
int get_line_intersection(LL p0_x, LL p0_y, LL p1_x, LL p1_y,
	LL p2_x, LL p2_y, LL p3_x, LL p3_y, LL &i_x, LL &i_y)
{
	LL s02_x, s02_y, s10_x, s10_y, s32_x, s32_y, s_numer, t_numer, denom, t;
	s10_x = p1_x - p0_x;
	s10_y = p1_y - p0_y;
	s32_x = p3_x - p2_x;
	s32_y = p3_y - p2_y;

	denom = s10_x * s32_y - s32_x * s10_y;
	bool denomPositive = denom > 0;

	s02_x = p0_x - p2_x;
	s02_y = p0_y - p2_y;

	t_numer = s32_x * s02_y - s32_y * s02_x;

	// Collision detected
	LL g = gcd(abs(t_numer), abs(denom));
	t_numer /= g;
	denom /= g;
	if (s10_x%denom != 0 || s10_y % denom != 0) return 0;
	//t = t_numer / denom;

	i_x = p0_x + (s10_x / denom * t_numer);
	i_y = p0_y + (s10_y / denom * t_numer);

	return 1;
}
LL x[N], y[N];
const int M = 1e6 + 10;
int cnt[M];
void init()
{
	for (int i = 1; i *(i - 1) / 2 < M; i++)
	{
		cnt[i*(i - 1) / 2] = i;
	}
}
struct point
{
	LL x, y;
	point(LL x = 0, LL y = 0)
	{
		this->x = x;
		this->y = y;
	}
};
struct Vec
{
	point start;
	point end;
};
LL multi(point p1, point p2, point p0)
{
	return (p1.x - p0.x)*(p2.y - p0.y) - (p2.x - p0.x)*(p1.y - p0.y);
}
int sgn(LL x)
{
	if (x == 0) return 0;
	if (x > 0) return 1;
	else return -1;
}
int panduan(Vec a, Vec b)
{
	if (max(a.start.x, a.end.x) >= min(b.start.x, b.end.x) &&//
		max(b.start.x, b.end.x) >= min(a.start.x, a.end.x) &&//
		max(a.start.y, a.end.y) >= min(b.start.y, b.end.y) &&//
		sgn(multi(b.start, a.end, a.start))*sgn(multi(a.end, b.end, a.start)) >= 0 &&//
		sgn(multi(a.start, b.end, b.start))*sgn(multi(b.end, a.end, b.start)) >= 0//
		)
		return 1;
	return 0;
}

int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n;
	init();
	scanf("%d", &n);
	LL ans = 0;
	for (int i = 0; i < 2 * n; i += 2)
	{
		scanf("%lld%lld%lld%lld", &x[i], &y[i], &x[i + 1], &y[i + 1]);
		LL a = abs(x[i] - x[i + 1]);
		LL b = abs(y[i] - y[i + 1]);
		ans += gcd(a, b) + 1;
	}
	map<pair<LL, LL>, int> mc;
	for (int i = 0; i < n * 2; i += 2)
	{
		for (int j = i + 2; j < n * 2; j += 2)
		{
			LL ox, oy;
			ox = oy = 0;
			Vec v1;
			v1.start = point(x[i], y[i]);
			v1.end = point(x[i + 1], y[i + 1]);
			Vec v2;
			v2.start = point(x[j], y[j]);
			v2.end = point(x[j + 1], y[j + 1]);
			if (!panduan(v1, v2)) continue;
			if (get_line_intersection(x[i], y[i], x[i + 1], y[i + 1],
				x[j], y[j], x[j + 1], y[j + 1],
				ox, oy))
			{
				mc[{ox, oy}]++;
			}
		}
	}
	for (auto &p : mc)
	{
		ans -= cnt[p.second] - 1;
	}
	printf("%lld\n", ans);
	return 0;
}