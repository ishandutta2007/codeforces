#include<cstdio>
#include<cstdlib>
#include<iostream>
#include<vector>
using namespace std;
typedef long long ll;
typedef unsigned int uint;
const int MAXN = 1e5 + 5;
const ll inf = 2e17;

inline void NO(void){ printf("NO"); exit(0);}

struct Edge
{
	int v;
	ll w;
};
vector<Edge> son[MAXN];
int fa[MAXN];

ll a[MAXN],b[MAXN],need[MAXN];

void dfs(int u)
{
	need[u] = a[u]-b[u];
	if(need[u]>inf) NO();
	for(uint i=0; i<son[u].size(); ++i)
	{
		int v=son[u][i].v;
		ll w=son[u][i].w;
		dfs(v);
		
		if(need[v]>=0)
		{
			if(need[v] > (inf+w-1)/w) NO();
			need[u] += w*need[v];
		}
		else need[u] += need[v];
		if(need[u]>inf) NO();
	}
}

int main(void)
{
	int n;
	scanf("%d",&n);
	for(int i=1; i<=n; ++i) cin>>b[i];
	for(int i=1; i<=n; ++i) cin>>a[i];
	for(int i=2; i<=n; ++i)
	{
		int x;
		ll w;
		cin>>x>>w;
		if(x==i) continue;
		fa[i]=x;
		son[x].push_back((Edge){i,w});
	}
	
	for(int i=1; i<=n; ++i)
		if(!fa[i])
		{
			dfs(i);
			if(need[i]>0) NO();
		}
	printf("YES");
	return 0;
}