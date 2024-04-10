#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007LL
#define pow DCXISSOHANDSOME

ll fac[1000010],ifac[1000010],pow[1000010],bin[1000010];
int n,m,vs,vt;

inline ll rd()
{
	ll x=0,f=1;char ch=getchar();
	for (;ch<'0'||ch>'9';ch=getchar()) if (ch=='-') f=-1;
	for (;ch>='0'&&ch<='9';ch=getchar()) x=x*10+ch-'0';
	return x*f;
}

inline ll pls(const ll &x,const ll &y) { return (x+y<mod)?x+y:x+y-mod; }
inline ll mns(const ll &x,const ll &y) { return (x-y<0)?x-y+mod:x-y; }
inline ll ksm(ll x,ll y) { ll res=1;for (;y;y>>=1,x=x*x%mod) if (y&1) res=res*x%mod;return res; }
inline ll C(int x,int y) { return (x<0||y<0||x<y)?x:fac[x]*ifac[y]%mod*ifac[x-y]%mod; }

inline void pre_gao()
{
	fac[0]=1;
	for (int i=1;i<=1000000;i++) fac[i]=fac[i-1]*i%mod;
	ifac[1000000]=ksm(fac[1000000],mod-2);
	for (int i=999999;~i;i--) ifac[i]=ifac[i+1]*(i+1)%mod;
	pow[0]=1;
	for (int i=1;i<=1000000;i++) pow[i]=pow[i-1]*n%mod;
	bin[0]=1;
	for (int i=1;i<=1000000;i++) bin[i]=bin[i-1]*m%mod;
}

int main()
{
	n=rd();m=rd();vs=rd();vt=rd();
	pre_gao();
	ll ans=0;
	for (int i=2;i<=min(n,m+1);i++)
	{
		ll res=C(n-2,i-2)*fac[i-2]%mod*C(m-1,i-2)%mod;
		ll res1=(i==n)?1:(pow[n-i-1]*bin[n-i]%mod*i%mod);
		ans=pls(ans,res*res1%mod);
	}
	printf("%lld\n",ans);
	return 0;
}