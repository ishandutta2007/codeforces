#include<bits/stdc++.h>
#define ll long long
#define pb push_back
using namespace std;
ll n,mi,hs,i,a[1010101];
vector<ll> v;
int main()
{
	cin>>n;
	mi=10e17;
	hs=10e17;
	for(i=1;i<=n;i++)
	{
		cin>>a[i];
		mi=min(mi,a[i]);
	}
	for(i=1;i<=n;i++)
	{
		if(a[i]==mi)
			v.pb(i);
	}
	for(i=1;i<v.size();i++)
	{
		hs=min(hs,v[i]-v[i-1]);
	}
	cout<<hs<<"\n";
}