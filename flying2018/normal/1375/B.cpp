#include<iostream>
#include<cstdio>
#include<cstring>
#define N 300
using namespace std;
int num[N][N],d[N][N],a[N][N];
int u[4]={0,1,0,-1},
	v[4]={1,0,-1,0};
void work(int n,int m)
{
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
		if(num[i][j])
		{
			d[i][j]=true;
			for(int k=0;k<4;k++)
			if(i+u[k]>=1 && i+u[k]<=n && j+v[k]>=1 && j+v[k]<=m) d[i+u[k]][j+v[k]]=true;
		}
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
		if(d[i][j])
		{
			for(int k=0;k<4;k++)
			if(i+u[k]>=1 && i+u[k]<=n && j+v[k]>=1 && j+v[k]<=m && d[i+u[k]][j+v[k]]) a[i][j]++;
		}
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
		if(num[i][j]>a[i][j]){puts("NO");return;}
	puts("YES");
	for(int i=1;i<=n;i++,puts(""))
		for(int j=1;j<=m;j++) printf("%d ",a[i][j]);
}
int main()
{
	int t;
	scanf("%d",&t);
	while(t --> 0)
	{
		int n,m;
		scanf("%d%d",&n,&m);
		for(int i=1;i<=n;i++)
			for(int j=1;j<=m;j++) scanf("%d",&num[i][j]);
		work(n,m);
		for(int i=1;i<=n;i++)
			for(int j=1;j<=m;j++) num[i][j]=d[i][j]=a[i][j]=0;
	}
	return 0;
}