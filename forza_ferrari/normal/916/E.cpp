#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
#define int long long
struct edge
{
	int nxt,to;
}e[300001<<1];
struct edges
{
	int x,y,w,id;
	bool operator <(const edges &other) const
	{
		return w==other.w? id<other.id:w<other.w;
	}
}ee[500001];
int root,n,m,r,tot,cnt,h[300001],a[300001],dep[300001],fa[300001],s[300001],son[300001],id[300001],w[300001],top[300001],ans[300001<<2],tag[300001<<2],bin[300001];
inline int read()
{
	int x=0,f=1;
	char c=getchar();
	while(c<'0'||c>'9')
	{
		if(c=='-')
			f=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9')
	{
		x=(x<<1)+(x<<3)+(c^48);
		c=getchar();
	}
	return x*f;
}
inline void add(int x,int y)
{
	e[++tot].nxt=h[x];
	h[x]=tot;
	e[tot].to=y;
}
inline int ls(int k)
{
	return k<<1;
}
inline int rs(int k)
{
	return k<<1|1;
}
inline void push_up(int k)
{
	ans[k]=ans[ls(k)]+ans[rs(k)];
}
inline void f(int k,int l,int r,int p)
{
	ans[k]+=p*(r-l+1);
	tag[k]+=p;
}
inline void push_down(int k,int l,int r)
{
	int mid=(l+r)>>1;
	f(ls(k),l,mid,tag[k]);
	f(rs(k),mid+1,r,tag[k]);
	tag[k]=0;
}
void build(int k,int l,int r)
{
	if(l==r)
	{
		ans[k]=w[l];
		return;
	}
	int mid=(l+r)>>1;
	build(ls(k),l,mid);
	build(rs(k),mid+1,r);
	push_up(k);
}
void update(int nl,int nr,int l,int r,int k,int p)
{
	if(l>=nl&&r<=nr)
	{
		ans[k]+=p*(r-l+1);
		tag[k]+=p;
		return;
	}
	push_down(k,l,r);
	int mid=(l+r)>>1;
	if(nl<=mid)
		update(nl,nr,l,mid,ls(k),p);
	if(nr>mid)
		update(nl,nr,mid+1,r,rs(k),p);
	push_up(k);
}
int query(int nl,int nr,int l,int r,int k)
{
	if(l>=nl&&r<=nr)
		return ans[k];
	push_down(k,l,r);
	int mid=(l+r)>>1,res=0;
	if(nl<=mid)
		res+=query(nl,nr,l,mid,ls(k));
	if(nr>mid)
		res+=query(nl,nr,mid+1,r,rs(k));
	return res;
}
void dfs1(int k,int f,int deep)
{
	dep[k]=deep;
	fa[k]=f;
	s[k]=1;
	int maxson=-1;
	for(register int i=h[k];i;i=e[i].nxt)
	{
		if(e[i].to==f)
			continue;
		dfs1(e[i].to,k,deep+1);
		s[k]+=s[e[i].to];
		if(s[e[i].to]>maxson)
		{
			maxson=s[e[i].to];
			son[k]=e[i].to;
		}
	}
}
void dfs2(int k,int t)
{
	id[k]=++cnt;
	w[cnt]=a[k];
	top[k]=t;
	if(!son[k])
		return;
	dfs2(son[k],t);
	for(register int i=h[k];i;i=e[i].nxt)
	{
		if(e[i].to==fa[k]||e[i].to==son[k])
			continue;
		dfs2(e[i].to,e[i].to);
	}
}
inline int lca(int x,int y)
{
	while(top[x]!=top[y])
	{
		if(dep[top[x]]<dep[top[y]])
			x^=y^=x^=y;
		x=fa[top[x]];
	}
	if(dep[x]>dep[y])
		x^=y^=x^=y;
	return x;
}
inline int find(int x,int y)
{
	while(top[x]!=top[y])
	{
		if(dep[top[x]]<dep[top[y]])
			x^=y^=x^=y;
		if(fa[top[x]]==y)
			return top[x];
		x=fa[top[x]];
	}
	if(dep[x]>dep[y])
		x^=y^=x^=y;
	return son[x];
}
inline int LCA(int x,int y)
{
	if(dep[x]>dep[y])
		x^=y^=x^=y;
	if(lca(x,y)==x)
	{
		if(id[root]>=id[y]&&id[root]<=id[y]+s[y]-1)
			return y;
		if(lca(x,root)==x)
			return lca(y,root);
		return x;
	}
	if(id[root]>=id[x]&&id[root]<=id[x]+s[x]-1)
		return x;
	if(id[root]>=id[y]&&id[root]<=id[y]+s[y]-1)
		return y;
	if((lca(x,root)==root&&lca(x,y)==lca(y,root))||(lca(y,root)==root&&lca(x,y)==lca(x,root)))
		return root;
	if(lca(x,root)==lca(y,root))
		return lca(x,y);
	if(lca(x,y)!=lca(x,root))
		return lca(x,root);
	return lca(y,root);
}
inline void up1(int x,int y,int p)
{
	while(top[x]!=top[y])
	{
		if(dep[top[x]]<dep[top[y]])
			x^=y^=x^=y;
		update(id[top[x]],id[x],1,n,1,p);
		x=fa[top[x]];
	}
	if(dep[x]>dep[y])
		x^=y^=x^=y;
	update(id[x],id[y],1,n,1,p);
}
inline void up2(int x,int p)
{
	if(root==x)
	{
		update(1,n,1,n,1,p);
		return;
	}
	int qwq=lca(root,x);
	if(qwq!=x)
		update(id[x],id[x]+s[x]-1,1,n,1,p);
	else
	{
		int node=find(root,x);
		update(1,n,1,n,1,p);
		update(id[node],id[node]+s[node]-1,1,n,1,-p);
	}
}
inline int q1(int x,int y)
{
	int res=0;
	while(top[x]!=top[y])
	{
		if(dep[top[x]]<dep[top[y]])
			x^=y^=x^=y;
		res+=query(id[top[x]],id[x],1,n,1);
		x=fa[top[x]];
	}
	if(dep[x]>dep[y])
		x^=y^=x^=y;
	res+=query(id[x],id[y],1,n,1);
	return res;
}
inline int q2(int x)
{
	if(x==root)
		return query(1,n,1,n,1);
	int qwq=lca(root,x);
	if(qwq!=x)
		return query(id[x],id[x]+s[x]-1,1,n,1);
	int node=find(root,x);
	return query(1,n,1,n,1)-query(id[node],id[node]+s[node]-1,1,n,1);
}
int anc(int k)
{
	if(!bin[k])
		return k;
	return bin[k]=anc(bin[k]);
}
inline void link(int x,int y)
{
	x=anc(x);
	y=anc(y);
	if(x!=y)
		bin[y]=x;
}
inline void mst()
{
	int res=0;
	for(register int i=1;i<=r;++i)
		if(anc(ee[i].x)!=anc(ee[i].y))
		{
			link(ee[i].x,ee[i].y);
			add(ee[i].x,ee[i].y);
			add(ee[i].y,ee[i].x);
			++res;
			if(res==n-1)
				return;
		}
}
signed main(signed argc,char **argv)
{
	n=read(),m=read(),root=1;
	for(register int i=1;i<=n;++i)
		a[i]=read();
	for(register int i=1;i<n;++i)
	{
	    int x=read(),y=read();
	    add(x,y);
	    add(y,x);
	}
	dfs1(1,0,1);
	dfs2(1,1);
	build(1,1,n);
	while(m--)
	{
		int opt=read();
		if(opt==1)
			root=read();
		if(opt==2)
		{
		    int x=read(),y=read(),p=read();
		    up2(LCA(x,y),p);
		}
		if(opt==3)
		{
		    int k=read();
		    printf("%lld\n",q2(k));
		}
	}
	return 0;
}