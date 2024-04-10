#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 998244353LL

ll ans[131072],f[131072],g[131072],h[131072],x,y,z;
int a[100010],b[100010],c[100010],n,k;

inline int rd()
{
	int x=0;char ch=getchar();
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

const ll inv2=ksm(2,mod-2);

inline void fwt(ll *a,int n)
{
	for (int w=2;w<=n;w<<=1) for (int k=0;k<n;k+=w) for (int j=k;j<k+(w>>1);j++)
	{
		ll u=a[j],t=a[j+(w>>1)];
		a[j]=u+t;a[j+(w>>1)]=u-t;
	}
}

inline void fwt1(ll *a,int n)
{
	for (int w=2;w<=n;w<<=1) for (int k=0;k<n;k+=w) for (int j=k;j<k+(w>>1);j++)
	{
		ll u=a[j],t=a[j+(w>>1)];
		a[j]=pls(u,t);a[j+(w>>1)]=mns(u,t);
		a[j]=a[j]*inv2%mod,a[j+(w>>1)]=a[j+(w>>1)]*inv2%mod;
	}
}

int main()
{
	n=rd();k=rd();x=rd();y=rd();z=rd();
	int sum=0;
	for (int i=1;i<=n;i++) a[i]=rd(),sum^=a[i],b[i]=rd()^a[i],c[i]=rd()^a[i];
	for (int i=1;i<=n;i++) f[b[i]]++,g[c[i]]++,h[b[i]^c[i]]++;
	fwt(f,1<<k);fwt(g,1<<k);fwt(h,1<<k);
	ll x1=pls(pls(x,y),z),x2=mns(pls(x,y),z),x3=pls(mns(x,y),z),x4=mns(x,pls(y,z));
	for (int i=0;i<(1<<k);i++)
	{
		int h1=n,h2=f[i],h3=g[i],h4=h[i];
		int a=(h1+h2+h3+h4)/4,b=(h1+h2-h3-h4)/4,c=(h1-h2+h3-h4)/4,d=(h1-h2-h3+h4)/4;
		ans[i]=ksm(x1,a)*ksm(x2,b)%mod*ksm(x3,c)%mod*ksm(x4,d)%mod;
	}
	fwt1(ans,1<<k);
	for (int i=0;i<(1<<k);i++) print(ans[i^sum]);
	putchar('\n');
	return 0;
}