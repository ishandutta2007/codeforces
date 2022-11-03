#include<bits/stdc++.h>
using namespace std;
int n,p,k;
int a[333333];
long long ans;
map<int,int> mp,mpb;
int main()
{
	scanf("%d%d%d",&n,&p,&k);
	for (int i=1;i<=n;i++) scanf("%d",&a[i]);
	for (int i=1;i<=n;i++)
	{
		mp[a[i]]++;
	}
	for (map<int,int>::iterator it=mp.begin();it!=mp.end();it++)
	{
		if (1ll*((it->first)+(it->first))*(2ll*(it->first)*(it->first)%p)%p!=k) ans-=(1ll*(it->second)*((it->second)-1));
	}
	for (int i=1;i<=n;i++)
	{
		mpb[((1ll*a[i]*a[i]%p*a[i]%p*a[i]-1ll*k*a[i])%p+p)%p]++;
	}
	for (map<int,int>::iterator it=mpb.begin();it!=mpb.end();it++)
	{
		ans+=(1ll*(it->second)*((it->second)-1));
	}
	printf("%lld\n",ans/2);
	return 0;
}