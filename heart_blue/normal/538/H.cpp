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
int low[N], dfn[N];
int in[N], s[N];
int belong[N];
int cnt, scccnt, top;
int clr[N], deg[N], arc[N];
vector<int> v1[N], v2[N];
void tarjan(int x)
{
	low[x] = dfn[x] = ++cnt;
	in[x] = 1;
	s[top++] = x;
	for (auto &y : v1[x])
	{
		if (dfn[y])
		{
			if (in[y])
				low[x] = min(low[x], dfn[y]);
		}
		else
		{
			tarjan(y);
			low[x] = min(low[x], low[y]);
		}
	}
	if (dfn[x] == low[x])
	{
		scccnt++;
		while (1)
		{
			int y = s[--top];
			in[y] = 0;
			belong[y] = scccnt;
			if (x == y) break;
		}
	}
}
bool solve(int n)
{
	for (int i = 0; i < n; i++)
	{
		if (!dfn[i])
			tarjan(i);
	}
	for (int i = 0; i < n; i += 2)
	{
		int x = belong[i];
		int y = belong[i + 1];
		if (x == y)
		{
			return false;
		}
		arc[x] = y;
		arc[y] = x;
	}
	for (int i = 1; i <= scccnt; i++) v2[i].clear();
	memset(deg, 0, sizeof(int)*(scccnt + 1));
	memset(clr, 0, sizeof(int)*(scccnt + 1));
	for (int i = 0; i < n; i++)
	{
		for (auto &j : v1[i])
		{
			int x = belong[i];
			int y = belong[j];
			if (x == y) continue;
			deg[y]++;
			v2[y].push_back(x);
		}
	}
	queue<int> q;
	for (int i = 1; i <= scccnt; i++)
	{
		if (deg[i] == 0) q.push(i);
	}
	while (!q.empty())
	{
		int x = q.front();
		q.pop();
		if (clr[x] == 0)
		{
			clr[x] = 1;
			clr[arc[x]] = 2;
		}
		for (auto &y : v2[x])
		{
			deg[y]--;
			if (deg[y] == 0) q.push(y);
		}
	}
	return true;
}
vector<pair<int, int>> vp;
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int t, T;
	scanf("%d%d", &t, &T);
	int n, m;
	scanf("%d%d", &n, &m);
	vp.resize(n);
	int l = 0, r = INF;
	for (auto &p : vp)
	{
		scanf("%d%d", &p.first, &p.second);
		l = max(l, p.first);
		r = min(r, p.second);
	}
	while (m--)
	{
		int x, y;
		scanf("%d%d", &x, &y);
		x--, y--;
		x <<= 1, y <<= 1;
		v1[x].push_back(y ^ 1);
		v1[x ^ 1].push_back(y);
		v1[y].push_back(x ^ 1);
		v1[y ^ 1].push_back(x);
	}
	for(int i = 0; i < vp.size(); i++)
	{
		auto p = vp[i];
		int x = i << 1;
		if (p.first > r)
		{
			v1[x].push_back(x ^ 1);
		}
		if (p.second < l)
		{
			v1[x ^ 1].push_back(x);
		}
	}
	if (!solve(2 * n))
	{
		puts("IMPOSSIBLE");
		return 0;
	}
	int l1 = 0, r1 = INF;
	int l2 = 0, r2 = INF;
	for (int i = 0; i < 2 * n; i += 2)
	{
		if (clr[belong[i]] == 1)
		{
			l1 = max(vp[i / 2].first, l1);
			r1 = min(vp[i / 2].second, r1);
		}
		else
		{
			l2 = max(vp[i / 2].first, l2);
			r2 = min(vp[i / 2].second, r2);
		}
	}
	if (l1 + l2 < t)
	{
		l1 += min(r1 - l1, t - l1 - l2);
		l2 += min(r2 - l2, t - l1 - l2);
	}
	int tot = l1 + l2;
	if (tot < t || tot > T)
	{
		puts("IMPOSSIBLE");
		return 0;
	}
	puts("POSSIBLE");
	printf("%d %d\n", l1, l2);
	for (int i = 0; i < n; i++)
	{
		if (clr[belong[i * 2]] == 1) putchar('1');
		else putchar('2');
	}
	return 0;
}