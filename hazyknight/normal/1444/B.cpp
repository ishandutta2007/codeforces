#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int MAXN = 300005;
const ll MOD = 998244353;

int n;
int a[MAXN];

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
	fac[0] = 1;
	for (int i = 1;i <= (n << 1);i++)
		fac[i] = fac[i - 1] * i % MOD;
	inv[n << 1] = power(fac[n << 1],MOD - 2);
	for (int i = n << 1;i >= 1;i--)
		inv[i - 1] = inv[i] * i % MOD;
}

ll C(int x,int y)
{
	return fac[x] * inv[y] % MOD * inv[x - y] % MOD;
}

int main()
{
	scanf("%d",&n);
	init();
	for (int i = 1;i <= (n << 1);i++)
		scanf("%d",&a[i]);
	sort(a + 1,a + (n << 1) + 1);
	for (int i = 1;i < (n << 1);i++)
	{
		ll mul = (ll)(min(0,(n << 1) - i - n) + min(i,n)) * (a[i + 1] - a[i]) % MOD;
		(ans += C(2 * n,n) * mul) %= MOD;
	}
	printf("%lld\n",ans);
	return 0;
}