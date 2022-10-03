#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007LL

ll fac[200010],ifac[200010];
int t,n,m;

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
	ifac[200000]=ksm(fac[20000],mod-2);
	for (int i=199999;~i;i--) ifac[i]=ifac[i+1]*(i+1)%mod;
}

inline void work()
{
	n=rd();m=rd();
	ll ans=1;
	for (int i=1;i+(i-1)*(m-1)<=n;i++)
	{
		int hh=n-(i+(i-1)*(m-1));
		ans=pls(ans,C(hh+i,i)*ksm(C(n,i),mod-2)%mod);
	}
	printf("%lld\n",ans);
}

int main()
{
	t=rd();pre_gao();
	while (t--) work();
	return 0;
}