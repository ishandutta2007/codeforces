#include<bits/stdc++.h>
using namespace std;
const int N=200005;
int a[N],c[N];
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n;
		scanf("%d",&n);
		for(int i=1;i<=n;i++)
			scanf("%d",&a[i]);
		int zh=1;
		for(int i=1;i<=n;i++)
			if(a[i]!=a[1])
				zh=0;
		if(zh)
		{
			puts("1");
			for(int i=1;i<=n;i++)
				printf("1 ");
			puts("");
			continue;
		}
		if(n%2==0)
		{
			printf("2\n");
			c[1]=1;
			for(int i=2;i<=n;i++)
				c[i]=3-c[i-1];
			for(int i=1;i<=n;i++)
				printf("%d ",c[i]);
			puts("");
		}
		else
		{
			int fl=0;
			c[1]=1;
			for(int i=2;i<=n;i++)
			{
				if(fl)
					c[i]=3-c[i-1];
				else
				{
					if(a[i]==a[i-1])
					{
						c[i]=c[i-1];
						fl=1;
					}
					else
						c[i]=3-c[i-1];
				}
			}
			if(a[1]==a[n]&&!fl)
				fl=1;
			int k=2;
			if(!fl)
			{
				c[n]=3;
				k++;
			}
			printf("%d\n",k);
			for(int i=1;i<=n;i++)
				printf("%d ",c[i]);
			puts("");
		}
	}
	return 0;
}