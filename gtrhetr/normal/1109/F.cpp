#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int,int>

struct node { int t,next; }a[1000010];

int f[1010][1010],head[200010],id[200010],num[200010],h[233],n,m,tt,tot;

inline int rd()
{
	int x=0;char ch=getchar();
	for (;ch<'0'||ch>'9';ch=getchar());
	for (;ch>='0'&&ch<='9';ch=getchar()) x=x*10+ch-'0';
	return x;
}

inline int min(const int &x,const int &y) { return (x<y)?x:y; }

namespace lct
{

int ch[200010][2],fa[200010],mn[200010],st[200010],top;
bool rev[200010];

inline bool isroot(int x) { return (ch[fa[x]][0]!=x)&&(ch[fa[x]][1]!=x); }

inline void revv(int x) { swap(ch[x][0],ch[x][1]);rev[x]^=1; }

inline void pushup(int x)
{
	mn[x]=num[x];
	if (ch[x][0]) mn[x]=min(mn[x],mn[ch[x][0]]);
	if (ch[x][1]) mn[x]=min(mn[x],mn[ch[x][1]]);
}

inline void pushdown(int x)
{
	if (!rev[x]) return;
	if (ch[x][0]) revv(ch[x][0]);
	if (ch[x][1]) revv(ch[x][1]);
	rev[x]=false;
}

inline void rotate(int x)
{
	int y=fa[x],z=fa[y],l=(ch[y][1]==x);
	if (!isroot(y)) ch[z][ch[z][1]==y]=x;
	ch[y][l]=ch[x][l^1];ch[x][l^1]=y;
	fa[ch[y][l]]=y;fa[y]=x;fa[x]=z;
	pushup(y);pushup(x);
}

inline void splay(int x)
{
	st[top=1]=x;
	for (int i=x;!isroot(i);i=fa[i]) st[++top]=fa[i];
	for (;top;top--) pushdown(st[top]);
	while (!isroot(x))
	{
		int y=fa[x],z=fa[y];
		if (!isroot(y))
		{
			if ((ch[y][0]==x)^(ch[z][0]==y)) rotate(x);
			else rotate(y);
		}
		rotate(x);
	}
}

inline void access(int x) { for (int y=0;x;y=x,x=fa[x]) splay(x),ch[x][1]=y,pushup(x); }

inline int findrt(int x)
{
	access(x);splay(x);
	for (;ch[x][0];x=ch[x][0]);
	splay(x);
	return x;
}

inline void makert(int x) { access(x);splay(x);revv(x); }

inline void link(int x,int y) { makert(x);fa[x]=y; }

inline void cut(int x,int y)
{
	makert(x);access(y);splay(y);
	fa[ch[y][0]]=0;ch[y][0]=0;
	pushup(y);
}

inline int findmn(int x,int y)
{
	makert(x);access(y);splay(y);
	return mn[y];
}

}

namespace sgt
{

pii mn[800010];
int tag[800010];

inline pii merge(pii x,pii y)
{
	if (x.first==y.first) return pii(x.first,x.second+y.second);
	return (x.first<y.first)?x:y;
}

inline void pushdown(int o)
{
	if (!tag[o]) return;
	mn[o<<1].first+=tag[o];tag[o<<1]+=tag[o];
	mn[o<<1|1].first+=tag[o];tag[o<<1|1]+=tag[o];
	tag[o]=0;
}

inline void build(int o,int l,int r)
{
	tag[o]=0;
	if (l==r) { mn[o]=pii(0,1);return; }
	int mid=(l+r)>>1;
	build(o<<1,l,mid);
	build(o<<1|1,mid+1,r);
	mn[o]=merge(mn[o<<1],mn[o<<1|1]);
}

inline void modify(int o,int l,int r,int x,int y,int hh)
{
	if (l>=x&&r<=y) { mn[o].first+=hh;tag[o]+=hh;return; }
	pushdown(o);
	int mid=(l+r)>>1;
	if (x<=mid) modify(o<<1,l,mid,x,y,hh);
	if (y>mid) modify(o<<1|1,mid+1,r,x,y,hh);
	mn[o]=merge(mn[o<<1],mn[o<<1|1]);
}

inline pii query(int o,int l,int r,int x,int y)
{
	if (l>=x&&r<=y) return mn[o];
	pushdown(o);
	int mid=(l+r)>>1;
	if (y<=mid) return query(o<<1,l,mid,x,y);
	if (x>mid) return query(o<<1|1,mid+1,r,x,y);
	return merge(query(o<<1,l,mid,x,y),query(o<<1|1,mid+1,r,x,y));
}

}

using namespace sgt;

inline void add(int x,int y) { a[++tot].t=y;a[tot].next=head[x];head[x]=tot; }

inline int calc(int x,int y) { return (x-1)*m+y; }

int main()
{
	n=rd();m=rd();
	for (int i=1;i<=n;i++) for (int j=1;j<=m;j++) num[calc(i,j)]=f[i][j]=rd(),id[f[i][j]]=calc(i,j);
	for (int i=1;i<=n;i++) for (int j=1;j<=m;j++)
	{
		if (i>1) add(calc(i,j),calc(i-1,j));
		if (i<n) add(calc(i,j),calc(i+1,j));
		if (j>1) add(calc(i,j),calc(i,j-1));
		if (j<m) add(calc(i,j),calc(i,j+1));
	}
	build(1,1,n*m);
	ll ans=0;int now=0;
	for (int hhh=1;hhh<=n*m;hhh++)
	{
		int x=id[hhh];
		modify(1,1,n*m,1,hhh,1);
		if (hhh==1) now=1;
		else
		{
			bool flag=true;tt=0;
			for (int i=head[x];i;i=a[i].next)
			{
				int t=a[i].t;
				if (num[t]>=now&&num[t]<hhh) h[++tt]=t;
			}
			for (int i=1;i<=tt;i++)
			{
				int hh=h[i];
				if (lct::findrt(hh)==lct::findrt(x)) { flag=false;break; }
				for (int j=1;j<i;j++) if (lct::findrt(hh)==lct::findrt(h[j])) { flag=false;break; }
				if (!flag) break;
			}
			while (!flag)
			{
				int hh=id[now];
				for (int i=head[hh];i;i=a[i].next)
				{
					int t=a[i].t;
					if (num[t]>num[hh]&&num[t]<hhh) lct::cut(hh,t);
				}
				now++;flag=true;tt=0;
				for (int i=head[x];i;i=a[i].next)
				{
					int t=a[i].t;
					if (num[t]>=now&&num[t]<hhh) h[++tt]=t;
				}
				for (int i=1;i<=tt;i++)
				{
					int hh=h[i];
					if (lct::findrt(hh)==lct::findrt(x)) { flag=false;break; }
					for (int j=1;j<i;j++) if (lct::findrt(hh)==lct::findrt(h[j])) { flag=false;break; }
					if (!flag) break;
				}
			}
		}
		for (int i=head[x];i;i=a[i].next)
		{
			int t=a[i].t;
			if (num[t]>=now&&num[t]<hhh) modify(1,1,n*m,1,num[t],-1),lct::link(x,t);
		}
		pii ans1=query(1,1,n*m,now,hhh);
		ans+=ans1.second;
	}
	printf("%lld\n",ans);
	return 0;
}