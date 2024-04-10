#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll i,hv;
unsigned ll n,ta,h1,h2;
unordered_map<ll,ll> d;
int main()
{
	cin>>n;
	hv=-n+1;
	for(i=1;i<=n;i++)
	{
		cin>>ta;
		if(hv<0)
			h1+=ta*(-hv);
		else
			h2+=ta*hv;
		hv+=2;
		d[ta]++;
		h2+=d[ta+1];
		h1+=d[ta-1];
	}
	if(h2>=h1)
		cout<<h2-h1<<"\n";
	else
		cout<<"-"<<h1-h2<<"\n";
}