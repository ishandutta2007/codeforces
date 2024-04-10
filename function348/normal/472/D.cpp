#include<cstdio>
#include<iostream>
const int N=2010,inf=2000000000;
struct Edge {int y,z,ne;};
int n,num,ok;
int a[N][N];
int v[N];
Edge e[N*2];int last[N];
void add(int x,int y,int z)
{
	e[++num].y=y;e[num].z=z;e[num].ne=last[x];last[x]=num;
}
void dfs(int i,int fa,int id,int dis)
{
	if (a[id][i]!=dis) ok=0;
	if (!ok) return;
	for (int j=last[i];j;j=e[j].ne)
		if (e[j].y!=fa) dfs(e[j].y,i,id,dis+e[j].z);
}
int main()
{
	scanf("%d",&n);
	for (int i=1;i<=n;i++)
	for (int j=1;j<=n;j++)
	{
		scanf("%d",&a[i][j]);
		if (i!=j&&a[i][j]==0) 
		{
			printf("NO\n");return 0;
		}
		if (i==j&&a[i][j]!=0)
		{
			printf("NO\n");return 0;
		}
		if (i>j&&a[i][j]!=a[j][i])
		{
			printf("NO\n");return 0;
		}
	}
	for (int i=1;i<=n;i++) v[i]=0;
	for (int i=1;i<n;i++)
	{
		int k=1;
		int p=0,q=0;
		for (;k<=n;k++)
			if (!v[k]) break;
		a[k][p]=0;
		for (int j=1;j<=n;j++)
			if (!v[j]&&a[k][j]>a[k][p]&&j!=k) p=j;
		a[p][0]=inf;
		for (int j=1;j<=n;j++)
			if (!v[j]&&a[p][j]<a[p][q]&&j!=p) q=j;
		add(p,q,a[p][q]);
		add(q,p,a[p][q]);
		v[p]=1;
	}
	ok=1;
	for (int i=1;i<=n;i++) dfs(i,0,i,0);
	if (ok) printf("YES\n");else printf("NO\n");
	return 0;
}