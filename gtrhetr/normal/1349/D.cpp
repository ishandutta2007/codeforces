#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 998244353LL

ll f[300010],inv[300010];
int num[100010],n,m;

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
	inv[1]=1;
	for (int i=2;i<=300000;i++) inv[i]=(mod-mod/i)*inv[mod%i]%mod;
}

inline void work()
{
	f[0]=n-1;
	for (int i=1;i<m;i++) f[i]=pls(f[i-1]*i%mod*inv[m]%mod,1)*m%mod*(n-1)%mod*inv[m-i]%mod;
	for (int i=m-1;~i;i--) f[i]=pls(f[i],f[i+1]);
}

int main()
{
	n=rd();pre_gao();
	if (n==1) { puts("0");return 0; }
	for (int i=1;i<=n;i++) m+=num[i]=rd();
	work();
	ll ans=0;
	for (int i=1;i<=n;i++) ans=pls(ans,f[num[i]]);
	printf("%lld\n",mns(ans,f[0]*(n-1)%mod)*inv[n]%mod);
	return 0;
}