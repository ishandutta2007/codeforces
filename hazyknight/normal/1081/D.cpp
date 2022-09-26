#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <iostream>
#include <algorithm>
#include <stack>
#include <queue>
#include <map>
#include <iomanip>
#include <assert.h>

using namespace std;

const int MAXN = 100005;

struct Edge
{
	int u,v,c;
	bool operator < (const Edge &p)const
	{
		return c < p.c;
	}
}edge[MAXN];

int n,m,k,id;
int x[MAXN];
int fa[MAXN << 1];
int ans[MAXN << 1];

bool mark[MAXN << 1];

int getroot(int p)
{
	if (p == fa[p])
		return p;
	int res = getroot(fa[p]);
	ans[p] = max(ans[p],ans[fa[p]]);
	return fa[p] = res;
}

int main()
{
	scanf("%d%d%d",&n,&m,&k);
	for (int i = 1;i <= n;i++)
	{
		fa[i] = i;
		mark[i] = false;
	}
	id = n;
	for (int i = 1;i <= k;i++)
	{
		scanf("%d",&x[i]);
		mark[x[i]] = true;
	}
	for (int i = 1;i <= m;i++)
		scanf("%d%d%d",&edge[i].u,&edge[i].v,&edge[i].c);
	sort(edge + 1,edge + m + 1);
	for (int i = 1;i <= m;i++)
	{
		int ra = getroot(edge[i].u),rb = getroot(edge[i].v);
		if (ra != rb)
		{
			id++;
			fa[id] = id;
			fa[ra] = fa[rb] = id;
			ans[ra] = ans[rb] = (mark[ra] && mark[rb]) * edge[i].c;
			mark[id] = (mark[ra] | mark[rb]);
		}
	}
	for (int i = 1;i <= k;i++)
	{
		getroot(x[i]);
		printf("%d ",ans[x[i]]);
	}
	printf("\n");
	return 0;
}