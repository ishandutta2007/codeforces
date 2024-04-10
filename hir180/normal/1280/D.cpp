#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
typedef pair<int,P> P1;
typedef pair<P,P> P2;
#define pu push
#define pb push_back
#define mp make_pair
#define eps 1e-7
#define INF 1000000000
#define fi first
#define sc second
#define rep(i,x) for(int i=0;i<x;i++)
#define repn(i,x) for(int i=1;i<=x;i++)
#define SORT(x) sort(x.begin(),x.end())
#define ERASE(x) x.erase(unique(x.begin(),x.end()),x.end())
#define POSL(x,v) (lower_bound(x.begin(),x.end(),v)-x.begin())
#define POSU(x,v) (upper_bound(x.begin(),x.end(),v)-x.begin())
int n,m;
ll b[3005],w[3005];
typedef pair<int,ll> Q;
Q dp[3005][3005];
vector<int>edge[3005];
int sz[3005];
void dfs(int v,int u){
	sz[v] = 1;
	rep(i,edge[v].size()){
		if(edge[v][i] == u) continue;
		dfs(edge[v][i],v);
		sz[v] += sz[edge[v][i]];
	}
	Q t[2][3005];
	rep(j,2) rep(i,sz[v]+3) t[j][i] = mp(-INF,-INF);
	t[0][0] = mp(0,0);
	int cur = 0,nxt = 1;
	int num = 0;
	rep(i,edge[v].size()){
		if(edge[v][i] == u) continue;
		rep(j,num+sz[edge[v][i]]+3) t[nxt][j] = mp(-INF,-INF);
		repn(j,sz[edge[v][i]]){
			if(dp[edge[v][i]][j].fi < 0) continue;
			//cut
			int add = (dp[edge[v][i]][j].sc > 0ll);
			rep(k,num+1){
				if(t[cur][k].fi < 0) continue;
				t[nxt][k+j] = max(t[nxt][k+j],mp(t[cur][k].fi+dp[edge[v][i]][j].fi+add,t[cur][k].sc));
			}
			//not cut
			rep(k,num+1){
				if(t[cur][k].fi < 0) continue;
				t[nxt][k+j-1] = max(t[nxt][k+j-1],mp(t[cur][k].fi+dp[edge[v][i]][j].fi,t[cur][k].sc+dp[edge[v][i]][j].sc));
			}
		}
		num += sz[edge[v][i]];
		swap(cur,nxt);
	}
	for(int j=0;j<=num;j++){
		dp[v][j+1] = mp(t[cur][j].fi,t[cur][j].sc+w[v]-b[v]);
	}
}
void solve(){
	scanf("%d%d",&n,&m);
	repn(i,n) scanf("%lld",&b[i]);
	repn(i,n) scanf("%lld",&w[i]);
	repn(i,n) edge[i].clear();
	repn(i,n) rep(j,n+2) dp[i][j] = mp(-INF,-INF);
	rep(i,n-1){
		int a,b; scanf("%d%d",&a,&b);
		edge[a].pb(b);
		edge[b].pb(a);
	}
	dfs(1,-1);
	int ans = dp[1][m].fi + (dp[1][m].sc > 0ll);
	printf("%d\n",ans);
}
int main(){
	int t; scanf("%d",&t);
	while(t--){
		solve();
	}
}