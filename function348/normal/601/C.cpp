#include<cstdio>
#include<iostream>
using namespace std;
const int N=110,M=N*1100;
int n,m;
double f[M],g[M],tmp[M];
int main()
{
	scanf("%d%d",&n,&m);
	int tot=0;
	f[0]=1;g[0]=1;
	for (int j=1;j<=n;j++)
	{
		int x;
		scanf("%d",&x);
		tot+=x;
		g[0]=f[0];
		for (int i=1;i<=j*m;i++) g[i]=g[i-1]+f[i];
		for (int i=0;i<=j*m;i++)
		{
			if (i) tmp[i]=g[i-1];
			if (i>=m+1) tmp[i]-=g[i-m-1];
			if (i>=x) tmp[i]-=f[i-x];
		}
		for (int i=0;i<=j*m;i++) f[i]=tmp[i]/m,tmp[i]=0;
	}
	double k1=0,k2=0;
	if (m==1) { printf("1\n");return 0;}
	for (int i=0;i<=n*m;i++) 
	{
		if (i<tot) k1+=f[i];
		k2+=f[i];
	}
	printf("%.10lf\n",k1/k2*(m-1)+1);
	return 0;
}