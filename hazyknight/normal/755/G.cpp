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
typedef vector<ll> Poly;
 
const int MAXN = 100005;
const ll MOD = 998244353;
const ll G = 5;
 
int n,m,N;
int rev[MAXN << 2];
 
ll Inv;
ll fac[MAXN << 2];
ll inv[MAXN << 2];
ll wn[2][MAXN << 2];
 
inline ll power(ll a,ll b)
{
	ll res = 1;
	while (b)
	{
		if (b & 1)
			res = res * a % MOD;
		a = a * a % MOD;
		b >>= 1;
	}
	return res;
}
 
inline void init()
{
	N = 131072;
	fac[0] = 1;
	for (int i = 1;i <= N;i++)
		fac[i] = fac[i - 1] * i % MOD;
	inv[N] = power(fac[N],MOD - 2);
	for (int i = N;i >= 1;i--)
		inv[i - 1] = inv[i] * i % MOD;
	int half = N >> 1;
	for (int i = 0;i < half;i++)
	{
		wn[0][i + half] = power(G,(MOD + 1) * i / N);
		wn[1][i + half] = power(wn[0][i + half],MOD - 2);
	}
	for (int i = half - 1;i >= 0;i--)
	{
		wn[0][i] = wn[0][i << 1];
		wn[1][i] = wn[1][i << 1];
	}
}
 
inline void NTTinit(int l)
{
	N = 1;
	while (N < l)
		N <<= 1;
	Inv = power(N,MOD - 2);
	for (int i = 1;i < N;i++)
		rev[i] = (rev[i >> 1] >> 1) + (i & 1) * (N >> 1);
}
 
inline void NTT(Poly &v,int inv)
{
	v.resize(N);
	for (int i = 0;i < N;i++)
		if (i < rev[i])
			swap(v[i],v[rev[i]]);
	for (int i = 1;i < N;i <<= 1)
		for (int j = 0;j < N;j += i << 1)
		{
			Poly::iterator l = v.begin() + j,r = v.begin() + j + i;
			ll *w = wn[inv == -1] + i,A;
			for (int k = 0;k < i;k++,l++,r++,w++)
			{
				A = *r * *w % MOD;
				*r = (*l - A) % MOD;
				*l = (*l + A) % MOD;
			}
		}
	if (inv == -1)
	{
		for (int i = 0;i < N;i++)
			(v[i] *= Inv) %= MOD;
	}
}

inline Poly ADD(Poly A,Poly B)
{
	int l = max(A.size(),B.size());
	A.resize(l);
	B.resize(l);
	for (int i = 0;i < l;i++)
		(A[i] += B[i]) %= MOD;
	return A;
}
 
inline Poly MUL(Poly A,Poly B)
{
	int la = A.size(),lb = B.size();
	NTTinit(la + lb - 1);
	NTT(A,1);
	NTT(B,1);
	for (int i = 0;i < N;i++)
		(A[i] *= B[i]) %= MOD;
	NTT(A,-1);
	A.resize(la + lb - 1);
	return A;
}
 
Poly INV(Poly A)
{
	int l = A.size();
	if (l == 1)
	{
		A[0] = power(A[0],MOD - 2);
		return A;
	}
	Poly a = A;
	a.resize((l + 1) >> 1);
	Poly b = INV(a);
	NTTinit(l << 1 | 1);
	NTT(A,1);
	NTT(b,1);
	for (int i = 0;i < N;i++)
		A[i] = b[i] * (2 - b[i] * A[i] % MOD) % MOD;
	NTT(A,-1);
	A.resize(l);
	return A;
}

Poly SQRT(Poly A)
{
	int l = A.size();
	if (l == 1)
		return A;
	Poly a = A;
	a.resize((l + 1) >> 1);
	Poly b = SQRT(a);
	b.resize(l);
	Poly Invb = INV(b);
	NTTinit(l << 1 | 1);
	NTT(A,1);
	NTT(b,1);
	NTT(Invb,1);
	for (int i = 0;i < N;i++)
		A[i] = (b[i] + A[i] * Invb[i] % MOD) * ((MOD + 1) >> 1) % MOD;
	NTT(A,-1);
	A.resize(l);
	return A;
}

inline Poly DER(Poly A)
{
	int l = A.size();
	for (int i = 1;i < l;i++)
		A[i - 1] = A[i] * i % MOD;
	A.pop_back();
	return A;
}
 
inline Poly DIF(Poly A)
{
	int l = A.size();
	if (!l)
	{
		A.push_back(0);
		return A;
	}
	A.push_back(A.back() * fac[l - 1] % MOD * inv[l] % MOD);
	for (int i = l - 2;i >= 0;i--)
		A[i + 1] = A[i] * fac[i] % MOD * inv[i + 1] % MOD;
	A[0] = 0;
	return A;
}
 
inline Poly LN(Poly A)
{
	int l = A.size();
	A = DIF(MUL(DER(A),INV(A)));
	A.resize(l);
	return A;
}
 
Poly EXP(Poly A)
{
	int l = A.size();
	if (l == 1)
	{
		A[0] = 1;
		return A;
	}
	Poly a = A;
	a.resize((l + 1) >> 1);
	Poly b = EXP(a);
	b.resize(l);
	Poly lnb = LN(b);
	NTTinit(l << 1 | 1);
	NTT(A,1);
	NTT(b,1);
	NTT(lnb,1);
	for (int i = 0;i < N;i++)
		A[i] = b[i] * (1 - lnb[i] + A[i]) % MOD;
	NTT(A,-1);
	A.resize(l);
	return A;
}

Poly POW(Poly A,ll b)
{
	int l = A.size();
	ll rmv = 0;
	reverse(A.begin(),A.end());
	while (A.size() && !A.back())
	{
		rmv++;
		A.pop_back();
	}
	reverse(A.begin(),A.end());
	A.resize(l);
	A = LN(A);
	for (int i = 0;i < l;i++)
		(A[i] *= b) %= MOD;
	A = EXP(A);
	rmv = min(rmv * b,(ll)l);
	reverse(A.begin(),A.end());
	while (rmv--)
		A.push_back(0);
	reverse(A.begin(),A.end());
	A.resize(l);
	return A;
}
 
int main()
{
	scanf("%d%d",&n,&m);
	init();
	Poly D;
	D.resize(max(3,m + 1));
	D[0] = D[2] = 1;
	D[1] = 6;
	D = SQRT(D);
	Poly INVD = INV(D),X1 = D,X2 = D;
	for (int i = 0;i <= m;i++)
		X2[i] = -X2[i];
	X1[0]++;
	X1[1]++;
	X2[0]++;
	X2[1]++;
	for (int i = 0;i <= m;i++)
		(X1[i] *= (MOD + 1) / 2) %= MOD;
	for (int i = 0;i <= m;i++)
		(X2[i] *= (MOD + 1) / 2) %= MOD;
	Poly A = MUL(X1,INVD),B = MUL(X2,INVD);
	for (int i = 0;i <= m;i++)
		B[i] = -B[i];
	A.resize(m + 1);
	B.resize(m + 1);
	Poly F = ADD(MUL(A,POW(X1,n)),MUL(B,POW(X2,n)));
	for (int i = 1;i <= m;i++)
	{
		if (i > n)
			printf("0 ");
		else
			printf("%lld ",(F[i] + MOD) % MOD);
	}
	printf("\n");
	return 0;
}