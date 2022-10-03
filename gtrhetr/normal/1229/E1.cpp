#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007LL

ll p[10][10];
ll f[1048576],g[1048576];
int cnt[1048576],id[1048576],h[110],c[110],n,m,tt;
bool bo[10][10],vis[10];

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

inline void gao(ll *a,int n) { for (int w=2;w<=n;w<<=1) for (int k=0;k<n;k+=w) for (int j=k;j<k+(w>>1);j++) a[j]=pls(a[j],a[j+(w>>1)]); }

inline bool dfs(int x)
{
	if (x>m) return true;
	for (int i=1;i<=m;i++) if (bo[x][c[i]]&&!vis[c[i]])
	{
		vis[c[i]]=true;
		if (dfs(x+1)) return true;
		vis[c[i]]=false;
	}
	return false;
}

inline bool check(int id)
{
	int cnt=0;
	for (int i=1;i<=n;i++) if ((1<<(i-1))&id) c[++cnt]=i;
	memset(vis,false,sizeof(vis));
	return dfs(1);
}

inline bool dfs1(int x)
{
	if (x>n) return true;
	for (int i=1;i<=n-m;i++) if (bo[x][c[i]]&&!vis[c[i]])
	{
		vis[c[i]]=true;
		if (dfs1(x+1)) return true;
		vis[c[i]]=false;
	}
	return false;
}
inline bool check1(int id)
{
	int cnt=0;
	for (int i=1;i<=n;i++) if (!((1<<(i-1))&id)) c[++cnt]=i;
	memset(vis,false,sizeof(vis));
	return dfs1(m+1);
}

int main()
{
	n=rd();
	for (int i=1;i<=n;i++) for (int j=1;j<=n;j++) p[i][j]=rd()*ksm(100,mod-2)%mod;
	if (n==1) { printf("%lld\n",p[1][1]);return 0; }
	m=n/2;
	for (int i=1;i<1048576;i++) cnt[i]=cnt[i>>1]+(i&1);
	tt=0;
	for (int i=1;i<(1<<n);i++) if (cnt[i]==m) id[i]=++tt,h[tt]=i;
	for (int i=1;i<(1<<(m*n));i++)
	{
		memset(bo,false,sizeof(bo));
		ll now=1;
		for (int j=1;j<=m;j++) for (int k=1;k<=n;k++)
		{
			int id=(j-1)*n+k-1;
			if ((i>>id)&1) bo[j][k]=true,now=now*p[j][k]%mod;
			else now=now*mns(1,p[j][k])%mod;
		}
		int hh=0;
		for (int j=1;j<=tt;j++) if (check(h[j])) hh|=(1<<(j-1));
		f[hh]=pls(f[hh],now);
	}
	for (int i=1;i<(1<<(n-m)*n);i++)
	{
		memset(bo,false,sizeof(bo));
		ll now=1;
		for (int j=1;j<=n-m;j++) for (int k=1;k<=n;k++)
		{
			int id=(j-1)*n+k-1;
			if ((i>>id)&1) bo[j+m][k]=true,now=now*p[j+m][k]%mod;
			else now=now*mns(1,p[j+m][k])%mod;
		}
		int hh=0;
		for (int j=1;j<=tt;j++) if (check1(h[j])) hh|=(1<<(j-1));
		g[hh]=pls(g[hh],now);
	}
	gao(f,1<<tt);gao(g,1<<tt);
	ll ans=0;
	for (int i=1;i<(1<<tt);i++)
	{
		if (cnt[i]&1) ans=pls(ans,f[i]*g[i]%mod);
		else ans=mns(ans,f[i]*g[i]%mod);
	}
	printf("%lld\n",ans);
	return 0;
}