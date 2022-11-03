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
const int M = 333;
int fa[N][20];
vector<int> v[N];
int depth[N];
int dis[N];
int flag[N];
void preinit(int n)
{
	queue<int> q;
	MEM(dis, 0x3f);
	for (int i = 1; i <= n; i++)
	{
		if (flag[i]) dis[i] = 0, q.push(i);
	}
	while (!q.empty())
	{
		int x = q.front();
		q.pop();
		for (auto &y : v[x])
		{
			if (dis[y] > dis[x] + 1)
			{
				dis[y] = dis[x] + 1;
				q.push(y);
			}
		}
	}
}
void dfs(int x, int p = 0)
{
	fa[x][0] = p;
	depth[x] = 1;
	if (p != 0) depth[x] += depth[p];
	for (auto &y : v[x])
	{
		if (y == p) continue;
		dfs(y, x);
	}
}
void init(int n)
{
	dfs(1);
	for (int o = 0; o + 1 < 20; o++)
	{
		for (int i = 1; i <= n; i++)
		{
			fa[i][o + 1] = fa[fa[i][o]][o];
		}
	}
}
inline int moveup(int x, int d)
{
	for (int i = 0; i < 20; i++)
	{
		if (1 << i&d) x = fa[x][i];
	}
	return x;
}
int getlca(int x, int y)
{
	if (depth[x] < depth[y]) swap(x, y);
	x = moveup(x, depth[x] - depth[y]);
	if (x == y) return x;
	int lca = 1;
	for (int i = 19; i >= 0; i--)
	{
		if (fa[x][i] == fa[y][i]) lca = fa[x][i];
		else x = fa[x][i], y = fa[y][i];
	}
	return lca;
}
int solve(int x, int y)
{
	int lca = getlca(x, y);
	return depth[x] + depth[y] - 2 * depth[lca];
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n, m;
	cin >> n >> m;
	for (int i = 1; i < n; i++)
	{
		int x, y;
		cin >> x >> y;
		v[x].push_back(y);
		v[y].push_back(x);
	}
	init(n);
	flag[1] = 1;
	preinit(n);
	vector<int> res;
	for (int i = 1; i <= m; i++)
	{
		if (i / M != (i - 1) / M)
		{
			for (auto &x : res) flag[x] = 1;
			res.clear();
			preinit(n);
		}
		int op, x;
		cin >> op >> x;
		if (op == 1)
		{
			res.push_back(x);
		}
		else
		{
			int ans = dis[x];
			for (auto &y : res) ans = min(ans, solve(x, y));
			printf("%d\n", ans);
		}
	}
	return 0;
}