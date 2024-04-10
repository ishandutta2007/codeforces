#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 998244353LL

ll f[2050][2050],g[2050][2050],sum[2050];
int n,K;

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

inline void getinv(ll *a,ll *b,int n)
{
	b[0]=1;
	for (int i=1;i<=n;i++)
	{
		ll now=0;
		for (int j=0;j<i;j++) now=mns(now,b[j]*a[i-j]%mod);
		b[i]=now;
	}
}

inline void gao1()
{
	static ll f[3010],g[3010];
	g[0]=1;
	for (int i=1;;i++)
	{
		if (i*(i*3-1)/2>n) break;
		if (i&1) g[i*(i*3-1)/2]=g[i*(i*3+1)/2]=mod-1;
		else g[i*(i*3-1)/2]=g[i*(i*3+1)/2]=1;
	}
	getinv(g,f,n);
	ll ans=0;
	for (int i=1;i<=n;i++) ans=pls(ans,f[i]);
	printf("%lld\n",ans);
}

inline void gao2()
{
	static int mx[110];
	f[0][n]=1;
	ll ans=0;mx[0]=n;
	for (int i=1;i*(i+1)/2<=n;i++)
	{
		mx[i]=n/i;
		memset(sum,0,sizeof(sum));
		for (int j=1;j<=mx[i];j++) for (int k=0;k<=n;k++) g[k][j]=0;
		for (int j=mx[i]+1;j<=mx[i-1];j++) for (int k=0;k<=n;k++) sum[k]=pls(sum[k],f[k][j]);
		for (int j=mx[i];j;j--)
		{
			for (int k=0;k<=n;k++) sum[k]=pls(sum[k],f[k][j]);
			for (int k=i*j;k<=n;k++) g[k][j]=sum[k-i*j],ans=pls(ans,g[k][j]);
		}
		for (int j=1;j<=mx[i];j++) for (int k=0;k<=n;k++) f[k][j]=g[k][j];
	}
	printf("%lld\n",ans);
}

int ans=0;

int h[2050],tt;
int num[2050],num1[2050];

inline void gao()
{
	int m=tt;
	for (int i=1;i<=m;i++) num[i]=h[i];
	for (int i=1;i<=K-2;i++)
	{
		int m1=0;
		for (int j=m;j;j--) for (int k=1;k<=num[j];k++) num1[++m1]=m-j+1;
		int sum=0;
		for (int j=1;j<=m1;j++) sum+=num1[j]*(m1-j+1);
		if (sum>n) return;
		m=m1;
		for (int j=1;j<=m;j++) num[j]=num1[j];
	}
	ans++;
}

inline void dfs(int x,int y,int z,int s)
{
	if (tt) gao();
	for (int i=x;i<=n;i++)
	{
		int h1=y+i,h2=z+i*y+i*(i+1)/2,h3=s+h2;
		if (h3<=n) h[++tt]=i,dfs(i,h1,h2,h3),tt--;
		else break;
	}
}

int main()
{
	n=rd();K=rd();
	if (K==1) { gao1();return 0; }
	if (K==2) { gao2();return 0; }
	tt=0;
	dfs(1,0,0,0);
	printf("%d\n",ans);
	return 0;
}