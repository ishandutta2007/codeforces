#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define mp make_pair
#define fi first
#define se second
using namespace std;
ll n,i,ta,b[101010],bl[101010];
vector<ll> v[101010],ve[101010];
ll rmt(ll aa)
{
	//cout<<aa<<"aa\n";
	b[aa]=1;
	ll ii;
	for(ii=0;ii<v[aa].size();ii++)
	{
		if(b[v[aa][ii]]==0)
		{
			bl[aa]=1;
			ve[aa].pb(v[aa][ii]);
			rmt(v[aa][ii]);
		}
	}
}
ll rct(ll aa)
{	
	ll ii,hh=0;
	for(ii=0;ii<ve[aa].size();ii++)
	{
		rct(ve[aa][ii]);
		if(bl[ve[aa][ii]]==0)
			hh++;
	}
	if(bl[aa]&&hh<3)
	{
		cout<<"No\n";
		exit(0);
	}
}
int main()
{
	cin>>n;
	for(i=2;i<=n;i++)
	{
		cin>>ta;
		v[ta].pb(i);
		v[i].pb(ta);
	}
	rmt(1);
	rct(1);
	cout<<"Yes\n";
}