#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define mp make_pair
#define fi first
#define se second
using namespace std;
ll n,m,i,a[202020],ta,h1,h2,x[202020],y[202020],te;
pair<ll,ll> b[202020];
unordered_map<ll,ll> me;
vector<ll> v[202020];
ll cari(ll aa)
{
	if(!me.count(aa))return 0;
	if(v[me[aa]].empty())return 0;
	ll tom=v[me[aa]].back();
	v[me[aa]].pop_back();
	return tom;
}
int main()
{
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
	cin>>n>>m;
	for(i=1;i<=n;i++)cin>>a[i];
	for(i=1;i<=n;i++)
	{
		if(!me.count(a[i]))me[a[i]]=++te;
		v[me[a[i]]].pb(i);
	}
	for(i=1;i<=m;i++)
	{
		cin>>ta;
		b[i]=mp(ta,i);
	}
	sort(b+1,b+1+m);
	for(i=1;i<=m;i++)
	{
		ll hz=0;
		while(1)
		{
			ll tem=cari(b[i].fi);
			if(tem)
			{
				h1++;
				h2+=hz;
				x[b[i].se]=hz;
				y[tem]=b[i].se;
				break;
			}
			else
				if(b[i].fi==1)break;
			b[i].fi=((b[i].fi/2)+(b[i].fi%2));
			hz++;
		}
	}
	cout<<h1<<" "<<h2<<"\n";
	for(i=1;i<=m;i++)
		if(i<m)cout<<x[i]<<" ";
		else cout<<x[i]<<"\n";
	for(i=1;i<=n;i++)
		if(i<n)cout<<y[i]<<" ";
		else cout<<y[i]<<"\n";
}