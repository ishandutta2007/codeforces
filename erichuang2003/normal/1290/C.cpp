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

const int MAXN = 300005;

int n,m,ans;
int u[MAXN];
int v[MAXN];
int fix[MAXN];
int fa[MAXN];
int sz[MAXN][2];

bool val[MAXN];
bool par[MAXN];

char s[MAXN];

int getval(int u)
{
	return u == fa[u] ? 0 : getval(fa[u]) ^ par[u];
}

int getroot(int u)
{
	return u == fa[u] ? u : getroot(fa[u]);
}

int size(int u)
{
	int rt = getroot(u);
	return sz[rt][0] + sz[rt][1];
}

void add(int u,int c)
{
	if (!fix[u])
		ans += min(sz[u][0],sz[u][1]) * c;
	else
		ans += sz[u][getval(fix[u]) ^ val[u]] * c;
}

int merge(int u,int v,bool c)
{
	if (size(u) > size(v))
		swap(u,v);
	bool p = getval(u) ^ getval(v) ^ c;
	int ru = getroot(u),rv = getroot(v);
	fa[ru] = rv;
	par[ru] = p;
	sz[rv][0] += sz[ru][p];
	sz[rv][1] += sz[ru][p ^ 1];
	if (fix[ru])
	{
		fix[rv] = fix[ru];
		val[rv] = val[ru];
	}
	return rv;
}

int main()
{
	scanf("%d%d%s",&n,&m,s + 1);
	for (int k,i = 1;i <= m;i++)
	{
		scanf("%d",&k);
		for (int a,j = 1;j <= k;j++)
		{
			scanf("%d",&a);
			if (u[a])
				v[a] = i;
			else
				u[a] = i;
		}
	}
	for (int i = 1;i <= m;i++)
	{
		fa[i] = i;
		sz[i][0] = 1;
		sz[i][1] = 0;
	}
	for (int i = 1;i <= n;i++)
	{
		if (!u[i])
		{
			printf("%d\n",ans);
			continue;
		}
		if (!v[i])
		{
			add(getroot(u[i]),-1);
			fix[getroot(u[i])] = u[i];
			val[getroot(u[i])] = s[i] - '0';
			add(getroot(u[i]),1);
		}
		else if (getroot(u[i]) != getroot(v[i]))
		{
			add(getroot(u[i]),-1);
			add(getroot(v[i]),-1);
			int rt = merge(u[i],v[i],(s[i] - '0') ^ 1);
			add(rt,1);
		}
		printf("%d\n",ans);
	}
	return 0;
}