#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 998244353LL
#define pow DCXISSOHANDSOME

ll pow[20][131072],inv[262145],fac[200010],ifac[200010];
int n,A,B;

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
	inv[1]=1;
	for (int i=2;i<=262144;i++) inv[i]=(mod-mod/i)*inv[mod%i]%mod;
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
		for (int i=0;i<n;i++) a[i]=a[i]*inv[n]%mod;
	}
}

inline ll *gao(int n)
{
	static ll c[262144],d[262144];
	ll *res=new ll[n+1];
	if (n==1) { res[0]=0;res[1]=1;return res; }
	if (n&1)
	{
		ll *h=gao(n-1);
		res[n]=1;res[0]=0;
		for (int i=1;i<n;i++) res[i]=pls(h[i-1],h[i]*(n-1)%mod);
		return res;
	}
	n>>=1;
	ll *f=gao(n);
	int len=1;
	for (;len<=(n<<1);len<<=1);
	ll hh=1;
	for (int i=0;i<=n;i++)
	{
		c[i]=f[i]*fac[i]%mod;
		d[i]=hh*ifac[i]%mod;
		hh=hh*n%mod;
	}
	reverse(c,c+n+1);
	memset(c+n+1,0,sizeof(ll)*(len-n-1));
	memset(d+n+1,0,sizeof(ll)*(len-n-1));
	ntt(c,len,1);ntt(d,len,1);
	for (int i=0;i<len;i++) c[i]=c[i]*d[i]%mod;
	ntt(c,len,-1);
	reverse(c,c+n+1);
	for (int i=0;i<=n;i++) c[i]=c[i]*ifac[i]%mod;
	memcpy(d,f,sizeof(ll)*(n+1));
	memset(c+n+1,0,sizeof(ll)*(len-n-1));
	memset(d+n+1,0,sizeof(ll)*(len-n-1));
	ntt(c,len,1);ntt(d,len,1);
	for (int i=0;i<len;i++) c[i]=c[i]*d[i]%mod;
	ntt(c,len,-1);
	memcpy(res,c,sizeof(ll)*((n<<1)+1));
	return res;
}

int main()
{
	n=rd();A=rd();B=rd();
	if (A+B-1>n||!A||!B) { puts("0");return 0; }
	if (n==1) { puts("1");return 0; }
	pre_gao();
	ll *f=gao(n-1);
	printf("%lld\n",f[A+B-2]*C(A+B-2,A-1)%mod);
	return 0;
}