#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define mp make_pair
#define fi first
#define se second
using namespace std;
ll n,i,a[303030],b[303030],ta,tb,te,h1,h2,mo=1000000007,m,j;
vector<ll> v1[303030],v2[303030],x,kel[303030];
void dfs1(ll aa)
{
	b[aa]=1;
	ll ii;
	for(ii=0;ii<v1[aa].size();ii++)
		if(!b[v1[aa][ii]])
			dfs1(v1[aa][ii]);
	x.pb(aa);
}
void dfs2(ll aa)
{
	b[aa]=1;
	kel[te].pb(a[aa]);
	ll ii;
	for(ii=0;ii<v2[aa].size();ii++)
		if(!b[v2[aa][ii]])
			dfs2(v2[aa][ii]);
}
int main()
{
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
	cin>>n;
	for(i=1;i<=n;i++)cin>>a[i];
	cin>>m;
	for(i=1;i<=m;i++)
	{
		cin>>ta>>tb;
		v1[ta].pb(tb);
		v2[tb].pb(ta);
	}
	for(i=1;i<=n;i++)
	{
		if(!b[i])
			dfs1(i);
	}
	reverse(x.begin(),x.end());
	memset(b,0,sizeof(b));
	for(i=0;i<x.size();i++)
	{
		if(!b[x[i]])
		{
			te++;
			dfs2(x[i]);
		}
	}
	//return 0;
	h2=1;
	for(i=1;i<=te;i++)
	{
		sort(kel[i].begin(),kel[i].end());
		h1+=kel[i][0];
		ll hz=0;
	//	for(j=0;j<kel[i].size();j++)cout<<i<<"  "<<kel[i][j]<<"\n";
		for(j=0;j<kel[i].size();j++)
			if(kel[i][j]==kel[i][0])hz++;
		h2=(h2*hz)%mo;
	}
	cout<<h1<<" "<<h2<<"\n";
}