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
const int N = 2e5 + 10;
const int K = 20;
class UnionFind
{
	int p[N];
public:
	void init(int n = N)
	{
		memset(p, -1, sizeof(int)*n);
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
			int tmp = p[x];
			p[x] = s;
			x = tmp;
		}
		return s;
	}
	void Union(int x, int y)
	{
		int px = Find(x);
		int py = Find(y);
		if (treesize(px) > treesize(py)) swap(px, py);
		p[py] += p[px];
		p[px] = py;
	}
} uf;
class Edge
{
public:
	int x, y, w;
	int flag;
	int pos;
	Edge(int x = 0, int y = 0, int w = 0, int pos = 0)
	{
		this->x = x;
		this->y = y;
		this->w = w;
		this->pos = pos;
		flag = 0;
	}
	bool operator < (const Edge& e2) const
	{
		return w < e2.w;
	}
};
vector<Edge> ve;
int fa[N][K];
int depth[N];
int maxv[N][K];
vector<pair<int, int>> vp[N];
LL ans[N];
void dfs(int x, int w = 0, int p = 0)
{
	fa[x][0] = p;
	maxv[x][0] = w;
	depth[x] = depth[p] + 1;
	for (auto &pp : vp[x])
	{
		int y, ww;
		tie(y, ww) = pp;
		if (y == p) continue;
		dfs(y, ww, x);
	}
}
void init(int n)
{
	dfs(1);
	for (int o = 1; o < K; o++)
	{
		for (int i = 1; i <= n; i++)
		{
			int p = fa[i][o - 1];
			fa[i][o] = fa[p][o - 1];
			maxv[i][o] = max(maxv[i][o - 1], maxv[p][o - 1]);
		}
	}
}
int moveup(int &x, int d)
{
	int ret = 0;
	for (int i = 0; (1 << i) <= d; i++)
	{
		if (d >> i & 1) ret = max(ret, maxv[x][i]), x = fa[x][i];
	}
	return ret;
}
int getlca(int x, int y)
{
	if (depth[x] < depth[y]) swap(x, y);
	moveup(x, depth[x] - depth[y]);
	if (x == y) return x;
	for (int i = K - 1; i >= 0; i--)
	{
		if (fa[x][i] != fa[y][i]) x = fa[x][i], y = fa[y][i];
	}
	return fa[x][0];
}
int solve(int x, int y)
{
	int lca = getlca(x, y);
	return max(moveup(x, depth[x] - depth[lca]), moveup(y, depth[y] - depth[lca]));
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
		ve.push_back({ x,y,w,i });
	}
	sort(ve.begin(), ve.end());
	LL tot = 0;
	for (auto &e : ve)
	{
		int x = e.x;
		int y = e.y;
		int w = e.w;
		if (uf.Find(x) != uf.Find(y))
		{
			uf.Union(x, y);
			tot += w;
			e.flag = 1;
			vp[x].push_back({ y,w });
			vp[y].push_back({ x,w });
		}
	}
	init(n);
	for (auto &e : ve)
	{
		if (e.flag)
		{
			ans[e.pos] = tot;
			continue;
		}
		else
		{
			ans[e.pos] = tot + e.w - solve(e.x, e.y);
		}
	}
	for (int i = 1; i <= m; i++) printf("%lld\n", ans[i]);
	return 0;
}