#include<bits/stdc++.h>
#define Accepted 0
using namespace std;
int n,a[111111],b[111111],c[111111],d[111111];
int main()
{
	scanf("%d",&n);
	for (int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
	}
	for (int i=1;i<=n;i++)
	{
		scanf("%d",&b[i]);
	}
	for (int i=1;i<=n;i++)
	{
		c[i]=a[i+1]-a[i];
		d[i]=b[i+1]-b[i];
	}
	sort(c+1,c+n);
	sort(d+1,d+n);
	if (a[1]!=b[1])
	{
		printf("No\n");
		return Accepted;
	}
	for (int i=1;i<n;i++)
	{
		if (c[i]!=d[i])
		{
			printf("No\n");
			return Accepted;
		}
	}
	printf("Yes\n");
	return Accepted;
}