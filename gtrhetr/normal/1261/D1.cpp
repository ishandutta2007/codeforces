#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 998244353LL
#define pow DCXISSOHANDSOME

ll fac[200010],ifac[200010];
int num[200010],n,m;

inline int rd()
{
	int x=0;char ch=getchar();
	for (;ch<'0'||ch>'9';ch=getchar());
	for (;ch>='0'&&ch<='9';ch=getchar()) x=x*10+ch-'0';
	return x;
}

inline ll pls(const ll &x,const ll &y) { return (x+y<mod)?x+y:x+y-mod; }
inline ll mns(const ll &x,const ll &y) { return (x-y<0)?x-y+mod:x-y; }
inline ll ksm(ll x,ll y) { ll res=1;for (;y;y>>=1,x=x*x%mod) if (y&1) res=res*x%mod;return res; }
inline ll C(const int &x,const int &y) { return (x<0||y<0||x<y)?0:fac[x]*ifac[y]%mod*ifac[x-y]%mod; }

inline void pre_gao()
{
	fac[0]=1;
	for (int i=1;i<=200000;i++) fac[i]=fac[i-1]*i%mod;
	ifac[200000]=ksm(fac[200000],mod-2);
	for (int i=199999;~i;i--) ifac[i]=ifac[i+1]*(i+1)%mod;
}

int main()
{
	n=rd();m=rd();pre_gao();
	for (int i=1;i<=n;i++) num[i]=rd();
	ll ans=1;int tt=n;
	for (int i=1;i<=n;i++) if (num[i]==num[i%n+1]) ans=ans*m%mod,tt--;
	ll sum=0,inv2=ksm(2,mod-2);
	for (int i=0;i<=tt;i++)
	{
		ll now=ksm(m-2,i)*C(tt,i)%mod;
		int hh=tt-i;
		if (hh&1) sum=pls(sum,now*ksm(2,hh-1)%mod);
		else
		{
			ll hhh=mns(ksm(2,hh),C(hh,hh/2));
			sum=pls(sum,now*hhh%mod*inv2%mod);
		}
	}
	printf("%lld\n",ans*sum%mod);
	return 0;
}