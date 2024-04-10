#include<bits/stdc++.h>
#define int long long
using namespace std;
int a[60],n,m,ans;
map<int,int>mp;
void zh(int i)
{
	for(int j=i+1;j<=50;j++)
	{
		if(a[j])
		{
			a[j]--;
			a[i]+=(1LL<<(j-i));
			ans+=(j-i);
			return;
		}
	}
}
signed main()
{
	ios::sync_with_stdio(false);
	for(int i=0;i<=50;i++)
		mp[(1LL<<i)]=i;
	int t;
	cin>>t;
	while(t--)
	{
		cin>>n>>m;
		ans=0;
		for(int i=0;i<=50;i++)
			a[i]=0;
		for(int i=1;i<=m;i++)
		{
			int x;
			cin>>x;
			a[mp[x]]++;
		}
		int can=1;
		for(int i=0;i<=50;i++)
		{
			if(i)
				a[i]+=a[i-1]/2;
			if(!(n&(1LL<<i)))
				continue;
			if(!a[i])
				zh(i);
			if(!a[i])
			{
				can=0;
				break;
			}
			a[i]--;
		}
		if(!can)
			cout<<-1<<endl;
		else
			cout<<ans<<endl;
	}
	return 0;
}