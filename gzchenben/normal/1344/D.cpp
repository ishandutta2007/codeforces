#include<cstdio>
using namespace std;
int n,a[100005],ans[100005];
bool ok[100005];
long long k;
long long check(long long v)
{
	for(int i=1;i<=n;i++)
	{
		int low=0,high=a[i];
		while(low<high)
		{
			int mid=(low+high+1)>>1;
			if(a[i]+v-3ll*mid*mid>=0) low=mid;
			else high=mid-1;
		}
		ok[i]=0;
		if(low==a[i])
		{
			ans[i]=low;
			continue;
		}
		if(3ll*low*low+3ll*low+1-a[i]-v<=0) ans[i]=low+1;
		else ans[i] = low;
		if(3ll*low*low+3ll*low+1-a[i]-v==0) ok[i]=1;
	}
	long long tot=0;
	for(int i=1;i<=n;i++)
	{
		tot+=ans[i];
	}
	return tot;
}
int main()
{
	scanf("%d%lld",&n,&k);
	for(int i=1;i<=n;i++) 
	{
		scanf("%d",&a[i]);
	}
	long long low=-3e18,high=3e18;
	while(low<high)
	{
		long long mid=(low+high)>>1;
		if(check(mid)>=k) high=mid;
		else low=mid+1;
	}
	long long tot=check(low);
	for(int i=1;i<=n;i++)
	{
		if(tot>k && ok[i])
		{
			ans[i]--;
			tot--;
		}
	}
	for(int i=1;i<=n;i++)
	{
		printf("%d ",ans[i]);
	}
    return 0;
}