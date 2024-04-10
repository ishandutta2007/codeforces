#include<cstdio>
#include<iostream>
using namespace std;
int n,k;
int main()
{
	scanf("%d%d",&n,&k);
	int l=1,r=n;
	for (int i=1;i<=k;i++)
	{
		if (i&1) printf("%d ",l),l++;
			else printf("%d ",r),r--;
	}
	if (k&1) for (int i=k+1;i<=n;i++) printf("%d ",l),l++;
		else for (int i=k+1;i<=n;i++) printf("%d ",r),r--;
}