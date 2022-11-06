#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define mp make_pair
#define fi first
#define se second
using namespace std;
ll i,j,pr[202020],PS,n,ta,tb,has,ma,nod,a[202020];
vector<ll> v[202020],P,isi[202020],fak[202020];
ll b[202020],B[202020];
void dfs1(ll aa,ll bb,ll cc)
{
	if(cc>ma)
	{
		nod=aa;
		ma=cc;
	}
	b[aa]=1;
	ll ii;
	for(ii=0;ii<v[aa].size();ii++)
		if(v[aa][ii]!=bb&&B[v[aa][ii]]==1)
			dfs1(v[aa][ii],aa,cc+1);
}
void dfs2(ll aa,ll bb,ll cc)
{
	has=max(has,cc);
	ll ii;
	for(ii=0;ii<v[aa].size();ii++)
		if(v[aa][ii]!=bb&&B[v[aa][ii]]==1)
			dfs2(v[aa][ii],aa,cc+1);
}
int main()
{
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	for(i=2;i<=200000;i++)
		if(!pr[i])
		{
			P.pb(i);
			for(j=i;j<=200000;j+=i)
			{
				pr[j]=1;
				fak[j].pb(PS);
			}
			PS++;
		}
	cin>>n;
	for(i=1;i<=n;i++)cin>>a[i];
	for(i=1;i<=n;i++)
	{
		for(j=0;j<fak[a[i]].size();j++)
			isi[fak[a[i]][j]].pb(i);
	}
	for(i=1;i<n;i++)
	{
		cin>>ta>>tb;
		v[ta].pb(tb);
		v[tb].pb(ta);
	}
	has=0;
	for(i=0;i<PS;i++)
	{
		for(j=0;j<isi[i].size();j++)B[isi[i][j]]=1;
		for(j=0;j<isi[i].size();j++)
		{
			if(!b[isi[i][j]])
			{
				ma=0;
				nod=0;
				dfs1(isi[i][j],0,1);
				dfs2(nod,0,1);
			}
		}
		for(j=0;j<isi[i].size();j++)b[isi[i][j]]=0;
		for(j=0;j<isi[i].size();j++)B[isi[i][j]]=0;
	}
	cout<<has<<"\n";
}