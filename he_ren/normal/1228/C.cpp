#include<cstdio>
#include<cmath>
#include<iostream>
typedef long long ll;
const int MAXM = 1e6 + 5;
const int mod = 1e9 + 7;
using namespace std;

int a[MAXM],m;

inline ll pw(ll a,ll b)
{
	a%=mod; b%=mod-1;
	ll res=1;
	while(b)
	{
		if(b&1) res=res*a%mod;
		a=a*a%mod;
		b>>=1ll;
	}
	return res;
}

int main(void)
{
	int x;
	ll n;
	cin>>x>>n;
	
	int sx=sqrt(x);
	for(int i=2; i<=sx && x>1; ++i)
	{
		if(x%i==0)
		{
			a[++m]=i;
			while(x%i==0) x/=i;
		}
	}
	if(x>1) a[++m]=x;
	
	ll ans=1;
	for(int i=1; i<=m; ++i)
	{
		for(ll p=1; p<=n/a[i];)
		{
			p*=a[i];
			ans=ans*pw(a[i],n/p)%mod;
		}
	}
	
	cout<<ans;
	return 0;
}