#include<bits/stdc++.h>
#define For(i,a,b) for(register int i=(a);i<=(b);++i)
#define Rep(i,a,b) for(register int i=(a);i>=(b);--i)
#define int long long
using namespace std;
inline int read()
{
    char c=getchar();int x=0;bool f=0;
    for(;!isdigit(c);c=getchar())f^=!(c^45);
    for(;isdigit(c);c=getchar())x=(x<<1)+(x<<3)+(c^48);
    if(f)x=-x;return x;
}
#define fi first
#define se second
#define pb push_back
#define mkp make_pair
typedef pair<int,int>pii;
typedef vector<int>vi;

#define maxn 300005
int n,m,k,uu[maxn],vv[maxn],w[maxn];
vector<int>e[maxn];

bool bo[maxn],have[maxn];
int dfn[maxn],low[maxn],idx,val[maxn],a[maxn],cnt,bel[maxn];
stack<int>s;
void tarjan(int u,int pa)
{
	dfn[u]=low[u]=++idx;
	s.push(u);
	for(auto v:e[u]){
		if(v==pa)continue;
		if(!dfn[v]) tarjan(v,u),low[u]=min(low[u],low[v]);
		else low[u]=min(low[u],dfn[v]);
	}
	if(low[u]!=dfn[u])return;
	++cnt; int v;
	do{
		v=s.top(); s.pop();
		val[cnt]+=a[v],have[cnt]|=bo[v],bel[v]=cnt;
	}while(v!=u);
}

int ff[maxn];
inline int getf(int x){
	while(x!=ff[x])x=ff[x]=ff[ff[x]];
	return x;
}

bool dohave[maxn];
int rt,res[maxn],dp[maxn],sum[maxn];
vector<pii>G[maxn];
void dfs1(int u,int pa)
{
	dohave[u]=have[u]; sum[u]=val[u];
	for(auto it:G[u]){
		int v=it.fi,w=it.se;
		if(v==pa)continue;
		dfs1(v,u);
		if(!dohave[v]) ff[v]=u,sum[u]+=sum[v];
		else dohave[u]=1;
	}
}

void dp1(int u,int pa)
{
	dp[u]=sum[u];
	for(auto it:G[u]){
		int v=it.fi,w=it.se;
		if(v==pa || !dohave[v])continue;
		dp1(v,u); dp[u]+=max(0ll,dp[v]-w); 
	}
}
void dp2(int u,int pa)
{
	res[u]=dp[u];
	for(auto it:G[u]){
		int v=it.fi,w=it.se;
		if(v==pa || !dohave[v])continue;
		dp[u]-=max(0ll,dp[v]-w);
		dp[v]+=max(0ll,dp[u]-w);
		dp2(v,u);
		dp[v]-=max(0ll,dp[u]-w);
		dp[u]+=max(0ll,dp[v]-w);
	}
}

signed main()
{
	n=read(),m=read(),k=read();
	For(i,1,k)bo[read()]=1;
	For(i,1,n)a[i]=read();
	For(i,1,m)w[i]=read();
	For(i,1,m){
		uu[i]=read(),vv[i]=read();
		e[uu[i]].pb(vv[i]),e[vv[i]].pb(uu[i]);
	}
	tarjan(1,0);
	For(i,1,m){
		int u=bel[uu[i]],v=bel[vv[i]],w=::w[i];
		if(u!=v)G[u].pb(mkp(v,w)),G[v].pb(mkp(u,w));
	}
	For(i,1,cnt)if(have[i])rt=i;
	For(i,1,cnt)ff[i]=i;
	dfs1(rt,0);
	dp1(rt,0),dp2(rt,0);
	For(i,1,n)printf("%lld ",res[getf(bel[i])]);
	return 0;
}