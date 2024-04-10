#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define mp make_pair
#define fi first
#define se second
using namespace std;
ll n,k,hs,i,ta;
int main()
{
	cin>>n>>k;
	hs=10e17;
	for(i=1;i<=n;i++)
	{
		cin>>ta;
		if(k%ta==0)
			hs=min(hs,k/ta);
	}
	if(hs==10e17)
		hs=-1;
	cout<<hs<<"\n";
}