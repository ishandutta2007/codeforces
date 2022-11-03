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
int fa[N][20];
int depth[N];
vector<int> v[N];
void dfs(int x, int p = 0)
{
	depth[x] = depth[p] + 1;
	fa[x][0] = p;
	for (auto &y : v[x])
	{
		if (y == p) continue;
		dfs(y, x);
	}
}
void init(int n)
{
	dfs(1);
	for (int o = 1; o < 20; o++)
	{
		for (int i = 1; i <= n; i++)
		{
			fa[i][o] = fa[fa[i][o - 1]][o - 1];
		}
	}
}
int moveup(int x, int step)
{
	for (int o = 0; (1 << o) <= step; o++)
	{
		if (step&(1 << o)) x = fa[x][o];
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
int getans(int x, int y, int z)
{
	int lcaxy = getlca(x, y);
	int lcaxz = getlca(x, z);
	int lcayz = getlca(y, z);
	//if (x == y)
	//{
	//	return depth[x] + depth[z] - 2*depth[lcaxz];
	//}
	if (lcaxz == lcayz)
	{
		return depth[lcaxy] + depth[z] - 2 * depth[lcaxz];
	}
	else if (lcayz == lcaxy)
	{
		return depth[z] - depth[lcaxz];
	}
	else
	{
		return depth[z] - depth[lcayz];
	}
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n, q;
	cin >> n >> q;
	for (int i = 2; i <= n; i++)
	{
		int x;
		cin >> x;
		v[x].push_back(i);
		v[i].push_back(x);
	}
	init(n);
	while (q--)
	{
		int x, y, z;
		cin >> x >> y >> z;
		printf("%d\n", 1 + max(getans(x, y, z), max(getans(y, z, x), getans(x, z, y))));
	}
	return 0;
}