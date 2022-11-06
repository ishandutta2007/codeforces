#include<bits/stdc++.h>
typedef long long ll;
#define pb push_back
#define mp make_pair
#define fi first
#define se second
using namespace std;
ll n,i,a[303030],ST[1201201],ada,c[303030],j;
vector<ll> v[1201201];
set<ll> st;
void upd(ll aa,ll bb,ll cc,ll dd,ll ee)
{
	if(aa==bb)
		ST[ee]=dd;
	else
	{
		ll ce=(aa+bb)/2;
		if(cc<=ce)
			upd(aa,ce,cc,dd,ee*2);
		else
			upd(ce+1,bb,cc,dd,ee*2+1);
		ST[ee]=max(ST[ee*2],ST[ee*2+1]);
	}
}
ll cari(ll aa,ll bb,ll cc,ll ee)
{
	if(aa==bb)
		return aa;
	else
	{
		ll ce=(aa+bb)/2;
		if(ST[ee*2+1]>cc)
			return cari(ce+1,bb,cc,ee*2+1);
		else
			return cari(aa,ce,cc,ee*2);
	}
}
int main()
{
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n;
	for(i=1;i<=n;i++)
	{
		cin>>a[i];
		a[i+n]=a[i];
		a[i+n+n]=a[i];
	}
	for(i=1;i<=n*3;i++)
	{
		upd(1,n*3,i,a[i],1);
		ll bts=a[i]*2;
		if(ST[1]>bts)
		{
			ada=1;
			ll tum=cari(1,n*3,bts,1);
			// cout<<i<<" "<<tum<<"_\n";
			v[tum].pb(i);
			st.insert(i);
		}
	}
	for(i=1;i<=n;i++)
		c[i]=-1;
	if(ada)
	{
		for(i=1;i<=n;i++)
		{
			auto it=st.begin();
			ll tem=*it;
			c[i]=tem-i;
			for(j=0;j<v[i].size();j++)
				st.erase(v[i][j]);
		}
	}
	for(i=1;i<=n;i++)
		if(i<n)
			cout<<c[i]<<" ";
		else
			cout<<c[i]<<"\n";
}