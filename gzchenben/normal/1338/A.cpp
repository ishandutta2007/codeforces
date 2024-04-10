#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int t,n,a[200005];
int main()
{
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		int now=-1000000001,ans=0;
		for(int i=1;i<=n;i++)
		{
			scanf("%d",&a[i]);
			now=max(now,a[i]);
			ans=max(ans,now-a[i]);
		}
		long long x=0;
		while((1ll<<x)<=ans)
		{
			x++;
		}
		printf("%lld\n",x);
	}
}