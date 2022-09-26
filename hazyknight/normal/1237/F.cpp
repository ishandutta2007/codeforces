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

const int MAXN = 3605;
const ll MOD = 998244353;

int n,m,q,totr,totc;

ll ans;
ll fac[MAXN];
ll inv[MAXN];
ll r[MAXN][MAXN];
ll c[MAXN][MAXN];

bool markr[MAXN];
bool markc[MAXN];

ll power(ll a,ll b)
{
	ll res = 1;
	while (b)
	{
		if (b & 1)
			(res *= a) %= MOD;
		(a *= a) %= MOD;
		b >>= 1;
	}
	return res;
}

void init(int l)
{
	fac[0] = 1;
	for (int i = 1;i <= l;i++)
		fac[i] = fac[i - 1] * i % MOD;
	inv[l] = power(fac[l],MOD - 2);
	for (int i = l;i >= 1;i--)
		inv[i - 1] = inv[i] * i % MOD;
}

ll C(int x,int y)
{
	return x < y ? 0 : fac[x] * inv[y] % MOD * inv[x - y] % MOD;
}

int main()
{
	scanf("%d%d%d",&n,&m,&q);
	init(max(n,m));
	while (q--)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		markr[x] = 1;
		markc[y] = 1;
		scanf("%d%d",&x,&y);
		markr[x] = 1;
		markc[y] = 1;
	}
	for (int i = 1;i <= n;i++)
		totr += !markr[i];
	for (int i = 1;i <= m;i++)
		totc += !markc[i];
	r[0][0] = 1;
	for (int i = 1;i <= n;i++)
		for (int j = 0;j * 2 <= i;j++)
		{
			r[i][j] = r[i - 1][j];
			if (i > 1 && j > 0 && !markr[i] && !markr[i - 1])
				(r[i][j] += r[i - 2][j - 1]) %= MOD;
		}
	c[0][0] = 1;
	for (int i = 1;i <= m;i++)
		for (int j = 0;j * 2 <= i;j++)
		{
			c[i][j] = c[i - 1][j];
			if (i > 1 && j > 0 && !markc[i] && !markc[i - 1])
				(c[i][j] += c[i - 2][j - 1]) %= MOD;
		}
	for (int i = 0;i * 2 <= totr && i <= totc;i++)
		for (int j = 0;i * 2 + j <= totr && i + 2 * j <= totc;j++)
		{
			ll vr = r[n][i] * C(totr - i * 2,j) % MOD,vc = c[m][j] * C(totc - j * 2,i) % MOD;
			(ans += vr * vc % MOD * fac[i] % MOD * fac[j]) %= MOD;
		}
	printf("%lld\n",ans);
	return 0;
}