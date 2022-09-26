#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int MAXN = 605;

int n,m,q;

ll l[MAXN][MAXN];
ll f[MAXN][MAXN];
ll lim[MAXN][MAXN];

bool ok[MAXN][MAXN];

int main()
{
	memset(lim,-1,sizeof(lim));
	scanf("%d%d",&n,&m);
	for (int i = 1;i <= n;i++)
		for (int j = 1;j <= n;j++)
			if (i != j)
				f[i][j] = l[i][j] = 1e18;
	for (int u,v,w,i = 1;i <= m;i++)
	{
		scanf("%d%d%d",&u,&v,&w);
		l[u][v] = l[v][u] = w;
		f[u][v] = f[v][u] = w;
	}
	for (int k = 1;k <= n;k++)
		for (int i = 1;i <= n;i++)
			for (int j = 1;j <= n;j++)
				f[i][j] = min(f[i][j],f[i][k] + f[k][j]);
	scanf("%d",&q);
	for (int u,v,w,i = 1;i <= q;i++)
	{
		scanf("%d%d%d",&u,&v,&w);
		for (int j = 1;j <= n;j++)
			lim[j][v] = max(lim[j][v],w - f[u][j]);
		swap(u,v);
		for (int j = 1;j <= n;j++)
			lim[j][v] = max(lim[j][v],w - f[u][j]);
	}
	for (int i = 1;i <= n;i++)
		for (int j = 1;j <= n;j++)
			for (int k = 1;k <= n;k++)
				if (l[i][j] + f[j][k] <= lim[i][k])
					ok[i][j] = 1;
	int ans = 0;
	for (int i = 1;i <= n;i++)
		for (int j = i + 1;j <= n;j++)
			if (ok[i][j] || ok[j][i])
				ans++;
	printf("%d\n",ans);
	return 0;
}