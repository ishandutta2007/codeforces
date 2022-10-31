#include<cstdio>
#include<iostream>
using namespace std;
int n,m;
int f[510][510];
int v[510],c[510];
void dfs(int i)
{
	if (c[i]) return;
	c[i]=1;
	for (int j=1;j<=i;j++)
	if (f[i][j]) 
	{
		printf("%d %d\n",j,i);
		dfs(i-j);
	}
}
int main()
{
	scanf("%d%d",&n,&m);
	v[0]=1;
	f[0][0]=1;
	for (int i=1;i<=n;i++)
	{
		int w;
		scanf("%d",&w);
		for (int j=m;j>=w;j--)
		if (v[j-w])
		{
			v[j]=1;
			for (int k=0;k<=j;k++)
			{
				f[j][k]|=f[j-w][k];
				f[j][k+w]|=f[j-w][k];
			}
			f[j][j]=1;
		}
	}
	int cnt=0;
	for (int i=0;i<=m;i++) cnt+=f[m][i];
	printf("%d\n",cnt);
	for (int i=0;i<=m;i++) 
	if (f[m][i]) printf("%d ",i);
	return 0;
}