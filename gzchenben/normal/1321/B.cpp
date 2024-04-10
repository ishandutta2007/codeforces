#include<cstdio>
#include<algorithm>
using namespace std;
long long n,ans,a[1000005],maxn[1000005];
int main()
{
	scanf("%lld",&n);
	for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
	for(int i=1;i<=n;i++)
	{
		long long dp=maxn[a[i]-i+200000]+a[i];
		maxn[a[i]-i+200000]=max(maxn[a[i]-i+200000],dp);
		ans=max(ans,dp);
	}
	printf("%lld\n",ans);
}