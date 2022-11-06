#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,x,i,ta,hz;
int main()
{
	cin>>n>>x;
	for(i=1;i<=n;i++)
	{
		cin>>ta;
		hz+=ta;
	}
	if(hz+n-1==x)
		cout<<"YES\n";
	else
		cout<<"NO\n";
}