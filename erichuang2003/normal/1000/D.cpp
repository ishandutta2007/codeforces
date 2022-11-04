#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <cstdlib>
#include <stack>
#include <queue>
#include <set>

using namespace std;

typedef long long ll;

const ll MOD = 998244353;

int n;
int a[1005];

ll f[1005];
ll fac[1005];
ll inv[1005];

ll power(ll a,ll b)
{
	ll ret = 1;
	while (b)
	{
		if (b & 1)
			ret = ret * a % MOD;
		a = a * a % MOD;
		b >>= 1; 
	}
	return ret;
}

void init()
{
	fac[0] = 1;
	for (int i = 1;i <= 1000;i++)
		fac[i] = fac[i - 1] * i % MOD;
	inv[1000] = power(fac[1000],MOD - 2);
	for (int i = 1000;i >= 1;i--)
		inv[i - 1] = inv[i] * i % MOD;
}

ll C(ll x,ll y)
{
	if (x < y)
		return 0;
	return fac[x] * inv[y] % MOD * inv[x - y] % MOD;
}

int main()
{
	init();
	ios::sync_with_stdio(false);
	cin >> n;
	for (int i = 1;i <= n;i++)
		cin >> a[i];
	for (int i = n;i >= 1;i--)
	{
		if (a[i] <= 0)
		{
			f[i] = 0;
			continue;
		}
		for (int j = i + 1;j <= n + 1;j++)
			(f[i] += C(j - i - 1,a[i]) * f[j]) %= MOD;
		(f[i] += C(n - i,a[i])) %= MOD;
	}
	ll ans = 0;
	for (int i = 1;i <= n;i++)
		(ans += f[i]) %= MOD;
	cout << ans << endl;
	return 0;
}