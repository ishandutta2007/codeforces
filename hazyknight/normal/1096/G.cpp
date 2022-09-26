#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <cstdlib>
#include <queue>
#include <ctime>
#include <vector>

using namespace std;

typedef long long ll;
typedef vector<ll> Poly;

const int MAXN = 1000005;
const ll MOD = 998244353;
const ll G = 3;

int n,k,N;
int rev[MAXN << 2];

ll ans;

Poly base;

ll power(ll a,ll b)
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

void NTT(Poly &a,int inv)
{
	for (int i = 0;i < N;i++)
		if (i < rev[i])
			swap(a[i],a[rev[i]]);
	for (int i = 1;i < N;i <<= 1)
	{
		ll wn = power(G,(MOD - 1) / (i << 1));
		if (inv == -1)
			wn = power(wn,MOD - 2);
		for (int j = 0;j < N;j += (i << 1))
		{
			ll w = 1;
			for (int k = 0;k < i;k++)
			{
				ll x = a[j + k],y = a[j + k + i] * w % MOD;
				a[j + k] = (x + y) % MOD;
				a[j + k + i] = (x - y) % MOD;
				w = w * wn % MOD;
			}
		}
	}
	if (inv == -1)
	{
		ll Inv = power(N,MOD - 2);
		for (int i = 0;i < N;i++)
			a[i] = a[i] * Inv % MOD;
	}
}

void init(int l)
{
	N = 1;
	while (N < l)
		N <<= 1;
	for (int i = 1;i < N;i++)
		rev[i] = (rev[i >> 1] >> 1) + (i & 1) * (N >> 1);
}

int main()
{
	ios::sync_with_stdio(false);
	cin >> n >> k;
	n >>= 1;
	base.resize(10);
	for (int a,i = 1;i <= k;i++)
	{
		cin >> a;
		base[a] = 1;
	}
	Poly res;
	res.push_back(1);
	while (1)
	{
		if (n & 1)
		{
			int l1 = res.size(),l2 = base.size();
			init(l1 + l2 - 1);
			res.resize(N);
			base.resize(N);
			NTT(res,1);
			NTT(base,1);
			for (int i = 0;i < N;i++)
				res[i] = res[i] * base[i] % MOD;
			NTT(res,-1);
			NTT(base,-1);
			res.resize(l1 + l2 - 1);
			base.resize(l2);
		}
		n >>= 1;
		if (!n)
			break;
		int l = base.size();
		init(l + l - 1);
		base.resize(N);
		NTT(base,1);
		for (int i = 0;i < N;i++)
			base[i] = base[i] * base[i] % MOD;
		NTT(base,-1);
		base.resize(l + l - 1);
	}
	for (int i = 0;i < res.size();i++)
		(ans += res[i] * res[i]) %= MOD;
	cout << (ans + MOD) % MOD << endl;
	return 0;
}