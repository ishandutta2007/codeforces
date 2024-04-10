#include <bits/stdc++.h>

using namespace std;

const int MAXN = 200005;

struct Edge
{
	int to;
	int ID;
	int nxt;
}edge[MAXN << 1];

int T,n,m,id;
int first[MAXN];
int a[MAXN];
int w[MAXN];
int u[MAXN];
int v[MAXN];
int Xor[MAXN];
int to[MAXN];

bool ok;
bool vis[MAXN];

vector<pair<int,int> > e[MAXN];

void addE(int u,int v,int ID)
{
	edge[++id] = (Edge){v,ID,first[u]};
	first[u] = id;
}

int popcount(int v)
{
	return v ? popcount(v - (v & -v)) ^ 1 : 0;
}

void dfs(int u)
{
	vis[u] = 1;
	for (int i = 0;i < e[u].size();i++)
	{
		int to = e[u][i].first,v = e[u][i].second;
		if (vis[to])
			ok &= (popcount(a[u] ^ a[to]) == v);
		else
		{
			a[to] = popcount(a[u]) ^ v;
			dfs(to);
		}
	}
}

void dfs1(int u,int fa,int pre)
{
	if (w[pre] == -1)
		w[pre] = a[u] ^ a[fa];
	for (int i = first[u];i;i = edge[i].nxt)
		if (edge[i].to != fa)
			dfs1(edge[i].to,u,edge[i].ID);
}

int main()
{
	scanf("%d",&T);
	while (T--)
	{
		scanf("%d%d",&n,&m);
		for (int i = 1;i <= n;i++)
			first[i] = vis[i] = 0,e[i].clear(),a[i] = -1;
		id = 0;
		for (int i = 1;i < n;i++)
		{
			scanf("%d%d%d",&u[i],&v[i],&w[i]);
			addE(u[i],v[i],i);
			addE(v[i],u[i],i);
			if (~w[i])
			{
				e[u[i]].push_back(make_pair(v[i],popcount(w[i])));
				e[v[i]].push_back(make_pair(u[i],popcount(w[i])));
			}
		}
		for (int u,v,w,i = 1;i <= m;i++)
		{
			scanf("%d%d%d",&u,&v,&w);
			e[u].push_back(make_pair(v,w));
			e[v].push_back(make_pair(u,w));
		}
		ok = 1;
		for (int i = 1;i <= n;i++)
			if (!vis[i])
			{
				a[i] = 0;
				dfs(i);
			}
		if (!ok)
			puts("NO");
		else
		{
			puts("YES");
			dfs1(1,0,0);
			for (int i = 1;i < n;i++)
				printf("%d %d %d\n",u[i],v[i],w[i]);
		}
	}
	return 0;
}