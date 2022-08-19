#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define ll long long
#define maxn 1000005
using namespace std;
const ll mod = 1000000007;
ll m;
ll sum[4][maxn];
const ll bk2 = (mod + 1) / 2, bk3 = (mod + 1) / 3, bk6 = (mod + 1) / 6;
int main()
{
	scanf("%I64d", &m);
	sum[0][0] = 1;
	for(int i = 1; i < maxn; i++)
	{
		ll ns = 1;
		for(int j = 0; j < 4; j++)
		{
			sum[j][i] = (sum[j][i - 1] + ns * 2) % mod;
			ns = ns * i % mod * i % mod;
		}
	}
	ll nm = m % mod;
	ll ans = 0;
	for(ll i = 0; i * i <= m; i++)
	{
		ll n1 = m - i * i;
		ll l = 0, r = maxn;
		while(l < r)
		{
			ll mid = ((l + r) >> 1) + 1;
			if(mid * mid <= n1) l = mid;
			else r = mid - 1;
		}
		ll ksm[4];
		ksm[0] = 1;
		for(int j = 1; j < 4; j++)
			ksm[j] = ksm[j - 1] * i % mod * i % mod;
		ll num[4] = 
		{ksm[3] * bk3 % mod 
		- (nm + 2) * bk2 % mod * ksm[2] % mod 
		+ (3 * nm + 4) % mod * bk6 % mod * ksm[1] % mod 
		+ nm * (nm + 1) % mod * (nm + 2) % mod * bk6 % mod, 
		
		ksm[2]
		- (nm + 2) * ksm[1] % mod
		+ (3 * nm + 4) % mod * bk6 % mod, 
		
		ksm[1]
		- (nm + 2) * bk2 % mod, 
		
		bk3};
		
		ll nans = 0;
		for(int j = 0; j < 4; j++)
			nans = (nans + num[j] % mod * sum[j][l]) % mod;
		if(!i) ans = (ans + nans) % mod;
		else ans = (ans + 2 * nans) % mod;
	}
	ans = (ans % mod + mod) % mod;
	printf("%I64d\n", ans);
	return 0;
}