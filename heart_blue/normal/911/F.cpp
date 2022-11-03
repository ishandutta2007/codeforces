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
int dis1[N];
int dis2[N];
int fa[N];
vector<int> v[N];
int flag[N];
void dfs(int x, int p, int dis[])
{
	dis[x] = dis[p] + 1;
	fa[x] = p;
	for (auto &y : v[x])
	{
		if (y == p) continue;
		dfs(y, x, dis);
	}
}
void solve(int n)
{
	int rt = 1;
	int key1, key2;
	dis1[0] = dis2[0] = -1;
	dfs(rt, 0, dis1);
	for (int i = 1; i <= n; i++)
	{
		if (dis1[i] > dis1[rt]) rt = i;
	}
	key1 = rt;
	dfs(rt, 0, dis1);
	for (int i = 1; i <= n; i++)
	{
		if (dis1[i] > dis1[rt]) rt = i;
	}
	key2 = rt;
	dfs(rt, 0, dis2);
	int x = key1;
	vector<int> vp;
	while (x)
	{
		vp.push_back(x);
		flag[x] = 1;
		x = fa[x];
	}
	int len = vp.size() - 1;
	LL ans = 1LL * len*(len + 1) / 2;
	vector<pair<int, int>> vv;
	for (int i = 1; i <= n; i++)
	{
		if (flag[i]) continue;
		int res = max(dis1[i], dis2[i]);
		ans += res;
		vv.push_back({ res,i });
	}
	printf("%lld\n", ans);
	if (!vv.empty()) sort(vv.begin(), vv.end());
	while (!vv.empty())
	{
		int i = vv.back().second;
		vv.pop_back();
		int o = key2;
		if (dis1[i] > dis2[i]) o = key1;
		printf("%d %d %d\n", o, i, i);
	}
	while (vp.size() > 1) printf("%d %d %d\n", vp[0], vp.back(), vp.back()), vp.pop_back();
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n;
	scanf("%d", &n);
	for (int i = 1; i < n; i++)
	{
		int x, y;
		scanf("%d%d", &x, &y);
		v[x].push_back(y);
		v[y].push_back(x);
	}
	solve(n);
	return 0;
}