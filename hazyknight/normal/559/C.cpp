#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <iostream>
#include <algorithm>
#include <stack>
#include <queue>
#include <map>
#include <set>
#include <iomanip>
#include <assert.h>
#include <fstream>
 
using namespace std;

typedef long long ll;

const int MAXN = 2005;
const int MAXV = 100005;
const ll MOD = 1000000007;

int n,H,W;
int x[MAXN];
int y[MAXN];

ll f[MAXN][2];
ll fac[MAXV << 1];
ll inv[MAXV << 1];

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

ll init(int N)
{
	fac[0] = 1;
	for (int i = 1;i <= N;i++)
		fac[i] = fac[i - 1] * i % MOD;
	inv[N] = power(fac[N],MOD - 2);
	for (int i = N;i >= 1;i--)
		inv[i - 1] = inv[i] * i % MOD;
}

ll C(int x,int y)
{
	return x < y ? 0 : fac[x] * inv[y] % MOD * inv[x - y] % MOD;
}

ll ways(int x,int y)
{
	return x < 0 || y < 0 ? 0 : C(x + y,x);
}

int main()
{
	scanf("%d%d%d",&H,&W,&n);
	init(H + W);
	for (int i = 1;i <= n;i++)
		scanf("%d%d",&x[i],&y[i]);
	x[0] = y[0] = 1;
	x[n + 1] = H;
	y[n + 1] = W;
	for (int i = 0;i <= n + 1;i++)
		for (int j = i + 1;j <= n + 1;j++)
			if (x[i] > x[j] || (x[i] == x[j] && y[i] > y[j]))
			{
				swap(x[i],x[j]);
				swap(y[i],y[j]);
			}
	f[0][0] = 1;
	for (int i = 1;i <= n + 1;i++)
		for (int j = 0;j < i;j++)
		{
			(f[i][0] += f[j][1] * ways(x[i] - x[j],y[i] - y[j])) %= MOD;
			(f[i][1] += f[j][0] * ways(x[i] - x[j],y[i] - y[j])) %= MOD;
		}
	printf("%lld\n",(f[n + 1][1] - f[n + 1][0] + MOD) % MOD);
	return 0;
}