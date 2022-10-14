#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> // Common file
#include <ext/pb_ds/tree_policy.hpp> // Including tree_order_statistics_node_update
using namespace std;
using namespace __gnu_pbds;

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

typedef tree<pii,
null_type,
less<pii>,
rb_tree_tag,
tree_order_statistics_node_update>
os;
//2 147 483 647 int max
//9 223 372 036 854 775 807 ll max


int main(){
	cin.tie(0)->sync_with_stdio(0);

	int n, m;
	cin >> n >> m;
	vector<vector<pii>> adj(n), badj(n);
	forn(i, m) {
		int u, v;
		cin >> u >> v;
		u--; v--;
		adj[u].pb({v, i});
		badj[v].pb({u, i});
	}

	vector<int> dist(n, MOD);

	priority_queue<pii, vector<pii>, greater<pii>> pq;
	pq.push({0, n-1});

	vector<os> vos(n);

	forn(i, n-1) {
		for(pii x: adj[i]){ 
			vos[i].insert({MOD, x.s});
		}
	}

	while(pq.size()) {
		pii p = pq.top(); pq.pop();
		if(dist[p.s] < MOD) {
			assert(dist[p.s] <= p.f);
			continue;
		}

		dist[p.s] = p.f;

		for(pii x: badj[p.s]) {
			if(dist[x.f] != MOD) continue;
			auto it = vos[x.f].find({MOD, x.s});
			assert(it != vos[x.f].end());
			vos[x.f].erase(it);
			vos[x.f].insert({dist[p.s], x.s});

			int gets = 1+dist[p.s] + adj[x.f].size() - 1 - (vos[x.f].order_of_key({dist[p.s]+1, -1}) - 1);
			pq.push({gets, x.f});
		}
	}

	cout << dist[0] << "\n";
}