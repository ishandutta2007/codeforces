#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define mp make_pair
#define fi first
#define se second
using namespace std;
ll n,m,i,p[2020],b[2020],d[2020],ta,tb,taa,tbb,j;
char a[2020][2020];
vector<ll> v[2020];
ll car(ll aa)
{
	if(aa==p[aa])return aa;
	else return p[aa]=car(p[aa]);
}
void dfs(ll aa)
{
	b[aa]=1;
	ll ii;
	for(ii=0;ii<v[aa].size();ii++)
	{
		if(b[v[aa][ii]]==1)
		{
			cout<<"No\n";
			exit(0);
		}
		else
		if(!b[v[aa][ii]])
			dfs(v[aa][ii]);
	}
	b[aa]=2;
}
ll depe(ll aa)
{
	if(d[aa]==-1)
	{
		d[aa]=1;
		ll ii;
		for(ii=0;ii<v[aa].size();ii++)
			d[aa]=max(d[aa],depe(v[aa][ii])+1);
	}
	return d[aa];
}
int main()
{
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
	cin>>n>>m;
	for(i=1;i<=n+m;i++)p[i]=i;
	for(i=1;i<=n;i++)
		for(j=1;j<=m;j++)
		{
			cin>>a[i][j];
			if(a[i][j]=='=')
			{
				ta=i;
				tb=n+j;
				taa=car(ta);
				tbb=car(tb);
				p[taa]=tbb;
			}
		}
	memset(d,-1,sizeof(d));
	for(i=1;i<=n;i++)
		for(j=1;j<=m;j++)
		{
			if(a[i][j]=='<')
				v[car(n+j)].pb(car(i));
			else if(a[i][j]=='>')
				v[car(i)].pb(car(n+j));
		}
	for(i=1;i<=n+m;i++)
		if(!b[car(i)])
			dfs(car(i));
	cout<<"Yes\n";
	for(i=1;i<=n;i++)
	{
		cout<<depe(car(i));
		if(i<n)cout<<" ";
		else cout<<"\n";
	}
	for(i=1;i<=m;i++)
	{
		cout<<depe(car(n+i));
		if(i<m)cout<<" ";
		else cout<<"\n";
	}
}