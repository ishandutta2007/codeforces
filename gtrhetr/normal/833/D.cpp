#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pll pair<int,ll>
#define mod 1000000007LL
#define lowbit(x) ((x)&(-(x)))

struct node { int t,col,next;ll v; }a[400010];

ll num[200010],ans1=1,ans2=1,sumall;
int size[200010],mx[200010],dep[200010],s0[200010],s1[200010],rt,all,maxn,cntall;
int head[200010],n,tot;
bool vis[200010];

inline int rd()
{
	int x=0;char ch=getchar();
	for (;ch<'0'||ch>'9';ch=getchar());
	for (;ch>='0'&&ch<='9';ch=getchar()) x=x*10+ch-'0';
	return x;
}

inline int min(const int &x,const int &y) { return (x<y)?x:y; }
inline int max(const int &x,const int &y) { return (x>y)?x:y; }

inline ll pls(const ll &x,const ll &y) { return (x+y<mod)?x+y:x+y-mod; }
inline ll mns(const ll &x,const ll &y) { return (x-y<0)?x-y+mod:x-y; }
inline ll ksm(ll x,ll y) { ll res=1;for (;y;y>>=1,x=x*x%mod) if (y&1) res=res*x%mod;return res; }

struct tree
{

int cnt[400010],size;
ll sum[400010];

inline void init(int n)
{
	size=n;
	for (int i=0;i<=size*4+1;i++) cnt[i]=0,sum[i]=1;
}

inline void add(int x,const ll &y) { x+=size*2+1;for (;x;x-=lowbit(x)) cnt[x]++,sum[x]=sum[x]*y%mod; }

inline pll query(int x)
{
	pll res(0,1);x+=size*2+1;
	for (;x<=size*4+1;x+=lowbit(x)) res.first+=cnt[x],res.second=res.second*sum[x]%mod;
	return res;
}

}bit1,bit2;

inline void add(const int &x,const int &y,const int &c,const ll &z)
{
	a[++tot].t=y;a[tot].col=c;a[tot].v=z;
	a[tot].next=head[x];head[x]=tot;
}

inline void dfs1(int x,int y)
{
	size[x]=1;mx[x]=0;
	for (int i=head[x];i;i=a[i].next)
	{
		int t=a[i].t;
		if (vis[t]||t==y) continue;
		dfs1(t,x);
		size[x]+=size[t];
		mx[x]=max(mx[x],size[t]);
	}
}

inline void dfs2(int x,int y)
{
	if (max(mx[x],all-size[x])<max(mx[rt],all-size[rt])) rt=x;
	for (int i=head[x];i;i=a[i].next) if (!vis[a[i].t]&&a[i].t!=y) dfs2(a[i].t,x);
}

inline void dfs3(int x,int y)
{
	maxn=max(maxn,dep[x]);
	for (int i=head[x];i;i=a[i].next)
	{
		int t=a[i].t;
		if (vis[t]||t==y) continue;
		dep[t]=dep[x]+1;
		dfs3(t,x);
	}
}

inline void dfs4(int x,int y)
{
	ans1=ans1*sumall%mod*ksm(num[x],cntall)%mod;
	pll now=bit1.query(s0[x]*2-s1[x]+1);
	ans2=ans2*now.second%mod*ksm(num[x],now.first)%mod;
	now=bit2.query(s1[x]*2-s0[x]+1);
	ans2=ans2*now.second%mod*ksm(num[x],now.first)%mod;
	for (int i=head[x];i;i=a[i].next)
	{
		int t=a[i].t;
		if (vis[t]||t==y) continue;
		s0[t]=s0[x];s1[t]=s1[x];
		num[t]=num[x]*a[i].v%mod;
		if (a[i].col==0) s0[t]++;
		else s1[t]++;
		dfs4(t,x);
	}
}

inline void dfs5(int x,int y)
{
	cntall++;sumall=sumall*num[x]%mod;
	bit1.add(s1[x]-s0[x]*2,num[x]);
	bit2.add(s0[x]-s1[x]*2,num[x]);
	for (int i=head[x];i;i=a[i].next) if (a[i].t!=y&&!vis[a[i].t]) dfs5(a[i].t,x);
}

inline void gao(int x)
{
	dfs1(x,0);rt=x;all=size[x];dfs2(x,0);
	if (size[x]==1) return;
	vis[rt]=true;maxn=0;
	dep[rt]=0;dfs3(rt,0);
	s0[rt]=s1[rt]=0;num[rt]=1;
	sumall=1;cntall=1;
	bit1.init(maxn);bit2.init(maxn);
	bit1.add(0,1);bit2.add(0,1);
	for (int i=head[rt];i;i=a[i].next)
	{
		int t=a[i].t;
		if (vis[t]) continue;
		s0[t]=s0[rt];s1[t]=s1[rt];
		num[t]=num[rt]*a[i].v%mod;
		if (a[i].col==0) s0[t]++;
		else s1[t]++;
		dfs4(t,rt);dfs5(t,rt);
	}
	for (int i=head[rt];i;i=a[i].next) if (!vis[a[i].t]) gao(a[i].t);
}

int main()
{
	n=rd();tot=0;
	for (int i=1;i<n;i++)
	{
		int x=rd(),y=rd(),z=rd(),c=rd();
		add(x,y,c,z);add(y,x,c,z);
	}
	gao(1);
	printf("%lld\n",ans1*ksm(ans2,mod-2)%mod);
	return 0;
}