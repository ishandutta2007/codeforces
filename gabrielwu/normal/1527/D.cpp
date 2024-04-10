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
template<typename T> bool ckmin(T& a, const T& b) { return b < a ? a = b, 1 : 0; }
template<typename T> bool ckmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }


//2 147 483 647 int max
//9 223 372 036 854 775 807 ll max

struct LCARMQ {
	/* O(NlogN) precomputation, O(1) queries */

	//A Sparse Table that breaks ties by decreasing occurrence time. It stores indices in jump.
	template <class T> struct LCASparseTable {
		std::vector<T> v;
		std::vector<std::vector<int>> jump;

		int level(int x) { return 31 - __builtin_clz(x); }

		int comb(int a, int b) {
			//get_child requires max(a, b) used for ties
			return v[a].first == v[b].first ? std::max(a, b) : (v[a] < v[b] ? a : b);
		}

		LCASparseTable() {}
		LCASparseTable(const std::vector<T>& _v) { init(_v); }
		void init(const std::vector<T>& _v) {
			v = _v;
			jump = {std::vector<int>((int)v.size())};
			iota(jump[0].begin(), jump[0].end(), 0);
			for (int j = 1; (1 << j) <= (int)v.size(); j++) {
				jump.push_back(std::vector<int>((int)v.size() - (1 << j) + 1));
				for (int i = 0; i < (int)jump[j].size(); i++) {
					jump[j][i] = comb(jump[j - 1][i], jump[j - 1][i + (1 << (j - 1))]);
				}
			}
		}

		int index(int l, int r) {
			assert(l <= r);
			int d = level(r - l + 1);
			return comb(jump[d][l], jump[d][r - (1 << d) + 1]);
		}

		T query(int l, int r) {
			return v[index(l, r)];
		}
	};

	int n; 
	std::vector<std::vector<int>> adj;
	std::vector<int> dep, in, par, out, pos;
	std::vector<std::pair<int, int>> euler, prefix;
	LCASparseTable<std::pair<int, int>> S;	//Euler tour order, indexed by pos[]
	LCASparseTable<std::pair<int, int>> T; //Prefix order, indexed by in[]

	LCARMQ() {}
	LCARMQ(int _n) { init(_n); }
	void init(int _n) {
		n = _n;
		adj.resize(n);
		dep = in = out = par = pos = std::vector<int>(n);
	}

	void ae(int u, int v) {
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	void dfs(int src) {
		in[src] = (int)prefix.size();
		prefix.emplace_back(dep[src], src);
		pos[src] = (int)euler.size();
		euler.emplace_back(dep[src], src);
		for (auto &nxt : adj[src]) {
			if (nxt == par[src]) continue;
			dep[nxt] = dep[par[nxt] = src] + 1;
			dfs(nxt);
			euler.emplace_back(dep[src], src);
		}
		out[src] = (int)prefix.size() - 1;
	}

	void gen(int root = 0) {
		par[root] = root;
		dfs(root);
		S.init(euler);
		T.init(prefix);
	}

	int lca(int u, int v) {
		u = pos[u];
		v = pos[v];
		if (u > v) std::swap(u, v);
		return S.query(u, v).second;
	}

	int dist(int u, int v) {
		return dep[u] + dep[v] - 2 * dep[lca(u, v)];
	}

	bool is_ancestor(int anc, int src) {
		return in[anc] <= in[src] && out[anc] >= out[src];
	}

	int get_child(int anc, int src) {
		if (!is_ancestor(anc, src)) return -1;
		int l = in[anc] + 1;
		int r = in[src];
		return T.query(l, r).second;
	}
};


int main(){
	cin.tie(0)->sync_with_stdio(0);

	int t;
	cin >> t;
	forn(ti, t){
		int n;
		cin >> n;
		LCARMQ lca(n);
		vector<vector<int>> adj(n);
		vector<ll> sz(n);
		forn(i, n-1){
			int x, y;
			cin >> x >> y;
			lca.ae(x, y);
			adj[x].pb(y);
			adj[y].pb(x);
		}

		function<void(int, int)> dfs = [&](int u, int par){
			// cout << u << endl;
			sz[u] = 1;
			for(int oth: adj[u]){
				if(oth != par){
					dfs(oth, u);
					sz[u] += sz[oth];
				}
			}
			return;
		};

		dfs(0, -1);
		// cout << "HERE" << endl;
		lca.gen();
		vector<ll> ways(n+1);
		ways[0] = (ll) n*(n-1)/2;
		for(int c: adj[0]){
			ways[0] -= sz[c]*(sz[c]-1)/2;
		}
		int a = 0, b = 0;
		for(int i=1; i<n; i++){
			if(i==1){
				b = i;
			} else if(lca.dist(a, i) + lca.dist(i, b) > lca.dist(a, b)) {
				if(a == 0){
					if(lca.is_ancestor(b, i)) b = i;
					else if(lca.get_child(0, i) != lca.get_child(0, b)){
						a = i;
					} else {
						break;
					}		
				} else {
					if(lca.is_ancestor(b, i)) b = i;
					else if(lca.is_ancestor(a, i)) a = i;
					else break;
				}
			}
			ll bsz = sz[b];
			ll asz = (a == 0 ? n - sz[lca.get_child(0, b)] : sz[a]);
			ways[i] = asz*bsz;
		}

		ll bef = (ll)n*(n-1)/2;
		forn(i, n+1){
			cout << bef - ways[i] << " ";
			bef = ways[i];
		}
		cout << "\n";
		
	}
}