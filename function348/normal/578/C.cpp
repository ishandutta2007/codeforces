#include<cstdio>
#include<iostream>
#include<cmath>
using namespace std;
const int N=200010;
int n;
int a[N];
double b[N];
double f(double m)
{
	for (int i=1;i<=n;i++) b[i]=a[i]-m;
	double now=0,mx1=-2000000000,mx2=2000000000;
	for (int i=1;i<=n;i++)
	{
		now+=b[i];
		mx1=max(mx1,now);
		if (now<0) now=0;
	}
	now=0;
	for (int i=1;i<=n;i++)
	{
		now+=b[i];
		mx2=min(mx2,now);
		if (now>0) now=0;
	}
	return max(mx1,-mx2);
}
int main()
{
	scanf("%d",&n);
	for (int i=1;i<=n;i++) scanf("%d",&a[i]);
	double l=-30000,r=30000;
	for (int tt=1;tt<=100;++tt)
	{
		double m1=l+(r-l)/3,m2=l+(r-l)/3*2;
		if (f(m1)<f(m2)) r=m2;else l=m1;
	}
	printf("%.8lf\n",f(l));
	return 0;
}