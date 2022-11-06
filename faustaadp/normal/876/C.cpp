#include<bits/stdc++.h>
#define ll long long
#define pb push_back
using namespace std;
ll n,i,nn;
vector<ll> v;
ll rmt(ll aa)
{
	ll da=0;
	while(aa>0)
	{
		da=da+aa%10;
		aa=aa/10;
	}
	return da;
}
int main()
{
	cin>>n;
	for(i=n-1;i>=max(0LL,n-100LL);i--)
	{
		if(rmt(i)+i==n)
			v.pb(i);
	}
	cout<<v.size()<<"\n";	
	nn=v.size();
	for(i=nn-1;i>=0;i--)
		cout<<v[i]<<"\n";
}