#include<bits/stdc++.h>

using namespace std;

int n1,n2,a[1005],b[1005],tj[100005],i,j,ans1,ans2;

int main()
{
	scanf("%d",&n1);
	for(i=0;i<n1;i++)
	{
		scanf("%d",&a[i]);
		tj[a[i]]++;
	}
	scanf("%d",&n2);
	for(i=0;i<n2;i++)
	{
		scanf("%d",&b[i]);
		tj[b[i]]++;
	}
	for(i=0;i<n1;i++)
		for(j=0;j<n2;j++)
			if(!tj[a[i]+b[j]])
			{
				ans1=a[i];
				ans2=b[j];
				break;
			}
	printf("%d %d\n",ans1,ans2);
	return 0;
}