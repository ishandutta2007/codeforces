#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007LL

struct node { int t,next; }a[200010];

ll f[100010][210],g[210],h[210],s[210][210],fac[210];
int head[100010],size[100010],n,m,tot;

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

inline void add(int x,int y) { a[++tot].t=y;a[tot].next=head[x];head[x]=tot; }

inline void pre_gao()
{
	s[0][0]=1;
	for (int i=1;i<=200;i++) for (int j=1;j<=i;j++) s[i][j]=pls(s[i-1][j-1],s[i-1][j]*j%mod);
	fac[0]=1;
	for (int i=1;i<=200;i++) fac[i]=fac[i-1]*i%mod;
}

inline void dfs(int x,int y)
{
	size[x]=1;f[x][0]=1;
	int son=0;
	for (int i=head[x];i;i=a[i].next)
	{
		int t=a[i].t;
		if (t==y) continue;
		dfs(t,x);son++;
		int tt=min(size[x]+size[t]-1,m);
		for (int j=0;j<=m;j++) h[j]=mns(h[j],f[t][j]);
		memset(g,0,sizeof(ll)*(tt+1));
		for (int j=0;j<=tt&&j<size[x];j++) for (int k=0;k+j<=tt&&k<=size[t];k++) g[j+k]=pls(g[j+k],f[x][j]*f[t][k]%mod);
		for (int j=0;j<=tt;j++) f[x][j]=pls(f[x][j],g[j]);
		size[x]+=size[t];
	}
	f[x][0]=mns(f[x][0],1);
	for (int i=0;i<=m;i++) h[i]=pls(h[i],f[x][i]*2%mod);
	for (int i=m;i;i--) f[x][i]=pls(f[x][i],f[x][i-1]);
	for (int i=0;i<=m;i++) f[x][i]=pls(f[x][i],f[x][i]);
	f[x][0]=pls(f[x][0],1);f[x][1]=pls(f[x][1],1);
}

int main()
{
	n=rd();m=rd();pre_gao();tot=0;
	for (int i=1;i<n;i++) { int x=rd(),y=rd();add(x,y);add(y,x); }
	dfs(1,0);
	ll ans=0;
	for (int i=0;i<=m;i++) ans=pls(ans,h[i]*s[m][i]%mod*fac[i]%mod);
	printf("%lld\n",ans);
	return 0;
}