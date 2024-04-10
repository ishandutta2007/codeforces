#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <iostream>
#include <algorithm>
#include <fstream>
#include <iomanip>
#include <bitset>
#include <vector>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <unordered_map>

using namespace std;

typedef long long ll;

const int MAXN = 1005;
const int MAXV = 100005;
const ll MOD = 998244353;

int n,m;
int a[MAXN];

ll ans;
ll cnt[MAXV];
ll f[MAXN][MAXN];

void calc(int v)
{
	for (int i = 1;i <= n;i++)
		f[1][i] = i;
	for (int i = 2;i <= m;i++)
	{
		for (int j = 1,k = 0;j <= n;j++)
		{
			while (k + 1 < j && a[j] - a[k + 1] >= v)
				k++;
			f[i][j] = f[i - 1][k];
		}
		for (int j = 1;j <= n;j++)
			(f[i][j] += f[i][j - 1]) %= MOD;
	}
	cnt[v] = f[m][n];
}

int main()
{
	scanf("%d%d",&n,&m);
	for (int i = 1;i <= n;i++)
		scanf("%d",&a[i]);
	sort(a + 1,a + n + 1);
	for (int i = 0;i * (m - 1) <= 100000;i++)
		calc(i);
	for (int i = 0;i * (m - 1) <= 100000;i++)
		(ans += i * (cnt[i] - cnt[i + 1])) %= MOD;
	printf("%lld\n",(ans + MOD) % MOD);
	return 0;
}