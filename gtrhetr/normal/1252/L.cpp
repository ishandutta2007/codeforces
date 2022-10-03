#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define lll long double

struct node { int t,a,b,bo,next; }a[200010];

struct point
{
	ll x,y;
	point() {}
	point(ll x1,ll y1):x(x1),y(y1) {}
}h[5000010],st[5000010],dis[100010];

inline point operator +(const point &x,const point &y) { return point(x.x+y.x,x.y+y.y); }
inline point operator -(const point &x,const point &y) { return point(x.x-y.x,x.y-y.y); }
inline lll cross(const point &x,const point &y) { return (lll)x.x*y.y-(lll)x.y*y.x; }
inline ll calc(const point &x,const ll &y) { return x.x*y+x.y; }

int son[100010],dep[100010],tp[100010],size[100010];
int ch[100010][2],fat[100010],fa[100010];
int head[100010],n,m,tt,tot,top;

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
	if (!x) { putchar('0');putchar(' ');return; }
	int tot=0;
	for (;x;x/=10) s[++tot]=x%10+'0';
	for (;tot;tot--) putchar(s[tot]);
	putchar(' '); 
}

inline void add(int x,int y,int A,int B)
{
	a[++tot].t=y;a[tot].a=A;a[tot].b=B;
	a[tot].next=head[x];head[x]=tot;
}

inline void link(int x,int y) { a[++tot].t=y;a[tot].bo=true;a[tot].next=head[x];head[x]=tot; }

inline void pre_dfs(int x,int y)
{
	int lst=0;fat[x]=y;size[x]=1;
	for (int i=head[x];i;i=a[i].next)
	{
		int t=a[i].t;
		if (t==y) continue;
		dis[t]=dis[x]+point(a[i].a,a[i].b);
		if (!lst) ch[x][0]=t,fa[t]=x;
		else ch[lst][1]=t,fa[t]=lst;
		dep[t]=dep[x]+1;
		lst=t;pre_dfs(t,x);
		size[x]+=size[t];
		if (size[t]>size[son[x]]) son[x]=t;
	}
}

inline void pre_dfs2(int x,int y)
{
	tp[x]=y;
	if (son[x]) pre_dfs2(son[x],y);
	for (int i=head[x];i;i=a[i].next) if (a[i].t!=fat[x]&&a[i].t!=son[x]) pre_dfs2(a[i].t,a[i].t);
}

int rt1,rt2,all;

inline void dfs1(int x,int y)
{
	size[x]=1;
	for (int i=head[x];i;i=a[i].next)
	{
		int t=a[i].t;
		if (t==y||!a[i].bo) continue;
		dfs1(t,x);size[x]+=size[t];
	}
}

inline void dfs2(int x,int y)
{
	if (y&&(!rt1||max(size[x],all-size[x])<max(size[rt1],all-size[rt1]))) rt1=x,rt2=y;
	for (int i=head[x];i;i=a[i].next) if (a[i].t!=y&&a[i].bo) dfs2(a[i].t,x);
}

inline int lca(int x,int y)
{
	for (;tp[x]!=tp[y];x=fat[tp[x]]) if (dep[tp[x]]<dep[tp[y]]) swap(x,y);
	if (dep[x]>dep[y]) swap(x,y);
	return x;
}

point h1[100010],st1[100010],h2[100010],st2[100010];

int mid,t1,t2,top1,top2;

inline void dfs3(int x,int y)
{
	int hh=lca(x,mid);
	h1[++t1]=dis[x]+dis[mid]-dis[hh]-dis[hh];
	for (int i=head[x];i;i=a[i].next) if (a[i].t!=y&&a[i].bo) dfs3(a[i].t,x);
}

inline void dfs4(int x,int y)
{
	h2[++t2]=dis[x]-dis[mid];
	for (int i=head[x];i;i=a[i].next) if (a[i].t!=y&&a[i].bo) dfs4(a[i].t,x);
}

inline bool cmp(const point &x,const point &y) { return (x.x^y.x)?x.x<y.x:(x.y<y.y); }

inline void work(point *a,point *st,int n,int &top)
{
	sort(a+1,a+n+1,cmp);
	top=0;
	for (int i=1;i<=n;i++)
	{
		while (top>1&&cross(st[top]-st[top-1],a[i]-st[top-1])>=0) top--;
		st[++top]=a[i];
	}
}

inline void merge()
{
	int now1=1,now2=1;
	h[++tt]=st1[now1]+st2[now2];
	while (now1<top1||now2<top2)
	{
		if (now1==top1) now2++,h[++tt]=st1[now1]+st2[now2];
		else if (now2==top2) now1++,h[++tt]=st1[now1]+st2[now2];
		else if (cross(st2[now2+1]-st2[now2],st1[now1+1]-st1[now1])>=0) now1++,h[++tt]=st1[now1]+st2[now2];
		else now2++,h[++tt]=st1[now1]+st2[now2];
	}
}

inline void gao(int x)
{
	dfs1(x,0);rt1=rt2=0;all=size[x];dfs2(x,0);
	if (!rt1) return;
	if (fa[rt1]==rt2) swap(rt1,rt2);
	mid=(fat[rt2]==rt1)?rt1:fat[rt1];
	t1=t2=0;
	dfs3(rt1,rt2);dfs4(rt2,rt1);
	work(h1,st1,t1,top1);work(h2,st2,t2,top2);merge();
	for (int i=head[rt1];i;i=a[i].next) if (a[i].t==rt2) a[i].bo=false;
	for (int i=head[rt2];i;i=a[i].next) if (a[i].t==rt1) a[i].bo=false;
	int t1=rt1,t2=rt2;gao(t1);gao(t2);
}

int main()
{
	n=rd();m=rd();tot=0;
	for (int i=1;i<n;i++)
	{
		int x=rd(),y=rd(),a=rd(),b=rd();
		add(x,y,a,b);add(y,x,a,b);
	}
	dep[1]=1;pre_dfs(1,0);pre_dfs2(1,1);
	memset(head,0,sizeof(head));tot=0;
	for (int i=1;i<=n;i++)
	{
		if (fa[i]) link(i,fa[i]);
		if (ch[i][0]) link(i,ch[i][0]);
		if (ch[i][1]) link(i,ch[i][1]);
	}
	gao(1);
	work(h,st,tt,top);
	int now=1;
	for (int i=0;i<m;i++)
	{
		while (now<top&&calc(st[now+1],i)>=calc(st[now],i)) now++;
		print(calc(st[now],i));
	}
	return 0;
}