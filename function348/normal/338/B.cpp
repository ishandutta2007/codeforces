#include<cstdio>
#include<iostream>
using namespace std;
const int N=100010,inf=1000000;
struct Edge {int y,ne;};
int n,m,d,num;
int down[N],up[N],fa[N],v[N];
Edge e[N*2];int last[N];
void dfs1(int i)
{
	down[i]=up[i]=-inf;
	if (v[i]) down[i]=0;
	for (int j=last[i];j;j=e[j].ne)
	if (e[j].y!=fa[i])
	{
		fa[e[j].y]=i;
		dfs1(e[j].y);
		down[i]=max(down[i],down[e[j].y]+1);
	}
}
void add(int x,int y) { e[++num]=(Edge){y,last[x]};last[x]=num;}
void dfs2(int i)
{
	int ma1=-inf,ma2=-inf;
	if (v[i]) up[i]=max(up[i],0);
	for (int j=last[i];j;j=e[j].ne)
	if (e[j].y!=fa[i])
	{
		up[e[j].y]=up[i]+1;
		if (down[e[j].y]>ma1) ma2=ma1,ma1=down[e[j].y];else
		if (down[e[j].y]>ma2) ma2=down[e[j].y];
	}
	for (int j=last[i];j;j=e[j].ne)
	if (e[j].y!=fa[i])
	{
		if (down[e[j].y]==ma1) up[e[j].y]=max(up[e[j].y],ma2+2);else
		up[e[j].y]=max(up[e[j].y],ma1+2);
		dfs2(e[j].y);
	}
}
int main()
{
	scanf("%d%d%d",&n,&m,&d);
	up[1]=-inf;
	for (int i=1;i<=m;i++) 
	{
		int x;
		scanf("%d",&x);
		v[x]=1;
	}
	for (int i=1;i<n;i++) 
	{
		int x,y;
		scanf("%d%d",&x,&y);
		add(x,y);add(y,x);
	}
	dfs1(1);
	dfs2(1);
	int cnt=0;
	for (int i=1;i<=n;i++) 
	if (max(up[i],down[i])<=d) cnt++;
	printf("%d\n",cnt);
	return 0;
}