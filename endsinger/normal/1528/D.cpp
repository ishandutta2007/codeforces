#include<bits/stdc++.h>
using namespace std;
const int N=605;
int n,m,d[N][N],rd[N],md[N],ans[N][N],vis[N];
long long dis[N];
void dij(int s)
{
	for(int i=0;i<n;i++)
		vis[i]=0,dis[i]=(1LL<<60);
	dis[s]=0;
	for(int y=0;y<n;y++)
	{
		int u=-1;
		for(int i=0;i<n;i++)
			if(!vis[i]&&(u==-1||dis[i]<dis[u]))
				u=i;
		vis[u]=1;
		for(int i=0;i<n;i++)
			rd[(dis[u]+i)%n]=d[u][i];
		for(int i=0;i<n;i++)
			md[i]=(1<<30);
		int pm=(1<<30);
		for(int i=0;i<n;i++)
		{
			if(rd[i])
				pm=min(pm,rd[i]-i);
			md[i]=min(md[i],i+pm);
		}
		int sm=(1<<30);
		for(int i=n-1;i>=0;i--)
		{
			if(rd[i])
				sm=min(sm,rd[i]-i);
			md[i]=min(md[i],sm+n+i);
		}
		for(int v=0;v<n;v++)
			dis[v]=min(dis[v],dis[u]+md[v]);
	}
	for(int i=0;i<n;i++)
		ans[s][i]=dis[i];
}
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=0;i<m;i++)
	{
		int u,v,w;
		scanf("%d%d%d",&u,&v,&w);
		d[u][v]=w;
	}
	for(int i=0;i<n;i++)
		dij(i);
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
			printf("%d ",ans[i][j]);
		puts("");
	}
	return 0;
}