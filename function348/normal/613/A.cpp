#include<cstdio>
#include<iostream>
#include<cmath>
using namespace std;
const double pi=acos(-1);
double mi,ma;
int n,nx,ny;
int x[100010],y[100010];
long long sqr(int n) { return 1LL*n*n;}
int main()
{
	scanf("%d%d%d",&n,&nx,&ny);
	mi=1e+15,ma=0;
	for (int i=1;i<=n;i++)
	{
		scanf("%d%d",&x[i],&y[i]);
		x[i]-=nx;y[i]-=ny;
	}
	for (int i=1;i<=n;i++) ma=max(ma,0.0+sqr(x[i])+sqr(y[i]));
	for (int i=1;i<=n;i++) mi=min(mi,0.0+sqr(x[i])+sqr(y[i]));
	x[n+1]=x[1],y[n+1]=y[1];
	for (int i=1;i<=n;i++)
	{
		double dist=1e+18;
		if (x[i]==x[i+1]) 
		{
			if (1LL*y[i]*y[i+1]<=0) dist=abs(x[i]);
		}
		else
		if (y[i]==y[i+1])
		{
			if (1LL*x[i]*x[i+1]<=0) dist=abs(y[i]);
		}
		else
		{
			double k=1.0*(y[i+1]-y[i])/(x[i+1]-x[i]);
			double b=y[i]-k*x[i];
			double px=-b*k/(k*k+1);
			if ((x[i]<=px&&px<=x[i+1])||(x[i]>=px&&px>=x[i+1])) dist=b/sqrt(k*k+1);

		}
		mi=min(mi,dist*dist);
	}
	double ans=(ma-mi)*pi;
	printf("%.8lf\n",ans);
	return 0;
}