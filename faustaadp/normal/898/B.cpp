#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,a,b,i;
int main()
{
	cin>>n>>a>>b;
	for(i=n;i>=0;i-=b)
	{
		if(i%a==0)
		{
			cout<<"YES\n";
			cout<<i/a<<" "<<(n-i)/b<<"\n";
			return 0;
		}
	}
	cout<<"NO\n";
}