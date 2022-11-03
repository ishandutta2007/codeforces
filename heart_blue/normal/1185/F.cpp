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
const int N = 5e2 + 20;
int cnt[N];
tuple<int, int, int> cost[N];
vector<pair<int, int>> v[N];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n, m;
	scanf("%d%d", &n, &m);
	while (n--)
	{
		int sz;
		scanf("%d", &sz);
		int o = 0;
		while (sz--)
		{
			int x;
			scanf("%d", &x);
			o |= 1 << x;
		}
		o >>= 1;
		cnt[o]++;
	}
	int mask = 1 << 9;
	mask--;
	for (int i = mask; i >= 1; i--)
	{
		int s = i ^ mask;
		for (int j = s; j; j = (j - 1) & s)
		{
			cnt[j | i] += cnt[i];
		}
	}
	for (int i = 1; i <= m; i++)
	{
		int c, sz;
		scanf("%d%d", &c, &sz);
		int o = 0;
		while (sz--)
		{
			int x;
			scanf("%d", &x);
			o |= 1 << x;
		}
		o >>= 1;
		v[o].emplace_back(c, i);
		v[0].emplace_back(c, i);
	}
	fill(cost, cost + mask + 1, make_tuple(int(2 * INF), -1, -1));
	for (int i = 0; i <= mask; i++)
	{
		sort(v[i].begin(), v[i].end());
	}
	for (int i = 0; i <= mask; i++)
	{
		if (v[i].empty()) continue;
		if (v[i].size() >= 2)
			cost[i] = min(cost[i],
				make_tuple(v[i][0].first + v[i][1].first, v[i][0].second, v[i][1].second));
		if (i == 0) continue;
		for (int j = 1; j <= mask; j++)
		{
			if (i == j) continue;
			if (v[j].empty()) continue;
			cost[i | j] = min(cost[i | j],
				make_tuple(v[i][0].first + v[j][0].first, v[i][0].second, v[j][0].second));
		}
	}
	tuple<int, int, int, int> ans = { -1,0,0,0 };
	for (int o = 0; o <= mask; o++)
	{
		auto [val, i, j] = cost[o];
		if (val == 2 * INF) continue;
		ans = max(ans, make_tuple(cnt[o], -val, i, j));
	}
	auto [res, c, i, j] = ans;
	printf("%d %d\n", i, j);
	return 0;
}