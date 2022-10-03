#include<bits/stdc++.h>
using namespace std;

struct node { int t,next; }a[400010];

int dis[200010];
int head[200010],fa[200010],h[200010],mx[200010],col[200010],n,k,tt,tot;
bool vis[200010];

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
	if (!x) { putchar('0');putchar(' ');return; }
	int tot=0;
	for (;x;x/=10) s[++tot]=x%10+'0';
	for (;tot;tot--) putchar(s[tot]);
	putchar(' ');
}

inline void add(int x,int y) { a[++tot].t=y;a[tot].next=head[x];head[x]=tot; }

inline void pre_dfs(int x)
{
	for (int i=head[x];i;i=a[i].next)
	{
		int t=a[i].t;
		if (t==fa[x]) continue;
		dis[t]=dis[x]+1;
		fa[t]=x;pre_dfs(t);
	}
}

inline void dfs(int x,int y)
{
	mx[x]=0;
	for (int i=head[x];i;i=a[i].next)
	{
		int t=a[i].t;
		if (vis[t]||t==y) continue;
		dfs(t,x);
		mx[x]=max(mx[x],mx[t]+1);
	}
}

inline void dfs1(int x,int y,int z)
{
	col[x]=(z-1)%k+1;
	for (int i=head[x];i;i=a[i].next)
	{
		int t=a[i].t;
		if (vis[t]||t==y) continue;
		dfs1(t,x,z+1);
	}
}

inline void dfs2(int x,int y,int z)
{
	col[x]=(z-1)%k+1;
	for (int i=head[x];i;i=a[i].next)
	{
		int t=a[i].t;
		if (vis[t]||t==y) continue;
		dfs2(t,x,z-1);
	}
}

inline void gao(int x,int y)
{
	for (int i=head[x];i;i=a[i].next)
	{
		int t=a[i].t;
		if (t==y) continue;
		col[t]=((col[x]-1)^1)+1;
		gao(t,x);
	}
}

int main()
{
	n=rd();k=rd();tot=0;
	for (int i=1;i<n;i++) { int x=rd(),y=rd();add(x,y);add(y,x); }
	dis[1]=fa[1]=0;pre_dfs(1);
	int id1=1;
	for (int i=1;i<=n;i++) if (dis[i]>dis[id1]) id1=i;
	dis[id1]=fa[id1]=0;pre_dfs(id1);
	int id2=id1;
	for (int i=1;i<=n;i++) if (dis[i]>dis[id2]) id2=i;
	tt=0;
	for (int i=id2;i;i=fa[i]) h[++tt]=i,vis[i]=true;
	reverse(h+1,h+tt+1);
	if (tt<k||k==1)
	{
		puts("Yes");
		for (int i=1;i<=n;i++) print(1);
		puts("");
		return 0;
	}
	if (k==2)
	{
		col[1]=1;gao(1,0);
		puts("Yes");
		for (int i=1;i<=n;i++) print(col[i]);
		puts("");
		return 0;
	}
	for (int i=1;i<=tt;i++) col[h[i]]=(i-1)%k+1;
	for (int i=1;i<=tt;i++)
	{
		int x=h[i];
		dfs(x,0);
		if (mx[x]&&mx[x]+i>=k&&mx[x]+(tt-i+1)>=k) { puts("No");return 0; }
		if (i>(tt-i+1)) dfs1(x,0,i);
		else dfs2(x,0,i);
	}
	puts("Yes");
	for (int i=1;i<=n;i++) print(col[i]);
	puts("");
	return 0;
}