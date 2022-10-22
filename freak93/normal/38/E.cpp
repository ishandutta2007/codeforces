#include<cstdio>
#include<algorithm>
#define x first
#define y second

using namespace std;

pair<int,int> a[5000];

int n,i,j;
long long dp[5000],cost;

int main()
{
	scanf("%d",&n);
	for(i=1;i<=n;++i)
		scanf("%d%d",&a[i].x,&a[i].y);
	sort(a+1,a+n+1);
	dp[1]=a[1].y;
	for(i=2;i<=n;++i)
	{
		dp[i]=dp[i-1]+a[i].y;cost=0;
		for(j=i-1;j>=1;--j)
			cost+=(long long)(a[j+1].x-a[j].x)*(long long)(i-j),dp[i]=min(dp[i],dp[j-1]+cost+a[j].y);
	}
	printf("%lld",dp[n]);
}