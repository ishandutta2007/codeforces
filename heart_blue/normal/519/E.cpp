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
vector<int> v[N];
int fa[N][20];
int depth[N];
int sons[N];
int n;
void dfs(int x, int p = -1)
{
	fa[x][0] = p;
	depth[x] = 1;
	sons[x] = 1;
	if (p != -1) depth[x] += depth[p];
	for (auto &y : v[x])
	{
		if (y == p) continue;
		dfs(y, x);
		sons[x] += sons[y];
	}
}
void init()
{
	dfs(1);
	for (int o = 0; o < 19; o++)
	{
		for (int i = 1; i <= n; i++)
		{
			int p = fa[i][o];
			if (p != -1) fa[i][o + 1] = fa[p][o];
		}
	}
}
int moveup(int x, int d)
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
	int lca = -1;
	for (int i = 19; i >= 0; i--)
	{
		if (fa[x][i] == fa[y][i]) lca = fa[x][i];
		else x = fa[x][i], y = fa[y][i];
	}
	return lca;
}
int getans(int x, int y)
{
	if (x == y) return n;
	if (depth[x] < depth[y]) swap(x, y);
	int lca = getlca(x, y);
	int dis = depth[x] + depth[y] - 2 * depth[lca];
	if (dis & 1) return 0;
	int root = moveup(x, dis / 2);
	if (root == lca)
	{
		x = moveup(x, dis / 2 - 1);
		y = moveup(y, dis / 2 - 1);
		return n - sons[x] - sons[y];
	}
	else
	{
		x = moveup(x, dis / 2 - 1);
		return sons[root] - sons[x];
	}
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	cin >> n;
	for (int i = 1; i < n; i++)
	{
		int x, y;
		cin >> x >> y;
		v[x].push_back(y);
		v[y].push_back(x);
	}
	init();
	int q;
	cin >> q;
	while (q--)
	{
		int x, y;
		cin >> x >> y;
		cout << getans(x, y) << '\n';
	}
	return 0;
}