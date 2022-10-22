#include<cstdio>
#include<cmath>
using namespace std;
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		long long n,sum=0,now=0;
		scanf("%lld",&n);
		for(int i=1;i<=n;i++)
		{
			long long x;
			scanf("%lld",&x);
			sum+=x;
			now^=x;
		}
		printf("2\n%lld %lld\n",now,sum+now);
	}
	return 0;
}