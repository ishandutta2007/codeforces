#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define fi first
#define se second
typedef long long ll;
using namespace std;
ll n,i,ta,a[202020],D[202020],IN[101010],OUT[101010],sz[101010],dep[101010],te,tb,q;
ll jaw[101010],isi[101010],Y[202020];
vector<ll> v[101010],Z[201010],X[201010];
vector<pair<ll,ll> > Q[101010];
string s;
unordered_map<string,ll> me;
//unordered_map<int,unordered_map<int,int> > cnt;
ll hey(string aa)
{
	if(!me[aa])
		me[aa]=++te;
	return me[aa];
}
void woi(ll aa,ll bb)
{
	Z[aa].pb(bb);
	X[aa].pb(0);
}
void dfs1(ll aa,ll bb)
{
	IN[aa]=++te;
	isi[te]=aa;
	sz[aa]=1;
	dep[aa]=bb;
	woi(dep[aa],a[aa]);
	ll ii;
	for(ii=0;ii<v[aa].size();ii++)
	{
		dfs1(v[aa][ii],bb+1);
		sz[aa]+=v[aa][ii];
	}
	OUT[aa]=te;
}
ll cari(ll aa,ll bb)
{
	//cout<<aa<<" "<<bb<<" "<<lower_bound(Z[aa].begin(),Z[aa].end(),bb)-Z[aa].begin()<<" "<<Z[aa].size()<<"\n";
	return lower_bound(Z[aa].begin(),Z[aa].end(),bb)-Z[aa].begin();
}
void dfs(ll aa,ll bb)
{
	ll ii,jj,BC=-1;
	for(ii=0;ii<v[aa].size();ii++)
		if(BC==-1||sz[BC]<sz[v[aa][ii]])
			BC=v[aa][ii];
	for(ii=0;ii<v[aa].size();ii++)
		if(v[aa][ii]!=BC)
			dfs(v[aa][ii],0);
	if(BC!=-1)
		dfs(BC,1);
	for(ii=0;ii<v[aa].size();ii++)
		if(v[aa][ii]!=BC)
			for(jj=IN[v[aa][ii]];jj<=OUT[v[aa][ii]];jj++)
			{
			//	cout<<Y[isi[jj]]<<" "<<cari(dep[isi[jj]],a[isi[jj]])<<"\n";
				X[dep[isi[jj]]][Y[isi[jj]]]++;
				if(X[dep[isi[jj]]][Y[isi[jj]]]==1)D[dep[isi[jj]]]++;
			}
	//cout<<Y[aa]<<" "<<cari(dep[aa],a[aa])<<"\n";
	X[dep[aa]][Y[aa]]++;
	if(X[dep[aa]][Y[aa]]==1)D[dep[aa]]++;
	for(ii=0;ii<Q[aa].size();ii++)
		jaw[Q[aa][ii].se]=D[Q[aa][ii].fi];
	if(bb==0)
	{
		for(jj=IN[aa];jj<=OUT[aa];jj++)
		{
			//cout<<Y[isi[jj]]<<" "<<cari(dep[isi[jj]],a[isi[jj]])<<"\n";
			X[dep[isi[jj]]][Y[isi[jj]]]--;
			if(X[dep[isi[jj]]][Y[isi[jj]]]==0)D[dep[isi[jj]]]--;
		}
	}
}
int main()
{
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
	cin>>n;
	for(i=1;i<=n;i++)
	{
		cin>>s>>ta;
		a[i]=hey(s);
		v[ta].pb(i);
	}
	te=0;
	dfs1(0,1);
	for(i=1;i<=n;i++)
	{
		sort(Z[i].begin(),Z[i].end());
		//for(ll j=0;j<Z[i].size();j++)
		//	cout<<i<<" "<<j<<"->"<<Z[i][j]<<"\n";
	}
	for(i=1;i<=n;i++)Y[i]=cari(dep[i],a[i]);
	//for(i=1;i<=n;i++)cout<<i<<" "<<Y[i]<<" "<<Z[dep[i]].size()<<"\n";
	cin>>q;
	for(i=1;i<=q;i++)
	{
		cin>>ta>>tb;
		tb+=dep[ta];
		Q[ta].pb(mp(tb,i));
	}
	dfs(0,1);
	for(i=1;i<=q;i++)
		cout<<jaw[i]<<"\n";
}