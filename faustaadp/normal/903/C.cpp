#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,i,ta,hs;
map<ll,ll> a;
int main()
{
	cin>>n;
	for(i=1;i<=n;i++)
	{
		cin>>ta;
		a[ta]++;
		hs=max(hs,a[ta]);
	}
	cout<<hs<<"\n";	
}