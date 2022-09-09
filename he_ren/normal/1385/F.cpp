#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<queue>
#include<set>
using namespace std;
typedef pair<int,int> pii;
const int MAXN = 2e5 + 5;

struct Edge
{
	int next,to;
}e[MAXN<<1];
int head[MAXN], etot=0, deg[MAXN];
inline void add(int u,int v)
{
	e[++etot] = (Edge){ head[u],v};
	head[u] = etot;
	++deg[v];
}

int g[MAXN];

void solve(void)
{
	int n,d;
	scanf("%d%d",&n,&d);
	etot = 0;
	for(int i=1; i<=n; ++i) head[i] = deg[i] = 0;
	for(int i=1; i<n; ++i)
	{
		int u,v;
		scanf("%d%d",&u,&v);
		add(u,v); add(v,u);
	}
	
	if(d == 1)
	{
		printf("%d\n",n-1);
		return;
	}
	
	for(int i=1; i<=n; ++i) g[i] = 0;
	
	for(int i=1; i<=n; ++i) if(deg[i] == 1)
		++g[e[head[i]].to];
	
	set<pii> t;
	for(int i=1; i<=n; ++i)
		if(g[i] >= d)
			t.insert(make_pair(g[i], i));
	
	int ans = 0;
	while(!t.empty())
	{
		pii cur = *t.rbegin();
		t.erase(cur);
		
		int u = cur.second;
		ans += g[u]/d;
		
		deg[u] -= g[u] - g[u] % d;
		g[u] %= d;
		
		if(deg[u] == 1)
		{
			for(int i=head[u]; i; i=e[i].next)
			{
				int v = e[i].to;
				if(deg[v] <= 1) continue;
				if(g[v] >= d) t.erase(make_pair(g[v], v));
				++g[v];
				if(g[v] >= d) t.insert(make_pair(g[v], v));
			}
		}
	}
	printf("%d\n",ans);
}

int main(void)
{
	int T;
	scanf("%d",&T);
	while(T--) solve();
	return 0;
}