#include<cstdio>
#include<algorithm>
using namespace std;
long long t,n,x;
long long f(long long x)
{
	long long maxn=-1,minn=10;
	while(x)
	{
		long long xx=x%10;
		maxn=max(maxn,xx);
		minn=min(minn,xx);
		x/=10;
	}
	return maxn*minn;
}
int main()
{
	scanf("%d",&t);
	while(t--)
	{
		scanf("%lld%lld",&x,&n);
		n--;
		for(int i=1;i<=n;i++)
		{
			if(f(x)) x+=f(x);
			else break;
		}
		printf("%lld\n",x);
	}
}