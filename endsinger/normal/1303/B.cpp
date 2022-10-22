#include<bits/stdc++.h>
#define int long long
using namespace std;
signed main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n,g,b;
		cin>>n>>g>>b;
		int m=(n+1)/2,zh=n-m,ans=0;
		if(m%g==0)
		{
			int k=m/g;
			ans+=k*g+(k-1)*b;
			zh-=(k-1)*b;
			if(zh<0LL)
				zh=0LL;
			ans+=zh;
		}
		else
		{
			int k=m/g;
			ans+=k*g+m%g+k*b;
			zh-=k*b;
			if(zh<0LL)
				zh=0LL;
			ans+=zh;
		}
		cout<<ans<<endl;
	}
	return 0;
}