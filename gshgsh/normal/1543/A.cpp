#include<iostream>
#include<cstdio>
using namespace std;
#define ll long long
#define For(i,l,r) for(int i=l;i<=r;i++)
int main()
{
	int T;cin>>T;
	while(T--)
	{
		ll a,b;cin>>a>>b;ll x=abs(a-b);
		if(!x)cout<<"0 0\n";else cout<<x<<' '<<min(min(a,b)%x,x-min(a,b)%x)<<endl;
	}
	return 0;
}