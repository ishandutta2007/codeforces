#include<bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define fi first
#define se second
typedef long long ll;
using namespace std;
ll n, q, ada[1010101], ta, tb, tc, jaw[202020], i, a[202020], j;
vector<ll> v[1010101];
vector<pair<pair<ll,ll>, ll> > isi[1010101];
set<ll> st;
int main()
{
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n>>q;
	for(i=1;i<=n;i++)
	{
		cin>>a[i];
		ada[a[i]]=1;
		v[a[i]].pb(i);
		st.insert(i);
	}
	for(i=1;i<=q;i++)
	{
		cin>>ta>>tb>>tc;
		if(ada[tc])
		{
			isi[tc].pb(mp(mp(ta,tb),i));
		}
		else
			jaw[i]=ta;
	}
	st.insert(n+1);
	for(i=1;i<=1000000;i++)
	{
		for(j=0;j<v[i].size();j++)st.erase(v[i][j]);
		for(j=0;j<isi[i].size();j++)
		{
			auto it=st.lower_bound(isi[i][j].fi.fi);
			ll caljaw=*it;
			if(caljaw>isi[i][j].fi.se)
				jaw[isi[i][j].se]=-1;
			else
				jaw[isi[i][j].se]=caljaw;
		}
		for(j=0;j<v[i].size();j++)st.insert(v[i][j]);
	}
	for(i=1;i<=q;i++)
		cout<<jaw[i]<<"\n";
}