#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pll pair<ll,ll>
#define inf 2333333333333333333LL

struct node { int t,v,next; }a[400010];
struct edge { int s,t,v; }e[200010];

vector<int> v[200010];

ll dis1[200010],dis2[200010],tag[800010];
int head[200010],L[200010],R[200010],h[200010],id[200010],fa[200010],n,m,q,tt,tot;
bool vis[200010],bo[200010];

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
	if (!x) { putchar('0');putchar('\n');return; }
	int tot=0;
	for (;x;x/=10) s[++tot]=x%10+'0';
	for (;tot;tot--) putchar(s[tot]);
	putchar('\n');
}

inline void add(int x,int y,int z) { a[++tot].t=y;a[tot].v=z;a[tot].next=head[x];head[x]=tot; }

inline void pre_dfs1(int x)
{
	if (id[x]) L[x]=id[x];
	for (int t:v[x]) L[t]=L[x],pre_dfs1(t);
}

inline void pre_dfs2(int x)
{
	if (id[x]) R[x]=id[x];
	for (int t:v[x]) R[t]=R[x],pre_dfs2(t);
}

inline void build(int o,int l,int r)
{
	tag[o]=inf;
	if (l==r) return;
	int mid=(l+r)>>1;
	build(o<<1,l,mid);
	build(o<<1|1,mid+1,r);
}

inline void modify(int o,int l,int r,int x,int y,ll hh)
{
	if (l>=x&&r<=y) { tag[o]=min(tag[o],hh);return; }
	int mid=(l+r)>>1;
	if (x<=mid) modify(o<<1,l,mid,x,y,hh);
	if (y>mid) modify(o<<1|1,mid+1,r,x,y,hh);
}

inline ll query(int o,int l,int r,int x)
{
	if (l==r) return tag[o];
	int mid=(l+r)>>1;
	if (x<=mid) return min(tag[o],query(o<<1,l,mid,x));
	else return min(tag[o],query(o<<1|1,mid+1,r,x));
}

inline void dijkstra()
{
	priority_queue<pll,vector<pll>,greater<pll> > q;
	for (int i=1;i<=n;i++) dis1[i]=inf;
	dis1[1]=0;q.push(pll(0,1));
	while (!q.empty())
	{
		pll hh=q.top();q.pop();
		int x=hh.second;
		if (dis1[x]<hh.first) continue;
		for (int i=head[x];i;i=a[i].next)
		{
			int t=a[i].t;
			if (dis1[t]>dis1[x]+a[i].v)
			{
				dis1[t]=dis1[x]+a[i].v;fa[t]=x;
				q.push(pll(dis1[t],t));
			}
		}
	}
	for (int i=n;i;i=fa[i]) h[++tt]=i;
	reverse(h+1,h+tt+1);
	for (int i=1;i<=tt;i++) id[h[i]]=i;
	for (int i=2;i<=n;i++) v[fa[i]].push_back(i);
	pre_dfs1(1);
	for (int i=1;i<=n;i++) dis2[i]=inf;
	for (int i=1;i<=tt;i++) dis2[h[i]]=dis1[n]-dis1[h[i]],q.push(pll(dis2[h[i]],h[i]));
	memset(fa,0,sizeof(fa));
	for (int i=1;i<tt;i++) fa[h[i]]=h[i+1];
	while (!q.empty())
	{
		pll hh=q.top();q.pop();
		int x=hh.second;
		if (dis2[x]<hh.first) continue;
		for (int i=head[x];i;i=a[i].next)
		{
			int t=a[i].t;
			if (dis2[t]>dis2[x]+a[i].v)
			{
				dis2[t]=dis2[x]+a[i].v;fa[t]=x;
				q.push(pll(dis2[t],t));
			}
		}
	}
	for (int i=1;i<=n;i++) v[i].clear();
	for (int i=1;i<n;i++) v[fa[i]].push_back(i);
	pre_dfs2(n);
	build(1,1,tt-1);
	for (int i=1;i<=m;i++) if (dis1[e[i].s]>dis1[e[i].t]) swap(e[i].s,e[i].t);
	for (int i=1;i<=m;i++)
	{
		if (id[e[i].s]&&id[e[i].t]&&id[e[i].t]==id[e[i].s]+1&&!vis[id[e[i].s]]&&dis1[e[i].t]==dis1[e[i].s]+e[i].v)
		{
			vis[id[e[i].s]]=true;bo[i]=true;
		}
	}
	for (int i=1;i<=m;i++)
	{
		if (bo[i]) continue;
		int h1=L[e[i].s],h2=R[e[i].t]-1;
		if (h1<=h2) modify(1,1,tt-1,h1,h2,e[i].v+dis1[e[i].s]+dis2[e[i].t]);
		h1=L[e[i].t];h2=R[e[i].s]-1;
		if (h1<=h2) modify(1,1,tt-1,h1,h2,e[i].v+dis1[e[i].t]+dis2[e[i].s]);
	}
}

int main()
{
	n=rd();m=rd();q=rd();tot=0;
	for (int i=1;i<=m;i++)
	{
		int x=rd(),y=rd(),z=rd();
		e[i].s=x;e[i].t=y;e[i].v=z;
		add(x,y,z);add(y,x,z);
	}
	dijkstra();
	while (q--)
	{
		int i=rd(),val=rd();
		int x=e[i].s,y=e[i].t;
		ll ans=min(dis1[x]+dis2[y]+val,dis1[y]+dis2[x]+val);
		if (bo[i]) ans=min(ans,query(1,1,tt-1,id[x]));
		else ans=min(ans,dis1[n]);
		print(ans);
	}
	return 0;
}