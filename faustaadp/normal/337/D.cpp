#include<bits/stdc++.h>
typedef long long ll;
#define pb push_back
using namespace std;
ll n,m,d,ta,tb,IN[101010],OUT[101010],LZ[404040],ST[404040],has,i,ptg[101010],te;
vector<ll> v[101010];
void turun(ll aa,ll bb,ll ee)
{
	if(LZ[ee])
	{
		ST[ee]+=LZ[ee];
		if(aa<bb)
		{
			LZ[ee*2]+=LZ[ee];
			LZ[ee*2+1]+=LZ[ee];
		}
		LZ[ee]=0;
	}
}
void upd(ll aa,ll bb,ll cc,ll dd,ll ee,ll ff)
{
	turun(aa,bb,ee);
	if(bb<cc||dd<aa)
		return ;
	else
	if(cc<=aa&&bb<=dd)
	{
		LZ[ee]+=ff;
		turun(aa,bb,ee);
	}
	else
	{
		ll ce=(aa+bb)/2;
		upd(aa,ce,cc,dd,ee*2,ff);
		upd(ce+1,bb,cc,dd,ee*2+1,ff);
		ST[ee]=max(ST[ee*2],ST[ee*2+1]);
	}
}
void dfs0(ll aa,ll bb,ll cc)
{
	IN[aa]=++te;
	if(ptg[aa])
		upd(1,n,IN[aa],IN[aa],1,cc);
	else
		upd(1,n,IN[aa],IN[aa],1,-1e9);
	ll ii;
	for(ii=0;ii<v[aa].size();ii++)
		if(v[aa][ii]!=bb)
			dfs0(v[aa][ii],aa,cc+1);
	OUT[aa]=te;
}
void dfs(ll aa,ll bb)
{
	ll ii;
	// cout<<aa<<" "<<ST[1]<<"_\n";
	if(ST[1]<=d)has++;
	for(ii=0;ii<v[aa].size();ii++)
	{
		if(v[aa][ii]!=bb)
		{
			ll nx=v[aa][ii];
			upd(1,n,IN[nx],OUT[nx],1,-1);
			upd(1,n,1,IN[nx]-1,1,1);
			upd(1,n,OUT[nx]+1,n,1,1);
			dfs(nx,aa);
			upd(1,n,IN[nx],OUT[nx],1,1);
			upd(1,n,1,IN[nx]-1,1,-1);
			upd(1,n,OUT[nx]+1,n,1,-1);
		}
	}
}
int main()
{
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n>>m>>d;
	for(i=1;i<=m;i++)
	{
		cin>>ta;
		ptg[ta]=1;
	}
	for(i=1;i<n;i++)
	{
		cin>>ta>>tb;
		v[ta].pb(tb);
		v[tb].pb(ta);
	}
	dfs0(1,1,0);
	dfs(1,1);
	cout<<has<<"\n";
}