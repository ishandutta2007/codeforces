#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,mod,k,arr[300005];
ll ans;
map<int,int> mp;
int gets(int a)
{
	return 1ll*a*a%mod*a%mod*a%mod;
}
int main()
{
	scanf("%d%d%d",&n,&mod,&k);
	for(int i=1;i<=n;i++) scanf("%d",&arr[i]);
	for(int i=1;i<=n;i++)
	{
		int a=arr[i];
		int t=((1ll*a*k%mod)-gets(a))%mod;
		if(t<0) t+=mod;
		ans+=mp[t];
		mp[t]++;
	}
	printf("%lld\n",ans);
	return 0;
}