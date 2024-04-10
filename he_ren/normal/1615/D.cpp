#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int MAXN = 2e5 + 5;

vector<int> g[MAXN], gw[MAXN];
inline void addg(int u,int v,int w)
{
	g[u].push_back(v); gw[u].push_back(w);
	g[v].push_back(u); gw[v].push_back(w);
}

int clr[MAXN];
bool invalid;
void dfs_clr(int u)
{
	for(int i=0; i<(int)g[u].size(); ++i)
	{
		int v = g[u][i], w = gw[u][i];
		if(clr[v] == -1)
		{
			clr[v] = clr[u] ^ w;
			dfs_clr(v);
			if(invalid) return;
		}
		else if(clr[v] != (clr[u] ^ w))
		{
			invalid = 1;
			return;
		}
	}
}

void solve(void)
{
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i=1; i<=n; ++i)
		g[i] = gw[i] = vector<int>();
	vector< array<int,3> > es;
	for(int i=1; i<n; ++i)
	{
		int u,v,w;
		scanf("%d%d%d",&u,&v,&w);
		es.push_back({u,v,w});
		if(w != -1) w = __builtin_parity(w);
		
		if(w != -1) addg(u, v, w);
	}
	for(int i=1; i<=m; ++i)
	{
		int u,v,w;
		scanf("%d%d%d",&u,&v,&w);
		addg(u,v,w);
	}
	
	invalid = 0;
	memset(clr, -1, (n+1)<<2);
	for(int i=1; i<=n; ++i) if(clr[i] == -1)
	{
		clr[i] = 0;
		dfs_clr(i);
	}
	
	if(invalid)
	{
		printf("NO\n");
		return;
	}
	else
	{
		printf("YES\n");
		for(auto p: es)
		{
			if(p[2] == -1) p[2] = clr[p[0]] ^ clr[p[1]];
			printf("%d %d %d\n",p[0],p[1],p[2]);
		}
	}
}

int main(void)
{
	int T;
	scanf("%d",&T);
	while(T--) solve();
	return 0;
}