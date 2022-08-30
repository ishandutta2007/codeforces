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

int n,k,r,q;
vector<int>edge[400005];
vector<int>vac;
int nw;

struct uf{
	int par[400005];
	void init(){
		rep(i,400005) par[i] = i;
	}
	int find(int x){
		if(x == par[x]) return x;
		else return par[x] = find(par[x]);
	}
	void unite(int x,int y){
		x = find(x); y = find(y);
		if(x == y) return;
		par[x] = y;
	}
	bool same(int x,int y){ return find(x) == find(y); }
}kaede;

int dist[400005];
bool used[400005];
int up[20][400005],dep[400005];

void dfs(int v,int u,int d){
	dep[v] = d;
	up[0][v] = u;
	
	rep(i,edge[v].size()){
		if(edge[v][i] == u) continue;
		dfs(edge[v][i],v,d+1);
	}
}

int lca(int a,int b){
	if(dep[a] > dep[b]) swap(a,b);
	int D = dep[b]-dep[a];
	rep(j,19){
		if(((D>>j)&1)) b = up[j][b];
	}
	if(a == b) return a;
	
	for(int j=18;j>=0;j--){
		if(up[j][a] != up[j][b]){
			a = up[j][a];
			b = up[j][b];
		}
	}
	return up[0][a];
}

int go(int v,int d){
	assert(dep[v] >= d);
	rep(j,19){
		if(((d>>j)&1)) v = up[j][v];
	}
	return v;
}
int main(){
	scanf("%d%d%d",&n,&k,&r);
	nw = n+1;
	rep(i,n-1){
		int a,b; scanf("%d%d",&a,&b);
		edge[a].pb(nw); edge[nw].pb(a);
		edge[b].pb(nw); edge[nw].pb(b);
		nw++;
	}
	queue<int>que;
	rep(i,400005) dist[i] = INF;
	rep(i,r){
		int a; scanf("%d",&a);
		vac.pb(a); que.push(a); dist[a] = 0;
	}
	kaede.init();
	
	while(!que.empty()){
		int q = que.front(); que.pop();
		if(used[q]) continue; used[q] = 1;
		if(dist[q] == k) continue;
		
		rep(i,edge[q].size()){
			int to = edge[q][i];
			kaede.unite(q,to);
			dist[to] = min(dist[to],dist[q]+1);
			if(!used[to]) que.push(to);
		}
	}
	
	dfs(1,-1,0);
	
	rep(j,19){
		rep(i,400005){
			if(up[j][i] == -1) up[j+1][i] = -1;
			else up[j+1][i] = up[j][up[j][i]];
		}
	}
	
	scanf("%d",&q);
	rep(i,q){
		int u,v; scanf("%d%d",&u,&v);
		int L = lca(u,v);
		int dist = dep[u]+dep[v]-2*dep[L];
		
		
		if(dist <= 2*k){
			puts("YES");
		}
		else{
			int uu,vv;
			if(dep[u]-dep[L] >= k) uu = go(u,k);
			else uu = go(v,dist-k);
			
			if(dep[v]-dep[L] >= k) vv = go(v,k);
			else vv = go(u,dist-k);
			
			if(kaede.same(uu,vv)) puts("YES");
			else puts("NO");
		}
	}
}