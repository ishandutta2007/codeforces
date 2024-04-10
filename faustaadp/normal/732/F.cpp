#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define mp make_pair
#define fi first
#define se second
using namespace std;
ll n,m,i,ta,tb,te,mi[404040],wa[404040],b[404040],hz,has,cal,kel[404040],B[404040];
vector<ll> v[404040],w[404040],v2[404040],w2[404040];
vector<pair<ll,ll> > z2[404040];
vector<pair<ll,pair<ll,ll> > > BR;
pair<ll,ll> E[404040];
void dfs(ll aa,ll bb)
{
	b[aa]=1;
	te++;
	wa[aa]=te;
	mi[aa]=te;
	ll ii;
	for(ii=0;ii<v[aa].size();ii++)
	{
		if(v[aa][ii]==bb)continue;
		if(!b[v[aa][ii]])
		{
			dfs(v[aa][ii],aa);
			mi[aa]=min(mi[aa],mi[v[aa][ii]]);
			if(mi[v[aa][ii]]>wa[aa])
			{
				BR.pb(mp(w[aa][ii],mp(aa,v[aa][ii])));
				B[w[aa][ii]]=1;
				//cout<<aa<<" - "<<v[aa][ii]<<"\n";
			}
		}
		else
			mi[aa]=min(mi[aa],wa[v[aa][ii]]);
	}
}
void dfs2(ll aa)
{
//	cout<<aa<<" <> "<<te<<"\n";
	b[aa]=1;
	kel[aa]=te;
	hz++;
	ll ii;
	for(ii=0;ii<v[aa].size();ii++)
	{
		if(E[w[aa][ii]]==mp(0LL,0LL)&&!B[w[aa][ii]])
		{
		//	cout<<aa<<" "<<v[aa][ii]<<" A\n";
			E[w[aa][ii]]=mp(aa,v[aa][ii]);
			if(!b[v[aa][ii]])
				dfs2(v[aa][ii]);
		}
	}
}
void dfs3(ll aa,ll bb)
{
	ll ii;
	for(ii=0;ii<v2[aa].size();ii++)
		if(bb!=v2[aa][ii])
		{
			E[w2[aa][ii]]=mp(z2[aa][ii].fi,z2[aa][ii].se);
			dfs3(v2[aa][ii],aa);
		}

}
int main()
{
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
	cin>>n>>m;
	for(i=1;i<=m;i++)
	{
		cin>>ta>>tb;
		v[ta].pb(tb);
		v[tb].pb(ta);
		w[ta].pb(i);
		w[tb].pb(i);
	}
	dfs(1,1);
	memset(b,0,sizeof(b));
	te=0;
	for(i=1;i<=n;i++)
	{
		hz=0;
		if(!b[i])
		{
			te++;
			dfs2(i);
			if(hz>has)
			{
				has=hz;
				cal=te;
			}
		}
	}
	for(i=0;i<BR.size();i++)
	{
		ta=kel[BR[i].se.fi];
		tb=kel[BR[i].se.se];
		v2[ta].pb(tb);
		v2[tb].pb(ta);
		w2[ta].pb(BR[i].fi);
		w2[tb].pb(BR[i].fi);
		z2[ta].pb(mp(BR[i].se.se,BR[i].se.fi));
		z2[tb].pb(mp(BR[i].se.fi,BR[i].se.se));
	}
	dfs3(cal,cal);
	cout<<has<<"\n";
	for(i=1;i<=m;i++)
		cout<<E[i].fi<<" "<<E[i].se<<"\n";
}