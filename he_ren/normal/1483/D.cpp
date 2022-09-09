#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int MAXN = 6e2 + 5;
const int MAXM = MAXN * MAXN;
const ll linf = 0x3f3f3f3f3f3f3f3f;

pair<pii,int> p[MAXM];

int f[MAXN][MAXN];
ll g[MAXN][MAXN];

int main(void)
{
	memset(g,0x3f,sizeof(g));
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i=1; i<=m; ++i)
	{
		int u,v,w;
		scanf("%d%d%d",&u,&v,&w);
		g[u][v] = g[v][u] = w;
		p[i] = make_pair(make_pair(u,v), w);
	}
	
	for(int i=1; i<=n; ++i) g[i][i] = 0;
	for(int k=1; k<=n; ++k)
		for(int i=1; i<=n; ++i)
			for(int j=1; j<=n; ++j)
				g[i][j] = min(g[i][j], g[i][k] + g[k][j]);
	int Q;
	scanf("%d",&Q);
	while(Q--)
	{
		int u,v,l;
		scanf("%d%d%d",&u,&v,&l);
		if(g[u][v] > l) continue;
		
		for(int i=1; i<=n; ++i) if(g[u][i] <= l)
			f[i][v] = max(f[i][v], l - (int)g[u][i]);
	}
	
	int ans = 0;
	for(int k=1; k<=m; ++k)
	{
		int u = p[k].first.first, v = p[k].first.second;
		bool ok = 0;
		
		for(int i=1; i<=n; ++i)
			if(f[u][i] >= p[k].second + g[v][i])
			{
				ok = 1;
				break;
			}
		if(!ok) for(int i=1; i<=n; ++i)
			if(f[v][i] >= p[k].second + g[u][i])
			{
				ok = 1;
				break;
			}
		if(ok) ++ans;
	}
	
	printf("%d",ans);
	return 0;
}