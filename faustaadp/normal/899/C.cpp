#include<bits/stdc++.h>
#define ll long long
#define pb push_back
using namespace std;
ll n,i,a[10101010],l,r,hz,hh;
vector<ll> v;
int main()
{
	cin>>n;
	for(i=1;i<=n;i++)
		a[i]=i;
	hz=(n*(n+1)/4);
	l=1;
	r=0;
	while(1)
	{
		while(hh<hz)
		{
			r++;
			hh+=a[r];
		}
		while(hh>hz)
		{
			hh-=a[l];
			l++;
		}
		if(hh==hz)
		{
			cout<<abs(n*(n+1)/2-hh-hh)<<"\n";
			cout<<r-l+1;
			for(i=l;i<=r;i++)
				cout<<" "<<i;
			cout<<"\n";
			return 0;
		}
	}
	//cout<<hs<<" "<<(n*(n+1)/2)<<"\n";
}