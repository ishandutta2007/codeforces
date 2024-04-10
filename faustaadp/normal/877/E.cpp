#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define mp make_pair
#define fi first
#define se second
using namespace std;
ll n,i,ta,q,IN[202020],OUT[202020],ST[808080],LZ[808080],te;
string s;
vector<ll> v[202020];
void dfs(ll aa)
{
	IN[aa]=++te;
	ll ii;
	for(ii=0;ii<v[aa].size();ii++)
		dfs(v[aa][ii]);
	OUT[aa]=te;
}
void upd(ll aa,ll bb,ll cc,ll dd,ll ee)
{
	if(LZ[ee])
	{
		ST[ee]=(bb-aa+1)-ST[ee];
		if(aa<bb)
		{
			LZ[ee*2]=1-LZ[ee*2];
			LZ[ee*2+1]=1-LZ[ee*2+1];
		}
		LZ[ee]=0;
	}
	if(bb<cc||dd<aa)return ;
	else
	if(cc<=aa&&bb<=dd)
	{
		ST[ee]=(bb-aa+1)-ST[ee];
		if(aa<bb)
		{
			LZ[ee*2]=1-LZ[ee*2];
			LZ[ee*2+1]=1-LZ[ee*2+1];
		}
	}
	else
	{
		ll ce=(aa+bb)/2;
		upd(aa,ce,cc,dd,ee*2);
		upd(ce+1,bb,cc,dd,ee*2+1);
		ST[ee]=ST[ee*2]+ST[ee*2+1];
	}
}
ll que(ll aa,ll bb,ll cc,ll dd,ll ee)
{
	if(LZ[ee])
	{
		ST[ee]=(bb-aa+1)-ST[ee];
		if(aa<bb)
		{
			LZ[ee*2]=1-LZ[ee*2];
			LZ[ee*2+1]=1-LZ[ee*2+1];
		}
		LZ[ee]=0;
	}
	if(bb<cc||dd<aa)return 0;
	else
	if(cc<=aa&&bb<=dd)
		return ST[ee];
	else
	{
		ll ce=(aa+bb)/2;
		return que(aa,ce,cc,dd,ee*2)+que(ce+1,bb,cc,dd,ee*2+1);
	}
}
int main()
{
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
	cin>>n;
	for(i=2;i<=n;i++)
	{
		cin>>ta;
		v[ta].pb(i);
	}
	dfs(1);
	for(i=1;i<=n;i++)
	{
		cin>>ta;
		//cout<<i<<" "<<IN[i]<<"\n";
		if(ta==1)upd(1,n,IN[i],IN[i],1);
	}
	cin>>q;
	while(q--)
	{
		cin>>s;
		if(s=="get")
		{
			cin>>ta;
			cout<<que(1,n,IN[ta],OUT[ta],1)<<"\n";
		}
		else
		{
			cin>>ta;
			upd(1,n,IN[ta],OUT[ta],1);
		}
	}
}