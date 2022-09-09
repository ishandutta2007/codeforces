#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<queue>
using namespace std;
typedef pair<int,int> pii;
const int MAXN = 2e5 + 5;
const int MAXM = 2e5 + 5;

struct Edge
{
	int next,to;
}e[MAXM];
int head[MAXN],etot=0, deg[MAXN];
inline void add(int u,int v)
{
	e[++etot] = (Edge){ head[u],v};
	head[u] = etot;
	++deg[v];
}

int dep[MAXN];

void solve(void)
{
	int n,m;
	scanf("%d%d",&n,&m);
	etot = 0;
	for(int i=1; i<=n; ++i) head[i] = deg[i] = 0;
	vector<pii> und;
	for(int i=1; i<=m; ++i)
	{
		int t,u,v;
		scanf("%d%d%d",&t,&u,&v);
		if(t == 1) add(u,v);
		else und.push_back(make_pair(u,v));
	}
	
	queue<int> q;
	for(int i=1; i<=n; ++i)
		if(!deg[i]) dep[i] = 0, q.push(i);
	while(!q.empty())
	{
		int u=q.front(); q.pop();
		for(int i=head[u]; i; i=e[i].next)
		{
			int v = e[i].to;
			--deg[v];
			if(!deg[v]) dep[v] = dep[u] + 1, q.push(v);
		}
	}
	
	for(int i=1; i<=n; ++i)
		if(deg[i])
		{
			printf("NO\n");
			return;
		}
	printf("YES\n");
	for(int u=1; u<=n; ++u)
		for(int i=head[u]; i; i=e[i].next)
			printf("%d %d\n",u,e[i].to);
	for(int i=0; i<(int)und.size(); ++i)
	{
		int u = und[i].first, v = und[i].second;
		if(dep[u] == dep[v]) printf("%d %d\n",min(u,v),max(u,v));
		else if(dep[u] < dep[v]) printf("%d %d\n",u,v);
		else printf("%d %d\n",v,u);
	}
}

int main(void)
{
	int T;
	scanf("%d",&T);
	while(T--) solve();
	return 0;
}