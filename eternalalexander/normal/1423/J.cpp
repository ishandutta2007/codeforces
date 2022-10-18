#include <bits/stdc++.h>
#define ll long long
const ll mod = 1e9+7;
const ll inv2 = (mod+1)/2;
const ll lim = 1e6;
ll x=0,ans=0;
void solve() {
	ans = 0;
	scanf("%lld",&x); 
//	assert(1 <= x && x <= lim);
	x -= x&1;
	ll cnt = x / 4 + 1;
	ans = (((cnt-1))%mod*((cnt)%mod)%mod + cnt)%mod;
//	printf("%lld\n",cnt);
	if (x%4) ans = (ans + cnt) % mod;
	/*
	for (int a = 0; 4*a <= x; ++ a) //{
		ans += (x-4*a) / 2 + 1;
	//	for (int b = 0; 4*a + 2*b <= x; ++ b) ans ++;*/
	printf("%lld\n",ans%mod);
	//return 0;
}

int main() {
	int t;scanf("%d",&t);while(t--)solve();
	return 0;
}