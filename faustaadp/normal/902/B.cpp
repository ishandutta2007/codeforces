#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define mp make_pair
#define fi first
#define se second
using namespace std;
ll n,i,ta,a[101010],hs;
vector<ll> v[101010];
bool b[101010];
ll rmt(ll aa)
{
	b[aa]=1;
	ll ii;
	for(ii=0;ii<v[aa].size();ii++)
	{
		if(b[v[aa][ii]]==0)
		{
			if(a[aa]!=a[v[aa][ii]])
				hs++;
			rmt(v[aa][ii]);
		}
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
	for(i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	hs=1;
	rmt(1);
	cout<<hs<<"\n";
}