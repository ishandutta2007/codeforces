#include<cstdio>
#include<iostream>
using namespace std;
const int N=100010;
struct Edge {int y,ne;};
int n,m,num,ok;
int v[N];
Edge e[N*2];int last[N];
void add(int x,int y) { e[++num]=(Edge){y,last[x]};last[x]=num;}
void dfs(int i,int col)
{
	if (v[i]!=-1)
	{
		if (v[i]!=col) ok=0;
		return;
	}
	v[i]=col;
	for (int j=last[i];j;j=e[j].ne)
		dfs(e[j].y,col^1);
}
int main()
{
	scanf("%d%d",&n,&m);
	for (int i=1;i<=m;i++)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		add(x,y);add(y,x);
	}
	for (int i=1;i<=n;i++) v[i]=-1;
	ok=1;
	for (int i=1;i<=n;i++)
	if (v[i]==-1) dfs(i,0);
	if (!ok) printf("-1\n");
	else
	{
		int k1=0,k2=0;
		for (int i=1;i<=n;i++)
			if (!v[i]) k1++;else k2++;
		printf("%d\n",k1);
		for (int i=1;i<=n;i++) if (!v[i]) printf("%d ",i);printf("\n");
		printf("%d\n",k2);
		for (int i=1;i<=n;i++) if ( v[i]) printf("%d ",i);printf("\n");
	}
	return 0;
}