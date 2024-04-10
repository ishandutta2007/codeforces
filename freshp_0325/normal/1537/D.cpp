#include<cstdio>
int t,n;
int main()
{
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		if(n==1)
		{
			printf("Bob\n");
			continue;
		}
		int tmp=n,cnt=0;
		while(tmp%2==0)
		{
			tmp/=2;
			cnt++;
		}
		if(cnt==0)
		{
			printf("Bob\n");
			continue;
		}
		else
		{
			if(tmp==1)
			{
				if(cnt%2==0)	printf("Alice\n");
				else	printf("Bob\n");
			}
			else	printf("Alice\n");
		}
	}
	return 0;
 }