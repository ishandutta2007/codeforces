#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=200005;
map<int,int>mp;
int a[N],sum[N],n,k;
signed main()
{
	ios::sync_with_stdio(false);
	cin>>n>>k;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)
	{
		mp[a[i]]++;
		if(mp[a[i]]==k)
		{
			cout<<0<<endl;
			return 0;
		}
		sum[i]=sum[i-1]+a[i];
	}
	int ans=1e18;
	ans=min(ans,a[k]*k-sum[k]);
	ans=min(ans,(sum[n]-sum[n-k])-a[n-k+1]*k);
	for(int i=1;i<=n;i++)
	{
		if(a[i]==a[i-1])
			continue;
		int r=0,j=i+mp[a[i]]-1;
		r+=(a[i]-1)*(i-1)-sum[i-1];
		r+=(sum[n]-sum[j])-(a[i]+1)*(n-j);
		r+=k-mp[a[i]];
		ans=min(ans,r);
		if(j>=k)
		{
			int r=0,j=i+mp[a[i]]-1;
			r+=(a[i]-1)*(i-1)-sum[i-1];
			r+=k-mp[a[i]];
			ans=min(ans,r);
		}
		if(n-i+1>=k)
		{
			int r=0,j=i+mp[a[i]]-1;
			r+=(sum[n]-sum[j])-(a[i]+1)*(n-j);
			r+=k-mp[a[i]];
			ans=min(ans,r);
		}
	}
	cout<<ans<<endl;
	return 0;
}