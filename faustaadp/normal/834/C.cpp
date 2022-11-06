#include<bits/stdc++.h>
#define ll long long
#define fast ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
ll n,i,ta,tb,tv;
bool rmt(ll aa)
{
	ll l=0,r=1000000,c,cu;
	while(l<=r)
	{
		c=(l+r)/2;
		cu=c*c*c;
		if(cu==aa)
		{
			tv=c;		
			return 1;
		}
		else
		if(cu>aa)
			r=c-1;
		else
			l=c+1;
	}
	return 0;
}
int main()
{
	fast
	cin>>n;
	for(i=1;i<=n;i++)
	{
		cin>>ta>>tb;
		if(rmt(ta*tb))
		{
			if(ta%tv==0&&tb%tv==0)
				cout<<"Yes\n";
			else
				cout<<"No\n";
		}
		else	cout<<"No\n";
	}
}