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

const int MAXN = 400005;
const ll MOD = 998244353;
const ll g = 3;

int n,N;
int rev[MAXN];

ll m,Inv;
ll f[MAXN];
ll A[MAXN];
ll B[MAXN];
ll fac[MAXN];
ll inv[MAXN];
ll wn[2][MAXN];

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
	N = 1;
	while (N < l)
		N <<= 1;
	int half = N >> 1;
	Inv = power(N,MOD - 2);
	for (int i = 1;i < N;i++)
		rev[i] = (rev[i >> 1] >> 1) + (i & 1) * half;
	for (int i = 0;i < half;i++)
	{
		wn[0][i + half] = power(g,(MOD - 1) * i / N);
		wn[1][i + half] = power((MOD + 1) / g,(MOD - 1) * i / N);
	}
	for (int i = half - 1;i >= 0;i--)
	{
		wn[0][i] = wn[0][i << 1];
		wn[1][i] = wn[1][i << 1];
	}
	fac[0] = 1;
	for (int i = 1;i <= l;i++)
		fac[i] = fac[i - 1] * i % MOD;
	inv[l] = power(fac[l],MOD - 2);
	for (int i = l;i >= 1;i--)
		inv[i - 1] = inv[i] * i % MOD;
}

void NTT(ll *v,bool inv)
{
	for (int i = 0;i < N;i++)
		if (i < rev[i])
			swap(v[i],v[rev[i]]);
	for (int i = 1;i < N;i <<= 1)
		for (int j = 0;j < N;j += i << 1)
		{
			ll *l = v + j,*r = v + j + i,*w = wn[inv] + i,A;
			for (int k = 0;k < i;k++,l++,r++,w++)
			{
				A = *r * *w;
				*r = (*l - A) % MOD;
				*l = (*l + A) % MOD;
			}
		}
	if (inv)
	{
		for (int i = 0;i < N;i++)
			(v[i] *= Inv) %= MOD;
	}
}

int main()
{
	scanf("%d%lld",&n,&m);
	init(n << 1 | 1);
	for (int i = 0;i <= n;i++)
		scanf("%lld",&f[i]);
	for (int i = 0;i <= n;i++)
		A[i] = inv[i];
	for (int i = 0;i <= n;i++)
		B[i] = fac[n - i] * f[n - i] % MOD;
	NTT(A,0);
	NTT(B,0);
	for (int i = 0;i < N;i++)
		f[i] = A[i] * B[i] % MOD;
	NTT(f,1);
	reverse(f,f + n + 1);
	for (int i = 0;i <= n;i++)
		f[i] = f[i] * inv[i] % MOD * power(fac[i] * inv[i + 1] % MOD,m) % MOD;
	memset(A,0,sizeof(A));
	memset(B,0,sizeof(B));
	for (int i = 0;i <= n;i++)
		A[i] = (i % 2 ? -inv[i] : inv[i]);
	for (int i = 0;i <= n;i++)
		B[i] = fac[n - i] * f[n - i] % MOD;
	NTT(A,0);
	NTT(B,0);
	for (int i = 0;i < N;i++)
		f[i] = A[i] * B[i] % MOD;
	NTT(f,1);
	reverse(f,f + n + 1);
	for (int i = 0;i <= n;i++)
		f[i] = f[i] * inv[i] % MOD;
	for (int i = 0;i <= n;i++)
		printf("%lld ",(f[i] + MOD) % MOD);
	printf("\n");
	return 0;
}