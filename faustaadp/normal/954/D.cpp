#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define mp make_pair
#define fi first
#define se second
using namespace std;
ll n,m,s,t,i,j,d[1010][1010],ta,tb,f[1010][1010],k,has;
vector<ll> v[101010];
int main()
{
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n>>m>>s>>t;
	for(i=1;i<=n;i++)
		for(j=1;j<=n;j++)
			if(i!=j)
				d[i][j]=1e17;
	for(i=1;i<=m;i++)
	{
		cin>>ta>>tb;
		f[min(ta,tb)][max(ta,tb)]=1;
		v[ta].pb(tb);
		v[tb].pb(ta);
	}
	for(i=1;i<=n;i++)
	{
		queue<ll> q;
		q.push(i);
		while(!q.empty())
		{
			ll u=q.front();
			q.pop();
			for(j=0;j<v[u].size();j++)
				if(d[i][v[u][j]]==1e17)
				{
					d[i][v[u][j]]=d[i][u]+1;
					q.push(v[u][j]);
				}
		}
	}
	for(i=1;i<=n;i++)
		for(j=i+1;j<=n;j++)
			if(f[i][j]==0)
			{
				if(d[s][t]<=d[s][i]+d[j][t]+1&&d[s][t]<=d[s][j]+d[i][t]+1)
					has++;
			}
	cout<<has<<"\n";
}