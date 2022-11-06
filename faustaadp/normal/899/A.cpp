#include<bits/stdc++.h>
#define ll long long
#define pb push_back
using namespace std;
ll n,i,ta,sat,du,hs;
int main()
{
	cin>>n;
	for(i=1;i<=n;i++)
	{
		cin>>ta;
		if(ta==1)
			sat++;
		else
			du++;
	}
	hs=min(du,sat);
	sat=sat-hs;
	hs+=sat/3;
	cout<<hs<<"\n";
}