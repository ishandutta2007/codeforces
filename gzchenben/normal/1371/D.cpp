#include<cstdio>
#include<algorithm>
using namespace std;
int t,a[1005][1005];
int main()
{
	scanf("%d",&t);
	while(t--)
	{
		int n,k,cnt=0;
		scanf("%d%d",&n,&k);
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<n;j++)
			{
				a[i][j]=0;
			}
		}
		for(int t=0;t<n;t++)
		{
			for(int i=0;i<n;i++)
			{
				if(cnt==k) break;
				int j=(t-i+n)%n;
				a[i][j]=1;
				cnt++;
			}
			if(cnt==k) break;
		}
		if(k%n==0) printf("0\n");
		else printf("2\n"); 
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<n;j++)
			{
				printf("%d",a[i][j]);
			}
			printf("\n");
		}
	}
}