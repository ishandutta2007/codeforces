#include<cstdio>
#include<iostream>
#include<cmath>
using namespace std;
int n,a,d;
double f[100010];
int main()
{
	scanf("%d%d%d",&n,&a,&d);
	for (int i=1;i<=n;i++)
	{
		int t,v;
		double tim;
		scanf("%d%d",&t,&v);
		if (1.0*v*v<=d*2.0*a) tim=1.0*v/a+(d-0.5*v*v/a)/v;
		else tim=sqrt(2.0*d/a);
		tim+=t;
		f[i]=max(f[i-1],tim);
		printf("%.6lf\n",f[i]);
	}
	return 0;
}