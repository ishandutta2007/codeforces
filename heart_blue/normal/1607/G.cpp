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
int a[N];
int b[N];
int ans1[N];
int ans2[N];
LL solve(int n, int m, int ans[])
{
	for (int i = 1; i <= n; i++) swap(a[i], b[i]);
	priority_queue<pair<int, int>> pq;
	LL tot = 0;
	for (int i = 1; i <= n; i++)
	{
		int dif = 0;
		{
			int o = m;
			int x = a[i];
			int y = b[i];
			o = min(o, y);
			y -= o;
			x -= m - o;
			ans[i] = m - o;
			dif += x - y;
			tot += x - y;
		}
		{
			int o = m;
			int x = a[i];
			int y = b[i];
			o = min(o, x);
			x -= o;
			y -= m - o;
			dif -= x - y;
		}
		if (dif > 0) pq.emplace(dif, i);
	}
	while (tot >= 1 && !pq.empty())
	{
		int val, pos;
		tie(val, pos) = pq.top();
		pq.pop();
		LL o = min(tot, 1LL * val) / 2 * 2;
		tot -= o;
		ans[pos] += o / 2;
	}
	return abs(tot);
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int ncase;
	scanf("%d", &ncase);
	while (ncase--)
	{
		int n, m;
		scanf("%d%d", &n, &m);
		for (int i = 1; i <= n; i++)
			scanf("%d%d", &a[i], &b[i]);
		LL res2 = solve(n, m, ans2);
		LL res1 = solve(n, m, ans1);
		if (res2 <= res1)
		{
			for (int i = 1; i <= n; i++)
				ans1[i] = m - ans2[i];
		}
		printf("%lld\n", min(res1, res2));
		for (int i = 1; i <= n; i++)
		{
			printf("%d %d\n", ans1[i], m - ans1[i]);
		}
	}
	return 0;
}