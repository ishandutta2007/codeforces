#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pll pair<ll,ll>
#define mod 998244353LL
 
pll h[13000010];
 
ll l1[110],r1[110],l2[110],r2[110],n,m,tt;
 
inline ll rd()
{
	ll x=0;char ch=getchar();
	for (;ch<'0'||ch>'9';ch=getchar());
	for (;ch>='0'&&ch<='9';ch=getchar()) x=x*10+ch-'0';
	return x;
}
 
inline void modify(ll l,ll len,ll flag) { h[++tt]=pll(l,flag);h[++tt]=pll(l+len,-flag); }
 
inline void gao(ll n,ll m,ll flag)
{
	n++;m++;
	ll now=0;
	for (int i=60;~i;i--)
	{
		ll h1=(n&((1LL<<i)-1)),h2=(m&((1LL<<i)-1));
		if ((n>>i)&1) modify(now^(m&(1LL<<i)),1LL<<i,flag*h2);
		if ((m>>i)&1) modify(now^(n&(1LL<<i)),1LL<<i,flag*h1);
		if ((n>>i)&(m>>i)&1) modify(now,1LL<<i,flag<<i);
		now^=(n&(1LL<<i))^(m&(1LL<<i));
	}
}
 
inline ll calc(ll l,ll r)
{
	ll h1=l+r,h2=r-l+1;
	if (h1&1) return h1%mod*((h2>>1)%mod)%mod;
	return (h1>>1)%mod*(h2%mod)%mod;
}
 
int main()
{
	srand(time(NULL));
	n=rd();
	for (int i=1;i<=n;i++) l1[i]=rd(),r1[i]=rd();
	m=rd();
	for (int i=1;i<=m;i++) l2[i]=rd(),r2[i]=rd();
	for (int i=1;i<=n;i++) for (int j=1;j<=m;j++)
	{
		gao(r1[i],r2[j],1);
		gao(r1[i],l2[j]-1,-1);
		gao(l1[i]-1,r2[j],-1);
		gao(l1[i]-1,l2[j]-1,1);
	}
	sort(h+1,h+tt+1);
	ll now=0,ans=0;
	ll mod1=(ll)rand()+1000000000;
	for (int i=1;i<tt;i++)
	{
		now=(now+h[i].second)%mod1;
		if (now) ans+=calc(h[i].first,h[i+1].first-1);
	}
	printf("%lld\n",ans%mod);
	return 0;
}