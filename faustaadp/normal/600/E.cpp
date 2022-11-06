#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define fi first
#define se second
typedef long long ll;
using namespace std;
ll n,i,te,IN[101010],OUT[101010],isi[101010],jaw[101010],sz[101010],ma,cnt[101010],ta,tb,a[101010],x[101010	];
vector<ll> v[101010];
void dfs1(ll aa,ll bb)
{
	IN[aa]=++te;
	isi[te]=aa;
	ll ii;
	sz[aa]=1;
	for(ii=0;ii<v[aa].size();ii++)
		if(v[aa][ii]!=bb)
		{
			dfs1(v[aa][ii],aa);
			sz[aa]+=sz[v[aa][ii]];
		}
	OUT[aa]=te;
}
void dfs(ll aa,ll bb,ll cc)
{
	ll ii,BC=-1,jj;
	for(ii=0;ii<v[aa].size();ii++)
		if(v[aa][ii]!=bb)
		{
			if(BC==-1||sz[BC]<sz[v[aa][ii]])
				BC=v[aa][ii];
		}
	for(ii=0;ii<v[aa].size();ii++)
		if(v[aa][ii]!=bb&&v[aa][ii]!=BC)
			dfs(v[aa][ii],aa,0);
	if(BC!=-1)
		dfs(BC,aa,1);
	for(ii=0;ii<v[aa].size();ii++)
		if(v[aa][ii]!=bb&&v[aa][ii]!=BC)
			for(jj=IN[v[aa][ii]];jj<=OUT[v[aa][ii]];jj++)
			{
				x[cnt[a[isi[jj]]]]-=a[isi[jj]];
				cnt[a[isi[jj]]]++;
				x[cnt[a[isi[jj]]]]+=a[isi[jj]];
				ma=max(ma,cnt[a[isi[jj]]]);
			}
	x[cnt[a[aa]]]-=a[aa];
	cnt[a[aa]]++;
	x[cnt[a[aa]]]+=a[aa];
	ma=max(ma,cnt[a[aa]]);
	//cout<<aa<<" "<<ma<<"\n";
	jaw[aa]=x[ma];
	if(cc==0)
	{
		for(jj=IN[aa];jj<=OUT[aa];jj++)
		{
			x[cnt[a[isi[jj]]]]-=a[isi[jj]];
			cnt[a[isi[jj]]]--;
			x[cnt[a[isi[jj]]]]+=a[isi[jj]];
			while(x[ma]==0)ma--;
		}
	}
}
int main()
{
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
	cin>>n;
	for(i=1;i<=n;i++)cin>>a[i];
	for(i=1;i<n;i++)
	{
		cin>>ta>>tb;
		v[ta].pb(tb);
		v[tb].pb(ta);
	}
	dfs1(1,1);
	dfs(1,1,1);
	for(i=1;i<=n;i++)
		if(i<n)
			cout<<jaw[i]<<" ";
		else
			cout<<jaw[i]<<"\n";
}