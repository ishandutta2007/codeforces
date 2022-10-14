#include <bits/stdc++.h>
using namespace std;

#define forn(i, n) for (int i = 0; i < (n); i++)
#define pb push_back
#define mp make_pair
#define MOD 1000000007
#define f first
#define s second
#define rand(i, j) uniform_int_distribution<ll>((ll)(i), (ll)(j))(rng)
mt19937 rng(std::chrono::steady_clock::now().time_since_epoch().count());

typedef long long ll;
typedef double ld;
typedef long double lld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<bool> vb;

template<typename A, typename B> ostream& operator<<(ostream &cout, pair<A, B> const &p) { return cout << "(" << p.f << ", " << p.s << ")"; }
template<typename A> ostream& operator<<(ostream &cout, vector<A> const &v) {
	cout << "["; for (int i = 0; i < (int)v.size(); i++) {if (i) cout << ", "; cout << v[i]; } return cout << "]";
}

//2 147 483 647 int max
//9 223 372 036 854 775 807 ll max

struct SCC {
	int n; 
	std::vector<std::vector<int>> g, rg, scc_graph, comps;
	std::vector<int> id, ord, roots, topo_ord;
	std::vector<bool> vis;

	void init(int n_) {
		n = n_;
		g.assign(n, std::vector<int>());
		rg.assign(n, std::vector<int>());
		scc_graph.assign(n, std::vector<int>());
		comps.assign(n, std::vector<int>());
		vis.assign(n, false);
		id.assign(n, -1);
		ord.clear();
		roots.clear();     
		topo_ord.clear();  
	}

	void ae(int u, int v) {
		g[u].push_back(v);
		rg[v].push_back(u);
	}

	void dfs_order(int u) {
		vis[u] = true;
		for (auto& v : g[u]) {
			if (vis[v]) 
				continue;
			dfs_order(v);
		}
		ord.push_back(u);
	}

	void dfs_color(int u, int c) {
		id[u] = c;
		for (int& v : rg[u]) 
			if (id[v] == -1) 
				dfs_color(v, c);
	}

	void topological_sort() {
		std::vector<int> in(n);
		std::list<int> todo;
		for (int i = 0; i < n; ++i) 
			for (auto& j : scc_graph[i])
				++in[j];
		for (int i = 0; i < n; ++i)
			if (!in[i] && id[i] == i)
				todo.push_back(i);
		while (!todo.empty()) {
			int u = todo.front();
			todo.pop_front();
			topo_ord.push_back(u);
			for (auto& v : scc_graph[u]) 
				if (!(--in[v])) 
					todo.push_back(v);
		}
	}

	void build_scc_graph() {
		for (int i = 0; i < n; ++i) {
			comps[id[i]].push_back(i);
			for (auto& j : g[i]) {
				if (id[i] == id[j]) 
					continue;
				scc_graph[id[i]].push_back(id[j]);
			}
		}
		topological_sort();
	}

	void gen() {
		for (int i = 0; i < n; ++i) {
			if (!vis[i])
				dfs_order(i);
		}
		reverse(ord.begin(), ord.end());
		for (auto& x : ord) 
			if (id[x] == -1) 
				dfs_color(x, x), roots.push_back(x);
	}
};


int main(){
	cin.tie(0)->sync_with_stdio(0);

	int n, m;
	cin >> n >> m;
	vector<vector<int>> v(n, vector<int>(m, -1));
	int ind = 0;
	forn(i, n){
		forn(j, m){
			char c;
			cin >> c;
			if(c == '#') v[i][j] = ind++;
		}
	}

	SCC s; s.init(ind);
	forn(j, m){
		int bef = -1;
		forn(i, n){
			if(v[i][j] >= 0){
				if(bef >= 0) s.ae(bef, v[i][j]);
				bef = v[i][j];
			}
		}
	}
	forn(j, m-1){
		int bef = -1;
		forn(i, n){
			if(v[i][j] >= 0){
				bef = v[i][j];
			}
			// cout << bef << " " << v[i][j+1] << endl;
			if(bef >= 0 && v[i][j+1] >= 0) s.ae(bef, v[i][j+1]);
		}
	}
	forn(j, m-1){
		int bef = -1;
		forn(i, n){
			if(v[i][j+1] >= 0){
				bef = v[i][j+1];
			}
			// cout << bef << " " << v[i][j] << endl;
			if(bef >= 0 && v[i][j] >= 0) s.ae(bef, v[i][j]);
		}
	}
	// cout << "HERE" << endl;
	forn(i, n-1){
		forn(j, m){
			if(v[i][j] >= 0 && v[i+1][j] >= 0) s.ae(v[i+1][j], v[i][j]);
		}
	}
	s.gen();
	vector<bool> good(ind, true);
	// cout << "HERE" << endl;
	forn(i, ind){
		for(int oth: s.g[i]) if(s.id[oth] != s.id[i]) good[s.id[oth]] = false;
	}
	int ans = 0;
	forn(i, ind){
		if(good[i] && i == s.id[i]) ans ++;
	}
	cout << ans << "\n";

}