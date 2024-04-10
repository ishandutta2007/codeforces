#include<bits/stdc++.h>
using namespace std;
#define inf 2123333333

struct node { int t,v,op,next; }a[1000010];

queue<int> q;

int head[3010],level[3010],cur[3010],n,h,m,vs,vt,tt,tot;

inline int rd()
{
	int x=0;char ch=getchar();
	for (;ch<'0'||ch>'9';ch=getchar());
	for (;ch>='0'&&ch<='9';ch=getchar()) x=x*10+ch-'0';
	return x;
}

inline int calc(int x,int y) { return (x-1)*h+y; }

inline void add(int x,int y,int z)
{
	a[++tot].t=y;a[tot].v=z;a[tot].op=tot+1;
	a[tot].next=head[x];head[x]=tot;
	a[++tot].t=x;a[tot].v=0;a[tot].op=tot-1;
	a[tot].next=head[y];head[y]=tot;
}

inline bool bfs()
{
	while (!q.empty()) q.pop();
	memset(level,0,sizeof(level));
	level[vs]=1;cur[vs]=head[vs];q.push(vs);
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
		if (!a[i].v||level[t]!=level[x]+1) continue;
		int hh=dfs(t,min(y,a[i].v));
		if (!hh) continue;
		res+=hh;y-=hh;
		a[i].v-=hh;a[a[i].op].v+=hh;
		if (!y) break;
	}
	if (!res) level[x]=0;
	return res;
}

int main()
{
	n=rd();h=rd();m=rd();tot=0;
	vs=0;vt=n*h+1;tt=vt;
	int ans=n*h*h;
	for (int i=1;i<=n;i++) for (int j=1;j<=h;j++) add(vs,calc(i,j),j*j-(j-1)*(j-1));
	for (int i=1;i<=m;i++)
	{
		int l=rd(),r=rd(),x=rd(),c=rd();
		if (x==h) continue;
		int now=++tt;
		add(now,vt,c);
		for (int j=l;j<=r;j++) for (int k=x+1;k<=h;k++) add(calc(j,k),now,inf);
	}
	while (bfs()) ans-=dfs(vs,inf);
	printf("%d\n",ans);
	return 0;
}