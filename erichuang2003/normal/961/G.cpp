#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <vector>

using namespace std;

const int MAXN = 200000 + 1000;
const int MOD = 1000000000 + 7;

int qpow(int x, int y)
{
	int ret = 1;
	for(; y; x = (long long)x * x % MOD, y >>= 1)
		if(y & 1)
			ret = (long long)ret * x % MOD;
	return ret;
}

int n, k;
int a[MAXN], sum;
int fac[MAXN], ifac[MAXN];
int ans = 0;

void init()
{
	fac[0] = 1;
	for(int i = 1; i < MAXN; i++)
		fac[i] = (long long)fac[i - 1] * i % MOD;
	ifac[MAXN - 1] = qpow(fac[MAXN - 1], MOD - 2);
	for(int i = MAXN - 2; i >= 0; i--)
		ifac[i] = (long long)ifac[i + 1] * (i + 1) % MOD;
	// cerr << ifac[5] << endl;
}

int get_c(int n, int m)
{
	if(n < 0 || m < 0 || n < m)
		return 0;
	return (long long)fac[n] * ifac[m] % MOD * ifac[n - m] % MOD;
}

int get_f(int x)
{
	if(n == 0) return 0;
	if(n == 1) return 1;
	return (qpow(1 + x, n - 1) + (long long)(n - 1) * qpow(1 + x, n - 2)) % MOD;
}

int main()
{
	ios::sync_with_stdio(false);
	// freopen("1.in", "r", stdin);
	// freopen("1.out", "w", stdout);

	init();
	cin >> n >> k;
	for(int i = 1; i <= n; i++)
		cin >> a[i];
	sum = 0;
	for(int i = 1; i <= n; i++)
		sum = (sum + a[i]) % MOD;
	// cerr << n << endl;
	for(int i = 0; i <= k - 1; i++)
	{
		// cerr << i << endl;
		long long tmp = 1;
		tmp = (long long)tmp * ((k - 1 - i) & 1 ? MOD - 1 : 1) % MOD;
		tmp = (long long)tmp * get_c(k - 1, i) % MOD;
		tmp = (long long)tmp * get_f(i) % MOD;
		ans = (ans + tmp) % MOD;
	}
	ans = (long long)ans * ifac[k - 1] % MOD;
	ans = (long long)ans * sum % MOD;
	cout << ans << endl;

	return 0;
}