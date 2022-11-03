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
const int N = 1e3 + 10;
LL solve(int x1, int y1, int x2, int y2, int o = 0)
{
	if (x1 > x2) return 0;
	if (y1 > y2) return 0;
	LL sz = (x2 - x1 + 1LL) * (y2 - y1 + 1);
	LL a = (sz + 1) / 2;
	LL b = sz - a;
	if ((x1 + y1) & 1) swap(a, b);
	if (o == 0) return a;
	else return b;
}
LL area(int a, int b, int c, int d)
{
	if (a > c) return 0;
	if (b > d) return 0;
	return (c - a + 1) * (d - b + 1LL);
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int ncase;
	cin >> ncase;
	while (ncase--)
	{
		int n, m;
		cin >> n >> m;
		int x1, y1, x2, y2;
		int x3, y3, x4, y4;
		cin >> x1 >> y1 >> x2 >> y2;
		cin >> x3 >> y3 >> x4 >> y4;
		int x5 = max(x1, x3), x6 = min(x2, x4);
		int y5 = max(y1, y3), y6 = min(y2, y4);
		LL cnt[2] = { 0LL,0LL };
		for (int o = 0; o < 2; o++)
		{
			cnt[o] = solve(1, 1, n, m, o) - solve(x1, y1, x2, y2, o) - solve(x3, y3, x4, y4, o) + solve(x5, y5, x6, y6, o);
		}
		cnt[0] += area(x1, y1, x2, y2) - area(x5, y5, x6, y6);
		cnt[1] += area(x3, y3, x4, y4);
		printf("%lld %lld\n", cnt[0], cnt[1]);
	}
	return 0;
}