#include<iostream>
#include<cstdio>
#include<map>
#include<algorithm>
using namespace std;
map<long long,long long> mp;
long long n,t,ans;
long long a[222222],sum[222222],ss[222222],cnt,bit[444444],sz;
void update(long long p)
{
	while(p<=sz)
	{
		bit[p]++;
		p+=p&(-p);
	}
}
long long get(long long p)
{
	long long res=0;
	while(p>=1)
	{
		res+=bit[p];
		p-=p&(-p);
	}
	return res;
}
int main()
{
	scanf("%I64d%I64d",&n,&t);
	for (long long i=1;i<=n;i++)
	{
		scanf("%I64d",&a[i]);
		sum[i]=sum[i-1]+a[i];
		ss[i]=sum[i];
	}
	sort(ss+1,ss+n+1);
	for (long long i=1;i<=n;i++)
	{
		if (mp.find(ss[i])==mp.end())
		{
			mp[ss[i]]=++cnt;
		}
	}
	sz=1;
	while(sz<cnt) sz*=2;
	for (long long i=n-1;i>=0;i--)
	{
		update(mp[sum[i+1]]);
		int pos=lower_bound(ss+1,ss+n+1,sum[i]+t)-ss;
		if (pos==n+1) pos=n;
		while(pos>=1 && ss[pos]-sum[i]>=t) pos--;
		if (!pos) continue;
		ans+=get(mp[ss[pos]]);
	}
	printf("%I64d\n",ans);
	return 0;
}