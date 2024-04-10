#include<bits/stdc++.h>
using namespace std;
#define inf 1061109567
#define pii pair<int,int>

struct node { int t,v,next; }a[100010];
struct hhhh { int s,t,v; }h[210];

priority_queue<pii,vector<pii>,greater<pii> > q;

int dis[10000010];
int head[110],from[110],fa[110],size[110],id[110],n,m,A,B,tt,tot;

inline int rd()
{
	int x=0;char ch=getchar();
	for (;ch<'0'||ch>'9';ch=getchar());
	for (;ch>='0'&&ch<='9';ch=getchar()) x=x*10+ch-'0';
	return x;
}

inline int min(const int &x,const int &y) { return (x<y)?x:y; }

inline void add(int x,int y,int z) { a[++tot].t=y;a[tot].v=z;a[tot].next=head[x];head[x]=tot; }

inline bool cmp(const hhhh &x,const hhhh &y) { return x.v<y.v; }

inline int find(int x) { return (x==fa[x])?x:fa[x]=find(fa[x]); }

inline int calc(const int &x,const int &y) { return ((x-1)<<tt)+y; }

int main()
{
	n=rd();m=rd();A=rd();B=rd();tot=0;
	for (int i=1;i<=m;i++)
	{
		h[i].s=rd();h[i].t=rd();h[i].v=rd();
		add(h[i].s,h[i].t,h[i].v);
		add(h[i].t,h[i].s,h[i].v);
	}
	sort(h+1,h+m+1,cmp);
	for (int i=1;i<=n;i++) fa[i]=i;
	for (int i=1;i<=m;i++) if (h[i].v==A) fa[find(h[i].s)]=find(h[i].t);
	for (int i=1;i<=n;i++) size[from[i]=find(i)]++;
	tt=0;
	for (int i=1;i<=n;i++) if (i==from[i]&&size[i]>3) id[i]=++tt;
	memset(dis,0x3f,sizeof(dis));
	if (size[from[1]]<=3) dis[calc(1,0)]=0,q.push(pii(0,calc(1,0)));
	else dis[calc(1,1<<(id[from[1]]-1))]=0,q.push(pii(0,calc(1,1<<(id[from[1]]-1))));
	while (!q.empty())
	{
		pii hh=q.top();q.pop();
		int hhh=hh.second;
		if (dis[hhh]<hh.first) continue;
		int x=(hhh>>tt)+1,y=hhh-((x-1)<<tt);
		for (int i=head[x];i;i=a[i].next)
		{
			int t=a[i].t;
			if (a[i].v==B)
			{
				if (from[t]==from[x]) continue;
				if (id[from[t]]&&((1<<(id[from[t]]-1))&y)) continue;
			}
			int t1=y|(id[from[t]]?(1<<(id[from[t]]-1)):0);
			int to=calc(t,t1);
			if (dis[to]>dis[hhh]+a[i].v)
			{
				dis[to]=dis[hhh]+a[i].v;
				q.push(pii(dis[to],to));
			}
		}
	}
	for (int i=1;i<=n;i++)
	{
		int res=inf;
		for (int j=0;j<(1<<tt);j++) res=min(res,dis[calc(i,j)]);
		printf("%d ",res);
	}
	puts("");
	return 0;
}