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
const int N = 5e5 + 10;
int fa[N][22];
int depth[N];
int flag[N];
vector<pair<int, int>> v[N];
vector<pair<int, int>> qr[N];
vector<tuple<int, int, int>> vp;
class UnionFind
{
public:
	int p[N];
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
int n, k, m;
class SegmentTree
{
public:
	int ql, qr, qx;
	int minv[N * 4];
	void set(int l, int r, int x = INF)
	{
		ql = l, qr = r, qx = x;
	}
	void pushdown(int o)
	{
		if (minv[o] != INF)
		{
			minv[o << 1] = min(minv[o << 1], minv[o]);
			minv[o << 1 | 1] = min(minv[o << 1 | 1], minv[o]);
			minv[o] = INF;
		}
	}
	void init(int l, int r, int o = 1)
	{
		if (ql <= l && r <= qr)
		{
			minv[o] = INF;
			return;
		}
		pushdown(o);
		int mid = (l + r) >> 1;
		if (ql <= mid) init(l, mid, o << 1);
		if (mid < qr) init(mid + 1, r, o << 1 | 1);
	}
	void update(int l, int r, int o = 1)
	{
		if (ql <= l && r <= qr)
		{
			minv[o] = min(minv[o], qx);
			return;
		}
		int mid = (l + r) >> 1;
		if (ql <= mid) update(l, mid, o << 1);
		if (mid < qr) update(mid + 1, r, o << 1 | 1);
	}
	int query(int l, int r, int o = 1)
	{
		if (ql <= l && r <= qr)
		{
			return minv[o];
		}
		int mid = (l + r) >> 1;
		int ans = minv[o];
		if (ql <= mid) ans = min(minv[o], query(l, mid, o << 1));
		if (mid < qr) ans = min(minv[o], query(mid + 1, r, o << 1 | 1));
		return ans;
	}
} st;
void dfs(int x, int p = 0)
{
	fa[x][0] = p;
	depth[x] = depth[p] + 1;
	for (auto &pp : v[x])
	{
		int y, o;
		tie(y, o) = pp;
		if (y == p) continue;
		if (o == 1) flag[y] = 1;
		dfs(y, x);
	}
}
void init(int n)
{
	dfs(1);
	for (int o = 1; o < 22; o++)
	{
		for (int i = 1; i <= n; i++)
		{
			fa[i][o] = fa[fa[i][o - 1]][o - 1];
		}
	}
}
int moveup(int x, int d)
{
	for (int i = 0; (1 << i) <= d; i++)
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
	for (int i = 21; i >= 0; i--)
	{
		if (fa[x][i] != fa[y][i]) x = fa[x][i], y = fa[y][i];
	}
	return fa[x][0];
}
LL ans = 0;
void solve(int x, int p = 0)
{
	st.set(depth[x], depth[x]);
	st.init(1, n);
	for (auto &pp : v[x])
	{
		int y, o;
		tie(y, o) = pp;
		if (y == p) continue;
		solve(y, x);
	}
	if (depth[x] <= 1) return;
	for (auto &pp : qr[x])
	{
		int y, w;
		tie(y, w) = pp;
		if (y == x) continue;
		st.set(depth[y] + 1, depth[x], w);
		st.update(1, n);
	}
	if (flag[x]) return;
	st.set(depth[x], depth[x]);
	int res = st.query(1, n);
	if (res == INF)
	{
		puts("-1");
		exit(0);
	}
	ans += res;
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	scanf("%d%d%d", &n, &k, &m);
	uf.init();
	for (int i = 1; i <= k; i++)
	{
		int x, y;
		scanf("%d%d", &x, &y);
		v[x].push_back({ y,0 });
		v[y].push_back({ x,0 });
		if (uf.Find(x) != uf.Find(y))
			uf.Union(x, y);
	}
	for (int i = 1; i <= m; i++)
	{
		int x, y, w;
		scanf("%d%d%d", &x, &y, &w);
		if (uf.Find(x) != uf.Find(y))
		{
			uf.Union(x, y);
			v[x].push_back({ y,1 });
			v[y].push_back({ x,1 });
		}
		else
			vp.push_back({ x,y,w });
	}
	init(n);
	for (auto &p : vp)
	{
		int x, y, w;
		tie(x, y, w) = p;
		int lca = getlca(x, y);
		qr[x].push_back({ lca,w });
		qr[y].push_back({ lca,w });
	}
	solve(1);
	printf("%lld\n", ans);
	return 0;
}