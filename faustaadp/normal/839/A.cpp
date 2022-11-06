#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,k,si,i,hz,ta;
int main()
{
	cin>>n>>k;
	for(i=1;i<=n;i++)
	{
		cin>>ta;
		ta=ta+si;
		si=0;
		if(ta>8)
		{
			si=ta-8;
			ta=8;
		}
		hz=hz+ta;
		if(hz>=k)
		{
			cout<<i<<"\n";
			return 0;
		}
	}
	cout<<-1<<"\n";
}