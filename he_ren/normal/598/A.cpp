#include<cstdio>
#include<iostream>
typedef long long ll;
using namespace std;

int main(void)
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		ll n;
		cin>>n;
		ll ans = n * (n+1) / 2;
		ll x=1;
		while(x<=n) ans-=x*2, x*=2;
		cout<<ans<<endl;
	}
	return 0;
}