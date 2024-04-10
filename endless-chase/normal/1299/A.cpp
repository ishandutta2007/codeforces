#include<bits/stdc++.h>
#define Accepted 0
using namespace std;
int n,a[111111],num[111],ans,id,cur;
int main()
{
	scanf("%d",&n);
	for (int i=1;i<=n;i++) scanf("%d",&a[i]);
	for (int i=0;i<30;i++)
	{
		for (int j=1;j<=n;j++)
		{
			if (a[j]&(1<<i)) num[i]++;
		}
	}
	id=1;
	for (int i=1;i<=n;i++)
	{
		cur=0;
		for (int j=0;j<30;j++)
		{
			if (a[i]&(1<<j))
			{
				if (num[j]==1) cur+=(1<<j);
			}
		}
		if (cur>ans) 
		{
			ans=cur;
			id=i;
		}
	}
	printf("%d ",a[id]);
	for (int i=1;i<=n;i++)
	{
		if (i!=id) printf("%d ",a[i]);
	}
	printf("\n");
	return Accepted;
}