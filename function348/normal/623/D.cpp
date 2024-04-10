#include<cstdio>
#include<iostream>
using namespace std;
const int N=110;
int n;
double a[N],b[N];
double ans,last,now;
int main()
{
	scanf("%d",&n);
	for (int i=1;i<=n;i++)
	{
		int x;
		scanf("%d",&x);
		a[i]=x*1.0/100;
	}
	for (int i=1;i<=n;i++) b[i]=a[i];
	last=1;
	for (int i=1;i<=n;i++) last*=a[i];
	ans=last*n;
	for (int j=n+1;j<=200000;j++)
	{
		double p=0;int q=0;
		for (int i=1;i<=n;i++)
		{
			double tmp=(b[i]+(1-b[i])*a[i])/b[i];
			if (tmp>p) p=tmp,q=i;
		}
		b[q]=b[q]+(1-b[q])*a[q];
		now=last*p;
		ans+=j*(now-last);
		last=now;
	}
	printf("%lf\n",ans);
	return 0;
}