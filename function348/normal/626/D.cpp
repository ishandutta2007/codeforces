#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;
const int N=20010;
typedef long long LL;
int n;
int a[N],b[N];
LL c[N];
int main()
{
	scanf("%d",&n);
	for (int i=1;i<=n;i++) scanf("%d",&a[i]);
	sort(a+1,a+1+n);
	for (int i=1;i<=n;i++)
	for (int j=i+1;j<=n;j++)
		b[a[j]-a[i]]++;
	for (int i=1;i<=5000;i++)
	for (int j=1;j<=5000;j++)
		c[i+j]+=b[i]*b[j];
	LL ans=0,sum=0;
	for (int i=1;i<=5000;i++)
	{
		ans+=sum*b[i];
		sum+=c[i];
	}
	LL m=n*(n-1)/2;
	double t=1.0*ans/m/m/m;
	printf("%.8lf\n",t);
	return 0;
}