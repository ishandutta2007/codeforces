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
#include <set>
#include <iomanip>
#include <assert.h>
#include <fstream>
 
using namespace std;

const int MAXN = 300005;

struct Edge
{
	int to;
	int nxt;
}edge[MAXN << 1];

int T,n,m,id,cnt;
int fa[MAXN];
int first[MAXN];

bool vis[MAXN];
bool marked[MAXN];

vector<int> ans;

int getroot(int u)
{
	return u == fa[u] ? u : fa[u] = getroot(fa[u]);
}

void addE(int u,int v)
{
	edge[++id] = (Edge){v,first[u]};
	first[u] = id;
}

void dfs(int u)
{
	if (!marked[u])
	{
		marked[u] = 1;
		ans.push_back(u);
		for (int j = first[u];j;j = edge[j].nxt)
			marked[edge[j].to] = 1;
	}
	vis[u] = 1;
	for (int j = first[u];j;j = edge[j].nxt)
		if (!vis[edge[j].to])
			dfs(edge[j].to);
}

int main()
{
	scanf("%d",&T);
	while (T--)
	{
		id = 0;
		scanf("%d%d",&n,&m);
		for (int i = 1;i <= n;i++)
		{
			fa[i] = i;
			first[i] = 0;
			vis[i] = marked[i] = 0;
		}
		cnt = 0;
		for (int u,v,i = 1;i <= m;i++)
		{
			scanf("%d%d",&u,&v);
			addE(u,v);
			addE(v,u);
			int ru = getroot(u),rv = getroot(v);
			if (ru != rv)
			{
				cnt++;
				fa[ru] = rv;
			}
		}
		if (cnt != n - 1)
		{
			puts("NO");
			continue;
		}
		puts("YES");
		ans.clear();
		dfs(1);
		sort(ans.begin(),ans.end());
		printf("%d\n",(int)ans.size());
		for (int i = 0;i < ans.size();i++)
			printf("%d ",ans[i]);
		printf("\n");
	}
	return 0;
}