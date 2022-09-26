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

const int MAXN = 100005;
const ll MOD = 998244353;
const ll G = 3;

int n,A,B,N;
int rev[MAXN << 2];

ll fac[MAXN];
ll inv[MAXN];
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

void init()
{
	fac[0] = 1;
	for (int i = 1;i <= A + B;i++)
		fac[i] = fac[i - 1] * i % MOD;
	inv[A + B] = power(fac[A + B],MOD - 2);
	for (int i = A + B;i >= 1;i--)
		inv[i - 1] = inv[i] * i % MOD;
	N = 1;
	while (N < (n << 1 | 1))
		N <<= 1;
	int half = N >> 1;
	for (int i = 0;i < half;i++)
	{
		wn[0][i + half] = power(G,(MOD - 1) * i / N);
		wn[1][i + half] = power((MOD + 1) / G,(MOD - 1) * i / N);
	}
	for (int i = half - 1;i >= 0;i--)
	{
		wn[0][i] = wn[0][i << 1];
		wn[1][i] = wn[1][i << 1];
	}
}

void NTT(Poly &v,int inv)
{
	v.resize(N);
	for (int i = 0;i < N;i++)
		if (i < rev[i])
			swap(v[i],v[rev[i]]);
	for (int i = 1;i < N;i <<= 1)
		for (int j = 0;j < N;j += i << 1)
		{
			Poly::iterator l = v.begin() + j,r = l + i;
			ll *w = wn[inv == -1] + i,A;
			for (int k = 0;k < i;k++,l++,r++,w++)
			{
				A = *r * *w;
				*r = (*l - A) % MOD;
				*l = (*l + A) % MOD;
			}
		}
	if (inv == -1)
	{
		ll Inv = power(N,MOD - 2);
		for (int i = 0;i < N;i++)
			(v[i] *= Inv) %= MOD;
	}
}

void NTTinit(int l)
{
	N = 1;
	while (N < l)
		N <<= 1;
	int half = N >> 1;
	for (int i = 1;i < N;i++)
		rev[i] = (rev[i >> 1] >> 1) + (i & 1) * half;
}

Poly mul(Poly a,Poly b)
{
	int l = a.size() + b.size() - 1;
	NTTinit(l);
	NTT(a,1);
	NTT(b,1);
	for (int i = 0;i < N;i++)
		(a[i] *= b[i]) %= MOD;
	NTT(a,-1);
	a.resize(l);
	return a;
}

Poly solve(int l,int r)
{
	if (l > r)
	{
		Poly res;
		res.push_back(1);
		return res;
	}
	if (l == r)
	{
		Poly res;
		res.push_back(l);
		res.push_back(1);
		return res;
	}
	int mid = l + r >> 1;
	return mul(solve(l,mid),solve(mid + 1,r));
}

ll C(int x,int y)
{
	return x < y ? 0 : fac[x] * inv[y] % MOD * inv[x - y] % MOD;
}

int main()
{
	cin >> n >> A >> B;
	A--;
	B--;
	if (A + B > n - 1)
		cout << 0 << endl;
	else
	{
		init();
		cout << (C(A + B,A) * solve(0,n - 2)[A + B] % MOD + MOD) % MOD << endl;
	}
	return 0;
}