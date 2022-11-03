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
const int N = 3e5 + 10;
vector<int> vp[N];
int depth[N];
int fa[N];
int ans[N];
vector<pair<int, int>> key[N];
set<int> s;
void dfs(int x, int p = 0)
{
	depth[x] = depth[p] + 1;
	fa[x] = p;
	for (auto& y : vp[x])
	{
		if (y == p) continue;
		dfs(y, x);
	}
}
int solve(int x, int n)
{
	dfs(x);
	for (int i = 1; i <= n; i++)
	{
		if (depth[i] > depth[x])
			x = i;
	}
	return x;
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n, a, b, da, db;
	int ncase;
	scanf("%d", &ncase);
	while (ncase--)
	{
		scanf("%d%d%d%d%d", &n, &a, &b, &da, &db);
		for (int i = 1; i <= n; i++)
			vp[i].clear();
		for (int i = 1; i < n; i++)
		{
			int x, y;
			scanf("%d %d", &x, &y);
			vp[x].push_back(y);
			vp[y].push_back(x);
		}
		if (da * 2 >= db)
		{
			puts("Alice");
			continue;
		}
		int rt = solve(a, n);
		if (depth[b] - 1 <= da)
		{
			puts("Alice");
			continue;
		}
		rt = solve(rt, n);
		if (depth[rt] - 1 <= da * 2)
		{
			puts("Alice");
		}
		else
			puts("Bob");
	}
	return 0;
}