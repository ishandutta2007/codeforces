#include<cstdio>
#include<iostream>
using namespace std;
int n,p;
double s,ans;
double abs(double n) { return n>0?n:-n;}
int main()
{
	scanf("%d",&n);
	ans=10000000;
	for (int i=1;i<=n*2;i++)
	{
		double x;
		scanf("%lf",&x);
		x-=((int)x);
		s+=x;
		if (x<1e-6) p++;
	}
	for (int i=0;i<=n;i++)
	if (2*n-p>=i&&p>=n-i) ans=min(ans,abs(i-s));
	ans+=1e-6;
	printf("%.3lf\n",ans);
	return 0;
}