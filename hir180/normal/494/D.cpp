#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;
typedef pair<int,int> P;
typedef long long ll;
#define pb push_back
#define mp make_pair
#define mod 1000000007
#define fi first
#define sc second
int n;
vector<P>edge[100005];
ll sum[100005];
ll sum2[100005];
ll up[100005];
ll up2[100005];
int s[100005];
int lca[100005][20];
int dep[100005];
ll dist[100005];
void dfs(int v,int u)
{
	s[v] = 1; lca[v][0] = u;
	for(int i=0;i<edge[v].size();i++)
	{
		if(edge[v][i].fi == u) continue;
		int x = edge[v][i].fi;
		dfs(x,v);
		sum[v] += sum[x] + 1LL* s[x] * edge[v][i].sc;
		sum2[v] += sum2[x] + 1LL*s[x]*edge[v][i].sc%mod*edge[v][i].sc + 2LL * edge[v][i].sc * sum[x];
		sum[v] %= mod;
		sum2[v] %= mod;
		s[v] += s[x];
	}
}
void dfs2(int v,int u,int c)
{
	if(u != -1)
	{
		dep[v] = dep[u]+1; dist[v] = dist[u]+c;
		ll x = sum2[v] + 2LL * c * sum[v] + 1LL * c * c % mod * s[v];
		x %= mod;
		ll y = sum[v] + 1LL * c * s[v];
		y %= mod;
		ll q  = (sum2[u]+up2[u]-x+mod)%mod;
		ll r  = (sum[u]+up[u]-y+mod)%mod;
		up[v] = (r + 1LL * (n-s[v]) * c)%mod;
		up2[v] = (q + 2LL * r * c + 1LL * c * c % mod * (n-s[v]))%mod;
	}
	for(int i=0;i<edge[v].size();i++) if(u != edge[v][i].fi) dfs2(edge[v][i].fi,v,edge[v][i].sc);
}
int calc(int a,int b)
{
	if(dep[a] > dep[b]) swap(a,b);
	for(int i=0;i<20;i++)
	{
		if((((dep[b]-dep[a])>>i)&1))
		{
			b = lca[b][i];
		}
	}
	if(a==b) return a;
	for(int i=19;i>=0;i--)
	{
		if(lca[a][i] != lca[b][i])
		{
			a = lca[a][i];
			b = lca[b][i];
		}
	}
	return lca[a][0];
}
int main()
{
	scanf("%d",&n);
	for(int i=0;i<n-1;i++)
	{
		int a,b,c; scanf("%d%d%d",&a,&b,&c);
		edge[a].pb(mp(b,c));
		edge[b].pb(mp(a,c));
	}
	dfs(1,-1);
	dfs2(1,-1,-1);
	int q; scanf("%d",&q);
	for(int i=0;i<19;i++) for(int j=1;j<=n;j++) if(lca[j][i]==-1) lca[j][i+1]=-1; else lca[j][i+1] = lca[lca[j][i]][i];
	for(int i=0;i<q;i++)
	{
		int u,v; scanf("%d%d",&u,&v);
		int x = calc(u,v);
		ll d = dist[u]+dist[v]-dist[x]*2;
		d %= mod;
		if(x == v && u!=v)
		{
			ll a = up2[v] + 2LL * d * up[v] + 1LL * d * d % mod * (n-s[v]);
			a %= mod;
			printf("%lld\n",(sum2[u]+up2[u]-2*a+mod+mod)%mod);
		}
		else
		{
			ll a = sum2[v] + 2LL * d * sum[v] + 1LL * d * d % mod * (s[v]);
			a %= mod;
			printf("%lld\n",(2*a-sum2[u]-up2[u]+mod+mod)%mod);
		}
	}
}