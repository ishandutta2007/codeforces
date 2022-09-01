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
const ll mod = 1000000007;
int q,n,k;
vector<P>edge[500005];
ll dp[2][500005];
void dfs(int v,int u){
	vector<ll>vec;
	ll base = 0;
	for(int i=0;i<edge[v].size();i++){
		int to = edge[v][i].fi;
		if(to == u) continue;
		dfs(to,v);
		base += dp[0][to];
		vec.pb(dp[1][to]-dp[0][to]+edge[v][i].sc);
	}
	sort(vec.begin(),vec.end(),greater<ll>());
	int sz = vec.size();
	dp[0][v] = base;
	for(int i=0;i<min(sz,k);i++){
		dp[0][v] += max(0LL,vec[i]);
	}
	dp[1][v] = base;
	for(int i=0;i<min(sz,k-1);i++){
		dp[1][v] += max(0LL,vec[i]);
	}
	dp[0][v] = max(dp[0][v],dp[1][v]);
	return ;
}
int main(){
	scanf("%d",&q);
	while(q--){
		scanf("%d%d",&n,&k);
		for(int i=1;i<=n;i++) edge[i].clear();
		for(int i=1;i<n;i++){
			int a,b,w; scanf("%d%d%d",&a,&b,&w);
			edge[a].pb(P(b,w));
			edge[b].pb(P(a,w));
		}
		for(int i=0;i<2;i++) repn(j,n) dp[i][j] = 0;
		dfs(1,-1);
		printf("%lld\n",dp[0][1]);
	}
}