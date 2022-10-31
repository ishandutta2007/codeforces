#include<cstdio>
#include<iostream>
using namespace std;
const int N=310,inf=2100000000;
int b[N][12],d[N];
int f[1000],g[1000];
int n;
int a[N],c[N],p[N];
int dp(int now)
{
	int m=d[now];
	for (int i=1;i<=n;i++) p[i]=0;
	for (int i=1;i<=n;i++)
	for (int j=0;j<d[now];j++)
	if (a[i]%b[now][j]==0) p[i]+=1<<j;
	for (int i=0;i<(1<<m);i++) f[i]=inf;
	f[(1<<m)-1]=0;
	for (int i=1;i<=n;i++)
	{
		for (int j=0;j<(1<<m);j++) g[j]=inf;
		for (int j=0;j<(1<<m);j++)
			g[j&p[i]]=min(g[j&p[i]],f[j]+c[i]);
		if (i!=now)
		for (int j=0;j<(1<<m);j++) g[j]=min(g[j],f[j]);
		for (int j=0;j<(1<<m);j++) f[j]=g[j];
	}
	return f[0];
}
int main()
{
	scanf("%d",&n);
	for (int i=1;i<=n;i++) scanf("%d",&a[i]);
	for (int i=1;i<=n;i++) scanf("%d",&c[i]);
	for (int i=1;i<=n;i++)
	{
		int tmp=a[i];
		for (int j=2;j*j<=tmp;j++)
		if (tmp%j==0)
		{
			while (tmp%j==0) tmp/=j;
			b[i][ d[i] ]=j;d[i]++;
		}
		if (tmp!=1) b[i][ d[i] ]=tmp,d[i]++;
	}
	int ans=inf;
	for (int i=1;i<=n;i++) ans=min(ans,dp(i));
	if (ans==inf) ans=-1;
	printf("%d\n",ans);
	return 0;
}