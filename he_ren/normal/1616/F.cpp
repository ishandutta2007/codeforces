#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int MAXN = 64 + 5;
const int MAXM = 3e2 + 5;
const int MAXP = 1e4 + 5;

int a[MAXP][MAXM], pcnt = 0;

int g[MAXN][MAXN], c[MAXM];

void solve(void)
{
	int n,m;
	scanf("%d%d",&n,&m);
	memset(g, 0, sizeof(g));
	memset(a, 0, sizeof(a));
	pcnt = 0;
	for(int i=1; i<=m; ++i)
	{
		int u,v,w;
		scanf("%d%d%d",&u,&v,&w);
		c[i] = w % 3;
		g[u][v] = g[v][u] = i;
		if(w != -1)
		{
			++pcnt;
			a[pcnt][i] = 1; a[pcnt][m+1] = w % 3;
		}
	}
	
	for(int i=1; i<=n; ++i)
		for(int j=i+1; j<=n; ++j)
			for(int k=j+1; k<=n; ++k) if(g[i][j] && g[i][k] && g[j][k])
			{
				int x = g[i][j], y = g[i][k], z = g[j][k];
				++pcnt;
				a[pcnt][x] = a[pcnt][y] = a[pcnt][z] = 1;
				a[pcnt][m+1] = 0;
			}
	
	for(int i=1; i<=pcnt; ++i)
	{
		int ii = rand() % i + 1;
		if(ii != i)
		{
			for(int j=1; j<=m+1; ++j)
				swap(a[i][j], a[ii][j]);
		}
	}
	
	pcnt = max(pcnt, m);
	for(int i=1, cur=0; i<=m; ++i)
	{
		int use = -1;
		for(int j=cur+1; j<=pcnt; ++j)
			if(a[j][i]){ use = j; break;}
		if(use == -1) continue;
		++cur;
		for(int j=i; j<=m+1; ++j) swap(a[cur][j], a[use][j]);
		
		int t = a[cur][i];
		for(int j=i; j<=m+1; ++j)
			a[cur][j] = a[cur][j] * t % 3;
		
		for(int k=1; k<=pcnt; ++k) if(k != cur && a[k][i])
		{
			t = (3 - a[k][i]) % 3;
			for(int j=i; j<=m+1; ++j)
				a[k][j] = (a[k][j] + a[cur][j] * t) % 3;
		}
	}
	
	memset(c, 0, sizeof(c));
	for(int i=1; i<=pcnt; ++i)
	{
		int pos = find(a[i]+1,a[i]+m+1,1) - a[i];
		if(pos > m && a[i][m+1]){ printf("-1\n"); return;}
		c[pos] = a[i][m+1];
	}
	
	for(int i=1; i<=m; ++i)
		printf("%d ",c[i]? c[i]: 3);
	printf("\n");
}

int main(void)
{
	srand((unsigned long long)new char ^ time(0));
	
	int T;
	scanf("%d",&T);
	while(T--) solve();
	return 0;
}