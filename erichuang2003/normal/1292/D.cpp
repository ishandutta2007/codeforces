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

const int MAXN = 5005;
const int MAXNN = 3000005;

struct Edge
{
	int to;
	int w;
	int nxt;
}edge[MAXNN << 1];

int n,m,cc,id,N = 5000,P,G;
int first[MAXNN];
int p[MAXN];
int cnt[MAXN];
int Cnt[MAXNN];
int c[MAXN][MAXN];
int v[MAXN];
int sz[MAXNN];
int MX[MAXNN];

ll ans;

void addE(int u,int v,int w)
{
	edge[++id] = (Edge){v,w,first[u]};
	first[u] = id;
	edge[++id] = (Edge){u,w,first[v]};
	first[v] = id;
}

bool cmp(const int &a,const int &b)
{
	return c[a][P] < c[b][P];
}

void create_graph(int rt,int cp,int l,int r)
{
	if (!cp)
	{
		Cnt[rt] = cnt[v[l]];
		return;
	}
	P = p[cp];
	int curP = P;
	sort(v + l,v + r + 1,cmp);
	int lst = l,ed = rt,edv = 0;
	for (int i = l + 1;i <= r + 1;i++)
		if (i == r + 1 || c[v[i]][curP] > c[v[i - 1]][curP])
		{
			addE(ed,++cc,c[v[i - 1]][curP] - edv);
			ed = cc;
			edv = c[v[i - 1]][curP];
			create_graph(cc,cp - 1,lst,i - 1);
			lst = i;
		}
}

void init()
{
	for (int i = 2;i <= N;i++)
		for (int j = 2;j <= i;j++)
			if (i % j == 0)
			{
				if (i == j)
					p[++m] = i;
				memcpy(c[i],c[i / j],sizeof(c[i]));
				c[i][j]++;
				break;
			}
	for (int i = 2;i <= N;i++)
		for (int j = 1;j <= N;j++)
			c[i][j] += c[i - 1][j];
	for (int i = 1;i <= N;i++)
		v[i] = i;
	create_graph(cc = 1,m,1,N);
}

void getG(int u,int fa)
{
	sz[u] = Cnt[u];
	for (int i = first[u];i;i = edge[i].nxt)
		if (edge[i].to != fa)
		{
			getG(edge[i].to,u);
			sz[u] += sz[edge[i].to];
			MX[u] = max(MX[u],sz[edge[i].to]);
		}
	MX[u] = max(MX[u],n - sz[u]);
	if (MX[u] < MX[G])
		G = u;
}

ll dfs(int u,int fa,ll d)
{
	ll res = Cnt[u] * d;
	for (int i = first[u];i;i = edge[i].nxt)
		if (edge[i].to != fa)
			res += dfs(edge[i].to,u,d + edge[i].w);
	return res;
}

int main()
{
	scanf("%d",&n);
	for (int k,i = 1;i <= n;i++)
	{
		scanf("%d",&k);
		cnt[max(k,1)]++;
	}
	init();
	MX[G = 0] = 1e9;
	getG(1,0);
	printf("%lld\n",dfs(G,0,0));
	return 0;
}