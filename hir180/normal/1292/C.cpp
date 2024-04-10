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

int n;
ll dp[3005][3005];
int sub[3005];
bool used[3005][3005];
queue<P>que;

vector<int>edge[3005];
int dist[3005][3005];
void dfs(int v,int u){
	sub[v] = 1;
	rep(i,edge[v].size()){
		if(edge[v][i] == u) continue;
		dfs(edge[v][i],v);
		int a = v,b = edge[v][i];
		if(a > b) swap(a,b);
		dp[a][b] = sub[edge[v][i]] * (n-sub[edge[v][i]]);
		que.push(mp(a,b));
		sub[v] += sub[edge[v][i]];
	}
}
void dfss(int v,int u,int d,int o){
	dist[o][v] = d;
	rep(i,edge[v].size()){
		if(edge[v][i]==u) continue;
		dfss(edge[v][i],v,d+1,o);
	}
}
int main(){
	scanf("%d",&n); 
	rep(i,n-1){
		int a,b; scanf("%d%d",&a,&b);
		edge[a].pb(b);
		edge[b].pb(a);
	}
	rep(i,3005)rep(j,3005)dp[i][j]=-1e18;
	dfs(1,-1);
	repn(i,n) dfss(i,-1,0,i);
	while(!que.empty()){
		P p = que.front(); que.pop();
		if(used[p.fi][p.sc]) continue;
		used[p.fi][p.sc] = 1;
		int curlen = dist[p.fi][p.sc];
		int su = sub[p.sc];
		rep(i,edge[p.sc].size()){
			int to = edge[p.sc][i];
			if(dist[p.fi][to]+1 == curlen){
				if(dist[1][to] > dist[1][p.sc]) su = n-sub[to];
			}
		}
		rep(i,edge[p.fi].size()){
			int to = edge[p.fi][i];
			if(curlen+1 != dist[to][p.sc]) continue;
			int su2;
			if(dist[1][p.fi] < dist[1][to]) su2 = sub[to];
			else su2 = n-sub[p.fi];
			
			int a = to, b = p.sc;
			if(a > b) swap(a,b);
			dp[a][b] = max(dp[a][b],dp[p.fi][p.sc]+su*su2);
			if(!used[a][b]) que.push(mp(a,b));
		}
		su = sub[p.fi];
		rep(i,edge[p.fi].size()){
			int to = edge[p.fi][i];
			if(dist[p.sc][to]+1 == curlen){
				if(dist[1][to] > dist[1][p.fi]) su = n-sub[to];
			}
		}
		rep(i,edge[p.sc].size()){
			int to = edge[p.sc][i];
			if(curlen+1 != dist[to][p.fi]) continue;
			int su2;
			if(dist[1][p.sc] < dist[1][to]) su2 = sub[to];
			else su2 = n-sub[p.sc];
			
			int a = to, b = p.fi;
			if(a > b) swap(a,b);
			dp[a][b] = max(dp[a][b],dp[p.fi][p.sc]+su*su2);
			if(!used[a][b]) que.push(mp(a,b));
		}
	}
	ll ans = 0;
	rep(i,3005)rep(j,3005)ans=max(ans,dp[i][j]);
	cout<<ans<<endl;
}