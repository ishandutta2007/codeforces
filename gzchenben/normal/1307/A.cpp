#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int n,d,t,a[105];
int main()
{
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d",&n,&d);
		for(int i=1;i<=n;i++)
		{
			scanf("%d",&a[i]);
		}
		int ans=0;
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=a[i];j++)
				if(d>=(i-1)) 
				{
					d=d-(i-1);
					ans++;
				}
		}
		printf("%d\n",ans);
	}
}