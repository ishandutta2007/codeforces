#include<cstdio>
#include<algorithm>
const int N=300005;
int gcd(int a,int b){return (!b)?a:gcd(b,a%b);}
inline int abs(int a){return a>0?a:-a;}
inline int max(int a,int b){return a>b?a:b;}
inline int min(int a,int b){return a<b?a:b;}
int cnt1[1<<21],cnt2[1<<21];
int main()
{
	int n,sum=0,x;
	long long ans=0;
	scanf("%d",&n);
	cnt2[0]=1;
	for(int i=1;i<=n;++i)
	{
		scanf("%d",&x);
		sum^=x;
		if(i&1)
		{
			ans+=cnt1[sum];
			++cnt1[sum];
		}
		else
		{
			ans+=cnt2[sum];
			++cnt2[sum];
		}
	}
	printf("%lld\n",ans);
	return 0;
}