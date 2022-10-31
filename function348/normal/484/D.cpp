#include<cstdio>
#include<iostream>
using namespace std;
typedef long long LL;
const int N=1000100;
int n;
LL a[N],c[N],f[N];
LL abs(LL n) { return n>0?n:-n;}
int main()
{
	scanf("%d",&n);
	for (int i=1;i<=n;i++) scanf("%I64d",&a[i]);
	for (int i=2;i<=n;i++)
	{
		int p=0;
		if (a[i-1]>=a[i-2]&&a[i-1]>=a[i]) p=1;
		if (a[i-1]<=a[i-2]&&a[i-1]<=a[i]) p=1;
		if (a[i-1]==a[i-2]&&a[i-1]==a[i]) p=0;
		if (i==2) p=1;
		if (p) c[i]=i-1;else c[i]=c[i-1];
	}
	for (int i=2;i<=n;i++)
	{
		f[i]=max(f[c[i]]+abs(a[c[i]+1]-a[i]),f[c[i]-1]+abs(a[c[i]]-a[i]));
	}
	printf("%I64d\n",f[n]);
	return 0;
}