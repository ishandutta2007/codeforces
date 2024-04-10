#include<bits/stdc++.h>
using namespace std;
const int N=200005;
int n,a[N];
map<int,vector<int>>mp;
int main()
{
	ios::sync_with_stdio(false);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		mp[a[i]-i].push_back(a[i]);
	}
	long long ans=0,sum;
	for(auto &s:mp)
	{
		auto &v=s.second;
		sum=0;
		for(auto i:v)
			sum+=i;
		ans=max(ans,sum);
	}
	cout<<ans<<endl;
	return 0;
}