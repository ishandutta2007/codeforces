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
vector<int>edge[200005];
vector<P>add;
vector<int>G[200005];
ll ww[200005],w[200005];

struct u{
	int par[200005],ran[200005];
	void init(){ for(int i=0;i<200005;i++) par[i] = i; }
	int find(int x){ if(x == par[x]) return x; else return par[x] = find(par[x]); }
	void unite(int x,int y){
		x = find(x); y = find(y); if(x==y) return;
		if(ran[x] < ran[y]) par[x] = y;
		else{
			par[y] = x;
			if(ran[x] == ran[y]) ran[x]++;
		}
	}
	bool same(int x,int y){ return find(x)==find(y); }
}kaede,dif;
int cnt[200005];
int dep[200005],up[20][200005];
int calc_lca(int ss,int t){
	if(dep[ss]>dep[t]) swap(ss,t);
	rep(i,19){
		if((((dep[t]-dep[ss])>>i)&1)){
			t = up[i][t];
		}
	}
	if(ss==t) return ss;
	for(int i=19;i>=0;i--){
		if(up[i][ss]!=up[i][t]){
			ss = up[i][ss];
			t = up[i][t];
		}
	}
	return up[0][ss];
}
void dfs(int v,int u,int d){
	dep[v] = d; up[0][v] = u;
	rep(i,edge[v].size()){
		if(u != edge[v][i]) dfs(edge[v][i],v,d+1);
	}
}
vector<P>bri;
void dfs2(int v,int u){
	rep(i,edge[v].size()){
		if(u != edge[v][i]){
			dfs2(edge[v][i],v);
			assert(cnt[edge[v][i]] >= 0);
			if(cnt[edge[v][i]]) dif.unite(v,edge[v][i]);
			else bri.pb(mp(v,edge[v][i]));
			cnt[v] += cnt[edge[v][i]];
		}
	}
}
ll addc[200005];
int cntc[200005];
ll ans,addd;
ll just_one = 0;
pair<int,ll> dfs3(int v,int u,ll up){
	up += addc[v];
	just_one = max(just_one,up);
	ll mx = up;
	int ex = 0;
	rep(i,G[v].size()){
		if(G[v][i] != u){
			pair<int,ll>a  = dfs3(G[v][i],v,up);
			ex |= a.fi;
			if(!a.fi){
				addd = max(addd,a.sc-up);
			}
			mx = max(mx,a.sc);
		}
	}
	ex |= (cntc[v] >= 2);
	if(ex) ans += addc[v];
	
	return mp(ex,mx);
}
int main(){
	scanf("%d%d",&n,&m);
	kaede.init();
	repn(i,n) scanf("%lld",&ww[i]);
	int cc = 0;
	rep(i,m){
		int a,b; scanf("%d%d",&a,&b);
		if(kaede.same(a,b)) add.pb(P(a,b));
		else{
			kaede.unite(a,b);
			edge[a].pb(b);
			edge[b].pb(a);
			cc++;
		}
	}
	assert(cc == n-1);
	dfs(1,-1,0);
	rep(j,19)repn(i,n){
		if(up[j][i] == -1) up[j+1][i] = -1;
		else up[j+1][i] = up[j][up[j][i]];
	}
	
	rep(i,add.size()){
		int u = add[i].fi;
		int v = add[i].sc;
		cnt[u]++; cnt[v]++;
		cnt[calc_lca(u,v)]-=2;
	}
	dif.init();
	dfs2(1,-1);
	
	for(auto a:bri){
		int u = dif.find(a.fi);
		int v = dif.find(a.sc);
		assert(u != v);
		
		G[u].pb(v);
		G[v].pb(u);
	}
	repn(i,n){
		addc[dif.find(i)] += ww[i];
		cntc[dif.find(i)] += 1;
	}
	int S; cin >> S;
	int beg = dif.find(S);
	dfs3(beg,-1,0);
	cout << max(just_one,ans+addd) << endl;
}