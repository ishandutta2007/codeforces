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
const int N = 1e5 + 10;
const int M = 1e6 + 10;
class UnionFind
{
public:
	int p[N];
	void init(int n = N)
	{
		memset(p, -1, sizeof(int) * n);
	}
	int treesize(int x)
	{
		return -p[Find(x)];
	}
	int Find(int x)
	{
		int s = x;
		while (p[s] >= 0) s = p[s];
		while (x != s)
		{
			int t = p[x];
			p[x] = s;
			x = t;
		}
		return s;
	}
	void Union(int x, int y)
	{
		int px = Find(x);
		int py = Find(y);
		if (p[px] > p[py]) swap(px, py);
		p[px] += p[py];
		p[py] = px;
	}
} uf;
int minv[N][20];
int maxv[N][20];
int fa[N][20];
int depth[N];
vector<tuple<int, int, int, int>> qr;
vector<pair<int, int>> vp[N];
int ans[M];
void dfs(int x, int p = 0)
{
	fa[x][0] = p;
	depth[x] = depth[p] + 1;
	for (auto& [y, w] : vp[x])
	{
		if (y == p) continue;
		maxv[y][0] = w;
		dfs(y, x);
	}
}
int moveup(int x, int d)
{
	for (int i = 0; d >> i; i++)
	{
		if (d >> i & 1)
			x = fa[x][i];
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
int getmax(int x, int d)
{
	int ret = 0;
	for (int i = 0; d >> i; i++)
	{
		if (d >> i & 1)
		{
			ret = max(ret, maxv[x][i]);
			x = fa[x][i];
		}
	}
	return ret;
}
void setmin(int x, int d, int val)
{
	for (int i = 0; d >> i; i++)
	{
		if (d >> i & 1)
		{
			minv[x][i] = min(minv[x][i], val);
			x = fa[x][i];
		}
	}
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n, m;
	scanf("%d%d", &n, &m);
	uf.init();
	for (int i = 1; i <= m; i++)
	{
		int x, y, w;
		scanf("%d%d%d", &x, &y, &w);
		qr.emplace_back(w, x, y, i);
	}
	sort(qr.begin(), qr.end());
	for (auto& [w, x, y, id] : qr)
	{
		if (uf.Find(x) != uf.Find(y))
		{
			uf.Union(x, y);
			id *= -1;
			vp[x].emplace_back(y, w);
			vp[y].emplace_back(x, w);
		}
	}
	dfs(1);
	for (int o = 1; o < 20; o++)
	{
		for (int i = 1; i <= n; i++)
		{
			int p = fa[i][o - 1];
			fa[i][o] = fa[p][o - 1];
			maxv[i][o] = max(maxv[i][o - 1], maxv[p][o - 1]);
		}
	}
	MEM(minv, 0x3f);
	MEM(ans, -1);
	for (auto [w, x, y, id] : qr)
	{
		if (id > 0)
		{
			int lca = getlca(x, y);
			ans[id] = max(getmax(x, depth[x] - depth[lca]), getmax(y, depth[y] - depth[lca]));
			setmin(x, depth[x] - depth[lca], w);
			setmin(y, depth[y] - depth[lca], w);
		}
	}
	for (int i = 1; i <= m; i++)
	{
		if (ans[i] >= 0)
			printf("%d\n", ans[i]);
	}
	return 0;
}