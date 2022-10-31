#include<cstdio>
#include<iostream>
using namespace std;
const int N=500010;
int n,ans;
int a[N];
int main()
{
	scanf("%d",&n);
	for (int i=1;i<=n;i++) scanf("%d",&a[i]);
	int ans=0,last=1;
	for (int i=2;i<=n+1;i++)
	if (a[i]==a[i-1]||i==n+1) 
	{
		ans=max(ans,(i-last-1)/2);
		int l=last+1,r=i-2;
		while (l<=r)
		{
			a[l]=a[last];a[r]=a[i-1];
			l++,r--;
		}
		last=i;
	}
	printf("%d\n",ans);
	for (int i=1;i<=n;i++) printf("%d ",a[i]);
	return 0;
}