#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int MAXN = 200005;

struct Edge
{
	int to;
	int len;
	int nxt;
}edge[MAXN];

int n,m,id,q,cc;
int first[MAXN];
int bel[MAXN];
int dfn[MAXN];
int low[MAXN];

ll depth[MAXN];
ll g[MAXN];
ll G[MAXN];

bool vis[MAXN];

stack<int> S;

void addE(int u,int v,int w)
{
	edge[++id] = (Edge){v,w,first[u]};
	first[u] = id;
}

void dfs(int u)
{
	dfn[u] = low[u] = ++id;
	vis[u] = 1;
	S.push(u);
	for (int i = first[u];i;i = edge[i].nxt)
		if (!dfn[edge[i].to])
		{
			depth[edge[i].to] = depth[u] + edge[i].len;
			dfs(edge[i].to);
			low[u] = min(low[u],low[edge[i].to]);
		}
		else if (vis[edge[i].to])
		{
			G[u] = __gcd(G[u],depth[u] - depth[edge[i].to] + edge[i].len);
			low[u] = min(low[u],dfn[edge[i].to]);
		}
	if (low[u] == dfn[u])
	{
		cc++;
		while (S.top() != u)
		{
			g[cc] = __gcd(g[cc],G[S.top()]);
			bel[S.top()] = cc;
			vis[S.top()] = 0;
			S.pop();
		}
		g[cc] = __gcd(g[cc],G[u]);
		bel[u] = cc;
		vis[u] = 0;
		S.pop();
	}
}

int main()
{
	scanf("%d%d",&n,&m);
	for (int u,v,w,i = 1;i <= m;i++)
	{
		scanf("%d%d%d",&u,&v,&w);
		addE(u,v,w);
	}
	id = 0;
	for (int i = 1;i <= n;i++)
		if (!dfn[i])
			dfs(i);
	scanf("%d",&q);
	for (int u,s,t,i = 1;i <= q;i++)
	{
		scanf("%d%d%d",&u,&s,&t);
		s = (t - s) % t;
		if (s % __gcd((ll)t,g[bel[u]]) == 0)
			puts("YES");
		else
			puts("NO");
	}
	return 0;
}