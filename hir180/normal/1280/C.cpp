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
int n;
vector<P>edge[200005];
int sz[200005];
ll ans1,ans2;
void dfs(int v,int u){
	sz[v] = 1;
	rep(i,edge[v].size()){
		if(edge[v][i].fi == u) continue;
		dfs(edge[v][i].fi,v);
		sz[v] += sz[edge[v][i].fi];
		ans1 += (sz[edge[v][i].fi]%2) * edge[v][i].sc;
		ans2 += 1LL * min(sz[edge[v][i].fi],n-sz[edge[v][i].fi]) * edge[v][i].sc;
	}
}
void solve(){
	scanf("%d",&n); n *= 2;
	ans1 = ans2 = 0;
	rep(i,n+2) edge[i].clear();
	rep(i,n-1){
		int a,b,c; scanf("%d%d%d",&a,&b,&c);
		edge[a].pb(P(b,c));
		edge[b].pb(P(a,c));
	}
	dfs(1,-1);
	printf("%lld %lld\n",ans1,ans2);
}
int main(){
	int t; scanf("%d",&t);
	while(t--){
		solve();
	}
}