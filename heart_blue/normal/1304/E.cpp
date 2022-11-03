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
vector<int> v[N];
int fa[N][20];
int depth[N];
void dfs(int x, int p = 0)
{
	fa[x][0] = p;
	depth[x] = depth[p] + 1;
	for (auto& y : v[x])
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
	if (depth[x] < depth[y])
		swap(x, y);
	x = moveup(x, depth[x] - depth[y]);
	if (x == y) return x;
	for (int o = 19; o >= 0; o--)
	{
		if (fa[x][o] != fa[y][o])
			x = fa[x][o], y = fa[y][o];
	}
	return fa[x][0];
}
int getdis(int x, int y)
{
	return depth[x] + depth[y] - 2 * depth[getlca(x, y)];
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n, q;
	scanf("%d", &n);
	for (int i = 1; i < n; i++)
	{
		int x, y;
		scanf("%d%d", &x, &y);
		v[x].push_back(y);
		v[y].push_back(x);
	}
	init(n);
	scanf("%d", &q);
	while (q--)
	{
		int x, y, a, b;
		LL k;
		scanf("%d%d%d%d%lld", &x, &y, &a, &b, &k);
		vector<int> v;
		v.push_back(getdis(a, b));
		v.push_back(getdis(x, a) + getdis(b, y) + 1);
		v.push_back(getdis(x, b) + getdis(a, y) + 1);
		int ok = 0;
		for (auto& d : v)
		{
			if (k >= d && (k - d) % 2 == 0)
				ok = 1;
		}
		if (ok) puts("YES");
		else puts("NO");
	}

	return 0;
}