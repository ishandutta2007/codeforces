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
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
#define MEM(a,b) memset((a),(b),sizeof(a))
const LL INF = 1e9 + 7;
const int N = 1e5 + 10;
const int M = 2e6 + 10;
vector<int> vp[N];
vector<int> vd[M];
vector<pair<int, int>> ans[M];
int res[N];
int a[N];
void dfs(int x, int fa = 0, int depth = 1)
{
	pair<int, int> ret = { -1,-1 };
	for (auto& p : vd[a[x]])
	{
		if (!ans[p].empty())
		{
			ret = max(ret, ans[p].back());
		}
		ans[p].emplace_back(depth, x);
	}
	res[x] = ret.second;
	for (auto& y : vp[x])
	{
		if (y == fa) continue;
		dfs(y, x, depth + 1);
	}
	for (auto& p : vd[a[x]])
	{
		ans[p].pop_back();
	}
}
void init()
{
	for (int i = 2; i < M; i++)
	{
		if (!vd[i].empty()) continue;
		for (int j = i; j < M; j += i) vd[j].push_back(i);
	}
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n, m;
	init();
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
	for (int i = 1; i < n; i++)
	{
		int x, y;
		scanf("%d%d", &x, &y);
		vp[x].emplace_back(y);
		vp[y].emplace_back(x);
	}
	dfs(1);
	while (m--)
	{
		int op;
		scanf("%d", &op);
		if (op == 1)
		{
			int x;
			scanf("%d", &x);
			printf("%d\n", res[x]);
		}
		else
		{
			int x, val;
			scanf("%d%d", &x, &val);
			a[x] = val;
			for (int i = 0; i < M; i++) ans[i].clear();
			dfs(1);
		}
	}
	return 0;
}