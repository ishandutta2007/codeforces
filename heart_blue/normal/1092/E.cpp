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
#include <chrono>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
#define MEM(a,b) memset((a),(b),sizeof(a))
const LL INF = 1e9 + 7;
const int N = 1e3 + 10;
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
vector<int> v[N];
int depth[N];
int fa[N];
int n;
void dfs(int x, int p = 0)
{
	fa[x] = p;
	depth[x] = depth[p] + 1;
	for (auto& y : v[x])
	{
		if (y == p) continue;
		dfs(y, x);
	}
}
void findroot(int& x)
{
	dfs(x);
	for (int i = 1; i <= n; i++)
	{
		if (uf.Find(i) != uf.Find(x))
			continue;
		if (depth[i] > depth[x])
			x = i;
	}
}
int getDiameter(int& x)
{
	findroot(x);
	findroot(x);
	return depth[x];
}
void findmiddle(int& x)
{
	findroot(x);
	findroot(x);
	int len = depth[x] / 2;
	while (len--)
		x = fa[x];
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int m;
	scanf("%d%d", &n, &m);
	uf.init();
	for (int i = 1; i <= m; i++)
	{
		int x, y;
		scanf("%d%d", &x, &y);
		v[x].push_back(y);
		v[y].push_back(x);
		uf.Union(x, y);
	}
	vector<pair<int, int>> vp;
	for (int i = 1; i <= n; i++)
	{
		if (uf.Find(i) != i) continue;
		int rt = i;
		int len = getDiameter(rt);
		findmiddle(rt);
		vp.emplace_back(len, rt);
	}
	sort(vp.begin(), vp.end());
	int rt = vp.back().second;
	vp.pop_back();
	reverse(vp.begin(), vp.end());
	vector<pair<int, int>> ans;
	for (auto [len, x] : vp)
	{
		ans.emplace_back(x, rt);
		v[rt].push_back(x);
		v[x].push_back(rt);
		uf.Union(rt, x);
		findmiddle(rt);
	}
	int len = getDiameter(rt) - 1;
	printf("%d\n", len);
	for (auto [a, b] : ans)
		printf("%d %d\n", a, b);
	return 0;
}