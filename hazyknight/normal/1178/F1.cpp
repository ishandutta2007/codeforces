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

typedef long long ll;

const int MAXN = 505;
const int MAXM = 1000005;
const ll MOD = 998244353;

int n,m;
int a[MAXN];

ll f[MAXN][MAXN];

int main()
{
	scanf("%d%d",&n,&m);
	for (int i = 1;i <= m;i++)
		scanf("%d",&a[i]);
	for (int i = 1;i <= m + 1;i++)
		f[i][i - 1] = 1;
	for (int l = 1;l <= m;l++)
		for (int i = 1,j = l;j <= m;i++,j++)
		{
			int MIN = i;
			for (int k = i + 1;k <= j;k++)
				if (a[k] < a[MIN])
					MIN = k;
			ll L = 0,R = 0;
			for (int k = i;k <= MIN;k++)
				(L += f[i][k - 1] * f[k][MIN - 1]) %= MOD;
			for (int k = j;k >= MIN;k--)
				(R += f[k + 1][j] * f[MIN + 1][k]) %= MOD;
			f[i][j] = L * R % MOD;
		}
	printf("%lld\n",f[1][m]);
	return 0;
}