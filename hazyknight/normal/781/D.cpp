#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include <iostream>
#include <algorithm>
#include <fstream>
#include <iomanip>
#include <vector>
#include <bitset>
#include <stack>
#include <queue>
#include <set>
#include <map>

using namespace std;

const int MAXN = 505;

int n,m,tot,tmp;
int a[MAXN];
int b[MAXN * MAXN];

bitset<MAXN> f[61][2][MAXN];

long long ans;

int main()
{
	scanf("%d%d",&n,&m);
	for (int u,v,tp,i = 1;i <= m;i++)
	{
		scanf("%d%d%d",&u,&v,&tp);
		f[0][tp][u][v] = 1;
	}
	for (int T = 1;T <= 60;T++)
	{
		for (int k = 1;k <= n;k++)
			for (int i = 1;i <= n;i++)
			{
				if (f[T - 1][0][i][k])
					f[T][0][i] = f[T][0][i] | f[T - 1][1][k];
				if (f[T - 1][1][i][k])
					f[T][1][i] = f[T][1][i] | f[T - 1][0][k];
			}
		for (int i = 1;i <= n;i++)
			for (int j = 1;j <= n;j++)
				if (f[T][0][i][j] && f[T][1][i][j] && f[T][0][j][i] && f[T][1][j][i])
				{
					puts("-1");
					return 0;
				}
	}
	for (int i = 1;i <= n;i++)
		a[i] = i;
	tot = n;
	int cur = 0;
	for (int T = 59;T >= 0;T--)
	{
		bool ok = 0;
		tmp = 0;
		for (int i = 1;i <= tot;i++)
			for (int j = 1;j <= n;j++)
				if (f[T][cur][a[i]][j])
				{
					ok = 1;
					b[++tmp] = j;
				}
		if (ok)
		{
			sort(b + 1,b + tmp + 1);
			tmp = unique(b + 1,b + tmp + 1) - b - 1;
			tot = tmp;
			for (int i = 1;i <= tot;i++)
				a[i] = b[i];
			cur ^= 1;
			ans += 1ll << T;
		}
	}
	if (ans > 1e18)
		puts("-1");
	else
		printf("%I64d\n",ans);
	return 0;
}