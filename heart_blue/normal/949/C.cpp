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
const int N = 1e5 + 10;
vector<int> v[N];
int u[N];
int low[N], dfn[N];
int cnt, scccnt;
int top, s[N];
int in[N];
int belong[N];
int sz[N];
int flag[N];
void tarjan(int x)
{
	low[x] = dfn[x] = ++cnt;
	s[top++] = x;
	in[x] = 1;
	for (auto& y : v[x])
	{
		if (dfn[y])
		{
			if (in[y])
				low[x] = min(low[x], dfn[y]);;
		}
		else
		{
			tarjan(y);
			low[x] = min(low[x], low[y]);
		}
	}
	if (low[x] == dfn[x])
	{
		scccnt++;
		while (1)
		{
			int y = s[--top];
			in[y] = 0;
			belong[y] = scccnt;
			sz[scccnt]++;
			if (x == y) break;
		}
	}
}
void solve(int n)
{
	for (int i = 1; i <= n; i++)
	{
		if (!dfn[i])
			tarjan(i);
	}
	for (int i = 1; i <= n; i++)
	{
		for (auto& y : v[i])
		{
			if (belong[i] == belong[y]) continue;
			flag[belong[i]] = 1;
			break;
		}
	}
	pair<int, int> ans = make_pair(int(INF), 1);
	for (int i = 1; i <= scccnt; i++)
	{
		if (flag[i]) continue;
		ans = min(ans, make_pair(sz[i], i));
	}
	printf("%d\n", ans.first);
	for (int i = 1; i <= n; i++)
	{
		if (belong[i] == ans.second)
			printf("%d ", i);
	}
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n, m, h;
	scanf("%d%d%d", &n, &m, &h);
	for (int i = 1; i <= n; i++)
	{
		scanf("%d", &u[i]);
	}
	for (int i = 1; i <= m; i++)
	{
		int x, y;
		scanf("%d%d", &x, &y);
		if ((u[x] + 1) % h == u[y])
		{
			v[x].push_back(y);
		}
		if ((u[y] + 1) % h == u[x])
		{
			v[y].push_back(x);
		}
	}
	solve(n);
	return 0;
}