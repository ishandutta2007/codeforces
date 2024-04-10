#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=200005,mod=998244353;
int a[N],vis[N],n,k,mx,ans=1,las=-1;
signed main()
{
	ios::sync_with_stdio(false);
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		if(a[i]>=n-k+1)
		{
			vis[i]=1;
			mx+=a[i];
		}
	}
	for(int i=1;i<=n;i++)
	{
		if(!vis[i])
			continue;
		if(las==-1)
			las=i;
		else
		{
			ans=ans*(i-las)%mod;
			las=i;
		}
	}
	cout<<mx<<' '<<ans<<endl;
	return 0;
}