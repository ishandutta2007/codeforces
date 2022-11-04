#include <stdio.h>
#include <bits/stdc++.h>

using namespace std;

const int MAXN = 305;

int T,n,m;
int a[MAXN][MAXN];
int b[MAXN][MAXN];

int main()
{
	scanf("%d",&T);
	while (T--)
	{
		scanf("%d%d",&n,&m);
		for (int i = 1;i <= n;i++)
			for (int j = 1;j <= m;j++)
				scanf("%d",&a[i][j]);
		bool ok = 1;
		for (int i = 1;i <= n;i++)
			for (int j = 1;j <= m;j++)
			{
				b[i][j] = (i > 1) + (i < n) + (j > 1) + (j < m);
				if (a[i][j] > b[i][j])
					ok = 0;
			}
		puts(ok ? "YES" : "NO");
		if (ok)
		{
			for (int i = 1;i <= n;i++,printf("\n"))
				for (int j = 1;j <= m;j++)
					printf("%d ",b[i][j]);
		}
	}
	return 0;
}