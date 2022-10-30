#include<cstdio>
#include<iostream>
using namespace std;
int a[1000],c[1000],v[1000];
int n;
int main()
{
	scanf("%d",&n);
	for (int i=1;i<=n;i++) scanf("%d",&a[i]);
	int ok=1;
	for (int i=3;i<=n;i++)
	if (a[i]-a[i-1]!=a[2]-a[1]) ok=0;
	if (ok) printf("%d\n",a[n]+a[2]-a[1]);
	else printf("%d\n",a[n]);
}