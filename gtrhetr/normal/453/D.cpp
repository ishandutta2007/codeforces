#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ldb long double

ll f[1048576],g[1048576],cnt[1048576],c[30],t,n,m,mod;

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
	if (!x) { putchar('0');putchar('\n');return; }
	int tot=0;
	for (;x;x/=10) s[++tot]=x%10+'0';
	for (;tot;tot--) putchar(s[tot]);
	putchar('\n');
}

inline ll pls(const ll &x,const ll &y) { return (x+y<mod)?x+y:x+y-mod; }
inline ll mns(const ll &x,const ll &y) { return (x-y<0)?x-y+mod:x-y; }

inline ll mul(const ll &x,const ll &y)
{
	ll res=x*y-(ll)((ldb)x/mod*y)*mod;
	return (res<0)?(res+mod):(res>=mod)?(res-mod):res;
}

inline ll ksm(ll x,ll y) { ll res=1;for (;y;y>>=1,x=mul(x,x)) if (y&1) res=mul(res,x);return res; }

inline void fwt(ll *a,int n,int on)
{
	for (int w=2;w<=n;w<<=1) for (int k=0;k<n;k+=w) for (int j=k;j<k+(w>>1);j++)
	{
		ll u=a[j],t=a[j+(w>>1)];
		a[j]=pls(u,t);a[j+(w>>1)]=mns(u,t);
	}
	if (on==-1) for (int i=0;i<n;i++) a[i]/=n;
}

int main()
{
	m=rd();t=rd();mod=(rd()<<m);
	n=(1<<m);
	for (int i=1;i<n;i++) cnt[i]=cnt[i>>1]+(i&1);
	for (int i=0;i<n;i++) f[i]=rd()%mod;
	for (int i=0;i<=m;i++) c[i]=rd()%mod;
	for (int i=0;i<n;i++) g[i]=c[cnt[i]];
	fwt(f,n,1);fwt(g,n,1);
	for (int i=0;i<n;i++) f[i]=mul(f[i],ksm(g[i],t));
	fwt(f,n,-1);
	for (int i=0;i<n;i++) print(f[i]);
	return 0;
}