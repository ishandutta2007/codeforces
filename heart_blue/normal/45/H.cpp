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
const int N = 9e2 + 10;
vector<int> v1[N], v2[N];
set<int> sp[N];
int low[N], dfn[N], cnt;
int scccnt, top, s[N];
int belong[N];
int a[N][N];
vector<int> leaf[N];
void tarjan(int x, int fa = 0)
{
	low[x] = dfn[x] = ++cnt;
	s[top++] = x;
	int flag = 0;
	for (auto& y : v1[x])
	{
		if (y == fa && flag == 0)
		{
			flag = 1;
			continue;
		}
		if (dfn[y])
		{
			low[x] = min(low[x], dfn[y]);
		}
		else
		{
			tarjan(y, x);
			low[x] = min(low[x], low[y]);
		}
	}
	if (low[x] == dfn[x])
	{
		scccnt++;
		while (1)
		{
			int y = s[--top];
			belong[y] = scccnt;
			v2[scccnt].push_back(y);
			if (x == y) break;
		}
	}
}
bool add(vector<pair<int, int>>& ans, int i, int j)
{
	for (auto& x : v2[i])
	{
		for (auto& y : v2[j])
		{
			if (a[x][y]) continue;
			ans.emplace_back(x, y);
			return true;
		}
	}
	return false;
}
void dfs(int x, vector<int>& v, int fa = 0)
{
	int flag = 0;
	for (auto& y : sp[x])
	{
		if (y == fa) continue;
		flag = 1;
		dfs(y, v, x);
	}
	if (flag == 0)
		v.push_back(x);
}
void solve(int n)
{
	tarjan(1);
	for (int i = 1; i <= n; i++)
	{
		for (auto& j : v1[i])
		{
			int x = belong[i];
			int y = belong[j];
			if (x == y) continue;
			sp[x].insert(y);
			sp[y].insert(x);
		}
	}
	vector<int> vp;
	vector<int> key;
	for (int i = 1; i <= scccnt; i++)
	{
		if (sp[i].size() == 1)
			vp.push_back(i);
		else
			key.push_back(i);
	}
	if (vp.size() == 1)
	{
		puts("0");
		return;
	}
	vector<pair<int, int>> ans;
	if (vp.size() == 2)
	{
		add(ans, vp.front(), vp.back());
		puts("1");
		auto [a, b] = ans[0];
		printf("%d %d\n", a, b);
		return;
	}
	for (auto& rt : key)
	{
		int tot = vp.size();
		priority_queue<pair<int, int>> pq;
		int maxv = 0;
		for (auto& x : sp[rt])
		{
			leaf[x].clear();
			dfs(x, leaf[x], rt);
			pq.emplace((int)leaf[x].size(), x);
			maxv = max(maxv, (int)leaf[x].size());
		}
		if (maxv > tot - maxv + 1) continue;
		ans.clear();
		while (pq.size() > 1)
		{
			int x = pq.top().second; pq.pop();
			int y = pq.top().second; pq.pop();
			int a = leaf[x].back(); leaf[x].pop_back();
			int b = leaf[y].back(); leaf[y].pop_back();
			add(ans, a, b);
			if (!leaf[x].empty()) pq.emplace((int)leaf[x].size(), x);
			if (!leaf[y].empty()) pq.emplace((int)leaf[y].size(), y);
		}
		if (pq.size() == 1)
		{
			int x = pq.top().second;
			int a = leaf[x].back();
			if (!add(ans, a, rt))
			{
				int y = v2[rt][0];
				for (auto& b : v1[y])
				{
					if (b == a) continue;
					ans.emplace_back(a, b);
					break;
				}
			}
		}
		printf("%d\n", ans.size());
		for (auto [x, y] : ans)
			printf("%d %d\n", x, y);
		return;
	}
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n, m;
	scanf("%d%d", &n, &m);
	if (n == 2)
	{
		puts("-1");
		return 0;
	}
	while (m--)
	{
		int x, y;
		scanf("%d%d", &x, &y);
		a[x][y] = a[y][x] = 1;
		v1[x].push_back(y);
		v1[y].push_back(x);
	}
	solve(n);
	return 0;
}