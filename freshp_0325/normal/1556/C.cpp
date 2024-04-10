#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
LL n,a[1005],sum[1005],tmp[1005];
int main(){
	scanf("%lld",&n);
	for(LL i=1;i<=n;++i)	scanf("%lld",&a[i]);
	for(LL i=1;i<=n;++i)
	{
		if(i&1)	sum[i]=sum[i-1]+a[i],tmp[i]=a[i];
		else	sum[i]=sum[i-1]-a[i],tmp[i]=-a[i];
	}
	LL ans=0;
	for(LL i=1;i<=n;i+=2)
	{
		LL minn=1e18,st=0;
		for(LL j=i+1;j<=n;++j)
		{
			LL range=sum[j-1]-sum[i];
			if((j%2==0) && max(1ll,-minn)<=a[i])
			{
				if(min(a[i],a[j]-range)>=max(1ll,-minn))
				{
					ans+=min(a[i],a[j]-range)-max(1ll,-minn)+1;
				}
			}
			st+=tmp[j];
			minn=min(minn,st);
		}
	}
	printf("%lld",ans);
	return 0;
}