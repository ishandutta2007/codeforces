#include<cstdio>
#include<algorithm>
using namespace std;
int n,t,a[100005];
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
		sort(a+1,a+n+1);
		int ans=0;
		for(int i=1;i<=n;i++)
		{
			if(a[i]<=i) ans=max(ans,i);
		}
		printf("%d\n",ans+1);
	}
}