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

using namespace std;

const int MAXN = 1000005;

int n,m;
int fa[MAXN];
int deg[MAXN];
int ans[MAXN];

queue<int> Q;
pair<int,int> b[MAXN];
vector<int> a[MAXN];
vector<int> e[MAXN];

int getroot(int u)
{
	return u == fa[u] ? u : fa[u] = getroot(fa[u]);
}

void addE(int u,int v)
{
	e[u].push_back(v);
	deg[v]++;
}

void merge(int u,int v)
{
	fa[getroot(u)] = getroot(v);
}

int main()
{
	scanf("%d%d",&n,&m);
	for (int i = 1;i <= n;i++)
	{
		a[i].resize(m + 1);
		for (int j = 1;j <= m;j++)
			scanf("%d",&a[i][j]);
	}
	for (int i = 1;i <= n * m;i++)
		fa[i] = i;
	for (int i = 1;i <= n;i++)
	{
		for (int j = 1;j <= m;j++)
			b[j] = make_pair(a[i][j],(i - 1) * m + j);
		sort(b + 1,b + m + 1);
		for (int j = 1;j < m;j++)
			if (b[j].first == b[j + 1].first)
				merge(b[j].second,b[j + 1].second);
	}
	for (int i = 1;i <= m;i++)
	{
		for (int j = 1;j <= n;j++)
			b[j] = make_pair(a[j][i],(j - 1) * m + i);
		sort(b + 1,b + n + 1);
		for (int j = 1;j < n;j++)
			if (b[j].first == b[j + 1].first)
				merge(b[j].second,b[j + 1].second);
	}
	for (int i = 1;i <= n;i++)
	{
		for (int j = 1;j <= m;j++)
			b[j] = make_pair(a[i][j],(i - 1) * m + j);
		sort(b + 1,b + m + 1);
		for (int j = 1;j < m;j++)
			if (b[j].first < b[j + 1].first)
				addE(getroot(b[j].second),getroot(b[j + 1].second));
	}
	for (int i = 1;i <= m;i++)
	{
		for (int j = 1;j <= n;j++)
			b[j] = make_pair(a[j][i],(j - 1) * m + i);
		sort(b + 1,b + n + 1);
		for (int j = 1;j < n;j++)
			if (b[j].first < b[j + 1].first)
				addE(getroot(b[j].second),getroot(b[j + 1].second));
	}
	for (int i = 1;i <= n * m;i++)
		if (getroot(i) == i && !deg[i])
		{
			Q.push(i);
			ans[i] = 1;
		}
	while (!Q.empty())
	{
		int u = Q.front();
		Q.pop();
		for (int i = 0;i < e[u].size();i++)
			if (!--deg[e[u][i]])
			{
				ans[e[u][i]] = ans[u] + 1;
				Q.push(e[u][i]);
			}
	}
	for (int i = 1;i <= n;i++,printf("\n"))
		for (int j = 1;j <= m;j++)
			printf("%d ",ans[getroot((i - 1) * m + j)]);
	return 0;
}