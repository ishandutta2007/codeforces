#include<cstdio>
#include<iostream>
#include<cmath>
using namespace std;
const int N=100010;
int n;
double a[N],b[N];
long double ans1[N],ans2[N];
int main()
{
	scanf("%d",&n);
	for (int i=1;i<=n;i++) scanf("%lf",&a[i]);
	for (int i=1;i<=n;i++) scanf("%lf",&b[i]);
	for (int i=1;i<=n;i++) a[i]+=a[i-1];
	for (int i=n;i>=1;i--) b[i]+=b[i+1];
	for (int i=1;i<n;i++)
	{
		long double c=a[i],d=b[i+1];
		d=c+1-d;
		long double x1=(d+sqrt(d*d-4*c+1e-14))/2;
		long double x2=(d-sqrt(d*d-4*c+1e-14))/2;
		ans1[i]=x1;ans2[i]=x2;
	}
	ans1[n]=ans2[n]=1;
	for (int i=n;i>=1;i--)
	{
		ans1[i]=ans1[i]-ans1[i-1];
		ans2[i]=ans2[i]-ans2[i-1];
	}
	for (int i=1;i<=n;i++) printf("%.8lf ",(double)ans1[i]);printf("\n");
	for (int i=1;i<=n;i++) printf("%.8lf ",(double)ans2[i]);printf("\n");
	return 0;
}