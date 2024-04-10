#include<iostream>
#include<cstdio>
#include<cstring>
#define int long long
using namespace std;
struct edge
{
	int nxt,to;
}e[500001<<1];
int n,m,tot,cnt,h[500001],dep[500001],top[500001],fa[500001],son[500001],s[500001],id[500001],ans[500001<<2],tag[500001<<2];
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
inline void f(int k,int l,int r,int p)
{
	ans[k]=p*(r-l+1);
	tag[k]=p;
}
inline void push_up(int k)
{
	ans[k]=ans[ls(k)]+ans[rs(k)];
}
inline void push_down(int k,int l,int r)
{
	if(tag[k]==-1)
		return;
	int mid=(l+r)>>1;
	f(ls(k),l,mid,tag[k]);
	f(rs(k),mid+1,r,tag[k]);
	tag[k]=-1;
}
void update(int nl,int nr,int l,int r,int k,int p)
{
	if(l>=nl&&r<=nr)
	{
		ans[k]=p*(r-l+1);
		tag[k]=p;
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
	fa[k]=f;
	dep[k]=deep;
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
	top[k]=t;
	id[k]=++cnt;
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
inline void up1(int k,int p)
{
	update(id[k],id[k]+s[k]-1,1,n,1,p);
}
inline void up2(int x,int y,int p)
{
	while(top[x]!=top[y])
	{
		if(dep[top[x]]<dep[top[y]])
			swap(x,y);
		update(id[top[x]],id[x],1,n,1,p);
		x=fa[top[x]];
	}
	if(dep[x]>dep[y])
		swap(x,y);
	update(id[x],id[y],1,n,1,p);
}
signed main()
{
	memset(tag,-1,sizeof(tag));
	n=read();
	for(register int i=1;i<n;++i)
	{
		register int x=read(),y=read();
		add(x,y);
		add(y,x);
	}
	dfs1(1,0,1);
	dfs2(1,1);
	m=read();
	while(m--)
	{
		register int opt=read(),x=read();
		if(opt==1)
			up1(x,1);
		if(opt==2)
			up2(x,1,0);
		if(opt==3)
			printf("%lld\n",query(id[x],id[x],1,n,1));
	}
	return 0;
}