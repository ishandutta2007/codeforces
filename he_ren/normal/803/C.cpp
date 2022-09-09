#include<cstdio>
#include<cmath>
#include<iostream>
typedef long long ll;
using namespace std;

int main(void)
{
	ll n,k;
	cin>>n>>k;
	ll m=k*(k+1)/2;
	if(k>=150000 || m>n)
	{
		printf("-1");
		return 0;
	}
	
	ll sn=sqrt(n), ans=0;
	for(ll i=1; i<=sn; ++i)
		if(n%i==0)
		{
			if(n/i>=m)
				ans = max(ans,i);
			if(i>=m)
				ans = max(ans,n/i);
		}
	
	n/=ans;
	for(ll i=1; i<k; ++i)
	{
		cout<<ans*i<<" ";
		n-=i;
	}
	cout<<ans*n;
	return 0;
}