#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define mp make_pair
#define fi first
#define se second
using namespace std;
ll n,m,p,i,j,ta,has,k;
vector<pair<ll,ll> > v[93099];
vector<pair<ll,pair<ll,ll> > >d[93909];
ll jar(ll aa,ll bb,ll cc,ll dd)
{
	return (abs(aa-cc)+abs(bb-dd));
}
int main()
{
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
	cin>>n>>m>>p;
	for(i=1;i<=n;i++)
		for(j=1;j<=m;j++)
		{
			cin>>ta;
			v[ta].pb(mp(i,j));
		}
	has=1e18;
	d[0].pb(mp(0,mp(1,1)));
	for(i=1;i<=p;i++)
	{
		sort(d[i-1].begin(),d[i-1].end());
		ll sz=d[i-1].size();
		for(j=0;j<v[i].size();j++)
		{
			ll hz=1e18;
			for(k=0;k<min(sz,n+m);k++)
			{
				hz=min(hz,jar(v[i][j].fi,v[i][j].se,d[i-1][k].se.fi,d[i-1][k].se.se)+d[i-1][k].fi);
			}
			d[i].pb(mp(hz,v[i][j]));
			if(i==p)has=min(has,hz);
		}
	}
	cout<<has<<"\n";
}