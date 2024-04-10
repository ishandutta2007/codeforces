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
vector<int> v1[N], v2[N];
int belong[N];
int s[N];
int top = 0, cnt = 0, scccnt = 0;
int dfn[N], low[N];
int depth[N];
int fa[N][20];
void tarjan(int x, int fa = 0)
{
	low[x] = dfn[x] = ++cnt;
	s[top++] = x;
	for (auto& y : v1[x])
	{
		if (y == fa) continue;
		if (dfn[y]) low[x] = min(low[x], dfn[y]);
		else
		{
			tarjan(y, x);
			low[x] = min(low[x], low[y]);
		}
	}
	if (low[x] == dfn[x])
	{
		scccnt++;
		while (1)
		{
			int y = s[--top];
			belong[y] = scccnt;
			if (y == x) break;
		}
	}
}
void dfs(int x, int p = 0)
{
	if (depth[x]) return;
	fa[x][0] = p;
	depth[x] = depth[p] + 1;
	for (auto y : v2[x])
	{
		if (y == p) continue;
		dfs(y, x);
	}
}
void init(int n)
{
	tarjan(1);
	for (int i = 1; i <= n; i++)
	{
		for (auto& j : v1[i])
		{
			v2[belong[i]].push_back(belong[j]);
		}
	}
	dfs(1);
	for (int o = 1; o < 20; o++)
	{
		for (int i = 1; i <= n; i++)
		{
			fa[i][o] = fa[fa[i][o - 1]][o - 1];
		}
	}
}
int moveup(int x, int d)
{
	for (int i = 0; d >> i; i++)
	{
		if (d >> i & 1) x = fa[x][i];
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
	x = belong[x], y = belong[y];
	return depth[x] + depth[y] - depth[getlca(x, y)] * 2;
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n, m;
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= m; i++)
	{
		int x, y;
		scanf("%d%d", &x, &y);
		v1[x].push_back(y);
		v1[y].push_back(x);
	}
	init(n);
	int q;
	scanf("%d", &q);
	while (q--)
	{
		int x, y;
		scanf("%d%d", &x, &y);
		printf("%d\n", solve(x, y));
	}
	return 0;
}