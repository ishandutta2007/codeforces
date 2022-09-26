#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <iostream>
#include <algorithm>
#include <iomanip>
#include <fstream>
#include <vector>
#include <bitset>
#include <queue>
#include <stack>
#include <map>
#include <set>

using namespace std;

const int MAXN = 100005;

int n,m,sz,Match_Cnt;
int u[MAXN];
int v[MAXN];
int S[MAXN];
int match[MAXN];
int ans[MAXN];
int p[MAXN];

bool vis[MAXN];

vector<int> e[MAXN];

bool ok(int u,int v)
{
	if (match[u] == v)
		return 0;
	for (int i = 0;i < e[u].size();i++)
		if (e[u][i] == v)
			return 0;
	return 1;
}

int get(int v)
{
	int a[4] = {0},cnt = 0,r = 0;
	while (1)
	{
		if (!sz)
			break;
		a[cnt++] = S[sz--];
		if (ok(v,a[cnt - 1]))
		{
			r = a[--cnt];
			break;
		}
	}
	for (int i = cnt - 1;i >= 0;i--)
		S[++sz] = a[i];
	return r;
}

bool dfs(int u)
{
	int r = get(u);
	if (r)
	{
		match[r] = u;
		ans[u] = r;
		return 1;
	}
	vis[u] = 1;
	for (int i = 1;i <= n;i++)
		if (!vis[match[i]] && ok(u,i) && dfs(match[i]))
		{
			match[i] = u;
			ans[u] = i;
			return 1;
		}
	return 0;
}

int main()
{
	scanf("%d%d",&n,&m);
	for (int i = 1;i <= m;i++)
	{
		scanf("%d%d",&u[i],&v[i]);
		e[u[i]].push_back(v[i]);
		e[v[i]].push_back(u[i]);
	}
	for (int i = 1;i <= n;i++)
	{
		e[i].push_back(i);
		sort(e[i].begin(),e[i].end());
	}
	for (int i = 1;i <= n;i++)
		p[i] = i;
	for (int T = 1;T <= 10;T++)
	{
		random_shuffle(p + 1,p + n + 1);
		memset(match,0,sizeof(match));
		memset(ans,0,sizeof(ans));
		sz = n;
		Match_Cnt = 0;
		for (int i = 1;i <= n;i++)
			S[i] = p[n - i + 1];
		for (int i = 1;i <= n && Match_Cnt < m;i++)
		{
			int r = get(p[i]);
			if (r)
			{
				Match_Cnt++;
				match[r] = p[i];
				ans[p[i]] = r;
				continue;
			}
			memset(vis,0,sizeof(vis));
			Match_Cnt += dfs(p[i]);
		}
		if (Match_Cnt < m)
			continue;
		for (int i = 1;i <= n;i++)
			if (ans[i])
				printf("%d %d\n",i,ans[i]);
		return 0;
	}
	puts("-1");
	return 0;
}