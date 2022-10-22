#include<cstdio>
#include<cstring>
#include<queue>
#include<stack> 
#include<algorithm>
using namespace std;
int n,t,ansx;
char a[5005],b[5005],ans[5005];
bool check()
{
	for(int i=1;i<=n;i++)
	{
		if(b[i]<ans[i]) return true;
		if(b[i]>ans[i]) return false;
	}
	return false;
}
int main()
{
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		for(int i=1;i<=n;i++)
		{
			scanf(" %c",&a[i]);
			ans[i]='z'+1;
		}
		for(int i=1;i<=n;i++)
		{
			int tmp=i-1;
			for(int j=1;j<=n-tmp;j++)
			{
				b[j]=a[j+tmp];
			}
			if((n-i)%2)
			{
				for(int j=1;j<=tmp;j++)
				{
					b[n-tmp+j]=a[j];
				}
			}
			else
			{
				for(int j=1;j<=tmp;j++)
				{
					b[n-tmp+j]=a[tmp-j+1];
				}
			}
//			printf("----");
//		    for(int j=1;j<=n;j++)
//		    {
//		    	printf("%c",b[j]);
//			}
//			printf("\n");
			if(!check()) continue;
			for(int j=1;j<=n;j++)
			{
				ans[j]=b[j];
			}
			ansx=i;
		}
		for(int i=1;i<=n;i++)
		{
			printf("%c",ans[i]);
		}
		printf("\n%d\n",ansx);
	}
	return 0;
}