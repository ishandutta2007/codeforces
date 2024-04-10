#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int MAXN = 260;

int T,n,m,tot;
int a[64 * 64 * 64 / 6 + 100][MAXN];
int G[MAXN][MAXN];
int b[64 * 64 * 64];
int x[MAXN];

bool pivot[64 * 64 * 64];

bool solve()
{
	if (tot < m)
		tot = m;
	memset(pivot,0,sizeof(pivot));
	for (int i = 1;i <= m;i++)
	{
		if (!a[i][i])
		{
			for (int j = 1;j <= tot;j++)
				if (!pivot[j] && a[j][i])
				{
					swap(a[i],a[j]);
					swap(b[i],b[j]);
					swap(pivot[i],pivot[j]);
					break;
				}
		}
		if (!a[i][i])
			continue;
		pivot[i] = 1;
		int inv = a[i][i];
		for (int j = 1;j <= tot;j++)
			if (!pivot[j] && a[j][i])
			{
				int mul = a[j][i] * inv % 3;
				for (int k = i;k <= m;k++)
					(a[j][k] -= a[i][k] * mul) %= 3;
				(b[j] -= b[i] * mul) %= 3;
			}
	}
	for (int i = m;i >= 1;i--)
	{
		for (int j = i + 1;j <= m;j++)
			(b[i] -= a[i][j] * x[j]) %= 3;
		if (a[i][i])
			x[i] = b[i] * a[i][i] % 3;
		else if (!b[i])
			x[i] = 0;
		else
			return 0;
	}
	for (int i = m + 1;i <= tot;i++)
		if (b[i])
			return 0;
	return 1;
}

int main()
{
	scanf("%d",&T);
	while (T--)
	{
		scanf("%d%d",&n,&m);
		tot = 0;
		memset(a,0,sizeof(a));
		memset(G,0,sizeof(G));
		memset(b,0,sizeof(b));
		for (int u,v,c,i = 1;i <= m;i++)
		{
			scanf("%d%d%d",&u,&v,&c);
			G[u][v] = i;
			G[v][u] = i;
			if (c != -1)
			{
				a[++tot][i] = 1;
				b[tot] = c % 3;
			}
		}
		for (int i = 1;i <= n;i++)
			for (int j = i + 1;j <= n;j++)
				for (int k = j + 1;k <= n;k++)
					if (G[i][j] && G[j][k] && G[i][k])
					{
						tot++;
						a[tot][G[i][j]] = a[tot][G[j][k]] = a[tot][G[k][i]] = 1;
						b[tot] = 0;
					}
		if (solve())
		{
			for (int i = 1;i <= m;i++)
			{
				(x[i] += 3) %= 3;
				printf("%d ",x[i] ? x[i] : 3);
			}
			printf("\n");
		}
		else
			puts("-1");
	}
	return 0;
}