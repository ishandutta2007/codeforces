#include<bits/stdc++.h>
using namespace std;
#define inf 2123333333
#define pii pair<int,int>

struct point { int x,y,id; }h[1010];

struct noed { int t,v,op,next; }a[2500010];

pii h1[1010],h2[1010];
queue<int> q;

int fa[1010],L[1010],R[1010];
int head[2010],cur[2010],level[2010],X[1010],Y[1010],n,vs,vt,t1,t2,tot;
bool vis[2010];

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

inline bool cmp1(const point &x,const point &y) { return (x.x!=y.x)?x.x<y.x:x.y<y.y; }
inline bool cmp2(const point &x,const point &y) { return (x.y!=y.y)?x.y<y.y:x.x<y.x; }

inline void add(int x,int y,int z)
{
	a[++tot].t=y;a[tot].v=z;a[tot].op=tot+1;a[tot].next=head[x];head[x]=tot;
	a[++tot].t=x;a[tot].v=0;a[tot].op=tot-1;a[tot].next=head[y];head[y]=tot;
}

inline bool bfs()
{
	while (!q.empty()) q.pop();
	memset(level,0,sizeof(level));
	level[vs]=1;q.push(vs);cur[vs]=head[vs];
	while (!q.empty())
	{
		int x=q.front();q.pop();
		for (int i=head[x];i;i=a[i].next)
		{
			int t=a[i].t;
			if (level[t]||!a[i].v) continue;
			level[t]=level[x]+1;cur[t]=head[t];
			if (t==vt) return true;
			q.push(t);
		}
	}
	return false;
}

inline int dfs(int x,int y)
{
	if (x==vt||!y) return y;
	int res=0;
	for (int &i=cur[x];i;i=a[i].next)
	{
		int t=a[i].t;
		if (level[t]!=level[x]+1||!a[i].v) continue;
		int hh=dfs(t,min(y,a[i].v));
		if (!hh) continue;
		res+=hh;y-=hh;
		a[i].v-=hh;a[a[i].op].v+=hh;
	}
	if (!res) level[x]=0;
	return res;
}

inline void gao(int x)
{
	vis[x]=true;
	for (int i=head[x];i;i=a[i].next)
	{
		int t=a[i].t;
		if (!a[i].v||vis[t]) continue;
		gao(t);
	}
}

inline int find(int x) { return (x==fa[x])?x:fa[x]=find(fa[x]); }

int main()
{
	n=rd();
	for (int i=1;i<=n;i++) h[i].x=rd(),h[i].y=rd(),h[i].id=i,X[i]=h[i].x,Y[i]=h[i].y;
	t1=t2=0;
	sort(h+1,h+n+1,cmp1);
	for (int i=1,j;i<=n;i=j)
	{
		for (j=i;j<=n&&h[j].x==h[i].x;j++);
		for (int k=i;k<j-1;k++) h1[++t1]=pii(h[k].id,h[k+1].id);
	}
	sort(h+1,h+n+1,cmp2);
	for (int i=1,j;i<=n;i=j)
	{
		for (j=i;j<=n&&h[j].y==h[i].y;j++);
		for (int k=i;k<j-1;k++) h2[++t2]=pii(h[k].id,h[k+1].id);
	}
	vs=0;vt=t1+t2+1;
	for (int i=1;i<=t1;i++) add(vs,i,1);
	for (int i=1;i<=t2;i++) add(i+t1,vt,1);
	for (int i=1;i<=t1;i++) for (int j=1;j<=t2;j++)
		if (X[h1[i].first]>X[h2[j].first]&&X[h1[i].first]<X[h2[j].second]&&Y[h2[j].first]>Y[h1[i].first]&&Y[h2[j].first]<Y[h1[i].second]) add(i,j+t1,inf);
	while (bfs()) dfs(vs,inf);
	gao(vs);
	for (int i=1;i<=n;i++) fa[i]=i,L[i]=R[i]=X[i];
	for (int i=1;i<=t2;i++) if (!vis[t1+i])
	{
		int f1=find(h2[i].first),f2=find(h2[i].second);
		if (f1!=f2) fa[f1]=f2,L[f2]=min(L[f1],L[f2]),R[f2]=max(R[f1],R[f2]);
	}
	int tt=0;
	for (int i=1;i<=n;i++) if (find(i)==i) tt++;
	print(tt);putchar('\n');
	for (int i=1;i<=n;i++) if (find(i)==i) print(L[i]),print(Y[i]),print(R[i]),print(Y[i]),putchar('\n');
	for (int i=1;i<=n;i++) fa[i]=i,L[i]=R[i]=Y[i];
	for (int i=1;i<=t1;i++) if (vis[i])
	{
		int f1=find(h1[i].first),f2=find(h1[i].second);
		if (f1!=f2) fa[f1]=f2,L[f2]=min(L[f1],L[f2]),R[f2]=max(R[f1],R[f2]);
	}
	tt=0;
	for (int i=1;i<=n;i++) if (find(i)==i) tt++;
	print(tt);putchar('\n');
	for (int i=1;i<=n;i++) if (find(i)==i) print(X[i]),print(L[i]),print(X[i]),print(R[i]),putchar('\n');
	return 0;
}