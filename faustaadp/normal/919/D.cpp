#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define mp make_pair
#define fi first
#define se second
using namespace std;
ll n,m,i,ta,tb,d[303030],g[303030],hs,j;
string s;
vector<ll> v[303030];
ll rmt(ll aa)
{
	if(g[aa]==1)
	{
		cout<<-1<<"\n";
		exit(0);
	}
	if(d[aa]==-1)
	{
		d[aa]=0;
		g[aa]=1;
		ll ii;
		for(ii=0;ii<v[aa].size();ii++)
			d[aa]=max(d[aa],rmt(v[aa][ii]));
		if(s[aa-1]==char(i))
			d[aa]++;
		g[aa]=0;
	}
	return d[aa];
}
int main()
{
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n>>m;
	cin>>s;
	for(i=1;i<=m;i++)
	{
		cin>>ta>>tb;
		v[ta].pb(tb);
	}
	for(i='a';i<='z';i++)
	{
		memset(d,-1,sizeof(d));
		memset(g,0,sizeof(g));
		for(j=1;j<=n;j++)
		{
//			if(i=='z')
//				cout<<j<<" "<<rmt(j)<<"\n";
		//	if(rmt(j)==7)
		//		cout<<char(i)<<" "<<j<<"\n";
			hs=max(hs,rmt(j));
		}
//		cout<<hs<<"\n";
	}
	cout<<hs<<"\n";
}