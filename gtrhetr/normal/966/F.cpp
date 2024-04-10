#include<bits/stdc++.h>
using namespace std;
#define eps (1e-7)
#define inf 2123333333

struct node { int t,op,next;double v; }a[10010];

struct edge { int s,t;double a,b,c,d; }h[2010];

double in[1010];
int head[1010],cur[1010],level[1010],n,m,vs,vt,tot;

inline int rd()
{
	int x=0,f=1;char ch=getchar();
	for (;ch<'0'||ch>'9';ch=getchar()) if (ch=='-') f=-1;
	for (;ch>='0'&&ch<='9';ch=getchar()) x=x*10+ch-'0';
	return x*f;
}

inline void add(int x,int y,double z)
{
	a[++tot].t=y;a[tot].v=z;a[tot].op=tot+1;a[tot].next=head[x];head[x]=tot;
	a[++tot].t=x;a[tot].v=0;a[tot].op=tot-1;a[tot].next=head[y];head[y]=tot;
}

queue<int> q;

inline bool bfs()
{
	while (!q.empty()) q.pop();
	memset(level,0,sizeof(level));
	q.push(vs);level[vs]=1;cur[vs]=head[vs];
	while (!q.empty())
	{
		int x=q.front();q.pop();
		for (int i=head[x];i;i=a[i].next) if (a[i].v>eps)
		{
			int t=a[i].t;
			if (level[t]) continue;
			level[t]=level[x]+1;cur[t]=head[t];
			if (t==vt) return true;
			q.push(t);
		}
	}
	return false;
}

inline double dfs(int x,double y)
{
	if (x==vt||y<eps) return y;
	double res=0;
	for (int &i=cur[x];i;i=a[i].next) if (a[i].v>eps)
	{
		int t=a[i].t;
		if (level[t]!=level[x]+1) continue;
		double hh=dfs(t,min(y,a[i].v));
		if (hh<eps) continue;
		res+=hh;y-=hh;
		a[i].v-=hh;a[a[i].op].v+=hh;
	}
	return res;
}

inline double gao(double mid)
{
	memset(head,0,sizeof(head));
	memset(in,0,sizeof(in));
	tot=0;vs=0;vt=n+1;
	for (int i=1;i<=m;i++)
	{
		double l=h[i].a*mid+h[i].b,r=h[i].c*mid+h[i].d;
		add(h[i].s,h[i].t,r-l);
		in[h[i].t]+=l;in[h[i].s]-=l;
	}
	double res=0;
	for (int i=1;i<=n;i++)
	{
		if (in[i]>0) add(vs,i,in[i]),res+=in[i];
		else add(i,vt,-in[i]);
	}
	while (bfs()) res-=dfs(vs,inf);
	return res;
}

int main()
{
	n=rd();m=rd();
	for (int i=1;i<=m;i++) h[i].s=rd(),h[i].t=rd(),h[i].a=rd(),h[i].b=rd(),h[i].c=rd(),h[i].d=rd();
	double pos=-1,l=0,r=1;
	while (r-l>eps)
	{
		double h1=(l+l+r)/3,h2=(l+r+r)/3;
		double now1=gao(h1),now2=gao(h2);
		if (now1<eps) { pos=h1;break; }
		if (now2<eps) { pos=h2;break; }
		if (now1<now2) r=h2;
		else l=h1;
	}
	if (pos==-1) { puts("0");return 0; }
	double ans=0;
	l=0;r=pos;
	while (r-l>eps)
	{
		double mid=(l+r)/2;
		if (gao(mid)<eps) r=mid;
		else l=mid;
	}
	ans-=l;l=pos;r=1;
	while (r-l>eps)
	{
		double mid=(l+r)/2;
		if (gao(mid)<eps) l=mid;
		else r=mid;
	}
	ans+=l;
	printf("%.10lf\n",ans);
	return 0;
}