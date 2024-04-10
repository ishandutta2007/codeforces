#include<cstdio>
#include<iostream>
using namespace std;
const int N=300100;
struct Edge {int y,ne;};
int n,m,q,num;
int s[N],fa[N],v[N],f[N][2];
Edge e[N*2];int last[N];
void dfs(int i,int anc)
{
	v[i]=1;fa[i]=anc;
	int x1=0,x2=0;
	for (int j=last[i];j;j=e[j].ne)
	if (!v[e[j].y])
	{
		dfs(e[j].y,anc);
		f[i][1]=max(f[i][1],f[e[j].y][1]+1);
		f[i][0]=max(f[i][0],f[e[j].y][0]);
		if (f[e[j].y][1]+1>x1) x2=x1,x1=f[e[j].y][1]+1;else
		if (f[e[j].y][1]+1>x2) x2=f[e[j].y][1]+1;
	}
	f[i][0]=max(f[i][0],x1+x2);
}
int find(int i) { return fa[i]==i?i:fa[i]=find(fa[i]);}
void add(int x,int y) { e[++num]=(Edge){y,last[x]};last[x]=num;}
int main()
{
	scanf("%d%d%d",&n,&m,&q);
	for (int i=1;i<=m;i++)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		add(x,y);add(y,x);
	}
	for (int i=1;i<=n;i++)
	if (!v[i]) 
	{
		dfs(i,i);
		s[i]=f[i][0];
	}
	while (q--)
	{
		int kd,x,y;
		scanf("%d",&kd);
		if (kd==1)
		{
			scanf("%d",&x);
			printf("%d\n",s[find(x)]);
		}
		if (kd==2)
		{
			scanf("%d%d",&x,&y);
			x=find(x),y=find(y);
			if (x==y) continue;
			fa[y]=x;
			s[x]=max(max(s[x],s[y]),(s[x]+1)/2+(s[y]+1)/2+1);
		}
	}
	return 0;
}