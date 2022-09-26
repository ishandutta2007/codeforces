#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include <iostream>
#include <algorithm>
#include <fstream>
#include <bitset>
#include <vector>
#include <queue>
#include <stack>
#include <set>
#include <map>

using namespace std;

typedef long long ll;
typedef vector<int> Poly;

const int MAXN = 400005;
const int MOD = 998244353;
const int G = 3;

int n,k,N,ans,cnt;
int a[MAXN];
int rev[MAXN << 2];
int wn[2][MAXN << 2];

int power(int a,int b)
{
	int res = 1;
	while (b)
	{
		if (b & 1)
			res = (ll)res * a % MOD;
		a = (ll)a * a % MOD;
		b >>= 1;
	}
	return res;
}

void init(int l)
{
	N = 1;
	while (N < l)
		N <<= 1;
	for (int i = 1;i < N;i++)
		rev[i] = (rev[i >> 1] >> 1) + (i & 1) * (N >> 1);
	int half = N >> 1;
	for (int i = 0;i < half;i++)
	{
		wn[0][i + half] = power(G,(ll)(MOD - 1) * i / N);
		wn[1][i + half] = power((MOD + 1) / G,(ll)(MOD - 1) * i / N);
	}
	for (int i = half - 1;i >= 0;i--)
	{
		wn[0][i] = wn[0][i << 1];
		wn[1][i] = wn[1][i << 1];
	}
}

void NTT(Poly &v,int inv)
{
	for (int i = 0;i < N;i++)
		if (i < rev[i])
			swap(v[i],v[rev[i]]);
	for (int i = 1;i < N;i <<= 1)
		for (int j = 0;j < N;j += (i << 1))
		{
			Poly::iterator l = v.begin() + j,r = v.begin() + j + i;
			int *w = wn[inv == -1] + i,A;
			for (int k = 0;k < i;k++,l++,r++,w++)
			{
				A = (ll)*w * *r % MOD;
				*r = (*l - A) % MOD;
				*l = (*l + A) % MOD;
			}
		}
	if (inv == -1)
	{
		ll Inv = power(N,MOD - 2);
		for (int i = 0;i < N;i++)
			v[i] = (ll)v[i] * Inv % MOD;
	}
}

int main()
{
	scanf("%d%d",&n,&k);
	for (int i = 1;i <= n;i++)
		scanf("%d",&a[i]);
	for (int i = 1;i <= n;i++)
		cnt += a[i] != a[i % n + 1];
	init(cnt * 2 + 1);
	Poly res;
	res.resize(N);
	res[0] = 1;
	res[1] = k - 2;
	res[2] = 1;
	NTT(res,1);
	for (int i = 0;i < N;i++)
		res[i] = power(res[i],cnt);
	NTT(res,-1);
	for (int i = cnt + 1;i <= 2 * cnt;i++)
		(ans += res[i]) %= MOD;
	ans = (ll)ans * power(k,n - cnt) % MOD;
	printf("%d\n",(ans + MOD) % MOD);
	return 0;
}