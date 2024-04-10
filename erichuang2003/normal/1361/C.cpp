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

const int MAXN = 500005;

struct Edge
{
	int to;
	int c;
	bool dir;
	int nxt;
}edge[1 << 22];

int n,id;
int a[MAXN];
int b[MAXN];
int fa[1 << 21];
int first[1 << 21];
int cur[1 << 21];
int deg[1 << 21];

bool vis[1 << 22];

vector<pair<int,int> > ans;

void addE(int u,int v,int c,bool dir)
{
	deg[u]++;
	edge[++id] = (Edge){v,c,dir,first[u]};
	first[u] = id;
}

int getroot(int u)
{
	return u == fa[u] ? u : fa[u] = getroot(fa[u]);
}

void dfs(int u)
{
	for (int &i = cur[u];i;i = edge[i].nxt)
	{
		if (vis[i])
			continue;
		vis[i] = vis[i ^ 1] = 1;
		int ID = edge[i].c;
		bool fl = edge[i].dir;
		dfs(edge[i].to);
		ans.push_back(fl ? make_pair(ID * 2 - 1,ID * 2) : make_pair(ID * 2,ID * 2 - 1));
	}
}

bool ok(int l,bool flag)
{
	memset(deg,0,sizeof(deg));
	int mask = ((1 << l) - 1);
	memset(first,0,sizeof(first));
	id = 1;
	for (int i = 0;i <= mask;i++)
		fa[i] = i;
	for (int i = 1;i <= n;i++)
	{
		int u = a[i] & mask,v = b[i] & mask;
		addE(u,v,i,0);
		addE(v,u,i,1);
		fa[getroot(u)] = getroot(v);
	}
	int lst = -1;
	for (int i = 0;i <= mask;i++)
		if (deg[i])
		{
			if (lst == -1)
				lst = i;
			if (getroot(i) != getroot(lst))
				return 0;
		}
	for (int i = 0;i <= mask;i++)
		if (deg[i] & 1)
			return 0;
	if (!flag)
		return 1;
	memcpy(cur,first,sizeof(cur));
	dfs(lst);
	return 1;
}

int main()
{
	scanf("%d",&n);
	for (int i = 1;i <= n;i++)
		scanf("%d%d",&a[i],&b[i]);
	int low = 0,high = 20;
	while (low < high)
	{
		int mid = low + high + 1 >> 1;
		if (ok(mid,0))
			low = mid;
		else
			high = mid - 1;
	}
	ok(low,1);
	printf("%d\n",low);
	for (int i = 0;i < ans.size();i++)
		printf("%d %d ",ans[i].first,ans[i].second);
	printf("\n");
	return 0;
}