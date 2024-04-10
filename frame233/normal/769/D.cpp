#pragma GCC target("popcnt")
#include<cstdio>
typedef long long ll;
int pos,a[1<<15];
int cnt[66385];
int main()
{
	int n,k,x;
	scanf("%d %d",&n,&k);
	for(int i=0;i<=(1<<14);++i)
	{
		if(__builtin_popcount(i)==k)
		{
			a[++pos]=i;
		}
	}
	ll ans=0;
	for(int i=1;i<=n;++i)
	{
		scanf("%d",&x);
		for(int j=1;j<=pos;++j)
		{
			ans+=cnt[x^a[j]];
		}
		++cnt[x];
	}
	printf("%lld\n",ans);
	return 0;
}