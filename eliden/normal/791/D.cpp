#include <bits/stdc++.h>
using namespace std;
#define rep(a,b,c) for(int a=b;a<c;++a)
#define repeq(a,b,c) for(int a=b;a<=c;++a)
#define debug(x) cerr<<(#x)<<": "<<x<<endl
typedef long long ll;
const int sz = 2e5;
ll tot;
ll n, k;
bool vis[sz];
vector<vector<int> > g;
ll depsum[sz];
ll up[5][sz], down[5][sz], subsz[sz];
int par[sz];
ll tot2[5];
void dfs1(int u)
{
	vis[u] = true;
	subsz[u]=1;
	rep(i,0,k)
		up[i][u]=0;
	up[0][u]=1;
	for(int v:g[u])
		if(!vis[v])
		{
			par[v]=u;
			dfs1(v);
			tot+=subsz[v]*(n-subsz[v]);
			subsz[u]+=subsz[v];
			rep(i,0,k)
				up[(i+1)%k][u]+=up[i][v];
		}
}
void dfs2(int u)
{
	if(par[u]==u)
		rep(i,0,k)
			down[i][u]=0;
	rep(i,0,k)
	{
		tot2[i]+=down[i][u]+up[i][u];
//		debug(u);
//		debug(down[i][u]);
//		debug(up[i][u]);
	}
	tot2[0]--;
		
	for(int v:g[u])
		if(v!=par[u])
			rep(i,0,k)
				down[(i+2)%k][v]+=down[(i+1)%k][u]+up[(i+1)%k][u]-up[i][v];
	for(int v:g[u])
		if(v!=par[u])
			dfs2(v);
}
int main()
{
	scanf("%d%d",&n,&k);
	g.resize(n);
	rep(i,0,n-1)
	{
		int u, v;
		scanf("%d%d",&u,&v);
		--u, --v;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	rep(i,0,n)
		vis[i]=false;
	tot=0;
	dfs1(0);
	rep(i,0,n)
		rep(j,0,k)
		down[j][i]=0;
	rep(i,0,k)
		tot2[i]=0;
	dfs2(0);

	ll ans = tot+(k-1)*n*(n-1)/2;
	rep(i,0,k)
	{
		ans-=((k+i-1)%k)*tot2[i]/2;
		//debug(tot2[i]);
	}
	ans/=k;
	cout<<ans<<endl;
}