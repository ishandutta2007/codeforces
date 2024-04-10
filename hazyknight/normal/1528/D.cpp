#include <bits/stdc++.h>

using namespace std;

const int MAXN = 605;

int n,m;
int MIN[MAXN];
int MINc[MAXN][MAXN];
int a[MAXN * MAXN];
int b[MAXN * MAXN];
int c[MAXN * MAXN];
int f[MAXN][MAXN];

int main()
{
	scanf("%d%d",&n,&m);
	for (int i = 0;i < n;i++)
		MIN[i] = 1e9;
	for (int i = 1;i <= m;i++)
	{
		scanf("%d%d%d",&a[i],&b[i],&c[i]);
		MIN[a[i]] = min(MIN[a[i]],c[i]);
	}
	for (int i = 0;i < n;i++)
		MIN[i]--;
	for (int i = 0;i < n;i++)
		for (int j = 0;j < n;j++)
			f[i][j] = (i == j ? 0 : 1e9);
	for (int i = 0;i <= 2 * n;i++)
	{
		for (int j = 0;j < n;j++)
			for (int k = 0;k < n;k++)
				MINc[j][k] = 2e9;
		for (int j = 1;j <= m;j++)
			MINc[a[j]][(b[j] + i) % n] = min(MINc[a[j]][(b[j] + i) % n],c[j]);
		for (int j = 0;j < n;j++)
		{
			int MN = 2e9;
			for (int k = 0;k < n;k++)
			{
				MINc[j][k] = min(MINc[j][k],MN + 1);
				MN = MINc[j][k];
			}
			for (int k = 0;k < n;k++)
			{
				MINc[j][k] = min(MINc[j][k],MN + 1);
				MN = MINc[j][k];
			}
		}
		for (int j = 0;j < n;j++)
		{
			for (int k = 0;k < n;k++)
				if (f[j][k] == i)
					for (int l = 0;l < n;l++)
						f[j][l] = min(f[j][l],f[j][k] + MINc[k][(l - (i ? MIN[j] : 0) % n + n) % n] - (i ? 0 : MIN[k]));
		}
	}
	for (int i = 0;i < n;i++,printf("\n"))
		for (int j = 0;j < n;j++)
		{
			if (i == j)
				printf("0 ");
			else
				printf("%d ",f[i][j] + MIN[i]);
		}
	return 0;
}