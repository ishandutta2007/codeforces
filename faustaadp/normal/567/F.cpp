#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
#define pb push_back
#define mp make_pair
#define fi first
#define se second
ll n,k,d[1010][1010],has,ta,tb,i;
string s;
vector<ll> v[1010];
vector<ll> x[1010];
vector<ll> w[1010];
ll dx[3]={-2,-1,0};
ll dy[3]={0,1,2};
ll val(ll aa,ll bb)
{
	if(!(v[aa].empty()&&v[bb].empty()))return 0;
	ll ii;
	for(ii=0;ii<w[aa].size();ii++)
		if(w[aa][ii]!=bb)
			return 0;
	for(ii=0;ii<w[bb].size();ii++)
		if(w[bb][ii]!=aa)
			return 0;
	return 1;
}
ll cek(ll aa,ll bb,ll cc,ll dd)
{
	ll ii;
	for(ii=0;ii<x[aa].size();ii++)
		if(x[aa][ii]!=bb)return 0;
	for(ii=0;ii<x[bb].size();ii++)
		if(x[bb][ii]!=aa)return 0;

	for(ii=0;ii<w[aa].size();ii++)
		if(!(min(cc,aa)<=w[aa][ii]&&w[aa][ii]<=max(bb,dd)))
			return 0;
	for(ii=0;ii<w[bb].size();ii++)
		if(!(min(cc,aa)<=w[bb][ii]&&w[bb][ii]<=max(bb,dd)))
			return 0;


	for(ii=0;ii<v[aa].size();ii++)
		if(!(cc<=v[aa][ii]&&v[aa][ii]<=dd))
			return 0;
	for(ii=0;ii<v[bb].size();ii++)
		if(!(cc<=v[bb][ii]&&v[bb][ii]<=dd))
			return 0;
	return 1;
}
ll depe(ll aa,ll bb)
{
	if(aa==1&&bb==n*2)
		return 1;
	if(d[aa][bb]==-1)
	{
		d[aa][bb]=0;
		ll ii,jj;
		for(ii=0;ii<3;ii++)
		{
			ll nx=aa+dx[ii];
			ll ny=bb+dy[ii];
			if(nx<1)continue;
			if(ny>(2*n))continue;
			// cout<<nx<<" "<<ny<<"___\n";
			if(ii==0&&cek(nx,nx+1,aa,bb)==0)continue;
			if(ii==1&&cek(nx,ny,aa,bb)==0)continue;
			if(ii==2&&cek(ny-1,ny,aa,bb)==0)continue;
			d[aa][bb]+=depe(nx,ny);
		}
	}
	// cout<<aa<<" "<<bb<<" "<<d[aa][bb]<<"\n";
	return d[aa][bb];
}
int main()
{
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n>>k;
	while(k--)
	{
		cin>>ta>>s>>tb;
		if(s=="<")	v[ta].pb(tb);
		else if(s==">")	v[tb].pb(ta);
		else
		{
			if(ta==tb)continue;
			else if(s=="<=") w[ta].pb(tb);
			else if(s==">=") w[tb].pb(ta);
			else
			{
				x[ta].pb(tb);
				x[tb].pb(ta);
			}
		}
	}
	memset(d,-1,sizeof(d));
	for(i=1;i<n*2;i++)
		if(val(i,i+1))
			has+=depe(i,i+1);
	cout<<has<<"\n";
}