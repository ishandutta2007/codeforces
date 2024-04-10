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

	int t; cin >> t;
	forn(ti, t) {
		int n, m; cin >> n >> m;
		vector<vector<pair<int, ll>>> adj(n);
		vector<pair<pii, ll>> edges(m);
		forn(i, m) {
			int u, v, w;
			cin >> u >> v >> w;
			u--; v--;
			adj[u].pb({v,w});
			adj[v].pb({u,w});
			edges[i] = {{u, v}, w};
		}

		vector<vector<ll>> dist(n, vector<ll>(n, MOD));
		forn(i, n) dist[i][i] = 0;
		forn(i, n) {
			for(auto p: adj[i]) {
				dist[i][p.f] = 1;
			}
		}
		forn(k, n) {
			forn(i, n) {
				forn(j, n) {
					ckmin(dist[i][j], dist[i][k] + dist[k][j]);
				}
			}
		}

		ll best = LLONG_MAX;
		for(auto e: edges) {
			ll d = min(dist[0][e.f.f] + dist[e.f.s][n-1] + 1, dist[0][e.f.s] + dist[e.f.f][n-1] + 1);
			ckmin(best, d*e.s);
		}

		forn(r, n) {
			for(auto e: edges) {
				ll d = min(dist[0][r] + dist[r][e.f.f] + dist[r][n-1] + 2,
						   dist[0][r] + dist[r][e.f.s] + dist[r][n-1] + 2);
				ckmin(best, d*e.s);
			}
		}

		cout << best << "\n";

		// int max_moves = 2*n+5;
		// vector<vector<ll>> dp(max_moves, vector<ll>(n, -1));
		// dp[0][0] = MOD;
		// for(int i=1; i<max_moves; i++) {
		// 	forn(j, n) {
		// 		ll curr = MOD;
		// 		for(auto p: adj[j]) {
		// 			if(dp[i-1][p.f] > 0) {
		// 				ckmin(curr, min(dp[i-1][p.f], p.s));
		// 			}
		// 		}
		// 		if(curr < MOD) dp[i][j] = curr;
		// 	}
		// }

		// ll best = LLONG_MAX;
		// forn(i, max_moves) {
		// 	if(dp[i][n-1] > 0) {
		// 		ckmin(best, dp[i][n-1]*i);
		// 	}
		// }
		// cout << best << "\n";
	}
}