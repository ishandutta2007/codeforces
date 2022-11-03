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
vector<pair<int,int>> v[N];
int fa[N][20];
int maxv[N][20];
int depth[N];
void dfs(int x, int p = 0)
{
	depth[x] = depth[p] + 1;
	fa[x][0] = p;
	for (auto& pp : v[x])
	{
		int y, w;
		tie(y, w) = pp;
		if (y == p) continue;
		maxv[y][0] = w;
		dfs(y, x);
	}
}
void init(int n)
{
	dfs(1);
	for (int i = 1; i < 20; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			int p = fa[j][i - 1];
			fa[j][i] = fa[p][i - 1];
			maxv[j][i] = max(maxv[j][i - 1], maxv[p][i - 1]);
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
int getans(int x, int d)
{
	int ans = 0;
	for (int i = 0; d >> i; i++)
	{
		if (d >> i & 1)
		{
			ans = max(ans, maxv[x][i]);
			x = fa[x][i];
		}
	}
	return ans;
}
int solve(int x, int y, int w)
{
	int lca = getlca(x, y);
	return max(getans(x, depth[x] - depth[lca]), getans(y, depth[y] - depth[lca])) == w;
}
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
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n, m;
	cin >> n >> m;
	uf.init();
	vector<tuple<int, int, int>> vp;
	while (m--)
	{
		int x, y, w;
		cin >> x >> y >> w;
		vp.emplace_back(w, x, y);
	}
	sort(vp.begin(), vp.end());
	for (auto& p : vp)
	{
		int x, y, w;
		tie(w, x, y) = p;
		if (uf.Find(x) == uf.Find(y)) continue;
		uf.Union(x, y);
		v[x].emplace_back(y, w);
		v[y].emplace_back(x, w);
	}
	init(n);
	int ans = 1 - n;
	for (auto& p : vp)
	{
		int x, y, w;
		tie(w, x, y) = p;
		ans += solve(x, y, w);
	}
	cout << ans << endl;
	return 0;
}