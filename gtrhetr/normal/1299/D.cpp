#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007LL

struct node { int t,v,next; }a[200010];

unordered_map<ll,int> mp;

ll f[410],g[410],val[410];
int nxt[410][32],to[410][410],tt;
int head[100010],num[100010],from[100010],dep[100010],h[100010],n,m,tot=1;
bool bo[100010],vis[100010];

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

inline void add(int x,int y,int z) { a[++tot].t=y;a[tot].v=z;a[tot].next=head[x];head[x]=tot; }

inline void pre_dfs(int x)
{
	for (int i=0;i<32;i++) if (!((val[x]>>i)&1))
	{
		ll now=val[x];
		for (int j=0;j<32;j++) if ((val[x]>>j)&1) now|=(1LL<<(j^i));
		if (!mp[now]) mp[now]=++tt,val[tt]=now,pre_dfs(tt);
		nxt[x][i]=mp[now];
	}
}

inline void dfs(int x)
{
	for (int i=head[x];i;i=a[i].next) if (!vis[i>>1])
	{
		int t=a[i].t;
		vis[i>>1]=true;
		if (from[t])
		{
			int hh=dep[x]^dep[t]^a[i].v;
			h[from[x]]=nxt[h[from[x]]][hh];
		}
		else from[t]=from[x],dep[t]=dep[x]^a[i].v,dfs(t);
	}
}

int main()
{
	n=rd();m=rd();
	val[tt=1]=1;mp[1]=1;pre_dfs(1);
	for (int i=1;i<=tt;i++) for (int j=i;j<=tt;j++) if ((val[i]&val[j])==1)
	{
		ll now=0;
		for (int k=0;k<32;k++) for (int l=0;l<32;l++)
			if (((val[i]>>k)&1)&&((val[j]>>l)&1)) now|=(1LL<<(k^l));
		to[i][j]=to[j][i]=mp[now];
	}
	for (int i=1;i<=n;i++) num[i]=-1;
	for (int i=1;i<=m;i++)
	{
		int x=rd(),y=rd(),z=rd();
		if (x>y) swap(x,y);
		if (x==1) { num[y]=z;continue; }
		add(x,y,z);add(y,x,z);
	}
	for (int i=2;i<=n;i++) h[i]=1;
	for (int i=2;i<=n;i++) if (!from[i]) from[i]=i,dfs(i);
	f[1]=1;
	for (int x=2;x<=n;x++) if (num[x]>=0) for (int l=head[x];l;l=a[l].next)
	{
		int y=a[l].t;
		if (x>y||num[y]==-1) continue;
		bo[x]=bo[y]=true;
		int h1=h[from[x]],h2=nxt[h1][num[x]^num[y]^a[l].v];
		memcpy(g,f,sizeof(g));
		if (h1) for (int j=1;j<=tt;j++) g[to[j][h1]]=pls(g[to[j][h1]],f[j]*2%mod);
		if (h2) for (int j=1;j<=tt;j++) g[to[j][h2]]=pls(g[to[j][h2]],f[j]);
		memcpy(f,g,sizeof(f));
	}
	for (int i=2;i<=n;i++) if (num[i]>=0&&!bo[i])
	{
		int hh=h[from[i]];
		if (hh)
		{
			memcpy(g,f,sizeof(g));
			for (int j=1;j<=tt;j++) g[to[j][hh]]=pls(g[to[j][hh]],f[j]);
			memcpy(f,g,sizeof(f));
		}
	}
	ll ans=0;
	for (int i=1;i<=tt;i++) ans=pls(ans,f[i]);
	printf("%lld\n",ans);
	return 0;
}