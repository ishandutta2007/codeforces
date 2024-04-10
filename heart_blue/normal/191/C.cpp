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
const int N = 2e5 + 10;
int fa[N][20];
int depth[N];
int key[N];
vector<pair<int, int>> vp[N];
int sum[N];
int ans[N];
int n;
void dfs(int x, int p = -1)
{
	fa[x][0] = p;
	if (p == -1) depth[x] = 0;
	else depth[x] = depth[p] + 1;
	for (auto &pp : vp[x])
	{
		int y, o;
		tie(y, o) = pp;
		if (y == p) continue;
		dfs(y, x);
		key[y] = o;
	}
}
void init()
{
	MEM(fa, -1);
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
	for (int i = 0; d >= (1 << i); i++)
	{
		if (1 << i&d) x = fa[x][i];
	}
	return x;
}
int getlca(int x, int y)
{
	if (depth[x] > depth[y]) swap(x, y);
	y = moveup(y, depth[y] - depth[x]);
	if (x == y) return x;
	int lca = -1;
	for (int i = 19; i >= 0; i--)
	{
		if (fa[x][i] != fa[y][i]) x = fa[x][i], y = fa[y][i];
		else lca = fa[x][i];
	}
	return lca;
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
		vp[x].push_back({ y,i });
		vp[y].push_back({ x,i });
	}
	init();
	int m;
	MEM(sum, 0);
	cin >> m;
	while (m--)
	{
		int x, y;
		cin >> x >> y;
		int lca = getlca(x, y);
		sum[x]++;
		sum[y]++;
		sum[lca] -= 2;
	}
	vector<int> v(n);
	for (int i = 0; i < n; i++) v[i] = i + 1;
	sort(v.begin(), v.end(), [&](int x, int y) -> bool
	{
		return depth[x] > depth[y];
	});
	for (auto &x : v)
	{
		if (fa[x][0] != -1) sum[fa[x][0]] += sum[x];
		ans[key[x]] = sum[x];
	}
	for (int i = 1; i < n; i++) cout << ans[i] << ' ';
	return 0;
}