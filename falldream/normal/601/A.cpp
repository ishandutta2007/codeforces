#include<iostream>
#include<cstdio>
#define MN 400
#define INF 1e9 
using namespace std;
inline int read()
{
	int x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}
int n,m,d[MN+5][MN+5];
int main()
{
	n=read();m=read();
	for(int i=1;i<=n;++i)for(int j=1;j<=n;++j) d[i][j]=INF;
	for(int i=1,j,k;i<=m;++i) j=read(),k=read(),d[j][k]=d[k][j]=1;
	if(d[1][n]==1)
	{
		for(int i=1;i<=n;++i)
			for(int j=1;j<=n;++j)
				d[i][j]=d[i][j]==1?INF:1;	
	}
	for(int k=1;k<=n;++k)
		for(int i=1;i<=n;++i)
			for(int j=1;j<=n;++j)
				d[i][j]=min(d[i][j],d[i][k]+d[k][j]);
	printf("%d\n",d[1][n]==INF?-1:d[1][n]);
	return 0;
}