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

const int MAXN = 100005;

struct Edge
{
	int to;
	int nxt;
}edge[MAXN << 1];

int n,id,ans;
int first[MAXN];
int f[MAXN][2][2];

void addE(int u,int v)
{
	edge[++id] = (Edge){v,first[u]};
	first[u] = id;
}

void dfs(int u,int fa)
{
	int deg = 0;
	for (int i = first[u];i;i = edge[i].nxt)
		if (edge[i].to != fa)
		{
			deg++;
			dfs(edge[i].to,u);
		}
	for (int i = first[u];i;i = edge[i].nxt)
		if (edge[i].to != fa)
			f[u][1][0] = max(f[u][1][0],max(f[edge[i].to][1][0],f[edge[i].to][1][1]) + deg - 1);
	f[u][0][0] = f[u][1][0];
	for (int i = first[u];i;i = edge[i].nxt)
		if (edge[i].to != fa)
			f[u][0][0] = max(f[u][0][0],max(f[edge[i].to][0][0],f[edge[i].to][0][1]));
	int MX = 0,MX2 = 0;
	for (int i = first[u];i;i = edge[i].nxt)
		if (edge[i].to != fa)
		{
			int v = max(f[edge[i].to][1][0],f[edge[i].to][1][1]);
			if (v >= MX)
			{
				MX2 = MX;
				MX = v;
			}
			else if (v > MX2)
				MX2 = v;
		}
	f[u][0][0] = max(f[u][0][0],MX + MX2 + max(0,deg - 2));
	ans = max(ans,MX + MX2 + deg - (bool)MX - (bool)MX2 + (bool)fa);
	MX = 0,MX2 = 0;
	for (int i = first[u];i;i = edge[i].nxt)
		if (edge[i].to != fa)
		{
			int v = f[edge[i].to][1][0];
			if (v >= MX)
			{
				MX2 = MX;
				MX = v;
			}
			else if (v > MX2)
				MX2 = v;
		}
	f[u][0][1] = MX + MX2 + 1;
	f[u][1][1] = 1;
	for (int i = first[u];i;i = edge[i].nxt)
		if (edge[i].to != fa)
			f[u][1][1] = max(f[u][1][1],f[edge[i].to][1][0] + 1);
//	for (int a = 0;a <= 1;a++)
//		for (int b = 0;b <= 1;b++)
//			cerr << "f[" << u << "][" << a << "][" << b << "]=" << f[u][a][b] << endl;
}

int main()
{
//	freopen("input.txt","r",stdin);
//	freopen("output1.txt","w",stdout);
	scanf("%d",&n);
	for (int u,v,i = 1;i < n;i++)
	{
		scanf("%d%d",&u,&v);
		addE(u,v);
		addE(v,u);
	}
	int rt = 1;
	dfs(rt,0);
	ans = max(ans,f[rt][0][0]);
	ans = max(ans,f[rt][0][1]);
	printf("%d\n",ans);
	return 0;
}