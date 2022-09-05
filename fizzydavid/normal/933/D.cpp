#include<bits/stdc++.h>
using namespace std;
#define FF first
#define SS second
#define PB push_back
#define MP make_pair
typedef long long ll;
const int mod=1e9+7;
ll qpow(ll x,ll k){return k==0?1:1ll*qpow(1ll*x*x%mod,k>>1)*(k&1?x:1)%mod;}
ll getpre0(ll n)//1*f(i)
{
	return ((n+3)/4-(n+1)/4)%mod;
}
ll getpre1(ll n)//i*f(i)
{
	ll ret=0;
	ll N;
	if(n>=1)
	{
		N=((n+3)/4)%mod;
		ret+=((N*(N+1)/2)%mod*4%mod-N*3)%mod;
	}
	if(n>=3)
	{
		N=((n+1)/4)%mod;
		ret-=((N*(N+1)/2)%mod*4%mod-N)%mod;
	}
	return ret;
}
ll inv6;
ll getpre2(ll n)//i*i*f(i)
{
	ll ret=0;
	ll N;
	if(n>=1)
	{
		N=((n+3)/4)%mod;
		ret+=N*(N+1)%mod*(2*N+1)%mod*inv6%mod*16%mod;
		ret+=((N*(N+1)/2)%mod*(-24)%mod+9*N)%mod;
	}
	if(n>=3)
	{
		N=((n+1)/4)%mod;
		ret-=N*(N+1)%mod*(2*N+1)%mod*inv6%mod*16%mod;
		ret-=((N*(N+1)/2)%mod*(-8)%mod+N)%mod;
	}
	return ret;
}
ll getpre3(ll n)//i*i*i*f(i)
{
	ll ret=0;
	ll N;
	if(n>=1)
	{
		N=((n+3)/4)%mod;
		ret+=((N*(N+1)/2)%mod*((N*(N+1)/2)%mod))%mod*64%mod;
		ret+=N*(N+1)%mod*(2*N+1)%mod*inv6%mod*(-144)%mod;
		ret+=((N*(N+1)/2)%mod*(108)%mod-27*N)%mod;
	}
	if(n>=3)
	{
		N=((n+1)/4)%mod;
		ret-=((N*(N+1)/2)%mod*((N*(N+1)/2)%mod))%mod*64%mod;
		ret-=N*(N+1)%mod*(2*N+1)%mod*inv6%mod*(-48)%mod;
		ret-=((N*(N+1)/2)%mod*(12)%mod-N)%mod;
	}
	return ret;
}


ll getsum0(ll n)
{
	ll ans=0,last=0;
	for(ll i=1;i<=n;i++)
	{
		ll v=(n/i);
		ll r=n/v;
		v%=mod;
		ll cur=getpre0(r);
		ans+=(cur-last)%mod*v%mod;
		last=cur;
		i=r;
	}
	return (ans%mod+mod)%mod;
}
ll getsum1(ll n)
{
	ll ans=0,last=0;
	for(ll i=1;i<=n;i++)
	{
		ll v=(n/i);
		ll r=n/v;
		v%=mod;
		ll cur=getpre1(r);
		//cerr<<i<<","<<r<<" "<<getpre1(r)-getpre1(i-1)<<" "<<v<<endl;
		ans+=(cur-last)%mod*((v*(v+1)/2)%mod)%mod;
		last=cur;
		i=r;
	}
	return (ans%mod+mod)%mod;
}
ll getsum2(ll n)
{
	ll ans=0,last=0;
	for(ll i=1;i<=n;i++)
	{
		ll v=(n/i);
		ll r=n/v;
		v%=mod;
		ll cur=getpre2(r);
		ans+=(cur-last)%mod*((v*(v+1)%mod*(2*v+1)%mod*inv6)%mod)%mod;
		last=cur;
		i=r;
	}
	return (ans%mod+mod)%mod;
}
ll getsum3(ll n)
{
	ll ans=0,last=0;
	for(ll i=1;i<=n;i++)
	{
		ll v=(n/i);
		ll r=n/v;
		v%=mod;
		ll cur=getpre3(r);
		ans+=(cur-last)%mod*(((v*(v+1)/2)%mod)*((v*(v+1)/2)%mod)%mod)%mod;
		last=cur;
		i=r;
	}
	return (ans%mod+mod)%mod;
}
ll n;

int main()
{
	inv6=qpow(6,mod-2);
	cin>>n;
	ll sum0=getsum0(n);
	ll sum1=getsum1(n);
	ll sum2=getsum2(n);
	ll sum3=getsum3(n);
	ll pwn[4]={};
	pwn[0]=1;
	for(int i=1;i<=3;i++)pwn[i]=pwn[i-1]*(n%mod)%mod;
//	cout<<sum0<<" "<<sum1<<" "<<sum2<<" "<<sum3<<endl;
	ll Ans=0;
	Ans+=sum0*(((pwn[3]*qpow(3,mod-2)%mod+
	           pwn[2]%mod+
			   pwn[1]*2*qpow(3,mod-2)%mod)%mod)%mod)%mod;
	Ans+=sum1*(pwn[1]+4*qpow(3,mod-2)%mod)%mod;
	Ans+=((-(n+2))%mod)%mod*sum2%mod;
	Ans+=2*qpow(3,mod-2)%mod*sum3%mod;
	Ans=Ans*2%mod;
//	cout<<Ans<<endl;
	Ans=((Ans%mod+mod)%mod+(n%mod*(n%mod+1)%mod*(n%mod+2)%mod*qpow(6,mod-2)%mod)%mod)%mod;
	cout<<Ans<<endl;
	return 0;
}