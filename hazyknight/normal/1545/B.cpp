#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int MAXN = 100005;
const ll MOD = 998244353;

int T,n,tot;

char s[MAXN];
char t[MAXN];

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
	for (int i = 1;i <= 100000;i++)
		fac[i] = fac[i - 1] * i % MOD;
	inv[100000] = power(fac[100000],MOD - 2);
	for (int i = 100000;i >= 1;i--)
		inv[i - 1] = inv[i] * i % MOD;
}

ll C(int x,int y)
{
	return fac[x] * inv[y] % MOD * inv[x - y] % MOD;
}

int main()
{
	init();
	scanf("%d",&T);
	while (T--)
	{
		scanf("%d%s",&n,s + 1);
		tot = 0;
		int cnt = 0;
		for (int i = 1;i <= n;i++)
		{
			t[++tot] = s[i];
			if (tot >= 2 && t[tot] == '1' && t[tot - 1] == '1')
			{
				tot -= 2;
				cnt++;
			}
		}
		int c = 0;
		for (int i = 0;i <= tot;i++)
			if (t[i] != '1')
				c++;
		printf("%lld\n",C(cnt + c - 1,c - 1));
	}
	return 0;
}