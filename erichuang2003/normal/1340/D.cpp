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

const int MAXN = 100005;

struct Edge
{
	int to;
	int nxt;
}edge[MAXN << 1];

int n,id,ans;
int deg[MAXN];
int first[MAXN];

vector<pair<int,int> > ANS;

void addE(int u,int v)
{
	edge[++id] = (Edge){v,first[u]};
	first[u] = id;
}

void dfs(int u,int fa,int st)
{
	ANS.push_back(make_pair(u,st));
	if (deg[u] == 1 && u > 1)
	{
		ANS.push_back(make_pair(u,st - 1));
		return;
	}
	int ed = st,cnt = deg[u];
	for (int i = first[u];i;i = edge[i].nxt)
	{
		if (edge[i].to == fa)
			continue;
		cnt--;
		if (st == ans)
		{
			if (u == 1)
			{
				ANS.push_back(make_pair(u,0));
				st = 0;
			}
			else
			{
				ANS.push_back(make_pair(u,ed - 1 - cnt));
				st = ed - 1 - cnt;
			}
		}
		st++;
		dfs(edge[i].to,u,st);
		ANS.push_back(make_pair(u,st));
	}
	if (st != ed - 1 && u > 1)
		ANS.push_back(make_pair(u,ed - 1));
}

int main()
{
	scanf("%d",&n);
	for (int u,v,i = 1;i < n;i++)
	{
		scanf("%d%d",&u,&v);
		addE(u,v);
		addE(v,u);
		deg[u]++;
		deg[v]++;
	}
	for (int i = 1;i <= n;i++)
		ans = max(ans,deg[i]);
	dfs(1,0,0);
	printf("%d\n",(int)ANS.size());
	for (int i = 0;i < ANS.size();i++)
		printf("%d %d\n",ANS[i].first,ANS[i].second);
	return 0;
}