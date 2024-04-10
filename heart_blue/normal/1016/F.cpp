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
const int N = 3e5 + 10;
vector<pair<int, int>> v[N];
int fa[N];
LL dis[N];
int flag[N];
int ok = 0;
int cnt[N];
int d[N];
void dfs(int x, LL d = 0, int p = 0)
{
	fa[x] = p;
	dis[x] = d;
	for (auto &pp : v[x])
	{
		int y, w;
		tie(y, w) = pp;
		if (y == p) continue;
		dfs(y, d + w, x);
	}
}
void dfs1(int x, int fa, int cur)
{
	for (auto &p : v[x])
	{
		int y, w;
		tie(y, w) = p;
		if (y == fa) continue;
		if (flag[y]) continue;
		cnt[cur]++;
		d[cur] = w;
		dfs1(y, x, cur);
	}
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n, m;
	scanf("%d%d", &n, &m);
	map<pair<int, int>, int> mp;
	for (int i = 1; i < n; i++)
	{
		int x, y, w;
		scanf("%d%d%d", &x, &y, &w);
		mp[{x, y}] = 1;
		mp[{y, x}] = 1;
		v[x].push_back({ y,w });
		v[y].push_back({ x,w });
	}
	dfs(1);
	int o = n;
	vector<int> vp;
	while (o)
	{
		flag[o] = 1;
		vp.push_back(o);
		o = fa[o];
	}
	for (auto &x : vp)
	{
		dfs1(x, 0, x);
		if (cnt[x] > 1)
		{
			ok = 1;
			break;
		}
	}

	if (ok)
	{
		while (m--)
			printf("%lld\n", dis[n]);
		return 0;
	}
	set<pair<LL, int>> s;
	LL maxv = 0;
	for (auto &x : vp)
	{
		s.insert({ dis[x] + d[x],x });
	}
	for (auto &x : vp)
	{
		LL cur = dis[n] - dis[x] + d[x];
		s.erase({ dis[x] + d[x],x });
		auto iter = s.rbegin();
		while (iter != s.rend())
		{
			LL w;
			int y;
			tie(w, y) = *iter;
			if (d[y] > 0 || d[x] > 0 || !mp.count({ x,y }))
			{
				maxv = max(cur + w, maxv);
				break;
			}
			iter++;
		}
	}
	while (m--)
	{
		int x;
		scanf("%d", &x);
		printf("%lld\n", min(dis[n], maxv + x));
	}
	return 0;
}