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
const int N = 3e5 + 10;
vector<int> v[N], v2[N];
int low[N], dfn[N];
int in[N], s[N];
int belong[N];
int scccnt, cnt, top;
int dis[N];
void tarjan(int x, int p = -1)
{
	low[x] = dfn[x] = ++cnt;
	in[x] = 1;
	s[top++] = x;
	for (auto &y : v[x])
	{
		if (y == p) continue;
		if (dfn[y])
		{
			if (in[y])
			{
				low[x] = min(low[x], dfn[y]);
			}
		}
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
			in[y] = 0;
			belong[y] = scccnt;
			if (y == x) break;
		}
	}
}
void init(int n)
{
	for (int i = 1; i <= n; i++)
	{
		if (!dfn[i])
			tarjan(i);
	}
	for (int i = 1; i <= n; i++)
	{
		int x = belong[i];
		for (auto &j : v[i])
		{
			int y = belong[j];
			if (x == y) continue;
			v2[x].push_back(y);
		}
	}
}
void dfs(int x, int p = 0)
{
	if (dis[x]) return;
	dis[x] = dis[p] + 1;
	for (auto &y : v2[x])
	{
		dfs(y, x);
	}
}
int solve()
{
	int rt = 1;
	MEM(dis, 0);
	dfs(rt);
	for (int i = 1; i <= scccnt; i++)
		if (dis[i] > dis[rt])
			rt = i;
	MEM(dis, 0);
	dfs(rt);
	for (int i = 1; i <= scccnt; i++)
		if (dis[i] > dis[rt])
			rt = i;
	return dis[rt] - 1;
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n, m;
	scanf("%d%d", &n, &m);
	while (m--)
	{
		int x, y;
		scanf("%d%d", &x, &y);
		v[x].push_back(y);
		v[y].push_back(x);
	}
	init(n);
	printf("%d\n", solve());
	return 0;
}