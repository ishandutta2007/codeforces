#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <assert.h>
#include <iostream>
#include <algorithm>
#include <iomanip>
#include <fstream>
#include <stack>
#include <queue>
#include <map>
#include <set>

using namespace std;

typedef long long ll;

const int MAXN = 200005;
const ll MOD = 998244353;

int n,k;
int a[MAXN];

ll f[MAXN][2];
ll ans;

ll work(int len,int l,int r)
{
	if (!len)
		return !(l && r && l == r);
	for (int i = 0;i <= len;i++)
		f[i][0] = f[i][1] = 0;
	if (!l)
	{
		len--;
		f[0][0] = k - 1;
		f[0][1] = 1;
	}
	else
		f[0][l == r] = 1;
	for (int i = 1;i <= len;i++)
	{
		f[i][0] = (f[i - 1][0] * (k - 2) + f[i - 1][1] * (k - 1)) % MOD;
		f[i][1] = f[i - 1][0];
	}
	return r ? f[len][0] : (f[len][0] + f[len][1]) % MOD;
}

int main()
{
	scanf("%d%d",&n,&k);
	for (int i = 1;i <= n;i++)
		scanf("%d",&a[i]);
	int lst = -1;
	ans = 1;
	for (int i = 1;i <= n + 2;i += 2)
		if (~a[i] || i > n)
		{
			(ans *= work((i - lst) / 2 - 1,a[lst],a[i])) %= MOD;
			lst = i;
		}
	lst = 0;
	for (int i = 2;i <= n + 2;i += 2)
		if (~a[i] || i > n)
		{
			(ans *= work((i - lst) / 2 - 1,a[lst],a[i])) %= MOD;
			lst = i;
		}
	printf("%lld\n",ans);
	return 0;
}