#include "bits/stdc++.h"
using namespace std;
 
// #pragma GCC optimize("O3")
// #pragma GCC target("avx2")
 
/* 
find my code templates at https://github.com/galencolin/cp-templates
also maybe subscribe please thanks 
*/
 
#define send {ios_base::sync_with_stdio(false);}
#define help {cin.tie(NULL);}
#define f first
#define s second
#define getunique(v) {sort(v.begin(), v.end()); v.erase(unique(v.begin(), v.end()), v.end());}
 
typedef long long ll;
// typedef int ll;
// #pragma warning("int")
 
typedef long double lld;
typedef unsigned long long ull;
 
template<typename A> ostream& operator<<(ostream &cout, vector<A> const &v);
template<typename A, typename B> ostream& operator<<(ostream &cout, pair<A, B> const &p) { return cout << "(" << p.f << ", " << p.s << ")"; }
template<typename A> ostream& operator<<(ostream &cout, vector<A> const &v) {
	cout << "["; for(int i = 0; i < v.size(); i++) {if (i) cout << ", "; cout << v[i];} return cout << "]";
}
template<typename A, typename B> istream& operator>>(istream& cin, pair<A, B> &p) {
	cin >> p.first;
	return cin >> p.second;
}
 
mt19937_64 rng(std::chrono::steady_clock::now().time_since_epoch().count());
// mt19937_64 rng(61378913);
/* usage - just do rng() */
 
void usaco(string filename) {
  // #pragma message("be careful, freopen may be wrong")
	freopen((filename + ".in").c_str(), "r", stdin);
	freopen((filename + ".out").c_str(), "w", stdout);
}
 
// #include <atcoder/all>
// using namespace atcoder;
 
const lld pi = 3.14159265358979323846;
const ll mod = 1000000007;
// const ll mod = 998244353;
// ll mod;
 

 
ll n, m, q, k, l, r, x, y, z;
const ll template_array_size = 1e6 + 17928;
ll a[template_array_size];
ll b[template_array_size];
ll c[template_array_size];
string s, t;

ll dp[1 << 15][16][16]; // note - last index is kinda 1-indexed
pair<ll, ll> par[1 << 15][16][16];
ll nxt[1 << 15][15]; // (mask of elements to take, last index in final array) -> index to merge to
ll sum[1 << 15];

ll get(ll v) {
	return c[v];
}

void del(ll v) {
	for (ll i = v; i < n; i++) --c[i];
}
 
void solve(int tc = 0) {
	cin >> n;
	
	iota(c, c + n, 0);
	
	for (ll i = 0; i < n; i++) cin >> a[i];
	
	for (ll i = 0; i < (1 << n); i++) {
		for (ll j = 0; j < n; j++) {
			ll best = n;
			for (ll k = j; k < n; k++) {
				if ((i >> k) & 1) {
					best = min(best, k);
				}
			}
			nxt[i][j] = best;
		}
	}
	
	for (ll i = 0; i < (1 << n); i++) {
		for (ll j = 0; j <= n; j++) {
			for (ll k = 0; k <= n; k++) {
				dp[i][j][k] = 1e9;
			}
		}
	}
	dp[0][0][0] = 0;
	
	for (ll i = 0; i < (1 << n); i++) {
		ll s = 0;
		for (ll j = 0; j < n; j++) {
			if ((i >> j) & 1) {
				s += a[j];
			}
		}
		sum[i] = s;
	}
	
	for (ll t = 0; t < (1 << n); t++) { // taken elements 
		ll sz = __builtin_popcount(t);
		ll rest = ((1 << n) - 1) - t;
		for (ll l = 0; l < n; l++) { // last index
			// if ((t >> l) & 1) {
				for (ll s = 0; s <= sz; s++) { // size of array
					// cout << bitset<15>(t) << " " << dp[t][l][s] << endl;
					for (ll m = rest; m; m = (m - 1) & rest) { // new mask - consider sorting these new masks by sum, but maybe that makes it worse lol
						if (sum[m] > dp[t][l][s]) {
							ll nm = t | m;
							ll ni = nxt[m][l];
							ll ns = s + 1;
							
							// cout << bitset<15>(t) << " " << bitset<15>(m) << " " << dp[t][l][s] << " " << sum[m] << endl;
							if (ni < n && dp[nm][ni][ns] > sum[m]) {
								dp[nm][ni][ns] = sum[m];
								par[nm][ni][ns] = {t, l};
							}
						}
					}
				}
			// }
		}
	}
	
	array<ll, 3> targ;
	
	ll ans = 0;
	for (ll j = 0; j <= n; j++) {
		for (ll k = 0; k <= n; k++) {
			if (dp[(1 << n) - 1][j][k] <= 1e8) {
				if (k > ans) {
					ans = k;
					targ = {(1 << n) - 1, j, k};
				}
			}
		}
	}
	
	vector<pair<ll, ll>> ops;
	
	while (targ[0] > 0) {
		pair<ll, ll> p = par[targ[0]][targ[1]][targ[2]];
		
		ll diff = (p.f ^ targ[0]);
		
		ll into = targ[1];
		
		for (ll i = 0; i < n; i++) {
			if ((diff >> i) & 1) {
				if (i != into) {
					ops.push_back({i, into});
				}
			}
		}
		
		targ[0] = p.f;
		targ[1] = p.s;
		--targ[2];
	}
	
	reverse(ops.begin(), ops.end());
	
	cout << ops.size() << '\n';
	for (pair<ll, ll> x: ops) {
		ll v = x.f;
		x.f = get(x.f), x.s = get(x.s);
		del(v);
		cout << x.f + 1 << " " << x.s + 1 << '\n';
	}
}

int main() {
	#ifdef galen_colin_local
		auto begin = std::chrono::high_resolution_clock::now();
	#endif
	
	send help
 
	#ifndef galen_colin_local
		// usaco("evacuation");
	#endif
	
	// usaco("cowland");
	
	// freopen("tc.cpp", "r", stdin);
	// freopen("tc2.cpp", "w", stdout);
	// freopen("in.txt", "r", stdin);
	// freopen("out.txt", "w", stdout);
		
	cout << setprecision(15) << fixed;
 
	
		
	int tc = 1;
	cin >> tc;
	for (int t = 0; t < tc; t++) {
		solve(t);
	}
	
	#ifdef galen_colin_local
		auto end = std::chrono::high_resolution_clock::now();
		cerr << setprecision(4) << fixed;
		cerr << "Execution time: " << std::chrono::duration_cast<std::chrono::duration<double>>(end - begin).count() << " seconds" << endl;
	#endif
}