#include<bits/stdc++.h>
using namespace std;
#define inf 1000000000

int ans=inf;
int dis[110][10];
int d[110][110],col[110],n,m;

inline int rd()
{
	int x=0;char ch=getchar();
	for (;ch<'0'||ch>'9';ch=getchar());
	for (;ch>='0'&&ch<='9';ch=getchar()) x=x*10+ch-'0';
	return x;
}

mt19937 rnd(time(NULL));

inline void work()
{
	for (int i=1;i<=n;i++) col[i]=rnd()&1;
	for (int i=1;i<=n;i++) for (int j=0;j<m;j++) dis[i][j]=inf;
	dis[1][0]=0;
	for (int j=1;j<m;j++)
	{
		for (int k=1;k<=n;k++) for (int l=1;l<=n;l++) if (col[k]^col[l]) dis[k][j]=min(dis[k][j],dis[l][j-1]+d[l][k]);
	}
	int res=inf;
	for (int i=2;i<=n;i++) if (col[i]^col[1]) res=min(res,dis[i][m-1]+d[i][1]);
	ans=min(ans,res); 
}

int main()
{
	n=rd();m=rd();
	for (int i=1;i<=n;i++) for (int j=1;j<=n;j++) d[i][j]=rd();
	for (int hhh=1;hhh<=10000;hhh++) work();
	printf("%d\n",ans);
	return 0;
}