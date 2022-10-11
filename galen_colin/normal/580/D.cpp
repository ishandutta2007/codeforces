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

ll combo[20][20]; // (i, j) -> value from eating i right before j
ll dp[(1 << 18)][19];
 
void solve(int tc = 0) {
	cin >> n >> m >> k;
	
	for (ll i = 0; i < n; i++) cin >> a[i];
	
	for (ll i = 0; i < k; i++) {
		ll x, y, c;
		cin >> x >> y >> c;
		--x; --y;
		combo[x][y] = c;
	}
	
	for (ll i = 0; i < (1 << n); i++) {
		for (ll j = 0; j < n; j++) {
			dp[i][j] = -1e17;
		}
	}
	
	for (ll i = 0; i < n; i++) {
		dp[1 << i][i] = a[i];
	}
	
	for (ll i = 1; i < (1 << n); i++) { // mask of eaten dishes
		for (ll j = 0; j < n; j++) { // previously eaten dish
			if ((i >> j) & 1) { // must have actually been eaten
				for (ll k = 0; k < n; k++) { // new dish to eat
					if (!((i >> k) & 1)) {
						ll new_mask = i | (1 << k);
						
						ll val = dp[i][j] + a[k] + combo[j][k];
						
						dp[new_mask][k] = max(dp[new_mask][k], val);
					}
				}
			}
		}
	}
	
	ll ans = 0;
	for (ll i = 0; i < (1 << n); i++) {
		if (__builtin_popcount(i) == m) {
			for (ll j = 0; j < n; j++) {
				if ((i >> j) & 1) {
					ans = max(ans, dp[i][j]);
				}
			}
		}
	}
	cout << ans << '\n';
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
	// cin >> tc;
	for (int t = 0; t < tc; t++) {
		solve(t);
	}
	
	#ifdef galen_colin_local
		auto end = std::chrono::high_resolution_clock::now();
		cerr << setprecision(4) << fixed;
		cerr << "Execution time: " << std::chrono::duration_cast<std::chrono::duration<double>>(end - begin).count() << " seconds" << endl;
	#endif
}