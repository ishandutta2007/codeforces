#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define fi first
#define se second
typedef long long ll;
using namespace std;
ll n,q,IN[505050],OUT[505050],sz[505050],te,ta,tb,i,jaw[505050],dep[505050],isi[505050];
vector<pair<ll,ll> > Q[505050];
char a[505050];
int cnt[500005][27];
vector<ll> v[505050];
void dfs1(ll aa,ll bb)
{
	IN[aa]=++te;
	isi[te]=aa;
	dep[aa]=bb;
	//cout<<aa<<" "<<dep[aa]<<"_\n";
	ll ii;
	sz[aa]=1;
	for(ii=0;ii<v[aa].size();ii++)dfs1(v[aa][ii],bb+1);
	for(ii=0;ii<v[aa].size();ii++)sz[aa]+=sz[v[aa][ii]];
	OUT[aa]=te;
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
				cnt[dep[isi[jj]]][a[isi[jj]]-'a']++;
	cnt[dep[aa]][a[aa]-'a']++;
	for(ii=0;ii<Q[aa].size();ii++)
	{
		ll gan=0;
		for(jj=0;jj<26;jj++)
		{
		//	if(Q[aa][ii].fi==2&&cnt[Q[aa][ii].se][jj]>1)cout<<jj<<"\n";
			gan+=(cnt[Q[aa][ii].se][jj]%2);
		}
		//cout<<Q[aa][ii].fi<<" "<<gan<<"\n";
		if(gan<=1)jaw[Q[aa][ii].fi]=1;
	}
	if(bb==0)
	{
		for(jj=IN[aa];jj<=OUT[aa];jj++)
			cnt[dep[isi[jj]]][a[isi[jj]]-'a']--;
	}
}
int main()
{
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
	cin>>n>>q;
	for(i=2;i<=n;i++)
	{
		cin>>ta;
		v[ta].pb(i);
	}
	for(i=1;i<=n;i++)cin>>a[i];
	dfs1(1,1);
	for(i=1;i<=q;i++)
	{
		cin>>ta>>tb;
		Q[ta].pb(mp(i,tb));
	}
	dfs(1,1);
	for(i=1;i<=q;i++)
		if(jaw[i])cout<<"Yes\n";
		else cout<<"No\n";
}