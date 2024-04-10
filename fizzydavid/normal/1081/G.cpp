//by yjz
#include<bits/stdc++.h>
using namespace std;
#define FF first
#define SS second
#define PB push_back
#define MP make_pair
#define foreach(it,s) for(__typeof((s).begin()) it=(s).begin();it!=(s).end();it++)
#ifndef LOCAL
#define cerr if(0)cout
#endif
typedef long long ll;
int mod;
const int maxn = 200111;
map<int, int> mp;
int n, k;
ll inv[maxn];
int id[maxn], g[maxn], gn;
ll sum;
ll calc(ll a, ll b)
{
	ll ret = 0;
	for (int i=2; i<=a+b; i++)
	{
		ll l = max(1ll, i-b), r = min(i-1ll, a);
		ll cnt = max(0ll, r-l+1);
		ret = (ret+cnt*inv[i])%mod;
	}
	return ret;
}
void solve(int l, int r, int k)
{
	if (l==r||k==1)
	{
		gn++;
		for (int i=l; i<=r; i++) id[i] = i-l+1, g[i] = gn;
		mp[r-l+1]++;
		return;
	}
	int m = l+r>>1;
	solve(l, m, k-1);
	solve(m+1, r, k-1);
}
int main()
{
	cin>>n>>k>>mod;
	inv[1] = 1;
	for (int i=2; i<maxn; i++) inv[i] = mod-1ll*(mod/i)*inv[mod%i]%mod;
	solve(1, n, k);
	ll ans = (1ll*n*(n-1)/2)%mod;
	for (auto x:mp)
	{
		for (auto y:mp)
		{
			if (x.FF>y.FF) continue;
			if (x.FF==y.FF)
			{
				ans = (ans-2ll*(1ll*x.SS*(x.SS-1)/2)%mod*calc(x.FF, x.FF))%mod;
			}
			else ans = (ans-2ll*x.SS*y.SS%mod*calc(x.FF, y.FF))%mod;
		}
	}
	/*
	for (int i=1; i<=n; i++)
	{
		for (int j=i+1; j<=n; j++)
		{
			if (g[i]!=g[j])
			{
				ans = (ans+(-2)%mod*inv[id[i]+id[j]])%mod;
			}
		}
	}
	*/
//	cerr<<"ans="<<ans<<endl;
	cout<<((ans*inv[2]%mod)+mod)%mod<<endl;
	return 0;
}