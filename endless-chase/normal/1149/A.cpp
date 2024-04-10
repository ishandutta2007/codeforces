#include<bits/stdc++.h>
#define Accepted 0
using namespace std;
int n,cnt1,cnt2,x;
int main()
{
	scanf("%d",&n);
	for (int i=1;i<=n;i++)
	{
		scanf("%d",&x);
		if (x==1) cnt1++;
		else cnt2++;
	}
	if (cnt1&1)
	{
		if (cnt1==1)
		{
			if (!cnt2)
			{
				printf("1\n");
				return 0;
			}
			printf("2 ");
			printf("1 ");
			for (int i=1;i<cnt2;i++) printf("2 ");
			printf("\n");
			return 0;
		}
		for (int i=1;i<=cnt1;i++) printf("1 ");
		for (int i=1;i<=cnt2;i++) printf("2 ");
		printf("\n");
	}
	else
	{
		if (!cnt1)
		{
			for (int i=1;i<=cnt2;i++) printf("2 ");
			printf("\n");
			return 0;
		}
		
		if (cnt1==2)
		{
			if (!cnt2)
			{
				printf("1 1\n");
				return 0;
			}
			printf("2 ");
			printf("1 ");
			for (int i=1;i<cnt2;i++) printf("2 ");
			printf("1\n");
			return 0;
		}
		for (int i=1;i<=cnt1-1;i++) printf("1 ");
		for (int i=1;i<=cnt2;i++) printf("2 ");
		printf("%d\n",1);
	}
	return Accepted;
}