#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define mp make_pair
#define fi first
#define se second
using namespace std;
ll n,q,i,a[404040],ST[1601601],LZ[1601601],ta,tb,te,IN[404040],OUT[404040];
vector<ll> v[404040];
void dfs(ll aa,ll bb)
{
	IN[aa]=++te;
	ll ii;
	for(ii=0;ii<v[aa].size();ii++)
		if(v[aa][ii]!=bb)
			dfs(v[aa][ii],aa);
	OUT[aa]=te;
}
void upd(ll aa,ll bb,ll cc,ll dd,ll ee,ll ff)
{
	if(LZ[ee])
	{
		ST[ee]=LZ[ee];
		if(aa<bb)
		{
			LZ[ee*2]=ST[ee];
			LZ[ee*2+1]=ST[ee];
		}
		LZ[ee]=0;
	}
	if(bb<cc||dd<aa)return ;
	else
	if(cc<=aa&bb<=dd)
	{
		ST[ee]=ff;
		if(aa<bb)
		{
			LZ[ee*2]=ST[ee];
			LZ[ee*2+1]=ST[ee];
		}
	}
	else
	{
		ll ce=(aa+bb)/2;
		upd(aa,ce,cc,dd,ee*2,ff);
		upd(ce+1,bb,cc,dd,ee*2+1,ff);
		ST[ee]=(ST[ee*2]|ST[ee*2+1]);
	}
}
ll que(ll aa,ll bb,ll cc,ll dd,ll ee)
{
	if(LZ[ee])
	{
		ST[ee]=LZ[ee];
		if(aa<bb)
		{
			LZ[ee*2]=ST[ee];
			LZ[ee*2+1]=ST[ee];
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
		return (que(aa,ce,cc,dd,ee*2)|que(ce+1,bb,cc,dd,ee*2+1));
	}
}
int main()
{
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
	cin>>n>>q;
	for(i=1;i<=n;i++)
		cin>>a[i];
	for(i=1;i<n;i++)
	{
		cin>>ta>>tb;
		v[ta].pb(tb);
		v[tb].pb(ta);
	}
	dfs(1,1);
	for(i=1;i<=n;i++)
		upd(1,n,IN[i],IN[i],1,(1LL<<a[i]));
	while(q--)
	{
		cin>>ta;
		if(ta==1)
		{
			cin>>ta>>tb;
			upd(1,n,IN[ta],OUT[ta],1,(1LL<<tb));
		}
		else
		{
			cin>>ta;
			cout<<__builtin_popcountll(que(1,n,IN[ta],OUT[ta],1))<<"\n";
		}
	}
}