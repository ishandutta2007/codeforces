#include<bits/stdc++.h>
using namespace std;
const int N=605;
int n,m,q,a[N*N],b[N*N],c[N*N],u[N*N],v[N*N],l[N*N],x[N][N],y[N][N],t;
long long d[N][N];
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			d[i][j]=(1LL<<60);
	for(int i=1;i<=n;i++)
		d[i][i]=0;
	for(int i=1;i<=m;i++)
	{
		scanf("%d%d%d",&u[i],&v[i],&l[i]);
		d[u[i]][v[i]]=d[v[i]][u[i]]=l[i];
	}
	for(int k=1;k<=n;k++)
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
				d[i][j]=min(d[i][j],d[i][k]+d[k][j]);
	scanf("%d",&q);
	for(int i=1;i<=q;i++)
	{
		scanf("%d%d%d",&a[i],&b[i],&c[i]);
		x[a[i]][b[i]]=c[i];
		x[b[i]][a[i]]=c[i];
	}
	for(int u=1;u<=n;u++)
	{
		for(int v=1;v<=n;v++)
		{
			for(int i=1;i<=n;i++)
			{
				if(!x[u][i])
					continue;
				if(x[u][i]>=d[v][i])
					y[u][v]=max((long long)y[u][v],(x[u][i]-d[v][i]));
			}
		}
	}
	for(int i=1;i<=m;i++)
	{
		int fl=0;
		for(int k=1;k<=n;k++)
		{
			if(d[k][u[i]]+l[i]<=y[k][v[i]])
				fl=1;
		}
		t+=fl;
	}
	printf("%d\n",t);
	return 0;
}