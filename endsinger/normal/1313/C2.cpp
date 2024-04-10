#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=500005;
int a[N],le[N],ri[N],n,ans[N];
vector<pair<int,int>>v;
signed main()
{
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	v.emplace_back(0,0);
	v.emplace_back(1,a[1]);
	le[1]=a[1];
	for(int i=2;i<=n;i++)
	{
		while(a[i]<v[v.size()-1].second)
			v.pop_back();
		int k=v[v.size()-1].first;
		le[i]=le[k]+(i-k)*a[i];
		v.emplace_back(i,a[i]);
	}
	v.clear();
	v.emplace_back(n+1,0);
	v.emplace_back(n,a[n]);
	ri[n]=a[n];
	for(int i=n-1;i>=1;i--)
	{
		while(a[i]<v[v.size()-1].second)
			v.pop_back();
		int k=v[v.size()-1].first;
		ri[i]=ri[k]+(k-i)*a[i];
		v.emplace_back(i,a[i]);
	}
	int p=1;
	for(int i=2;i<=n;i++)
	{
		if(le[i]+ri[i]-a[i]>le[p]+ri[p]-a[p])
			p=i;
	}
	ans[p]=a[p];
	for(int i=p-1;i>=1;i--)
		ans[i]=min(ans[i+1],a[i]);
	for(int i=p+1;i<=n;i++)
		ans[i]=min(ans[i-1],a[i]);
	for(int i=1;i<=n;i++)
		cout<<ans[i]<<' ';
	return 0;
}