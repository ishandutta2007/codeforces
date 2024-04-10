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

const int MAXN = 2005;
const ll MOD = 1000000007;

int n,m;
int r[MAXN][MAXN];
int c[MAXN][MAXN];

ll f[MAXN][MAXN];
ll g[MAXN][MAXN];
ll sumf[MAXN][MAXN];
ll sumg[MAXN][MAXN];

char s[MAXN][MAXN];

int main()
{
	scanf("%d%d",&n,&m);
	for (int i = 1;i <= n;i++)
		scanf("%s",s[i] + 1);
	for (int i = 1;i <= n;i++)
	{
		int tot = 0;
		for (int j = m;j >= 1;j--)
			if (s[i][j] == 'R')
				r[i][++tot] = j;
	}
	for (int i = 1;i <= m;i++)
	{
		int tot = 0;
		for (int j = n;j >= 1;j--)
			if (s[j][i] == 'R')
				c[i][++tot] = j;
	}
	f[1][1] = g[1][1] = sumf[1][1] = 1,sumg[1][1] = 1;
	for (int i = 1;i <= n;i++)
		for (int j = 1;j <= m;j++)
		{
			if (i == 1 && j == 1)
				continue;
			if (j > 1 && r[i][m - j + 1] - 1 <= j - 1)
				f[i][j] = (sumg[i][j - 1] - sumg[i][r[i][m - j + 1] - 1]) % MOD;
			if (i > 1 && c[j][n - i + 1] - 1 <= i - 1)
				g[i][j] = (sumf[i - 1][j] - sumf[c[j][n - i + 1] - 1][j]) % MOD;
			sumf[i][j] = (sumf[i - 1][j] + f[i][j]) % MOD;
			sumg[i][j] = (sumg[i][j - 1] + g[i][j]) % MOD;
		}
	if (n == 1 && m == 1)
		puts("1");
	else
		printf("%lld\n",((f[n][m] + g[n][m]) % MOD + MOD) % MOD);
	return 0;
}