#include<cstdio>
#include<algorithm>
using namespace std;
int t,n,k,p,a[200005],pri[200005],ans;
int main()
{
	scanf("%d",&t);
	while(t--)
	{
		ans=0;
		scanf("%d%d%d",&n,&p,&k);
		for(int i=1;i<=n;i++)
		{
			scanf("%d",&a[i]);
		}
		sort(a+1,a+n+1);
		for(int i=1;i<k;i++)
		{
			pri[i]=pri[i-1]+a[i];
		}
		for(int i=k;i<=n;i++)
		{
			pri[i]=pri[i-k]+a[i];
		}
		for(int i=1;i<=n;i++)
		{
			if(pri[i]<=p) ans=max(ans,i);
		}
		printf("%d\n",ans);
	}
	return 0;
}