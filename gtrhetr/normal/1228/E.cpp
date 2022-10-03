#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007LL
 
ll fac[310],ifac[310];
int n,k;
 
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
inline ll C(const int &x,const int &y) { return fac[x]*ifac[y]%mod*ifac[x-y]%mod; }

int main()
{
	n=rd();k=rd();
	if (k==1) { puts("1");return 0; }
	fac[0]=1;
	for (int i=1;i<=n;i++) fac[i]=fac[i-1]*i%mod;
	ifac[n]=ksm(fac[n],mod-2);
	for (int i=n-1;~i;i--) ifac[i]=ifac[i+1]*(i+1)%mod;
	ll ans=0;
	ll hh=(k-1)*ksm(k,mod-2)%mod;
	for (int i=0;i<=n;i++)
	{
		if (i&1) ans=mns(ans,C(n,i)*ksm(k,n*(n-i))%mod*ksm(k-1,n*i)%mod*ksm(mns(1,ksm(hh,n-i)),n)%mod);
		else ans=pls(ans,C(n,i)*ksm(k,n*(n-i))%mod*ksm(k-1,n*i)%mod*ksm(mns(1,ksm(hh,n-i)),n)%mod);
	}
	printf("%lld\n",ans);
	return 0;
}