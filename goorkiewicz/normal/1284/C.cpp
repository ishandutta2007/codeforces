#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 300000;
ll n, i, mod, out, res;
ll fac [N+5];

int main ()
	{
	scanf("%lld%lld", &n, &mod);

	fac[0] = 1;
	for (i=1; i<=N; i++)
		fac[i] = (fac[i-1]*i)%mod;

	for (i=1; i<=n; i++)
		{
		res = (n-i+1);
		res *= res;
		res %= mod;
		res *= fac[i];
		res %= mod;
		res *= fac[n-i];
		res %= mod;
		out += res;
		out %= mod;
		}

	printf("%lld", out);
	return 0;
	}