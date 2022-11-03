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
const int N = 1e5 + 10;

int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	map<pair<int, int>, int> ms;
	int o = 4;
	int cnt0 = 0, cnt1 = 0;
	while (o--)
	{
		int a, b, c, d;
		cin >> a >> b >> c >> d;
		if (a == c) cnt0++;
		else if (b == d) cnt1++;
		else
		{
			puts("NO");
			return 0;
		}
		if (a == c && b == d)
		{
			puts("NO");
			return 0;
		}
		ms[{a, b}] = 1;
		ms[{c, d}] = 1;
	}
	if (cnt0 != 2 || cnt1 != 2)
	{
		puts("NO");
		return 0;
	}
	int u = INF, d = -INF, l = INF, r = -INF;
	if (ms.size() != 4)
	{
		puts("NO");
		return 0;
	}
	for (auto &p : ms)
	{
		int x, y;
		tie(x, y) = p.first;
		u = min(u, x);
		d = max(d, x);
		l = min(l, y);
		r = max(r, y);
	}
	if (u == d || l == r)
	{
		puts("NO");
		return 0;
	}
	int x[2] = { u,d }, y[2] = { l,r };
	for (int i = 0; i < 2; i++)
	{
		for (int j = 0; j < 2; j++)
		{
			if (!ms.count({ x[i],y[j] }))
			{
				puts("NO");
				return 0;
			}
		}
	}
	puts("YES");
	return 0;
}