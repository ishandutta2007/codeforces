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
const int N = 1e5 + 10;

vector<int> v1[N];
set<int> v2[N];
int fa[N][20];
int depth[N];
int sum[N];
int low[N], dfn[N], cnt;
int scccnt, belong[N];
int s[N], top;
int sz[N];
int p2[N];
void tarjan(int x, int p = 0)
{
	low[x] = dfn[x] = ++cnt;
	s[top++] = x;
	for (auto& y : v1[x])
	{
		if (y == p) continue;
		if (dfn[y])
		{
			low[x] = min(low[x], dfn[y]);
		}
		else
		{
			tarjan(y, x);
			low[x] = min(low[x], low[y]);

		}
	}
	if (dfn[x] == low[x])
	{
		scccnt++;
		while (1)
		{
			int y = s[--top];
			sz[scccnt]++;
			belong[y] = scccnt;
			if (y == x) break;
		}
	}
}
void dfs(int x, int p = 0)
{
	fa[x][0] = p;
	sum[x] = sum[p] + (sz[x] > 1);
	depth[x] = depth[p] + 1;
	for (auto& y : v2[x])
	{
		if (y == p) continue;
		dfs(y, x);
	}
}
int moveup(int x, int d)
{
	for (int o = 0; d >> o; o++)
	{
		if (d >> o & 1)
			x = fa[x][o];
	}
	return x;
}
int getlca(int x, int y)
{
	if (depth[x] < depth[y]) swap(x, y);
	x = moveup(x, depth[x] - depth[y]);
	if (x == y) return x;
	for (int i = 19; i >= 0; i--)
	{
		if (fa[x][i] != fa[y][i])
			x = fa[x][i], y = fa[y][i];
	}
	return fa[x][0];
}
int solve(int x, int y)
{
	x = belong[x];
	y = belong[y];
	int lca = getlca(x, y);
	int cnt = sum[x] + sum[y] - 2 * sum[lca] + (sz[lca] > 1);
	return p2[cnt];
}
void build(int n)
{
	p2[0] = 1;
	for (int i = 1; i < N; i++) p2[i] = p2[i - 1] * 2 % INF;
	tarjan(1);
	for (int i = 1; i <= n; i++)
	{
		for (auto& j : v1[i])
		{
			int x = belong[i];
			int y = belong[j];
			if (x == y) continue;
			v2[x].insert(y);
			v2[y].insert(x);
		}
	}
	dfs(1);
	for (int o = 0; o + 1 < 20; o++)
	{
		for (int i = 1; i <= scccnt; i++)
		{
			fa[i][o + 1] = fa[fa[i][o]][o];
		}
	}
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n, m, q;
	scanf("%d%d", &n, &m);
	while (m--)
	{
		int x, y;
		scanf("%d%d", &x, &y);
		v1[x].push_back(y);
		v1[y].push_back(x);
	}
	build(n);
	scanf("%d", &q);
	while (q--)
	{
		int x, y;
		scanf("%d%d", &x, &y);
		printf("%d\n", solve(x, y));
	}
	return 0;
}