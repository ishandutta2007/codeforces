#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 998244353LL

ll c[4010][4010],fac[4010],ifac[4010],f[4010],bin[4010],n,k,l;

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

inline void pre_gao()
{
	for (int i=0;i<=4000;i++)
	{
		c[i][0]=1;
		for (int j=1;j<=i;j++) c[i][j]=pls(c[i-1][j-1],c[i-1][j]);
	}
	fac[0]=1;
	for (int i=1;i<=4000;i++) fac[i]=fac[i-1]*i%mod;
	ifac[4000]=ksm(fac[4000],mod-2);
	for (int i=3999;~i;i--) ifac[i]=ifac[i+1]*(i+1)%mod;
	bin[0]=1;
	ll Inv=ksm(2,mod-2);
	for (int i=1;i<=4000;i++) bin[i]=bin[i-1]*Inv%mod;
}

int main()
{
	n=rd();k=rd();l=rd();pre_gao();
	ll ans=0;
	for (int i=0;i<=n*2;i+=2) f[i]=fac[i]*ifac[i>>1]%mod*bin[i>>1]%mod;
	for (int i=2;i<n*2+1;i++) if (i-1>=k&&n*2+1-i>=k)
	{
		for (int j=k;j<=i-1&&j<=n*2+1-i;j++) if (!((i-1-j)&1)) ans=pls(ans,c[i-1][j]*f[i-1-j]%mod*c[n*2+1-i][j]%mod*f[n*2+1-i-j]%mod*fac[j]%mod);
	}
	printf("%lld\n",ans*ksm(f[n*2],mod-2)%mod*l%mod*ksm(n*2+1,mod-2)%mod);
	return 0;
}