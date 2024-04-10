#include<cstdio>
#include<iostream>
typedef long long ll;
const ll mod = 1e9 + 7;
using namespace std;

inline ll pow(ll a,ll b)
{
	ll ans=1;
	while(b)
	{
		if(b&1) ans = ans*a %mod;
		a = a*a %mod;
		b>>=1;
	}
	return ans;
}

inline ll mul(ll a,ll b)
{
	a%=mod; b%=mod;
	return a*b%mod;
}

int main(void)
{
	ll inv=pow(2,mod-2);
	
	ll n,m;
	cin>>n>>m;
	ll ans = (n%mod) * (m%mod) % mod;
	for(ll l=1,r; l<=m; l=r+1)
	{
		ll t=n/l;
		r = t? min(n/t, m): m;
		ans -= mul(mul(t , (r-l+1)) , (l+r)) * inv % mod;
		ans%=mod;
		if(ans<0) ans+=mod;
	}
	cout<<ans;
	return 0;
}