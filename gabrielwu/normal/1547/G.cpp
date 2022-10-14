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
	int n, time, num_comps;
	std::vector<std::vector<int>> adj;
	std::vector<int> disc, id, stk;
	std::vector<std::vector<int>> comps;

	void init(int n_) {
		n = n_;
		time = 0;
		num_comps = 0;
		adj.assign(n, std::vector<int>());
		id.assign(n, -1);
		disc.assign(n, 0);
		comps.clear();
	}

	void ae(int u, int v) {
		adj[u].push_back(v);
	}

	int dfs(int src) {
		int low = disc[src] = ++time;
		stk.push_back(src);
		for (int nxt : adj[src]) 
			if (id[nxt] == -1)
				low = std::min(low, disc[nxt] ? : dfs(nxt));
		if (low == disc[src]) {
			for (int nxt = -1; nxt != src;)
				id[nxt = stk.back()] = num_comps, stk.pop_back();
			num_comps++;
		}
		return low;
	}
	
	void build() {
		// builds in topological order
		for (int i = 0; i < n; i++) 
			if (!disc[i])
				dfs(i);
		for (auto& x : id) 
			x = num_comps - 1 - x;
		comps.resize(num_comps);
		for (int i = 0; i < n; i++)
			comps[id[i]].push_back(i);
	}
};

int main(){
	cin.tie(0)->sync_with_stdio(0);

	int t;
	cin >> t;
	forn(ti, t){
		
		int n, m;
		cin >> n >> m;
		SCC s;
		s.init(n);
		vector<pii> edges(m);
		vector<int> selfs;
		forn(i, m){
			int x, y;
			cin >> x >> y;
			x--;y--;
			if(x == y) selfs.pb(x);
			s.ae(x, y);
			edges[i] = mp(x, y);
		}

		s.build();
		int c = s.num_comps;
		vector<bool> inf(c);
		forn(i, c){
			if(s.comps[i].size() > 1){
				inf[i] = true;
			}
		}
		for(int x: selfs){
			inf[s.id[x]] = true;
		}

		vector<set<int>> adj(c), badj(c);
		vector<int> deg(c);
		for(pii p: edges){
			if(s.id[p.s] == s.id[p.f]) continue;
			badj[s.id[p.s]].emplace(s.id[p.f]);
			adj[s.id[p.f]].emplace(s.id[p.s]);
		}
		vector<int> zs;
		forn(i, c){
			deg[i] = badj[i].size();
			if(deg[i] == 0){
				zs.pb(i);
			}
		}
		// cout << deg << "\n";

		vector<int> ans(c);
		while(!zs.empty()){
			int x = zs.back(); zs.pop_back();
			for(int y: adj[x]){
				deg[y]--;
				if(deg[y] == 0){
					zs.pb(y);
				}
			}
			int curr = s.id[0] == x;
			for(int y: badj[x]){
				if(ans[y] == -1){
					curr = -1;
				}else if(ans[y] == 1){
					if(curr == 0) curr = 1;
					else if(curr == 1) curr = 2;
				}else if(ans[y] == 2){
					if(curr == 0 || curr == 1) curr = 2;
				}
			}
			if(inf[x] && curr != 0) curr = -1;
			ans[x] = curr;
		}

		forn(i, n){
			cout << ans[s.id[i]] << " ";
		}cout << "\n";
	}

}