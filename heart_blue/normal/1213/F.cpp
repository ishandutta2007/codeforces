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
#include <chrono>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
#define MEM(a,b) memset((a),(b),sizeof(a))
const LL INF = 1e9 + 7;
const int N = 2e5 + 10;
vector<int> vp1[N], vp2[N];
int low[N], dfn[N], cnt;
int scccnt;
int belong[N];
int top, s[N], in[N];
int deg[N];
int ans[N];
void tarjan(int x)
{
	low[x] = dfn[x] = ++cnt;
	s[top++] = x;
	in[x] = 1;
	for (auto& y : vp1[x])
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
	if (low[x] == dfn[x])
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
void solve(int n, int k)
{
	top = 0;
	scccnt = 0;
	cnt = 0;
	memset(dfn, 0, sizeof(int) * (n + 1));
	for (int i = 1; i <= n; i++)
	{
		if (!dfn[i])
			tarjan(i);
	}
	for (int i = 1; i <= scccnt; i++)
	{
		vp2[0].push_back(i);
		deg[i] = 1;
	}
	for (int i = 1; i <= n; i++)
	{
		for (auto& j : vp1[i])
		{
			if (belong[i] == belong[j]) continue;
			vp2[belong[i]].push_back(belong[j]);
			deg[belong[j]]++;
		}
	}
	queue<int> q;
	q.push(0);
	int maxv = 0;
	while (!q.empty())
	{
		int x = q.front();
		q.pop();
		maxv = max(maxv, ans[x]);
		for (auto& y : vp2[x])
		{
			ans[y] = max(ans[y], ans[x] + 1);
			if (deg[y]-- == 1)
			{
				q.push(y);
			}
		}
	}
	if (maxv < k)
	{
		puts("NO");
		return;
	}
	puts("YES");
	for (int i = 1; i <= n; i++)
	{
		putchar(min(ans[belong[i]], k) + 'a' - 1);
	}
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n, k;
	scanf("%d%d", &n, &k);
	for(int o = 0; o < 2; o++)
	{
		int pre = 0;
		for (int i = 1; i <= n; i++)
		{
			int x;
			scanf("%d", &x);
			if (pre != 0)
			{
				vp1[pre].push_back(x);
			}
			pre = x;
		}
	}
	solve(n, k);
	return 0;
}