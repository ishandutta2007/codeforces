#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 998244353LL
#define pow DCXISSOHANDSOME

ll pow[20][131072],inv[131073];
ll f[50010][2][2],h[50010][2][2],g[50010][2][2],s[50010];
int n;

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
	for (int i=2;i<=131072;i++) inv[i]=(mod-mod/i)*inv[mod%i]%mod;
	for (int w=2,hh=1;w<=131072;w<<=1,hh++)
	{
		ll now=ksm(3,(mod-1)/w);
		pow[hh][0]=1;
		for (int j=1;j<(w>>1);j++) pow[hh][j]=pow[hh][j-1]*now%mod;
	}
}

inline void ntt(ll *a,int n,int on)
{
	static int rev[131072];
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

inline void solve(int l,int r)
{
	static ll c[131072],d[131072];
	if (l==r)
	{
		for (int i=0;i<2;i++) for (int j=0;j<2;j++) f[l][i][j]=pls(h[l-1][i][j],g[l-1][i][j]);
		return;
	}
	int mid=(l+r)>>1;
	solve(l,mid);
	int len=1;
	for (;len<=r-l+mid-l;len<<=1);
	for (int h1=0;h1<2;h1++) for (int h2=0;h2<2;h2++) for (int m=0;m<2;m++)
	{
		for (int i=l;i<=mid;i++) c[i-l]=f[i][h1][m];
		for (int i=0;i<=r-l;i++) d[i]=g[i][m][h2];
		memset(c+mid-l+1,0,sizeof(ll)*(len-(mid-l+1)));
		memset(d+r-l+1,0,sizeof(ll)*(len-(r-l+1)));
		ntt(c,len,1);ntt(d,len,1);
		for (int i=0;i<len;i++) c[i]=c[i]*d[i]%mod;
		ntt(c,len,-1);
		for (int i=mid+1;i<=r;i++) h[i][h1][h2]=pls(h[i][h1][h2],c[i-l]);
	}
	solve(mid+1,r);
}

int main()
{
	n=rd();pre_gao();
	s[0]=s[2]=1;
	for (int i=4;i<=n;i+=2) s[i]=pls(s[i-2],s[i-4]);
	for (int i=1;i<=n;i++) for (int j=0;j<2;j++) for (int k=0;k<2;k++) if (j+k<=i) g[i][j][k]=pls(g[i][j][k],s[i-j-k]*i%mod*i%mod);
	solve(1,n);
	ll ans=0;
	ans=pls(ans,pls(g[n-1][0][0],g[n-1][1][1])*n%mod);
	for (int i=0;i<n-1;i++) for (int j=0;j<2;j++) for (int k=0;k<2;k++) ans=pls(ans,f[i+1][j][k]*g[n-i-2][k][j]%mod*(n-i-1)%mod);
	printf("%lld\n",ans);
	return 0;
}