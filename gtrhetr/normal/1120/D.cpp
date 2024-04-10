#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define inf 233333333333333333LL

struct node { int t,next; }a[400010];

ll f[200010][2],num[200010];
int head[200010],n,tot;
bool bo[200010][2],can[200010];

inline int rd()
{
	int x=0;char ch=getchar();
	for (;ch<'0'||ch>'9';ch=getchar());
	for (;ch>='0'&&ch<='9';ch=getchar()) x=x*10+ch-'0';
	return x;
}

inline void add(int x,int y) { a[++tot].t=y;a[tot].next=head[x];head[x]=tot; }

inline void dfs(int x,int y)
{
	int son=0;
	for (int i=head[x];i;i=a[i].next)
	{
		int t=a[i].t;
		if (t==y) continue;
		dfs(t,x);son++;
	}
	if (son==0)
	{
		f[x][0]=num[x];f[x][1]=0;
		return;
	}
	if (son==1)
	{
		int hh=0;
		for (int i=head[x];i;i=a[i].next) if (a[i].t!=y) hh=a[i].t;
		f[x][0]=min(f[hh][0],f[hh][1]+num[x]);
		f[x][1]=f[hh][1];
		return;
	}
	ll mn1=inf,sum=0;
	for (int i=head[x];i;i=a[i].next)
	{
		int t=a[i].t;
		if (t==y) continue;
		sum+=f[t][0];
		if (f[t][1]-f[t][0]<mn1) mn1=f[t][1]-f[t][0];
	}
	f[x][0]=min(sum,sum+mn1+num[x]);
	f[x][1]=sum+mn1;
}

inline void dfs1(int x,int y)
{
	int son=0;
	for (int i=head[x];i;i=a[i].next)
	{
		int t=a[i].t;
		if (t==y) continue;
		son++;
	}
	if (son==0)
	{
		if (bo[x][0]) can[x]=true;
		return;
	}
	if (son==1)
	{
		int hh=0;
		for (int i=head[x];i;i=a[i].next) if (a[i].t!=y) hh=a[i].t;
		if (bo[x][0])
		{
			if (f[x][0]==f[hh][1]+num[x]) can[x]=true,bo[hh][1]=true;
			if (f[x][0]==f[hh][0]) bo[hh][0]=true;
		}
		if (bo[x][1])
		{
			bo[hh][1]=true;
		}
		dfs1(hh,x);
		return;
	}
	ll mn1=inf,sum=0;
	for (int i=head[x];i;i=a[i].next)
	{
		int t=a[i].t;
		if (t==y) continue;
		sum+=f[t][0];
		if (f[t][1]-f[t][0]<mn1) mn1=f[t][1]-f[t][0];
	}
	/*
	f[x][0]=min(sum,sum+mn1+num[x]);
	f[x][1]=min(sum+mn1,sum+mn1+mn2+num[x]);
	*/
	int tt=0;
	for (int i=head[x];i;i=a[i].next)
	{
		int t=a[i].t;
		if (t==y) continue;
		if (f[t][1]-f[t][0]==mn1) tt++;
	}
	if (bo[x][0])
	{
		if (f[x][0]==sum) for (int i=head[x];i;i=a[i].next) if (a[i].t!=y) bo[a[i].t][0]=true;
		if (f[x][0]==sum+mn1+num[x])
		{
			can[x]=true;
			for (int i=head[x];i;i=a[i].next)
			{
				int t=a[i].t;
				if (t==y) continue;
				if (f[t][1]-f[t][0]==mn1) bo[t][1]=true;
				if (tt>1) bo[t][0]=true;
				else if (f[t][1]-f[t][0]>mn1) bo[t][0]=true;
			}
		}
	}
	if (bo[x][1])
	{
		for (int i=head[x];i;i=a[i].next)
		{
			int t=a[i].t;
			if (t==y) continue;
			if (f[t][1]-f[t][0]==mn1) bo[t][1]=true;
			if (tt>1) bo[t][0]=true;
			else if (f[t][1]-f[t][0]>mn1) bo[t][0]=true;
		}
	}
	for (int i=head[x];i;i=a[i].next)
	{
		int t=a[i].t;
		if (t==y) continue;
		dfs1(t,x);
	}
}

int main()
{
	n=rd();tot=0;
	for (int i=1;i<=n;i++) num[i]=rd();
	for (int i=1;i<n;i++)
	{
		int x=rd(),y=rd();
		add(x,y);add(y,x);
	}
	for (int i=1;i<=n;i++) f[i][0]=f[i][1]=inf;
	dfs(1,0);
	printf("%lld ",f[1][0]);
	bo[1][0]=true;
	dfs1(1,0);
	int res=0;
	for (int i=1;i<=n;i++) if (can[i]) res++;
	printf("%d\n",res);
	for (int i=1;i<=n;i++) if (can[i]) printf("%d ",i);
	puts("");
	return 0;
}