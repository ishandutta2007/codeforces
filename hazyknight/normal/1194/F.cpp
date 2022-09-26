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

const int MAXN = 200005;
const ll MOD = 1000000007;

int n,X,Y;
int t[MAXN];

ll T,ans,val;
ll f[MAXN];
ll pw2[MAXN];
ll fac[MAXN];
ll inv[MAXN];

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

void init()
{
	fac[0] = 1;
	for (int i = 1;i <= n;i++)
		fac[i] = fac[i - 1] * i % MOD;
	inv[n] = power(fac[n],MOD - 2);
	for (int i = n;i >= 1;i--)
		inv[i - 1] = inv[i] * i % MOD;
}

ll C(int x,int y)
{
	return fac[x] * inv[y] % MOD * inv[x - y] % MOD;
}

ll calc(int x,int y)
{
	if (!X)
	{
		for (int i = 0;i <= y;i++)
			(val += C(x,i)) %= MOD;
		X = x;
		Y = y;
		return val;
	}
	while (X < x)
	{
		val = (val * 2 - C(X,Y)) % MOD;
		X++;
	}
	while (Y > y)
	{
		(val -= C(X,Y)) %= MOD;
		Y--;
	}
	return val;
}

int main()
{
	scanf("%d%lld",&n,&T);
	init();
	for (int i = 1;i <= n;i++)
		scanf("%d",&t[i]);
	pw2[0] = 1;
	for (int i = 1;i <= n;i++)
		pw2[i] = pw2[i - 1] * 2 % MOD;
	f[0] = pw2[n];
	for (int i = 1;i <= n;i++)
	{
		T -= t[i];
		if (T < 0)
			break;
		if (T >= i)
		{
			f[i] = pw2[n];
			continue;
		}
		f[i] = calc(i,T) * pw2[n - i] % MOD;
	}
	for (int i = 1;i <= n;i++)
		(ans += i * (f[i] - f[i + 1])) %= MOD;
	(ans *= power(pw2[n],MOD - 2)) %= MOD;
	printf("%lld\n",(ans + MOD) % MOD);
	return 0;
}