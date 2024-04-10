#include<cstdio>
#include<iostream>
using namespace std;
const int N=100010;
int n,ans;
int a[N];
int main()
{
	scanf("%d",&n);
	for (int i=1;i<=n;i++) scanf("%d",&a[i]);
	for (int i=1;i<=n;i++)
	if (a[i]<0) a[i]=-a[i];
	for (int i=1;i<=n;i++)
	{
		int k1=0,k2=0;
		for (int j=1;j<i;j++) if (a[j]<a[i]) k1++;
		for (int j=i+1;j<=n;j++) if (a[j]<a[i]) k2++;
		ans+=min(k1,k2);
	}
	printf("%d\n",ans);
	return 0;
}