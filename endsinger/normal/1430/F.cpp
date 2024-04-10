#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2005;
int n,k,l[N],r[N],a[N],dp[N],ans,x;
signed main()
{
	ios::sync_with_stdio(false);
	cin>>n>>k;
	for(int i=1;i<=n;i++)
		cin>>l[i]>>r[i]>>a[i];
	for(int i=n;i>=1;i--)
	{
		int t=a[i];
		if(i!=n&&r[i]==l[i+1])
			t+=dp[i+1];
		if((r[i]-l[i]+1)*k<t)
		{
			cout<<-1<<endl;
			return 0;
		}
		t-=(r[i]-l[i])*k;
		if(t<0)
			t=0;
		dp[i]=t;
	}
	x=k;
	for(int i=1;i<=n;i++)
	{
		if(x<dp[i])
		{
			ans+=x;
			x=k;
		}
		ans+=a[i];
		x=(x-a[i]%k+k)%k;
	}
	cout<<ans<<endl;
	return 0;
}