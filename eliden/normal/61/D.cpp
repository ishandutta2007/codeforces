#include <bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i=a;i<b;++i)
const int sz=1e5;
typedef long long ll;
int n;
vector<vector<pair<int,int>> > g;
ll best;
bool vis[sz];
ll dfs(int u)
{
	vis[u]=true;
	ll acc=0;
	for(auto p:g[u])
		if(!vis[p.first])
		{
			ll d = dfs(p.first);
			d+=p.second;
			if(d+acc>best)
				best=d+acc;
			if(d>acc)
				acc=d;
		}
	return acc;
}
int main()
{
	scanf("%d",&n);
	g.resize(n);
	ll tot=0;
	rep(i,0,n-1)
	{
		int u, v, c;
		scanf("%d%d%d",&u,&v,&c);
		--u, --v;
		g[u].push_back(make_pair(v,c));
		g[v].push_back(make_pair(u,c));
		tot+=2*c;
	}
	best=0;
	rep(i,0,n)
		vis[i]=false;
	ll ans=tot-dfs(0);
	cout<<ans<<endl;
}