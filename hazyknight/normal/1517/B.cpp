#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int MAXN = 105;

struct path
{
	int v,x,y;
	
	bool operator < (const path &p)const
	{
		return v < p.v;
	}
}a[MAXN * MAXN];

int T,n,m,tot;
int b[MAXN][MAXN];
int ans[MAXN][MAXN];

bool vis[MAXN][MAXN];

int main()
{
	scanf("%d",&T);
	while (T--)
	{
		scanf("%d%d",&n,&m);
		tot = 0;
		for (int i = 1;i <= n;i++)
			for (int j = 1;j <= m;j++)
			{
				scanf("%d",&b[i][j]);
				a[++tot] = (path){b[i][j],i,j};
				vis[i][j] = 0;
			}
		sort(a + 1,a + tot + 1);
		for (int i = 1;i <= m;i++)
			for (int j = 1;j <= n;j++)
				ans[i][j] = 0;
		for (int i = 1;i <= m;i++)
		{
			ans[i][a[i].x] = a[i].y;
			vis[a[i].x][a[i].y] = 1;
		}
		for (int i = 1;i <= m;i++)
			for (int j = 1;j <= n;j++)
				if (!ans[i][j])
					for (int k = 1;k <= m;k++)
						if (!vis[j][k])
						{
							vis[j][k] = 1;
							ans[i][j] = k;
							break;
						}
		for (int i = 1;i <= n;i++,printf("\n"))
			for (int j = 1;j <= m;j++)
				printf("%d ",b[i][ans[j][i]]);
	}
	return 0;
}