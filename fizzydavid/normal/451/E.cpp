//by yjz
#include<bits/stdc++.h>
using namespace std;
#define FF first
#define SS second
#define PB push_back 
#define MP make_pair
typedef long long ll;
const ll INF=1<<28;
const ll LINF=1ll<<61;
const ll mod=1e9+7;
ll getinv(ll x)
{
	ll k=mod-2,ans=1;
	while(k>0)
	{
		if(k&1)ans=ans*x%mod;
		x=x*x%mod;
		k>>=1;
	}
	return ans;
}
ll inv[22];
ll C(ll x,ll y)
{
	ll ans=1;
	for(int i=1;i<=y;i++)
	{
		ans=(x-i+1)%mod*ans%mod*inv[i]%mod;
	}
	return ans;
}
int n;
ll a[21],s;
int main()
{
	for(int i=0;i<=20;i++)inv[i]=getinv(i);
	cin>>n>>s;
	for(int i=0;i<n;i++)cin>>a[i];
	ll ans=0;
	for(int i=0;i<(1<<n);i++)
	{
		int coef=1;
		ll sum=0;
		for(int j=0;j<n;j++)
		{
			if((i>>j)&1)
			{
				coef*=-1;
				sum+=a[j]+1;
			}
		}
		if(sum>s)continue;
		ans=(ans+C(s-sum+n-1,n-1)*coef+mod)%mod;
	}
	cout<<ans<<endl;
	return 0;
}