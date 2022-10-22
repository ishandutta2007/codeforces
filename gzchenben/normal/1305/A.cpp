#include<cstdio>
#include<cstring>
#include<queue>
#include<stack> 
#include<algorithm>
using namespace std;
int n,t,a[200005],b[200005];
int main()
{
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		for(int i=1;i<=n;i++)
		{
			scanf("%d",&a[i]);
		}
		for(int i=1;i<=n;i++)
		{
			scanf("%d",&b[i]);
		}
		sort(a+1,a+n+1);
		sort(b+1,b+n+1);
		for(int i=1;i<=n;i++)
		{
			printf("%d ",a[i]);
		}
		printf("\n");
		for(int i=1;i<=n;i++)
		{
			printf("%d ",b[i]);
		}
		printf("\n");
	}
	return 0;
}