#include <bits/stdc++.h>

using namespace std;

const int MAXN = 500005;

int T,n,m,id,tot;
int deg[MAXN];
int fa[MAXN];
int p[MAXN];
int ans1[MAXN];
int ans2[MAXN];
int sz[MAXN];
int u[MAXN];
int v[MAXN];

bool vis[MAXN];

vector<int> e[MAXN];
vector<pair<int,vector<int> > > Q;

map<int,bool> G[MAXN];

int getroot(int u)
{
	return u == fa[u] ? u : fa[u] = getroot(fa[u]);
}

void addE(int u,int v)
{
	int ru = getroot(u),rv = getroot(v);
	if (ru != rv)
	{
		fa[ru] = rv;
		e[u].push_back(v);
		e[v].push_back(u);
	}
}

void dfs(int u,int fa)
{
	vis[u] = 1;
	if (fa)
	{
		vector<int> one;
		for (int i = 0;i < e[u].size();i++)
		{
			int to = e[u][i];
			if (to == fa)
				continue;
			dfs(to,u);
			if (sz[to] == 1)
				one.push_back(to);
		}
		if (one.size())
		{
			Q.push_back(make_pair(u,one));
			sz[u] = 0;
		}
		else
			sz[u] = 1;
	}
	else
	{
		vector<int> one;
		for (int i = 0;i < e[u].size();i++)
		{
			int to = e[u][i];
			if (to == fa)
				continue;
			dfs(to,u);
			if (sz[to] == 1)
				one.push_back(to);
		}
		if (one.size())
		{
			Q.push_back(make_pair(u,one));
			sz[u] = 0;
		}
		else
			Q.back().second.push_back(u);
	}
}

void tag(int u,vector<int> t)
{
	int st = ++id,ed = id + t.size();
	ans1[u] = st;
	ans2[u] = ed;
	for (int i = 0;i < t.size();i++)
	{
		ans2[t[i]] = id;
		ans1[t[i]] = ++id;
	}
}

int main()
{
	scanf("%d",&T);
	while (T--)
	{
		scanf("%d%d",&n,&m);
		Q.clear();
		for (int i = 1;i <= n;i++)
		{
			deg[i] = vis[i] = 0;
			fa[i] = i;
			G[i].clear();
			e[i].clear();
		}
		for (int i = 1;i <= m;i++)
		{
			scanf("%d%d",&u[i],&v[i]);
			deg[u[i]]++;
			deg[v[i]]++;
			G[u[i]][v[i]] = 1;
			G[v[i]][u[i]] = 1;
		}
		id = 0,tot = 0;
		for (int i = 1;i <= n;i++)
		{
			if (deg[i] == n - 1)
				ans1[i] = ans2[i] = ++id;
			else
				p[++tot] = i;
		}
		for (int i = 1;i <= tot;i++)
		{
			int cur = p[i];
			for (int j = 1;j <= tot;j++)
			{
				int mt = p[j];
				if (i != j && !G[cur][mt])
				{
					addE(cur,mt);
					break;
				}
			}
		}
		for (int i = 1;i <= tot;i++)
			if (!vis[p[i]])
				dfs(p[i],0);
		for (int i = 0;i < Q.size();i++)
			tag(Q[i].first,Q[i].second);
		for (int i = 1;i <= n;i++)
			printf("%d ",ans1[i]);
		printf("\n");
		for (int i = 1;i <= n;i++)
			printf("%d ",ans2[i]);
		printf("\n");
	}
	return 0;
}