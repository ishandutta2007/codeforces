#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define N 100010
#define ll long long
using namespace std;
ll p[N],num[N],swp[N],n;
int tot,tot2,cnt;
void pre_work(ll x)
{
	for(ll i=1;i*i<=x;i++)
	if(x%i==0)
	{
		num[++tot]=i;
		if(i*i!=x) num[++tot]=x/i;
	}
	sort(num+1,num+tot+1);
}
void work(ll x,ll p[],int &tot)
{
	for(ll i=2;i*i<=x;i++)
	if(x%i==0)
	{
		p[++tot]=i;
		while(x%i==0) x/=i;
	}
	if(x>1) p[++tot]=x;
}
ll euler(ll x)
{
	ll res=x;
	for(int i=1;i<=cnt;i++)
	if(res%p[i]==0) res-=res/p[i];
	return res;
}
ll mul(ll a,ll b,ll mod)
{
	a%=mod;b%=mod;
	ll res=(long double)a*b/mod+0.5;
	res=a*b-mod*res;
	return (res%mod+mod)%mod;
}
ll ksm(ll a,ll b,ll mod)
{
	ll ans=1;
	for(;b;b>>=1)
	{
		if(b&1) ans=mul(ans,a,mod);
		a=mul(a,a,mod);
	}
	return ans;
}
int main()
{
	ll x;
	scanf("%lld%lld",&n,&x);
	pre_work(n);
	work(n,p,cnt);
	ll ans=0,er=euler(n);
	if(er>1) work(er,swp,tot2);
	else swp[++tot2]=1;
	for(int i=1;i<=tot;i++)
	{
		ll u,er1;
		u=er1=euler(num[i]);
		if(u>1)
			for(int j=1;j<=tot2;j++)
			while(u%swp[j]==0 && ksm(x,u/swp[j],num[i])==1) u/=swp[j];
		ans+=er1/u;
	}
	printf("%lld\n",ans);
	return 0;
}