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
set<pair<int, int>> sp[20];
int a[N];
LL inline sum(int x)
{
	return 1LL * x * (x + 1) / 2;
}
LL add(set<pair<int, int>>& sp, int x)
{
	auto iter2 = sp.lower_bound(make_pair(x, -1));
	auto iter1 = iter2;
	iter1--;
	auto [r2, l2] = *iter2;
	auto [r1, l1] = *iter1;
	if (l2 <= x && x <= r2) return 0;
	LL delta = 0;
	if (r1 + 1 == x && x + 1 == l2)
	{
		delta -= sum(r1 - l1 + 1);
		delta -= sum(r2 - l2 + 1);
		delta += sum(r2 - l1 + 1);
		sp.erase(*iter1);
		sp.erase(*iter2);
		sp.emplace(r2, l1);
	}
	else if (r1 + 1 == x)
	{
		delta -= sum(r1 - l1 + 1);
		delta += sum(r1 - l1 + 2);
		sp.erase(*iter1);
		sp.emplace(x, l1);
	}
	else if (x + 1 == l2)
	{
		delta -= sum(r2 - l2 + 1);
		delta += sum(r2 - l2 + 2);
		sp.erase(*iter2);
		sp.emplace(r2, x);
	}
	else
	{
		delta += 1;
		sp.emplace(x, x);
	}
	return delta;
}
LL del(set<pair<int, int>>& sp, int x)
{
	auto iter = sp.lower_bound(make_pair(x, -1));
	auto [r, l] = *iter;
	if (x < l || x > r) return 0;
	LL delta = -sum(r - l + 1);
	sp.erase(*iter);
	if (l < x)
	{
		delta += sum(x - l);
		sp.emplace(x - 1, l);
	}
	if (x < r)
	{
		delta += sum(r - x);
		sp.emplace(r, x + 1);
	}
	return delta;
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	LL ans = 0;
	int n;
	scanf("%d", &n);
	int q;
	scanf("%d", &q);
	for (int o = 0; o < 20; o++)
	{
		sp[o].emplace((int)INF, (int)INF);
		sp[o].emplace(-(int)INF, -(int)INF);
	}
	for (int i = 1; i <= n; i++)
	{
		int x;
		scanf("%d", &x);
		a[i] = x;
		for (int o = 0; x >> o; o++)
		{
			if (x >> o & 1)
				ans += add(sp[o], i) << o;
		}
	}
	while (q--)
	{
		int pos, x;
		scanf("%d%d", &pos, &x);
		for (int o = 0; a[pos] >> o; o++)
		{
			if (a[pos] >> o & 1)
				ans += del(sp[o], pos) << o;
		}
		a[pos] = x;
		for (int o = 0; x >> o; o++)
		{
			if (x >> o & 1)
				ans += add(sp[o], pos) << o;
		}
		printf("%lld\n", ans);
	}
	return 0;
}