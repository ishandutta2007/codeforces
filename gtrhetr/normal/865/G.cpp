#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007LL

ll c[1010],f[1010],g[1010],h[1010],ans[1010];
ll p[1010],C[1010],F,B,n,m;

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

inline void mul(ll *a,ll *b,ll *c,int n,int m)
{
	static ll res[1010];
	memset(res,0,sizeof(ll)*(n+m+1));
	for (int i=0;i<=n;i++) for (int j=0;j<=m;j++) res[i+j]=pls(res[i+j],a[i]*b[j]%mod);
	memcpy(c,res,sizeof(ll)*(n+m+1));
}

inline void getmod(ll *a,ll *b,ll *c,int n,int m)
{
	static ll res[1010];
	memcpy(res,a,sizeof(ll)*(n+1));
	for (int i=n;i>=m;i--) if (res[i])
	{
		ll now=res[i];
		for (int j=i;j>=i-m;j--) res[j]=mns(res[j],b[j-i+m]*now%mod);
	}
	memcpy(c,res,sizeof(ll)*m);
}

inline void calc(ll n)
{
	static ll x[1010];
	memset(g,0,sizeof(g));
	memset(x,0,sizeof(x));
	x[1]=g[0]=1;
	if (m==1) x[0]=mns(0,f[0]),x[1]=0;
	for (;n;n>>=1,mul(x,x,x,m-1,m-1),getmod(x,f,x,m*2-2,m)) if (n&1) mul(g,x,g,m-1,m-1),getmod(g,f,g,m*2-2,m);
}

inline void gao(ll n)
{
	ans[0]=1;
	for (;n;n>>=1,mul(h,h,h,m-1,m-1),getmod(h,f,h,m*2-2,m)) if (n&1) mul(ans,h,ans,m-1,m-1),getmod(ans,f,ans,m*2-2,m);
}

int main()
{
	F=rd();B=rd();n=rd();
	for (int i=1;i<=F;i++) p[i]=rd();
	for (int i=1;i<=B;i++) C[i]=rd();
	m=0;
	for (int i=1;i<=B;i++) m=max(m,C[i]);
	c[0]=1;
	for (int i=1;i<=m;i++) for (int j=1;j<=B;j++) if (C[j]<=i) c[i]=pls(c[i],c[i-C[j]]);
	f[m]=1;
	for (int i=1;i<=B;i++) f[m-C[i]]=mns(f[m-C[i]],1);
	for (int i=1;i<=F;i++)
	{
		calc(p[i]);
		for (int j=0;j<m;j++) h[j]=pls(h[j],g[j]);
	}
	gao(n);
	ll res=0;
	for (int i=0;i<m;i++) res=pls(res,ans[i]*c[i]%mod);
	printf("%lld\n",res);
	return 0;
}