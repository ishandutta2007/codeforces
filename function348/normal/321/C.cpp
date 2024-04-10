#include<cstdio>
#include<iostream>
using namespace std;
const int N=100010;
struct Edge {int y,ne;};
int n,num,root,mi;
Edge e[N*2];int last[N];
int size[N],lim[N],v[N];
void add(int x,int y) { e[++num]=(Edge){y,last[x]};last[x]=num;}
void dfs1(int i,int fa)
{
	size[i]=1;lim[i]=0;
	for (int j=last[i];j;j=e[j].ne)
	if (v[e[j].y]==0&&e[j].y!=fa)
	{
		dfs1(e[j].y,i);
		size[i]+=size[e[j].y];
		lim[i]=max(lim[i],size[e[j].y]);
	}
}
void dfs2(int i,int fa,int p)
{
	lim[i]=max(lim[i],size[p]-size[i]);
	if (lim[i]<mi) root=i,mi=lim[i];
	for (int j=last[i];j;j=e[j].ne)
	if (v[e[j].y]==0&&e[j].y!=fa)dfs2(e[j].y,i,p);
}
void work(int i,int fa,int deep)
{
	dfs1(i,fa);
	root=0,mi=100000000;
	dfs2(i,fa,i);
	int rt=root;
	v[rt]=deep;
	for (int j=last[rt];j;j=e[j].ne)
	if (v[e[j].y]==0)
		work(e[j].y,rt,deep+1);
}
int main()
{
	scanf("%d",&n);
	for (int i=1;i<n;i++) 
	{
		int x,y;
		scanf("%d%d",&x,&y);
		add(x,y);add(y,x);
	}
	work(1,0,1);
	for (int i=1;i<=n;i++) printf("%c ",64+v[i]);printf("\n");
	return 0;
}