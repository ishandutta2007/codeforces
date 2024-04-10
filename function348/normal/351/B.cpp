#include<cstdio>
#include<iostream>
using namespace std;
const int N=3010;
int n,p;
int a[N];
int main()
{
	scanf("%d",&n);
	for (int i=1;i<=n;i++) scanf("%d",&a[i]);
	for (int i=1;i<=n;i++)
	for (int j=i+1;j<=n;j++)
		p+=a[i]>a[j];
	if (p&1) printf("%.6lf\n",2.0*p-1);else printf("%.6lf\n",2.0*p);
	return 0;
}