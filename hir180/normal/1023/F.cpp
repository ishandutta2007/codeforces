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
int dep[500005],up[20][500005];
vector<int>edge[500005];
int n,k,m;
struct UF{
	int par[500005];
	void init(){ for(int i=0;i<500005;i++) par[i] = i; }
	int find(int x){ if(x == par[x]) return x; else return par[x] = find(par[x]); }
	void unite(int x,int y){
		x = find(x); y = find(y); if(x==y) return;
		if(dep[x] > dep[y]) par[x] = y;
		else par[y] = x;
	}
	bool same(int x,int y){ return find(x)==find(y); }
}kaede,yui;

vector<P1>G;
ll ans;
int use;

void dfs(int v,int u,int d){
	up[0][v] = u; dep[v] = d;
	rep(i,edge[v].size()){
		if(edge[v][i] == u) continue;
		dfs(edge[v][i],v,d+1);
	}
}
int lca(int a,int b){
	if(kaede.same(a,b) == false) return -1;
	if(dep[a] > dep[b]) swap(a,b);
	int D = dep[b]-dep[a];
	rep(j,20){
		if(((D>>j)&1)) b = up[j][b];
	}
	if(b == a) return a;
	for(int j=19;j>=0;j--){
		if(up[j][a] != up[j][b]){
			a = up[j][a];
			b = up[j][b];
		}
	}
	return up[0][a];
}

int main(){
	scanf("%d%d%d",&n,&k,&m);
	kaede.init();
	rep(i,k){
		int a,b; scanf("%d%d",&a,&b);
		edge[a].pb(b);
		edge[b].pb(a);
		kaede.unite(a,b);
	}
	rep(i,m){
		int a,b,c; scanf("%d%d%d",&a,&b,&c);
		G.pb(mp(c,mp(a,b)));
	}
	vector<P>add;
	for(auto g:G){
		P1 p = g; 
		int cs = p.fi;
		int u = p.sc.fi;
		int v = p.sc.sc;
		if(kaede.find(u) != kaede.find(v)){
			edge[u].pb(v);
			edge[v].pb(u);
			add.pb(P(u,v));
			kaede.unite(u,v);
		}
	}
	repn(i,n) assert(kaede.same(1,i));
	dfs(1,-1,0);
	rep(j,19)repn(i,n){
		if(up[j][i] == -1) up[j+1][i] = -1;
		else up[j+1][i] = up[j][up[j][i]];
	}
	yui.init();
	rep(i,add.size()) yui.unite(add[i].fi, add[i].sc);
	
	for(auto g:G){
		P1 p = g; 
		int cs = p.fi;
		int u = p.sc.fi;
		int v = p.sc.sc;
		if(yui.find(u) == yui.find(v)) continue;
		int r = lca(u,v);
		while(1){
			u = yui.find(u);
			if(dep[u] <= dep[r]) break;
			assert(yui.find(u) != yui.find(up[0][u]));
			yui.unite(u,up[0][u]);
			use++;
			ans+=cs;
		}
		while(1){
			v = yui.find(v);
			if(dep[v] <= dep[r]) break;
			assert(yui.find(v) != yui.find(up[0][v]));
			yui.unite(v,up[0][v]);
			use++;
			ans+=cs;
		}
	}
	assert(use <= k);
	if(use < k){
		puts("-1");
	}
	else{
		printf("%lld\n",ans);
	}
}