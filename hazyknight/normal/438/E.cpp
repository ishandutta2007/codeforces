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
typedef vector<ll> Poly;
typedef Poly::iterator itr;

const int MAXN = 300005;
const ll MOD = 998244353;
const ll g = 3;

int n,m,N;
int rev[MAXN << 2];

ll Inv;
ll wn[2][MAXN << 2];

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

void INIT(int l)
{	
	N = 1;
	while (N < l)
		N <<= 1;
	int half = N >> 1;
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
}

void init(int l)
{
	N = 1;
	while (N < l)
		N <<= 1;
	Inv = power(N,MOD - 2);
	int half = N >> 1;
	for (int i = 1;i < N;i++)
		rev[i] = (rev[i >> 1] >> 1) + (i & 1) * half;
}

void NTT(Poly &a,bool inv)
{
	a.resize(N);
	for (int i = 0;i < N;i++)
		if (i < rev[i])
			swap(a[i],a[rev[i]]);
	for (int i = 1;i < N;i <<= 1)
		for (int j = 0;j < N;j += i << 1)
		{
			itr l = a.begin() + j,r = a.begin() + j + i;
			ll *w = wn[inv] + i,A;
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
			(a[i] *= Inv) %= MOD;
	}
}

Poly operator + (const Poly &a,const Poly &b)
{
	int l = max(a.size(),b.size());
	Poly c(l);
	for (int i = 0;i < l;i++)
		c[i] = ((i < a.size() ? a[i] : 0) + (i < b.size() ? b[i] : 0)) % MOD;
	return c;
}

Poly operator - (const Poly &a,const Poly &b)
{
	int l = max(a.size(),b.size());
	Poly c(l);
	for (int i = 0;i < l;i++)
		c[i] = ((i < a.size() ? a[i] : 0) - (i < b.size() ? b[i] : 0)) % MOD;
	return c;
}

Poly operator * (Poly a,Poly b)
{
	int l = a.size() + b.size() - 1;
	init(l);
	Poly c(N);
	NTT(a,0);
	NTT(b,0);
	for (int i = 0;i < N;i++)
		c[i] = a[i] * b[i] % MOD;
	NTT(c,1);
	c.resize(l);
	return c;
}

Poly inv(Poly A)
{
	int l = A.size();
	if (l == 1)
	{
		A[0] = power(A[0],MOD - 2);
		return A;
	}
	Poly B = A;
	B.resize((l + 1) >> 1);
	B = inv(B);
	init(l << 1);
	NTT(B,0);
	NTT(A,0);
	for (int i = 0;i < N;i++)
		(B[i] *= 2 - B[i] * A[i] % MOD) %= MOD;
	NTT(B,1);
	B.resize(l);
	return B;
}

Poly sqrt(Poly A)
{
	int l = A.size();
	if (l == 1)
		return A;
	Poly B = A;
	B.resize((l + 1) >> 1);
	B = sqrt(B);
	Poly C = B;
	C.resize(l);
	C = inv(C);
	init(l << 1);
	NTT(B,0);
	NTT(A,0);
	NTT(C,0);
	for (int i = 0;i < N;i++)
		B[i] = (B[i] + A[i] * C[i] % MOD) * ((MOD + 1) / 2) % MOD;
	NTT(B,1);
	B.resize(l);
	return B;
}

int main()
{
	INIT(300000);
	scanf("%d%d",&n,&m);
	Poly A(m + 1);
	for (int c,i = 1;i <= n;i++)
	{
		scanf("%d",&c);
		if (c <= m)
			A[c] = 2;
	}
	int cnt = 0;
	for (int i = 0;;i++)
		if (A[i])
		{
			cnt = i;
			break;
		}
	A.resize(m + 2 * cnt + 1);
	Poly B = A;
	for (int i = 1;i <= m;i++)
		B[i] *= -2;
	B[0]++;
	B = sqrt(B);
	for (int i = 0;i <= m + 2 * cnt + 1;i++)
		B[i] = -B[i] - A[i];
	B[0]++;
	for (int i = 0;i <= m;i++)
		A[i] = A[i + cnt];
	A.resize(A.size() - cnt);
	A = B * inv(A);
	for (int i = 1 + cnt;i <= m + cnt;i++)
		printf("%lld\n",(A[i] + MOD) % MOD);
	return 0;
}