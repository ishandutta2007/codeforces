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
vector<int> v[N];
int dis1[N];
int dis2[N];
int flag[N];
void dfs1(int x, int fa, int dis[])
{
	dis[x] = dis[fa] + 1;
	for (auto& y : v[x])
	{
		if (y == fa) continue;
		dfs1(y, x, dis);
	}
}
void dfs2(int x, int fa = 0)
{
	for (auto& y : v[x])
	{
		if (y == fa) continue;
		dfs2(y, x);
		flag[x] |= flag[y];
	}
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int ncase;
	scanf("%d", &ncase);
	while (ncase--)
	{
		int n, k;
		scanf("%d%d", &n, &k);
		dis1[0] = dis2[0] = -1;
		int s, t;
		scanf("%d%d", &s, &t);
		fill(flag, flag + n + 1, 0);
		flag[s] = 1;
		vector<int> key(k);
		for (auto& x : key)
			scanf("%d", &x), flag[x] = 1;
		for (int i = 1; i <= n; i++) v[i].clear();
		for (int i = 1; i < n; i++)
		{
			int x, y;
			scanf("%d%d", &x, &y);
			v[x].push_back(y);
			v[y].push_back(x);
		}
		dfs1(s, 0, dis1);
		dfs1(t, 0, dis2);
		dfs2(s);
		int cnt = count(flag + 1, flag + n + 1, 1);
		int sum = (cnt - 1) * 2;
		int ans = INF;
		for (auto& x : key)
		{
			ans = min(ans, sum - dis1[x] + dis2[x]);
		}
		printf("%d\n", ans);
	}
	return 0;
}