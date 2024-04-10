#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using db = long double;
using str = string;
using pi = pair<int, int>;
#define mp make_pair
#define f first
#define s second
#define tcT template<class T
tcT> using V = vector<T>;
tcT, size_t SZ> using AR = array<T, SZ>;
using vi = V<int>;
using vb = V<bool>;
using vpi = V<pi>;

#define sz(x) int((x).size())
#define all(x) begin(x), end(x)
#define sor(x) sort(all(x))
#define rsz resize
#define pb push_back
#define ft front()
#define bk back()

#define FOR(i,a,b) for(int i = (a); i < (b); ++i)
#define F0R(i,a) FOR(i,0,a)

#define ROF(i,a,b) for(int i = (b)-1; i >= (a); --i)
#define R0F(i,a) ROF(i,0,a)

#define each(a, x) for(auto& a: x)

const int MOD = 1e9+7;
const db PI = acos((db)-1);
mt19937 rng(0);

tcT> bool ckmin(T& a, const T& b){
	return b < a ? a = b, 1 : 0;
}
tcT> bool ckmax(T& a, const T& b){
	return a < b ? a = b, 1 : 0;
}

// struct DSU{
// 	vi e; void init(int N) {e = vi(N, -1);}
// 	int get(int x){
// 		return e[x] < 0 ? x : e[x] = get(e[x]);
// 	}
// 	bool sameSet(int a, int b){
// 		return get(a) == get(b);
// 	}
// 	int size(int x){
// 		return -e[get(x)];
// 	}

// 	bool unite(int x, int y){
// 		x = get(x), y = get(y); if(x == y) return 0;
// 		if(e[x] > e[y]) swap(x, y);
// 		e[x]+=e[y]; e[y] = x; return 1;
// 	}
// };

struct LCA{
	int N; V<vi> par, adj; vi depth;
	void init(int _N){
		N = _N;
		int d = 1; while((1<<d) < N) ++ d;
		par.assign(d, vi(N)); adj.rsz(N); depth.rsz(N);
	}
	void ae(int x, int y){
		adj[x].pb(y);
		adj[y].pb(x);
	}
	void gen(int R = 0){
		par[0][R] = R; dfs(R);
	}
	void dfs(int x = 0){
		FOR(i,1,sz(par)) par[i][x] = par[i-1][par[i-1][x]];
		each(y, adj[x]) if(y != par[0][x])
			depth[y] = depth[par[0][y]=x]+1, dfs(y);
	}
	int jmp(int x, int d){
		F0R(i, sz(par)) if((d>>i)&1) x = par[i][x];
		return x;
	}
	int lca(int x, int y){
		if(depth[x] < depth[y]) swap(x, y);
		x = jmp(x, depth[x]-depth[y]); if(x == y) return x;
		R0F(i,sz(par)){
			int X = par[i][x], Y = par[i][y];
			if(X != Y) x = X, y = Y;
		}
		return par[0][x];
	}

	// int dist(int x, int y){

	// }
};

const int mx = 200005;

int n, m, s;
vi adj[mx];
bool visited[mx];

LCA lca;

void dfs(int node){
	// cout << node << "\n";
	// cout.flush();
	for(auto u: adj[node]){
		if(visited[u]) continue;
		visited[u] = 1;
		lca.ae(node, u);
		dfs(u);
	}
}

vi genPathDown(int node){
	assert(visited[node]);
	vi path = vi{node};
	while(node != s){
		node = lca.par[0][node];
		path.pb(node);
	}
	reverse(all(path));
	return path;
}

int main(){
	cin.tie(0)->sync_with_stdio(0);
	
	cin >> n >> m >> s;
	lca.init(n+5);
	for(int i = 1; i <= m; i++){
		int u, v;
		cin >> u >> v;
		adj[u].pb(v);
	}

	visited[s] = 1;
	dfs(s);
	lca.gen(s);

	for(int i = 1; i <= m; i++){
		if(!visited[i]) continue;
		for(auto u: adj[i]){
			if(!visited[u]) continue;
			if(lca.par[0][u] == i) continue;
			if(lca.lca(u, i) == u) continue;

			int top_node = lca.lca(u, i);
			if(top_node != s) continue;
			//top_node -> u
			//top_node -> i -> u
			vi path1 = genPathDown(u);
			vi path2 = genPathDown(i);
			path2.pb(u);

			cout << "Possible" << "\n";
			cout << sz(path1) << "\n";
			for(int j = 0; j < sz(path1); j++){
				cout << path1[j];
				if(j+1 < sz(path1)){
					cout << " ";
				}
			}
			cout << "\n";
			cout << sz(path2) << "\n";
			for(int j = 0; j < sz(path2); j++){
				cout << path2[j];
				if(j+1 < sz(path2)){
					cout << " ";
				}
			}
			cout << "\n";
			exit(0);
		}
	}

	cout << "Impossible" << "\n";

}