#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define mp make_pair
#define fi first
#define se second
using namespace std;
ll n,m,i,te,b[402020],a[402020],x,ta,tb,kel[402020];
vector<ll> z,v[402020],y[402020];
void gabung(ll aa,ll bb)
{
	aa+=m;
	bb+=m;
	v[aa].pb(bb);
}
void dfs1(ll aa)
{
	b[aa]=1;
	ll ii;
	for(ii=0;ii<v[aa].size();ii++)
		if(!b[v[aa][ii]])
			dfs1(v[aa][ii]);
	z.pb(aa);
}
void dfs2(ll aa)
{
	kel[aa]=te;
//	cout<<aa<<" "<<kel[aa]<<"\n";	
	b[aa]=1;
	ll ii;
	for(ii=0;ii<v[aa].size();ii++)
		if(!b[v[aa][ii]])
			dfs2(v[aa][ii]);
}
int main()
{
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
	cin>>n>>m;
	for(i=1;i<=n;i++)cin>>a[i];
	for(i=1;i<=m;i++)
	{
		cin>>x;
		while(x--)
		{
			cin>>ta;
			y[ta].pb(i);
		}
	}
	for(i=1;i<=n;i++)
	{
		ll A=y[i][0];
		ll B=y[i][1];
		//cout<<A<<" "<<B<<"\n";
		if(!a[i])
		{
			gabung(-A,B);
			gabung(-B,A);
			gabung(B,-A);
			gabung(A,-B);
		}
		else
		{
			gabung(-A,-B);
			gabung(-B,-A);
			gabung(A,B);
			gabung(B,A);
		}
	}
	for(i=0;i<=m*2;i++)
		if(!b[i])
			dfs1(i);
	memset(b,0,sizeof(b));
	reverse(z.begin(),z.end());
	for(i=0;i<z.size();i++)
	{
		if(!b[z[i]])
		{
			te++;
			dfs2(z[i]);
		}
	}
	for(i=1;i<=m;i++)
	{
		if(kel[-i+m]==kel[i+m])
		{
			cout<<"NO\n";
			return 0;
		}
	}
	cout<<"YES\n";
}