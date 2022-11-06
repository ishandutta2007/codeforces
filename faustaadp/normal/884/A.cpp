#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,t,i,ta;
int main()
{
	cin>>n>>t;
	for(i=1;i<=n;i++)
	{
		cin>>ta;
		ta=86400-ta;
		t-=ta;
		if(t<=0)
		{
			cout<<i<<"\n";
			return 0;
		}
	}
}