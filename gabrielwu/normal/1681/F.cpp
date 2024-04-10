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
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

template<typename A, typename B> ostream& operator<<(ostream &cout, pair<A, B> const &p) { return cout << "(" << p.f << ", " << p.s << ")"; }
template<typename A> ostream& operator<<(ostream &cout, vector<A> const &v) {
	cout << "["; for (int i = 0; i < (int)v.size(); i++) {if (i) cout << ", "; cout << v[i]; } return cout << "]";
}
template<typename T> bool ckmin(T& a, const T& b) { return b < a ? a = b, 1 : 0; }
template<typename T> bool ckmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }


//2 147 483 647 int max
//9 223 372 036 854 775 807 ll max


int main(){
	cin.tie(0)->sync_with_stdio(0);

	int n; cin >> n;

	vector<vector<pii>> adj(n);
	forn(i, n-1) {
		int u, v, x;
		cin >> u >> v >> x;
		u--; v--; x--;
		adj[u].pb({v, x});
		adj[v].pb({u, x});
	}

	vector<int> val(n), sz(n), tot_cov(n), my_cov(n);
	using M = unordered_map<int, int>;
	function<M*(int, int)> dfs1 = [&](int u, int par) {
		sz[u] = 1;

		vector<M*> v;
		for(pii oth: adj[u]) {
			if(oth.f == par) continue;
			val[oth.f] = oth.s;
			v.pb(dfs1(oth.f, u));
			sz[u] += sz[oth.f];
		}

		if(sz[u] == 1) {
			//leaf
			M* res = new M();
			(*res)[val[u]]++;
			return res;
		}

		M* best = v[0];
		int besti = 0;
		for(int i=1; i<v.size(); i++) {
			if(v[i]->size() > best->size()) {
				best = v[i];
				besti = i;
			}
		}
		forn(i, v.size()) {
			if(i != besti) {
				for(pii p: *v[i]) {
					(*best)[p.f] += p.s;
				}
			}
		}


		if(u == 0) {
			forn(i, n) {
				tot_cov[i] = (*best)[i];
			}
		} else {
			my_cov[u] = (*best)[val[u]];
			(*best)[val[u]] = sz[u];
		}
		return best;
	};

	dfs1(0, -1);

	// cout << my_cov << " " << tot_cov << endl;

	ll ans = 0;
	vector<vector<int>> stacks(n);
	function<void(int, int)> dfs2 = [&](int u, int par) {

		if(u) stacks[val[u]].pb(u);
		for(pii oth: adj[u]) {
			if(oth.f == par) continue;
			dfs2(oth.f, u);
		}
		if(u) stacks[val[u]].pop_back();

		if(u == 0) return;
		ll below = sz[u] - my_cov[u];
		ll above;
		if(stacks[val[u]].empty()) {
			above = n - tot_cov[val[u]];
		} else {
			int block = stacks[val[u]].back();
			above = sz[block] - my_cov[block];
		}
		ans += below * above;
	};

	dfs2(0, -1);
	cout << ans << "\n";
}