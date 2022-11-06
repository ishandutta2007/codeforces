#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define mp make_pair
#define fi first
#define se second
using namespace std;
ll n,x,y,i,ta,tb,b[303030],X,Y,valid,tem;
vector<ll> v[303030];
void dfs1(ll aa)
{
//	cout<<aa<<"\n";
	ll ii;
	b[aa]=1;
	tem++;
	if(aa==y)
		valid=0;
	for(ii=0;ii<v[aa].size();ii++)
		if(b[v[aa][ii]]==0&&v[aa][ii]!=x)
			dfs1(v[aa][ii]);
}
void dfs2(ll aa)
{
//	cout<<aa<<"\n";
	ll ii;
	b[aa]=1;
	tem++;
	if(aa==x)
		valid=0;
	for(ii=0;ii<v[aa].size();ii++)
		if(b[v[aa][ii]]==0&&v[aa][ii]!=y)
			dfs2(v[aa][ii]);
}
int main()
{
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n>>x>>y;
	for(i=1;i<n;i++)
	{
		cin>>ta>>tb;
		v[ta].pb(tb);
		v[tb].pb(ta);
	}
	X=1;Y=1;
	for(i=1;i<=n;i++)
	{
		if(!b[i]&&i!=x)
		{
			tem=0;
			valid=1;
			dfs1(i);
			if(valid)
				X+=tem;
		}
	}
	memset(b,0,sizeof(b));
	for(i=1;i<=n;i++)
	{
		if(!b[i]&&i!=y)
		{
			tem=0;
			valid=1;
			dfs2(i);
			if(valid)
				Y+=tem;
		}
	}
//	cout<<X<<" "<<Y<<"\n";
	cout<<(n*(n-1))-(X*Y)<<"\n";
}