#include<cstdio>
#include<iostream>
typedef long long ll;
using namespace std;

int main(void)
{
	ll d,k,a,b,t;
	cin>>d>>k>>a>>b>>t;
	
	if(d<=k)
	{
		cout<<d*a;
		return 0;
	}
	
	d-=k;
	ll ans=k*a;
	if(k*a+t >= k*b)
	{
		cout<<ans+d*b;
		return 0;
	}
	
	ans+=(d/k)*(k*a+t);
	d%=k;
	
	if(d*a+t < d*b) ans+=d*a+t;
	else ans+=d*b;
	
	cout<<ans;
	return 0;
}