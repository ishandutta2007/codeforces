#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define mp make_pair
#define fi first
#define se second
using namespace std;
ll n,m,s,k,i,j,d[110][101010],a[101010],ta,tb,X,Y,Z,haz[101010],sz[101010];
queue<pair<ll,ll> > q;
vector<ll> v[101010];
int main()
{
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n>>m>>s>>k;
	for(i=1;i<=s;i++)
		for(j=1;j<=n;j++)
			d[i][j]=1e18;
	for(i=1;i<=n;i++)
	{
		cin>>a[i];
		q.push(mp(a[i],i));
		d[a[i]][i]=0;
	}
	for(i=1;i<=m;i++)
	{
		cin>>ta>>tb;
		v[ta].pb(tb);
		v[tb].pb(ta);
	}
	ll te=0;
	while(!q.empty())
	{
		te++;
		X=q.front().fi;
		Y=q.front().se;
		q.pop();
//			continue;
		sz[Y]++;//
		if(sz[Y]<=k)
		haz[Y]+=d[X][Y];
		for(i=0;i<v[Y].size();i++)
		{
			if(d[X][v[Y][i]]>d[X][Y]+1)
			{
				d[X][v[Y][i]]=d[X][Y]+1;
				q.push(mp(X,v[Y][i]));
			}
		}
	}
//	cout<<te<<"\n";
	for(i=1;i<=n;i++)
	{
		cout<<haz[i]<<" ";
	}
}