#include<bits/stdc++.h>
using namespace std;
#define ll long long

struct node { int t,next;ll v; }a[200010];

ll mx[100010],dis[100010];
int head[100010],fa[100010],size[100010],fat[100010],h[100010],dep[100010],n,q,vs,vt,rt,tot;
bool vis[100010];

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

inline void add(int x,int y,ll z) { a[++tot].t=y;a[tot].v=z;a[tot].next=head[x];head[x]=tot; }

inline void pre_dfs(int x)
{
	vis[x]=true;
	for (int i=head[x];i;i=a[i].next) if (!vis[a[i].t]) dis[a[i].t]=dis[x]+a[i].v,pre_dfs(a[i].t);
}

inline void dfs1(int x)
{
	for (int i=head[x];i;i=a[i].next) if (a[i].t!=fat[x]) fat[a[i].t]=x,dep[a[i].t]=dep[x]+1,dfs1(a[i].t);
}

inline void pre_gao()
{
	pre_dfs(1);vs=1;
	for (int i=1;i<=n;i++) if (dis[i]>dis[vs]) vs=i;
	memset(vis,false,sizeof(vis));
	dis[vs]=0;pre_dfs(vs);vt=vs;
	for (int i=1;i<=n;i++) if (dis[i]>dis[vt]) vt=i;
	for (int i=1;i<=n;i++) mx[i]=dis[i];
	memset(vis,false,sizeof(vis));
	dis[vt]=0;pre_dfs(vt);
	for (int i=1;i<=n;i++) mx[i]=max(mx[i],dis[i]);
	rt=1;
	for (int i=1;i<=n;i++) if (mx[i]<mx[rt]) rt=i;
	dfs1(rt);
}

inline bool cmp(const int &x,const int &y) { return (mx[x]!=mx[y])?(mx[x]<mx[y]):(dep[x]<dep[y]); }

inline int find(int x) { return (x==fa[x])?x:fa[x]=find(fa[x]); }

inline void work()
{
	ll l=rd();
	int now=n;
	for (int i=1;i<=n;i++) fa[i]=i,size[i]=1;
	int ans=0;
	for (int i=n;i;i--)
	{
		int x=h[i];
		for (int j=head[x];j;j=a[j].next) if (a[j].t!=fat[x]) fa[a[j].t]=x,size[x]+=size[a[j].t];
		while (mx[h[now]]-mx[x]>l) size[find(h[now])]--,now--;
		ans=max(ans,size[x]);
	}
	print(ans);
}

int main()
{
	n=rd();tot=0;
	for (int i=1;i<n;i++) { int x=rd(),y=rd();ll z=rd();add(x,y,z);add(y,x,z); }
	pre_gao();
	for (int i=1;i<=n;i++) h[i]=i;
	sort(h+1,h+n+1,cmp);
	q=rd();
	while (q--) work();
	return 0;
}