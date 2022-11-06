#include <bits/stdc++.h>
#define fi first
#define se second
#define mp make_pair
#define pb push_back
typedef long long ll;
using namespace std;
ll n,i,a[1555],p[1555],te,ma,idx,j;
vector<pair<ll,pair<ll,ll> > > z;
vector<pair<int,int> > A[2552550];
int main()
{
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
	cin>>n;
	for(i=1;i<=n;i++)cin>>a[i];
	for(i=1;i<=n;i++)p[i]=p[i-1]+a[i];
	for(i=1;i<=n;i++)
		for(j=i;j<=n;j++)
			z.pb(mp(p[j]-p[i-1],mp(i,j)));
	sort(z.begin(),z.end());
	for(i=0;i<z.size();i++)
	{
		if(i==0||z[i].fi!=z[i-1].fi)
			te++;
		A[te].pb(mp(z[i].se.se,z[i].se.fi));
	}
	ma=0;
	for(i=1;i<=te;i++)
	{
		sort(A[i].begin(),A[i].end());
		ll hz=0,las=0;
		for(j=0;j<A[i].size();j++)
		{
			if(las>=A[i][j].se)continue;
			hz++;
			las=A[i][j].fi;
		}
		if(hz>ma)
		{
			ma=hz;
			idx=i;
		}
	}
	cout<<ma<<"\n";
	for(i=idx;i<=idx;i++)
	{
		sort(A[i].begin(),A[i].end());
		ll las=0;
		for(j=0;j<A[i].size();j++)
		{
			if(las>=A[i][j].se)continue;
			cout<<A[i][j].se<<" "<<A[i][j].fi<<"\n";
			las=A[i][j].fi;
		}
	}
}