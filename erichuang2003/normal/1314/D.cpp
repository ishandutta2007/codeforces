#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <iostream>
#include <algorithm>
#include <iomanip>
#include <fstream>
#include <vector>
#include <bitset>
#include <queue>
#include <stack>
#include <map>
#include <set>

using namespace std;

typedef long long ll;

const int MAXN = 85;
const int INF = (1 << 30) - 1;

int n,K,m,ans;
int f[6][MAXN];
int g[6][MAXN];
int G[MAXN][MAXN];

bool t[MAXN];

int main()
{
	scanf("%d%d",&n,&K);
	for (int i = 1;i <= n;i++)
		for (int j = 1;j <= n;j++)
			scanf("%d",&G[i][j]);
	m = K >> 1;
	int T = 50000;
	ans = INF;
	while (T--)
	{
		for (int i = 2;i <= n;i++)
			t[i] = rand() % 2;
		for (int i = 0;i <= m;i++)
			for (int j = 1;j <= n;j++)
				f[i][j] = g[i][j] = INF;
		f[0][1] = g[0][1] = 0;
		for (int i = 0;i < m;i++)
			for (int j = 1;j <= n;j++)
				if (f[i][j] < ans)
					for (int k = 1;k <= n;k++)
						if (t[k] == ((i + 1) & 1))
							f[i + 1][k] = min(f[i + 1][k],f[i][j] + G[j][k]);
		for (int i = 0;i < m;i++)
			for (int j = 1;j <= n;j++)
				if (g[i][j] < ans)
					for (int k = 1;k <= n;k++)
						if (t[k] == ((K - i - 1) & 1))
							g[i + 1][k] = min(g[i + 1][k],g[i][j] + G[k][j]);
		for (int i = 1;i <= n;i++)
			ans = min(ans,f[m][i] + g[m][i]);
	}
	printf("%d\n",ans);
	return 0;
}