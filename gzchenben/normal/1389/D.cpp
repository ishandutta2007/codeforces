#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int n,t;
long long k,a,b,l1,l2,r1,r2;
int main()
{
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%lld",&n,&k);
		scanf("%lld%lld%lld%lld",&l1,&r1,&l2,&r2);
		long long now=n*max(min(r1,r2)-max(l1,l2),0ll);
		if(now>=k)
		{
			printf("0\n");
			continue;
		}
		a=max(max(l1,l2)-min(r1,r2),0ll);
		b=(max(r1,r2)-min(l1,l2))-max(min(r1,r2)-max(l1,l2),0ll);
//		printf("now=%lld a=%lld b=%lld\n",now,a,b);
		long long minn=1e18;
		for(int i=1;i<=n;i++)
		{
			if(k-now>i*b) minn=min(minn,i*a+i*b+(k-now-i*b)*2);
			else minn=min(minn,i*a+(k-now));
		}
		printf("%lld\n",minn);
	}
}