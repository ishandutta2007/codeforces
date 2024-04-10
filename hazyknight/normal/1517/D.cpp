#include <bits/stdc++.h>

using namespace std;

const int MAXN = 505;

int n,m,K;
int r[MAXN][MAXN];
int c[MAXN][MAXN];
int f[15][25][25];

bool ok(int x,int y)
{
	return x >= 1 && x <= n && y >= 1 && y <= m;
}

int solve(int x,int y)
{
	for (int i = 0;i <= K;i++)
		for (int j = -i;j <= i;j++)
			for (int k = abs(j) - i;k <= i - abs(j);k++)
				f[i][j + K][k + K] = 1e9;
	f[0][K][K] = 0;
	for (int i = 0;i < K;i++)
		for (int j = -i;j <= i;j++)
			for (int k = abs(j) - i;k <= i - abs(j);k++)
				if (ok(x + j,y + k))
				{
					f[i + 1][j - 1 + K][k + K] = min(f[i + 1][j - 1 + K][k + K],f[i][j + K][k + K] + c[x + j - 1][y + k]);
					f[i + 1][j + K][k + K - 1] = min(f[i + 1][j + K][k + K - 1],f[i][j + K][k + K] + r[x + j][y + k - 1]);
					f[i + 1][j + 1 + K][k + K] = min(f[i + 1][j + 1 + K][k + K],f[i][j + K][k + K] + c[x + j][y + k]);
					f[i + 1][j + K][k + K + 1] = min(f[i + 1][j + K][k + K + 1],f[i][j + K][k + K] + r[x + j][y + k]);
				}
	int MN = 1e9;
	for (int j = -K;j <= K;j++)
		for (int k = abs(j) - K;k <= K - abs(j);k++)
			if (ok(x + j,y + k))
				MN = min(MN,f[K][j + K][k + K]);
	return MN;
}

int main()
{
	scanf("%d%d%d",&n,&m,&K);
	if (K & 1)
	{
		for (int i = 1;i <= n;i++,printf("\n"))
			for (int j = 1;j <= m;j++)
				printf("-1 ");
		return 0;
	}
	K >>= 1;
	for (int i = 1;i <= n;i++)
		for (int j = 1;j < m;j++)
			scanf("%d",&r[i][j]);
	for (int i = 1;i < n;i++)
		for (int j = 1;j <= m;j++)
			scanf("%d",&c[i][j]);
	for (int i = 1;i <= n;i++,printf("\n"))
		for (int j = 1;j <= m;j++)
			printf("%d ",solve(i,j) * 2);
	return 0;
}