#include<iostream>
#include<cstdio>
#include<cstring>
#define N 200010
using namespace std;
int nxt[N<<1],to[N<<1],head[N],cnt;
void add(int u,int v)
{
	nxt[++cnt]=head[u];
	to[cnt]=v;
	head[u]=cnt;
}
int fa[N],dep[N],siz[N],son[N];
void dfs(int u,int p)
{
	dep[u]=dep[p]+1;
	fa[u]=p;siz[u]=1;
	for(int i=head[u];i;i=nxt[i])
	{
		int v=to[i];
		if(v==p) continue;
		dfs(v,u);
		siz[u]+=siz[v];
		if(siz[son[u]]<siz[v]) son[u]=v;
	}
}
int top[N],id[N],nid[N],tot;
void dfs2(int u,int topp)
{
	top[u]=topp;
	nid[id[u]=++tot]=u;
	if(son[u]) dfs2(son[u],topp);
	for(int i=head[u];i;i=nxt[i])
	{
		int v=to[i];
		if(v!=fa[u] && v!=son[u]) dfs2(v,v);
	}
}
int lca(int u,int v)
{
	while(top[u]!=top[v])
	{
		if(dep[top[u]]<dep[top[v]]) swap(u,v);
		u=fa[top[u]];
	}
	return dep[u]<dep[v]?u:v;
}
struct line{
	int l,r;//l->r
	line(int L=0,int R=0):l(L),r(R){}
};
inline bool is_f(int x,int y){return id[y]>=id[x] && id[y]<=id[x]+siz[x]-1;}//x is the ancestor of y
bool operator &(const line a,const line b)
{
	int l=lca(a.l,a.r);
	return is_f(l,b.l) && is_f(l,b.r) && (is_f(b.l,a.l) || is_f(b.l,a.r)) && (is_f(b.r,a.l) || is_f(b.r,a.r));
}
line operator +(const line a,const line b)
{
	if(a.l==0 || b.l==0) return line(a.l|b.l,a.r|b.r);
	if(a.l==-1 || b.l==-1) return line(-1,-1);
	if(line(a.l,a.r)&line(b.l,b.r)) return line(a.l,a.r);
	if(line(a.l,b.r)&line(b.l,a.r)) return line(a.l,b.r);
	if(line(b.l,a.r)&line(a.l,b.r)) return line(b.l,a.r);
	if(line(b.l,b.r)&line(a.l,a.r)) return line(b.l,b.r);
	if(line(a.l,b.l)&line(a.r,b.r)) return line(a.l,b.l);
	if(line(a.r,b.r)&line(a.l,b.l)) return line(a.r,b.r);
	return line(-1,-1);
}
int w[N],wp[N];
line val[N<<2];
void build(int u,int l,int r)
{
	if(l==r){val[u]=(line){wp[l],wp[l]};return;}
	int mid=(l+r)>>1;
	build(u<<1,l,mid);
	build(u<<1|1,mid+1,r);
	val[u]=val[u<<1]+val[u<<1|1];
}
void insert(int u,int l,int r,int p)
{
	if(l==r){val[u]=(line){wp[l],wp[l]};return;}
	int mid=(l+r)>>1;
	if(p<=mid) insert(u<<1,l,mid,p);
	else insert(u<<1|1,mid+1,r,p);
	val[u]=val[u<<1]+val[u<<1|1];
}
int answer(int u,int l,int r,line v)
{
	if(l==r) return l;
	line w=v+val[u<<1];
	int mid=(l+r)>>1;
	if(w.l!=-1) return answer(u<<1|1,mid+1,r,w);
	else return answer(u<<1,l,mid,v);
}
int main()
{
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%d",&w[i]),wp[++w[i]]=i;
	for(int i=2;i<=n;i++)
	{
		scanf("%d",&fa[i]);
		add(fa[i],i);
	}
	dfs(1,0);
	dfs2(1,1);
	build(1,1,n);
	int m;
	scanf("%d",&m);
	for(int i=1;i<=m;i++)
	{
		int opt;
		scanf("%d",&opt);
		if(opt==1)
		{
			int u,v;
			scanf("%d%d",&u,&v);
			swap(wp[w[u]],wp[w[v]]),swap(w[u],w[v]);
			insert(1,1,n,w[u]),insert(1,1,n,w[v]);
		}
		else printf("%d\n",(val[1].l==-1?answer(1,1,n,line()):n+1)-1);
	}
	return 0;
}