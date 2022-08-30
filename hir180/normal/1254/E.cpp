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
vector<int>edge[500005];
vector<P>order[500005];
int a[500005];
int up[20][500005],dep[500005];
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
	for(int j=19;j>=0;j--){
		if(dep[b]-(1<<j) >= dep[a]){
			b = up[j][b];
		}
	}
	assert(dep[a] == dep[b]);
	if(a == b) return a;
	for(int j=19;j>=0;j--){
		if(up[j][a] != up[j][b]){
			a = up[j][a];
			b = up[j][b];
		}
	}
	return up[0][a];
}

//nice problem!
int main(){
	scanf("%d",&n);
	rep(i,n-1){
		int a,b; scanf("%d%d",&a,&b);
		edge[a].pb(b);
		edge[b].pb(a);
	}
	dfs(1,-1,0);
	rep(j,19)repn(i,n){
		if(up[j][i] == -1) up[j+1][i] = -1;
		else up[j+1][i] = up[j][up[j][i]];
	}
	repn(i,n) SORT(edge[i]);
	
	int Q = 0;
	repn(i,n){
		scanf("%d",&a[i]);
		if(a[i] == 0) continue;
		if(a[i] == i){
		    puts("0");  return 0;
		}
		
		vector<int>A,B;
		int u = a[i], v = i;
		int w = lca(u,v);
		while(u != w){
			A.pb(u);
			u = up[0][u];
		}
		while(1){
			B.pb(v);
			if(v == w) break;
			v = up[0][v];
		}
		reverse(B.begin(), B.end());
		for(auto b:B) A.pb(b);
		Q += A.size() - 1;
		if(Q > 2*n){
		    puts("0"); return 0;
		}
		for(int i=0;i<A.size();i++){
			if(i == 0){
				int k = POSL(edge[A[i]], A[i+1]);
				assert(edge[A[i]][k] == A[i+1]);
				order[A[i]].pb(mp(edge[A[i]].size(), k));
			}
			else if(i+1 == A.size()){
				int k = POSL(edge[A[i]], A[i-1]);
				assert(edge[A[i]][k] == A[i-1]);
				order[A[i]].pb(mp(k,edge[A[i]].size()+1));
			}
			else{
				int k = POSL(edge[A[i]], A[i-1]);
				int l = POSL(edge[A[i]], A[i+1]);
				order[A[i]].pb(mp(k,l));
			}
		}
	}
	ll ans = 1;
	repn(i,n){
		//0 ~ edge[i].size()+1
		vector<vector<int>>G; G.resize(edge[i].size()+2, vector<int>());
		vector<int>deg; deg.resize(edge[i].size()+2, 0);
		vector<int>used; used.resize(edge[i].size()+2, 0);
		SORT(order[i]);
		ERASE(order[i]);
		rep(j,order[i].size()){
			int a = order[i][j].fi, b = order[i][j].sc;
			G[a].pb(b);
			deg[b]++;
		}
		int free = 0;
		bool bind = 0;
		for(int j=0;j<edge[i].size()+2;j++){
			if(G[j].size() >= 2 || deg[j] >= 2){
				puts("0"); return 0; 
			}
			if(deg[j]) continue;
			int cur = j;
			int fix = 0;
			while(1){
				if(cur >= edge[i].size()) fix += 1;
				used[cur] = 1;
				if(G[cur].size() == 0) break;
				cur = G[cur][0];
			}
			if(!fix) free++;
			else if(fix == 2) bind = 1;
		}
		rep(j,edge[i].size()+2){
			if(!used[j]){
				puts("0"); return 0;
			}
		}
		if(bind && free){
		    puts("0");  return 0;
		}
		repn(i,free) ans = ans*i%mod;
	}
	cout << ans << endl;
}