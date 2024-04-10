#include<cstdio>
#include<iostream>
using namespace std;
const int N=500010;
double f[N][70];
int fa[N],n;
int main()
{
	int q;
	scanf("%d",&q);
	n=1;
	for (int i=0;i<=60;i++) f[n][i]=1;
	while (q--)
	{
		int kd,p;
		scanf("%d%d",&kd,&p);
		if (kd==1)
		{
			int j=++n;fa[n]=p;
			for (int i=0;i<=60;i++) f[n][i]=1;
			double t1=0.5,t2=1;
			for (int i=0;i<=60;i++)
			{
				t2=(f[fa[j]][i]*t1+1)/(f[fa[j]][i]+1);
				f[fa[j]][i]=f[fa[j]][i]*t1;
				t1=t2;
				j=fa[j];
				if (j==0) break;
			}
		}
		if (kd==2)
		{
			double ans=0;
			for (int i=0;i<60;i++) ans-=f[p][i];
			ans+=f[p][60]*60;
			printf("%.6lf\n",ans);
		}
	}
	return 0;
}