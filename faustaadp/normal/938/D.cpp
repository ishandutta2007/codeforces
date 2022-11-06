#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define mp make_pair
#define fi first
#define se second
using namespace std;
ll n,m,i,ta,tb,tc,a[202020],b[202020],d[202020];
vector<pair<ll,ll> > v[202020];
priority_queue<pair<ll,ll> > q;
pair<ll,ll> u;
int main()
{
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(i=1;i<=m;i++)
	{
		cin>>ta>>tb>>tc;
		v[ta].pb(mp(tb,tc));
		v[tb].pb(mp(ta,tc));
	}
	for(i=1;i<=n;i++)
	{
		cin>>a[i];
		q.push(mp(-a[i],i));
	}
	while(!q.empty())
	{
		u=q.top();
	//	cout<<u.fi<<" "<<u.se<<"\n";
		q.pop();
		if(b[u.se]==0)
		{
			b[u.se]=1;
			d[u.se]=-u.fi;
			for(i=0;i<v[u.se].size();i++)
			{
				if(b[v[u.se][i].fi]==0)
				{
					q.push(mp(max(-a[v[u.se][i].fi],u.fi-2*v[u.se][i].se),v[u.se][i].fi));
				}
			}
		}
	}
	for(i=1;i<n;i++)
		cout<<d[i]<<" ";
	cout<<d[n]<<"\n";
}