#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int mod = 998244353;
const int N = 400005;

int n, k;
int a [N];
int fac [N];
int rev [N];

int pw (int a, int b)
	{
	int res = 1;
	while (b!=0)
		{
		if (b%2==1)
			res = 1ll * res * a % mod;
		a = 1ll * a * a % mod;
		b /= 2;
		}
	return res;
	}

int newton(int N, int K)
	{
	int res = fac[N];
	res = 1ll * res * rev[K] % mod;
	res = 1ll * res * rev[N-K] % mod;
	return res;
	}

int main()
	{
	fac[0] = 1;
	rev[0] = 1;

	for(int i=1; i<=400000; i++)
		{
		fac[i] = 1ll * fac[i-1] * i % mod;
		rev[i] = pw(fac[i], mod-2);
		}

	scanf("%d%d", &n, &k);

	for(int i=0; i<n; i++) 
		scanf("%d", &a[i]);

	int dif = 0;
	for(int i=0; i<n; i++)
		dif += (a[i] != a[(i+1)%n]);

	int out = pw(k,dif);
	int sum = dif; 
	for (int i=0; i<=sum; i++)
		{
		if(i>0 && k<=2)
			break;
		int sum2 = sum - i;
		if(sum2 % 2) 
			continue;
		out -= (ll) newton(sum, sum2) * newton(sum2, sum2 / 2) % mod * pw(k - 2, i) % mod;
		out += mod;
		out %= mod;

		}
	out = (ll) out * pw(2, mod - 2) % mod;
	int s = 0;
	for (int i=0; i<n; i++)
		s += (a[i] == a[(i+1)%n]);

	out = 1ll * out * pw(k, s) % mod;
	printf("%d\n", out);
	return 0;
	}