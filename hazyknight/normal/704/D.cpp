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

typedef long long ll;

const int MAXN = 200005;
const int INF = (1 << 30) - 1;

struct Edge
{
	int to;
	int cap;
	int nxt;
}edge[MAXN * 5];

int n,m,r,b,id = 1,totx,toty,S,T,SS,TT,ans;
int x[MAXN];
int y[MAXN];
int MNx[MAXN];
int MNy[MAXN];
int valx[MAXN];
int valy[MAXN];
int mem[MAXN];
int cur[MAXN];
int first[MAXN];
int deg[MAXN];
int degx[MAXN];
int degy[MAXN];
int dis[MAXN];
int cor[MAXN];

queue<int> Q;
map<int,int> matchx,matchy;

void addE(int u,int v,int low,int high)
{
	if (low > high)
	{
		puts("-1");
		exit(0);
	}
	deg[v] += low;
	deg[u] -= low;
	edge[++id] = (Edge){v,high - low,first[u]};
	first[u] = id;
	edge[++id] = (Edge){u,0,first[v]};
	first[v] = id;
}

bool bfs()
{
	memset(dis,-1,sizeof(dis));
	Q.push(S);
	dis[S] = 0;
	while (!Q.empty())
	{
		int u = Q.front();
		Q.pop();
		for (int i = first[u];i;i = edge[i].nxt)
			if (edge[i].cap && dis[edge[i].to] == -1)
			{
				dis[edge[i].to] = dis[u] + 1;
				Q.push(edge[i].to);
			}
	}
	return ~dis[T];
}

int dfs(int u,int f)
{
	if (u == T)
		return f;
	int res = 0;
	for (int &i = cur[u];i;i = edge[i].nxt)
		if (edge[i].cap && dis[edge[i].to] == dis[u] + 1)
		{
			int ret = dfs(edge[i].to,min(f,edge[i].cap));
			edge[i].cap -= ret;
			edge[i ^ 1].cap += ret;
			f -= ret;
			res += ret;
			if (!f)
				break;
		}
	if (!res)
		dis[u] = -1;
	return res;
}

int Dinic()
{
	int res = 0;
	while (bfs())
	{
		memcpy(cur,first,sizeof(cur));
		res += dfs(S,INF);
	}
	return res;
}

int main()
{
	scanf("%d%d%d%d",&n,&m,&r,&b);
	for (int i = 1;i <= n;i++)
	{
		scanf("%d%d",&x[i],&y[i]);
		valx[++totx] = x[i];
		valy[++toty] = y[i];
	}
	sort(valx + 1,valx + totx + 1);
	sort(valy + 1,valy + toty + 1);
	totx = unique(valx + 1,valx + totx + 1) - valx - 1;
	toty = unique(valy + 1,valy + toty + 1) - valy - 1;
	for (int i = 1;i <= totx;i++)
		matchx[valx[i]] = i;
	for (int i = 1;i <= toty;i++)
		matchy[valy[i]] = i;
	for (int i = 1;i <= n;i++)
	{
		x[i] = matchx[x[i]];
		y[i] = matchy[y[i]];
		degx[x[i]]++;
		degy[y[i]]++;
		cor[i] = id + 1;
		addE(x[i],totx + y[i],0,1);
	}
	for (int i = 1;i <= totx;i++)
		MNx[i] = degx[i];
	for (int i = 1;i <= toty;i++)
		MNy[i] = degy[i];
	S = 0,T = totx + toty + 1;
	int need = 0;
	for (int tp,l,d,i = 1;i <= m;i++)
	{
		scanf("%d%d%d",&tp,&l,&d);
		if (tp == 1)
		{
			l = matchx[l];
			if (l)
				MNx[l] = min(MNx[l],d);
		}
		else
		{
			l = matchy[l];
			if (l)
				MNy[l] = min(MNy[l],d);
		}
	}
	for (int i = 1;i <= totx;i++)
		addE(S,i,max(0,(degx[i] - MNx[i] + 1) / 2),min(degx[i],(degx[i] + MNx[i]) / 2));
	for (int i = 1;i <= toty;i++)
		addE(totx + i,T,max(0,(degy[i] - MNy[i] + 1) / 2),min(degy[i],(degy[i] + MNy[i]) / 2));
	memcpy(mem,first,sizeof(mem));
	SS = totx + toty + 2;
	TT = totx + toty + 3;
	for (int i = S;i <= T;i++)
	{
		if (deg[i] > 0)
		{
			need += deg[i];
			addE(SS,i,0,deg[i]);
		}
		if (deg[i] < 0)
			addE(i,TT,0,-deg[i]);
	}
	addE(T,S,0,INF);
	S = SS;
	T = TT;
	if (Dinic() != need)
	{
		puts("-1");
		return 0;
	}
	ans = edge[id].cap;
	memcpy(first,mem,sizeof(mem));
	S = totx + toty + 1;
	T = 0;
	ans -= Dinic();
	printf("%lld\n",(ll)min(r,b) * (n - ans) + (ll)max(r,b) * ans);
	for (int i = 1;i <= n;i++)
	{
		if (edge[cor[i]].cap)
			putchar(r < b ? 'r' : 'b');
		else
			putchar(r < b ? 'b' : 'r');
	}
	putchar('\n');
	return 0;
}