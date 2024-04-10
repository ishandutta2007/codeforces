#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 998244353LL
#define pow DCXISSOHANDSOME

ll pow[20][131072],fac[100010],ifac[100010],inv[100010],f[262144],g[262144];
ll n,m,len;

inline ll rd()
{
	ll x=0;char ch=getchar();
	for (;ch<'0'||ch>'9';ch=getchar());
	for (;ch>='0'&&ch<='9';ch=getchar()) x=x*10+ch-'0';
	return x;
}

inline void print(ll x)
{
	static char s[233];
	if (!x) { putchar('0');putchar(' ');return; }
	int tot=0;
	for (;x;x/=10) s[++tot]=x%10+'0';
	for (;tot;tot--) putchar(s[tot]);
	putchar(' ');
}

inline ll pls(const ll &x,const ll &y) { return (x+y<mod)?x+y:x+y-mod; }
inline ll mns(const ll &x,const ll &y) { return (x-y<0)?x-y+mod:x-y; }
inline ll ksm(ll x,ll y) { ll res=1;for (;y;y>>=1,x=x*x%mod) if (y&1) res=res*x%mod;return res; }

inline void pre_gao()
{
	fac[0]=1;
	for (int i=1;i<=100000;i++) fac[i]=fac[i-1]*i%mod;
	ifac[100000]=ksm(fac[100000],mod-2);
	for (int i=99999;~i;i--) ifac[i]=ifac[i+1]*(i+1)%mod;
	inv[1]=1;
	for (int i=2;i<=100001;i++) inv[i]=(mod-mod/i)*inv[mod%i]%mod;
	for (int w=2,hh=1;w<=262144;w<<=1,hh++)
	{
		ll now=ksm(3,(mod-1)/w);
		pow[hh][0]=1;
		for (int j=1;j<(w>>1);j++) pow[hh][j]=pow[hh][j-1]*now%mod;
	}
}

inline void ntt(ll *a,int n,int on)
{
	static int rev[262144];
	for (int i=1;i<n;i++) rev[i]=(rev[i>>1]>>1)|((i&1)?(n>>1):0);
	for (int i=1;i<n;i++) if (i<rev[i]) swap(a[i],a[rev[i]]);
	for (int w=2,hh=1;w<=n;w<<=1,hh++) for (int k=0;k<n;k+=w) for (int j=k;j<k+(w>>1);j++)
	{
		ll u=a[j],t=a[j+(w>>1)]*pow[hh][j-k]%mod;
		a[j]=pls(u,t);a[j+(w>>1)]=mns(u,t);
	}
	if (on==-1)
	{
		reverse(a+1,a+n);
		ll Inv=ksm(n,mod-2);
		for (int i=0;i<n;i++) a[i]=a[i]*Inv%mod;
	}
}

int main()
{
	n=rd();m=rd();pre_gao();
	for (len=1;len<=n*2;len<<=1);
	for (int i=0;i<=n;i++) f[i]=rd()*fac[i]%mod;
	reverse(f,f+n+1);
	for (int i=0;i<=n;i++) g[i]=ifac[i];
	ntt(f,len,1);ntt(g,len,1);
	for (int i=0;i<len;i++) f[i]=f[i]*g[i]%mod;
	ntt(f,len,-1);
	for (int i=0;i<=n;i++) f[i]=f[i]*ksm(inv[n+1-i],m)%mod;
	memset(f+n+1,0,sizeof(ll)*(len-n-1));
	for (int i=0;i<=n;i++) g[i]=(i&1)?mns(0,ifac[i]):ifac[i];
	memset(g+n+1,0,sizeof(ll)*(len-n-1));
	ntt(f,len,1);ntt(g,len,1);
	for (int i=0;i<len;i++) f[i]=f[i]*g[i]%mod;
	ntt(f,len,-1);
	reverse(f,f+n+1);
	for (int i=0;i<=n;i++) print(f[i]*ifac[i]%mod);
	putchar('\n');
	return 0;
}