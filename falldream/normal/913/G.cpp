#include<iostream>
#include<cstdio>
#define ll long long
using namespace std;
ll Mul(ll x,ll y,ll mod)
{
	ll res=0;
	for(;x;x>>=1,y=(y<<1)%mod)
		if(x&1) res=(res+y)%mod;
	return res;	
}
ll pow(ll x,ll k,ll mod)
{
	ll sum=1;
	for(;k;k>>=1,x=Mul(x,x,mod))
		if(k&1) sum=Mul(sum,x,mod);
	return sum;	
}
ll Calc(int al,ll y)
{
	//2^?=y mod 5^al
	ll g=-1,phi=4,mod=5;
	for(int i=0;i<4;++i) if((1<<i)%5==y%5) g=i;
	for(int i=2;i<=al;++i,phi*=5)
	{
		mod*=5;
		for(int j=0;j<5;++j)
			if(pow(2,g+j*phi,mod)==y%mod) {g+=j*phi;break;}
	}
	return g;
}
int main()
{
	int T,n;
	for(scanf("%d",&T);T;--T)
	{
		ll a,mx=1;scanf("%lld",&a);n=0;
		for(ll s=a;s;s/=10) ++n;
		for(int m=0;;++m,a*=10,mx*=10)
		{
			ll b=0;
			if(a%(1LL<<n+m)) b=(1LL<<n+m)-a%(1LL<<n+m); 
			if((a+b)%5==0) b+=1LL<<n+m;
			if(b>=mx) continue;
			ll s=Calc(n+m,(a+b)>>n+m);
			printf("%lld\n",n+m+s);
			break;
		}
	}
	return 0;
}