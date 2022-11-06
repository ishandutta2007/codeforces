#include<bits/stdc++.h>
#define ll long long
#define fast ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
vector<ll> hs;
ll n,m,i,a[10101010],tt,hz;
int main()
{
	fast
	cin>>n>>m;
	for(i=0;i<n;i++)
	{
		cin>>a[i];
	}
	sort(a,a+n);
	for(i=1;i<=1000000000;i++)
	{
		if(i==a[tt])
		{
			tt++;
			continue;
		}
		if(hz+i<=m)
		{
		//	cout<<i<<endl;
			hs.push_back(i);
			hz=hz+i;
		}
		else
			break;
	}
	if(hs.empty())
	{
		cout<<0<<"\n";
		return 0;
	}
	cout<<hs.size()<<"\n";
	for(i=0;i<hs.size()-1;i++)
		cout<<hs[i]<<" ";
	cout<<hs[hs.size()-1]<<"\n";
}