#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 200005;
const int mod = 1000000007;

int n, m, i, j, a, b, c, d, out;

int pw (int a, int b)
	{
	int res = 1;
	while (b!=0)
		{
		if (b%2==1)
			res = (1ll*res*a)%mod;
		a = (1ll*a*a)%mod;
		b /= 2;
		}
	return res;
	}

int fac[N];
int rev[N];

int Newton (int n, int k)
	{
	int res = fac[n];
	res = (1ll*res*rev[k])%mod;
	res = (1ll*res*rev[n-k])%mod;
	return res;
	}

int main()
	{
	fac[0] = 1;
	rev[0] = 1;
	for (i=1; i<N; i++)
		{
		fac[i] = (1ll*fac[i-1]*i)%mod;
		rev[i] = pw(fac[i], mod-2);
		}

	scanf("%d%d",&n,&m);

	for(d=0; d<=max(n,m); d++)
		{
		a = n - 2 * d;
		b = m - 2 * d;
		if (a >= 0) out = (out+(1ll*Newton(a+d, d)*2)%mod)%mod;
		if (b >= 0) out = (out+(1ll*Newton(b+d, d)*2)%mod)%mod;
		}
	out -= 2;
	out += mod;
	out %= mod;
	printf("%d\n", out);
	return 0;
	}