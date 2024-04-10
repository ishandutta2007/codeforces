#include <iostream>
#include <cstdio>
#include <algorithm>
#define ll long long
#define maxn 200005
using namespace std;
const int mo = 1e9 + 7;
int T;
int n, k, fac[maxn], ifac[maxn], inv[maxn];
int pow(int x, int step)
{
	int res = 1;
	for(; step; step >>= 1)
	{
		if(step & 1) res = (ll)res * x % mo;
		x = (ll)x * x % mo;
	}
	return res;
}
int calc(int x, int y)
{
	if(y < 0 || x < y) return 0;
	return (ll)fac[x] * ifac[y] % mo * ifac[x - y] % mo;
}
void solve()
{
	scanf("%d%d", &n, &k);
	inv[1] = ifac[0] = ifac[1] = fac[0] = fac[1] = 1;
	for (int i = 2; i <= n; i++)
	{
		fac[i] = (ll)fac[i - 1] * i % mo;
		inv[i] = (ll)(mo - mo / i) * inv[mo % i] % mo;
		ifac[i] = (ll)ifac[i - 1] * inv[i] % mo;
	}
	int ans;
	if(n & 1)
	{
		int x = 1;
		for (int i = 0; i < n; i += 2) x = (x + calc(n, i)) % mo;
		ans = 1;
		for (int i = 1; i <= k; i++)
		{
			ans = (ll)ans * x % mo;
		}
	}
	else
	{
		ans = 0;
		int tmp = 1, x = 1;
		for (int i = 2; i < n; i += 2) x = (x + calc(n, i)) % mo;
		for (int i = 1; i <= k; i++)
		{
			ans = (ans + (ll)tmp * pow(pow(2, k - i), n) % mo) % mo;
			tmp = (ll)tmp * x % mo;
		}
		ans = (ans + tmp) % mo;
	}
	printf("%d\n", ans);
}
int main()
{
	scanf("%d", &T);
	while(T--) solve();
	return 0;
}