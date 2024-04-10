#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int MAXN = 100005;
const ll MOD = 1000000007;

int T,n,k;

ll ans;
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
	int N = 100000;
	fac[0] = 1;
	for (int i = 1;i <= N;i++)
		fac[i] = fac[i - 1] * i % MOD;
	inv[N] = power(fac[N],MOD - 2);
	for (int i = N;i >= 1;i--)
		inv[i - 1] = inv[i] * i % MOD;
}

ll C(int x,int y)
{
	return x < 0 || x < y ? 0 : fac[x] * inv[y] % MOD * inv[x - y] % MOD;
}

int main()
{
	init();
	scanf("%d",&T);
	while (T--)
	{
		scanf("%d%d",&n,&k);
		k--;
		ans = 0;
		for (int i = 1;i <= n && n - i - (i + 1) * (k - 1) - 1 + 2 * k >= 0;i++)
			(ans += C(n - i - (i + 1) * (k - 1) - 1 + 2 * k,i) * power(C(n,i),MOD - 2) % MOD) %= MOD;
		printf("%lld\n",(ans + 1 + MOD) % MOD);
	}
	return 0;
}