#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include <iostream>
#include <algorithm>
#include <fstream>
#include <iomanip>
#include <vector>
#include <bitset>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <assert.h>

using namespace std;

const int MAXN = 200005;

int n,m;
int ans[MAXN];
int cnt[MAXN];

bool have[MAXN];

queue<int> Q;
vector<pair<int,int> > e[MAXN];
vector<int> v[MAXN];
vector<pair<int,int> > app[MAXN];

void addE(int u,int v,int c)
{
	e[u].push_back(make_pair(v,c));
}

void setv(int u,int c)
{
	if (u < 0)
		u = -u,c ^= 1;
	if (ans[u] != -1 && ans[u] != c)
	{
		puts("NO");
		exit(0);
	}
	if (ans[u] == -1)
	{
		for (int j = 0;j < app[u].size();j++)
		{
			cnt[app[u][j].first]++;
			if (c ^ (app[u][j].second == -1))
				have[app[u][j].first] = 1;
		}
	}
	ans[u] = c;
}

int getv(int u)
{
	return u < 0 ? ans[u] ^ 1 : ans[u];
}

void dfs(int u,int c)
{
	setv(u,c);
	for (int i = 0;i < e[u].size();i++)
		if (ans[e[u][i].first] == -1)
			dfs(e[u][i].first,e[u][i].second ^ c);
}

int main()
{
	scanf("%d%d",&n,&m);
	memset(ans,-1,sizeof(ans));
	for (int i = 1;i <= n;i++)
	{
		int k;
		scanf("%d",&k);
		v[i].resize(k);
		for (int j = 0;j < k;j++)
		{
			scanf("%d",&v[i][j]);
			app[abs(v[i][j])].push_back(make_pair(i,v[i][j] < 0 ? -1 : 1));
		}
	}
	for (int i = 1;i <= m;i++)
	{
		if (!app[i].size())
		{
			setv(i,0);
			continue;
		}
		if (app[i].size() == 1)
		{
			setv(i * app[i][0].second,1);
			continue;
		}
		if (app[i][0].second * app[i][1].second == 1)
			setv(app[i][0].second * i,1);
	}
	for (int i = 1;i <= n;i++)
		if (v[i].size() - cnt[i] == 1 && !have[i])
			Q.push(i);
	while (!Q.empty())
	{
		int u = Q.front();
		Q.pop();
		if (have[u])
			continue;
		int fl = -1;
		for (int i = 0;i < v[u].size();i++)
			if (ans[abs(v[u][i])] == -1)
			{
				fl = abs(v[u][i]);
				setv(v[u][i],1);
				break;
			}
		if (fl == -1 || app[fl].size() < 2)
			continue;
		for (int j = 0;j < app[fl].size();j++)
			if (app[fl][j].first != u)
			{
				int to = app[fl][j].first;
				if (v[to].size() - cnt[to] == 1 && !have[to])
					Q.push(to);
			}
	}
	for (int i = 1;i <= n;i++)
		if (!have[i] && v[i].size() - cnt[i] >= 2)
		{
			int a = 0,b = 0;
			for (int j = 0;j < v[i].size();j++)
				if (ans[abs(v[i][j])] == -1)
				{
					a = b;
					b = v[i][j];
				}
			addE(abs(a),abs(b),(long long)a * b < 0 ? 0 : 1);
			addE(abs(b),abs(a),(long long)a * b < 0 ? 0 : 1);
		}
	for (int i = 1;i <= m;i++)
		if (ans[i] == -1)
			dfs(i,1);
	for (int i = 1;i <= n;i++)
		if (!have[i])
		{
			puts("NO");
			return 0;
		}
	puts("YES");
	for (int i = 1;i <= m;i++)
		printf("%d",ans[i]);
	printf("\n");
	return 0;
}