#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int MAXN = 605;
const int MOD = 998244353;

int n,m;
int a[MAXN];
int b[MAXN];
int f[MAXN][MAXN];

vector<int> e[MAXN];

int main()
{
	scanf("%d%d",&n,&m);
	for (int i = 1;i <= n;i++)
		for (int j = 1;j <= n;j++)
			if (i != j)
				f[i][j] = 1e9;
	for (int u,v,i = 1;i <= m;i++)
	{
		scanf("%d%d",&u,&v);
		e[u].push_back(v);
		e[v].push_back(u);
		f[u][v] = f[v][u] = 1;
	}
	for (int k = 1;k <= n;k++)
		for (int i = 1;i <= n;i++)
			for (int j = 1;j <= n;j++)
				f[i][j] = min(f[i][j],f[i][k] + f[k][j]);
	for (int i = 1;i <= n;i++,printf("\n"))
		for (int j = 1;j <= n;j++)
		{
			int len = f[i][j];
			for (int k = 1;k <= n;k++)
				a[k] = f[k][i],b[k] = f[k][j];
			int cnt = 0;
			for (int k = 1;k <= n;k++)
				if (a[k] + b[k] == len)
					cnt++;
			if (cnt > len + 1)
			{
				printf("0 ");
				continue;
			}
			int ans = 1;
			for (int k = 1;k <= n;k++)
				if (a[k] + b[k] > len)
				{
					int C = 0;
					for (int l = 0;l < e[k].size();l++)
					{
						int to = e[k][l];
						if (a[to] == a[k] - 1 && b[to] == b[k] - 1)
							C++;
					}
					ans = (ll)ans * C % MOD;
				}
			printf("%d ",ans);
		}
	return 0;
}