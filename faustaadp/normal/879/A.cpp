#include<bits/stdc++.h>
#define ll long long
#define pb push_back
using namespace std;
ll n,i,ta,tb,hz,j,hc;
int main()
{
	cin>>n;
	for(i=1;i<=n;i++)
	{
		cin>>ta>>tb;
		ll l=0;
	  	ll r=100000000000000;
		while(l<=r)
		{
			ll c=(l+r)/2;
			if(hz<tb*c+ta)
			{
				hc=c;
				r=c-1;
			}
			else
				l=c+1;
		}
		hz=tb*hc+ta;
	}
	cout<<hz<<"\n";
}