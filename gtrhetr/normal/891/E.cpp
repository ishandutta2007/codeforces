#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007LL

ll f[5010];
ll num[5010],bin[5010],n,k;

inline ll rd()
{
	ll x=0;char ch=getchar();
	for (;ch<'0'||ch>'9';ch=getchar());
	for (;ch>='0'&&ch<='9';ch=getchar()) x=x*10+ch-'0';
	return x;
}

inline ll pls(const ll &x,const ll &y) { return (x+y<mod)?x+y:x+y-mod; }
inline ll mns(const ll &x,const ll &y) { return (x-y<0)?x-y+mod:x-y; }
inline ll ksm(ll x,ll y) { ll res=1;for (;y;y>>=1,x=x*x%mod) if (y&1) res=res*x%mod;return res; }

int main()
{
	n=rd();k=rd();
	for (int i=1;i<=n;i++) num[i]=rd();
	ll ans1=1;
	for (int i=1;i<=n;i++) ans1=ans1*num[i]%mod;
	f[0]=1;
	for (int i=1;i<=n;i++) for (int j=i-1;~j;j--)
	{
		f[j+1]=mns(f[j+1],f[j]);
		f[j]=f[j]*num[i]%mod;
	}
	bin[0]=ksm(n,k);
	ll Inv=ksm(n,mod-2);
	for (int i=1;i<=n;i++) bin[i]=bin[i-1]*Inv%mod;
	ll now=1,ans=0;
	for (int i=0;i<=min(n,k);i++)
	{
		ans=pls(ans,f[i]*bin[i]%mod*now%mod);
		now=now*(k-i)%mod;
	}
	printf("%lld\n",mns(ans1,ans*ksm(bin[0],mod-2)%mod));
	return 0;
}