#include<bits/stdc++.h>
using namespace std;
#define lowbit(x) (x&-x)

struct node { int t,next; }a[400010];
struct hhhh { int p,x,y; }h[200010];

priority_queue<int,vector<int>,greater<int> > q;

int c[400010];
int head[200010],d[200010],n,m,cnt,tot,maxn;
bool vis[200010];
char s[233];

inline int rd()
{
	int x=0;char ch=getchar();
	for (;ch<'0'||ch>'9';ch=getchar());
	for (;ch>='0'&&ch<='9';ch=getchar()) x=x*10+ch-'0';
	return x;
}

inline void print(int x)
{
	static char s[233];
	if (!x) { putchar('0');putchar('\n');return; }
	int tot=0;
	for (;x;x/=10) s[++tot]=x%10+'0';
	for (;tot;tot--) putchar(s[tot]);
	putchar('\n');
}

inline void modify(int x,const int &y) { for (;x<=maxn;x+=lowbit(x)) c[x]+=y; }

inline int sum(int x)
{
	int res=0;
	for (;x;x-=lowbit(x)) res+=c[x];
	return res;
}

namespace lct
{

int ch[200010][2],fa[200010],size[200010],col[200010],tag[200010],st[200010],top;
bool rev[200010];

inline void init()
{
	for (int i=1;i<=n;i++) size[i]=1;
	for (int i=1;i<=n;i++) modify(i,1);
}

inline bool isroot(const int &x) { return (ch[fa[x]][0]!=x)&&(ch[fa[x]][1]!=x); }

inline void revv(const int &x) { swap(ch[x][0],ch[x][1]);rev[x]^=1; }

inline void change(const int &x,const int &y) { col[x]=tag[x]=y; }

inline void pushup(int x) { size[x]=size[ch[x][0]]+size[ch[x][1]]+1; }

inline void pushdown(int x)
{
	if (rev[x])
	{
		if (ch[x][0]) revv(ch[x][0]);
		if (ch[x][1]) revv(ch[x][1]);
		rev[x]=false;
	}
	if (!tag[x]) return;
	if (ch[x][0]) change(ch[x][0],tag[x]);
	if (ch[x][1]) change(ch[x][1],tag[x]);
	tag[x]=0;
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

inline void access(int x,int now)
{
	int hh=x;
	for (int y=0;x;y=x,x=fa[x])
	{
		splay(x);
		if (col[x]) modify(col[x],-size[ch[x][0]]-1);
		ch[x][1]=y;pushup(x);
	}
	splay(hh);change(hh,now);
	modify(now,size[hh]);
}

inline void gao(int x) { access(x,++cnt);revv(x); }

inline int query(int x)
{
	splay(x);
	return sum(col[x])-size[ch[x][0]];
}

}

inline void add(const int &x,const int &y) { a[++tot].t=y;a[tot].next=head[x];head[x]=tot; }

inline void pre_dfs(int x,int y)
{
	for (int i=head[x];i;i=a[i].next)
	{
		int t=a[i].t;
		if (t==y) continue;
		lct::fa[t]=x;
		pre_dfs(t,x);
	}
}

int main()
{
	n=rd();m=rd();tot=0;
	for (int i=1;i<n;i++) { int x=rd(),y=rd();add(x,y);add(y,x);d[x]++;d[y]++; }
	maxn=n;
	for (int i=1;i<=m;i++)
	{
		char ch=getchar();
		for (;ch<'a'||ch>'z';ch=getchar());
		if (ch=='u') h[i].p=1,h[i].x=rd(),maxn++;
		else if (ch=='w') h[i].p=2,h[i].x=rd();
		else h[i].p=3,h[i].x=rd(),h[i].y=rd();
	}
	int rt=0,tt=0;
	for (int i=1;i<=n;i++) if (d[i]==1) q.push(i);
	while (!q.empty())
	{
		int x=q.top();q.pop();
		vis[x]=true;lct::col[x]=++tt;rt=x;
		for (int i=head[x];i;i=a[i].next)
		{
			int t=a[i].t;
			if (!vis[t]) if ((--d[t])==1) q.push(t);
		}
	}
	pre_dfs(rt,0);
	cnt=n;lct::init();
	for (int i=1;i<=m;i++)
	{
		if (h[i].p==1) lct::gao(h[i].x);
		else if (h[i].p==2) print(lct::query(h[i].x));
		else print((lct::query(h[i].x)<lct::query(h[i].y))?h[i].x:h[i].y);
	}
	return 0;
}