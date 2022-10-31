#include<cstdio>
#include<iostream>
#include<cmath>
#include<algorithm>
using namespace std;
struct point { double x,y;};
typedef long long LL;
const int N=2010;
const double eps=1e-12,inf=1e+30;
int n;
LL ans;
point a[N];
double p[N];
point calc(int a,int b,int c)
{
	return (point){1.0*a*c/(a*a+b*b),1.0*b*c/(a*a+b*b)};
}
int main()
{
	scanf("%d",&n);
	for (int i=1;i<=n;i++)
	{
		int p,q,r;
		scanf("%d%d%d",&p,&q,&r);
		a[i]=calc(p,q,r);
//		printf("%lf %lf\n",a[i].x,a[i].y);
	}
	
	for (int i=1;i<=n;i++)
	{
		int num=0;
		for (int j=i+1;j<=n;j++)
		{
			double k=0;
			if (abs(a[i].x-a[j].x)<eps) 
				if (abs(a[i].y-a[j].y)<eps) { ans+=n-i-1;continue;}
				else k=inf;
			else k=(a[i].y-a[j].y)/(a[i].x-a[j].x);
			p[++num]=k;
		}
		sort(p+1,p+1+num);
		int cnt=1;
		for (int i=2;i<=num;i++)
		if (p[i]-p[i-1]<eps) cnt++;else
		{
			ans+=1LL*cnt*(cnt-1)/2;
			cnt=1;
		}
		ans+=1LL*cnt*(cnt-1)/2;
	}
	printf("%lld\n",ans);
	return 0;
}