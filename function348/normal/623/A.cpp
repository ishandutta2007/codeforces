#include<cstdio>
#include<iostream>
using namespace std;
const int N=510;
int n,m;
int flag;
int a[N][N];
int c[N];
void dfs(int i)
{
	for (int j=1;j<=n;j++)
	if (a[i][j])
	{
		if (c[j]==-1)
		{
			c[j]=2-c[i];
			dfs(j);
		}
		else if (c[i]+c[j]!=2) flag=1;
	}
	else 
	{
		if (c[j]==-1)
		{
			c[j]=c[i];
			dfs(j);
		}
		else if (c[j]+c[i]==2) flag=1;
	}
}
int main()
{
	scanf("%d%d",&n,&m);
	for (int i=1;i<=m;i++) 
	{
		int x,y;
		scanf("%d%d",&x,&y);
		a[x][y]=a[y][x]=1;
	}
	for (int i=1;i<=n;i++) a[i][i]=1;
	for (int i=1;i<=n;i++) c[i]=-1;
	for (int i=1;i<=n;i++)
	for (int j=1;j<=n;j++)
		a[i][j]^=1;
	for (int i=1;i<=n;i++)
	{
		int cnt=0;
		for (int j=1;j<=n;j++) cnt+=a[i][j];
		if (cnt==0) c[i]=1;
	}
	flag=0;
	for (int i=1;i<=n;i++)
	if (c[i]==-1) 
	{
		c[i]=0;
		dfs(i);
	}
	
	
	if (flag) printf("No\n");else
	{
		printf("Yes\n");
		for (int i=1;i<=n;i++) printf("%c",c[i]+97);
	}
	return 0;
}