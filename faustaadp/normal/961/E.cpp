#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define mp make_pair
#define fi first
#define se second
using namespace std;
ll n,i,a[202020],st[808080],has,j;
vector<ll> v[202020];
void upd(ll aa,ll bb,ll cc,ll dd,ll ee)
{
	if(aa==bb)
		st[ee]=dd;
	else
	{
		ll ce=(aa+bb)/2;
		if(cc<=ce)
			upd(aa,ce,cc,dd,ee*2);
		else
			upd(ce+1,bb,cc,dd,ee*2+1);
		st[ee]=st[ee*2]+st[ee*2+1];
	}
}
ll qn(ll aa,ll bb,ll cc,ll dd,ll ee)
{
//	cout<<aa<<" "<<bb<<" "<<cc<<" "<<dd<<" "<<ee<<"\n";
	if(bb<cc||dd<aa)
		return 0;
	else
	if(cc<=aa&&bb<=dd)
	{
		return st[ee];
	}
	else
	{
		ll ce=(aa+bb)/2;
		return qn(aa,ce,cc,dd,ee*2)+qn(ce+1,bb,cc,dd,ee*2+1);
	}
}
int main()
{
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n; 
	for(i=1;i<=n;i++)
	{
		cin>>a[i];
		a[i]=min(a[i],n);
		v[a[i]].pb(i);
	}
	for(i=1;i<=n;i++)
		upd(1,n,i,1,1);
	//cout<<st[1]<<"\n";
	for(i=1;i<n;i++)
	{
		if(a[i]<=i)
		{
			for(j=0;j<v[i].size();j++)
				upd(1,n,v[i][j],0,1);
			continue;
		}
		has+=qn(1,n,i+1,a[i],1);
		for(j=0;j<v[i].size();j++)
				upd(1,n,v[i][j],0,1);
		//cout<<has<<"\n";
		
	}	
	cout<<has<<"\n";
}