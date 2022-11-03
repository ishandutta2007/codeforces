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
const int N = 1e6 + 10;
vector<pair<int, int>> vp1[N], vp2[N];
int dfn[N], low[N], cnt, scccnt;
int in[N], top, s[N];
int belong[N];
LL sum[N];
LL dp[N];
void tarjan(int x)
{
	dfn[x] = low[x] = ++cnt;
	in[x] = 1;
	s[++top] = x;
	for (auto& [y, w] : vp1[x])
	{
		if (dfn[y])
		{
			if (in[y])
				low[x] = min(low[x], dfn[y]);
		}
		else
		{
			tarjan(y);
			low[x] = min(low[x], low[y]);
		}
	}
	if (low[x] == dfn[x])
	{
		scccnt++;
		while (1)
		{
			int y = s[top--];
			in[y] = 0;
			belong[y] = scccnt;
			if (y == x) break;
		}
	}
}
LL getsum(int x)
{
	int l = 0, r = 20000;
	int key = 0;
	while (l <= r)
	{
		int mid = (l + r) / 2;
		if (mid * (mid + 1) / 2 <= x) key = mid, l = mid + 1;
		else r = mid - 1;
	}
	return 1LL * (key + 1) * x - 1LL * key * (key + 1) * (key + 2) / 6;
}
LL dfs(int x)
{
	if (dp[x] != -1)
		return dp[x];
	LL ret = 0;
	for (auto [y, w] : vp2[x])
	{
		ret = max(ret, dfs(y) + w);
	}
	return dp[x] = sum[x] + ret;
}
LL solve(int n, int s)
{
	for (int i = 1; i <= n; i++)
	{
		if (!dfn[i])
			tarjan(i);
	}
	for (int i = 1; i <= n; i++)
	{
		for (auto [j, w] : vp1[i])
		{
			int x = belong[i];
			int y = belong[j];
			if (x == y)
				sum[x] += getsum(w);
			else
				vp2[x].emplace_back(y, w);
		}
	}
	MEM(dp, -1);
	return dfs(belong[s]);
}

int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n, m;
	scanf("%d%d", &n, &m);
	while (m--)
	{
		int x, y, w;
		scanf("%d%d%d", &x, &y, &w);
		vp1[x].emplace_back(y, w);
	}
	int s;
	scanf("%d", &s);
	printf("%lld\n", solve(n, s));
	return 0;
}