#include<bits/stdc++.h>
using namespace std;
#define eps (1e-8)

double f[2010],p[2010],q[2010];
int sum1[2010],sum2[2010],n,a,b;

inline void gao(double h1,double h2)
{
	memset(sum1,0,sizeof(sum1));
	memset(sum2,0,sizeof(sum2));
	for (int i=1;i<=n;i++)
	{
		f[i]=f[i-1];sum1[i]=sum1[i-1];sum2[i]=sum2[i-1];
		if (f[i-1]+p[i]-h1>f[i]) f[i]=f[i-1]+p[i]-h1,sum1[i]=sum1[i-1]+1,sum2[i]=sum2[i-1];
		if (f[i-1]+q[i]-h2>f[i]) f[i]=f[i-1]+q[i]-h2,sum1[i]=sum1[i-1],sum2[i]=sum2[i-1]+1;
		if (f[i-1]+p[i]+q[i]-p[i]*q[i]-h1-h2>f[i]) f[i]=f[i-1]+p[i]+q[i]-p[i]*q[i]-h1-h2,sum1[i]=sum1[i-1]+1,sum2[i]=sum2[i-1]+1;
	}
}

int main()
{
	scanf("%d%d%d",&n,&a,&b);
	for (int i=1;i<=n;i++) scanf("%lf",&p[i]);
	for (int i=1;i<=n;i++) scanf("%lf",&q[i]);
	double l=0,r=1,l1,r1;
	while (r-l>eps)
	{
		double mid=(l+r)/2;
		l1=0;r1=1;
		while (r1-l1>eps)
		{
			double mid1=(l1+r1)/2;
			gao(mid,mid1);
			if (sum2[n]<=b) r1=mid1;
			else l1=mid1;
		}
		gao(mid,r1);
		if (sum1[n]<=a) r=mid;
		else l=mid;
	}
	gao(r,r1);
	printf("%.10lf\n",f[n]+l*a+l1*b);
	return 0;
}