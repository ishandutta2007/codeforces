#include<cstdio>
#include<iostream>
using namespace std;
typedef long long ll;

int main(void)
{
	ll n,p,w,d;
	cin>>n>>p>>w>>d;
	
	for(ll y=0; y<w; ++y)
	{
		ll t = p - d*y;
		if(t<0) break;
		if(t%w) continue;
		
		ll x = t/w, z=n-x-y;
		if(x<=n && y<=n && z>=0 && z<=n)
		{
			cout<<x<<' '<<y<<' '<<z;
			return 0;
		}
	}
	printf("-1");
	return 0;
}