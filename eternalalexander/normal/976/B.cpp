#include <bits/stdc++.h>
#define ll long long
ll n,m,k;
int main() {
	scanf("%lld%lld%lld",&n,&m,&k);
	if (k < n) { printf("%lld %lld",k+1,1ll); return 0; }
	if (k == n) { printf("%lld %lld",n,2ll); return 0; }
	k -= n;
	ll full = k / (m-1);
	ll x = n - full;
	ll y = full % 2 ? m : 2;
	k -= full * (m-1);
	//printf(">%lld\n",k);
	if (full % 2 == 0) { y += k; }
	else y -= k;
	printf("%lld %lld\n",x,y);
	return 0;
}