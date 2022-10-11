#include <bits/stdc++.h>
using namespace std;

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
// const ll mod = 1000000007;
const ll mod = 998244353;
// ll mod;



ll n, m, q, k, l, r, x, y, z;
const ll template_array_size = 1e6 + 14742;
ll a[template_array_size];
ll b[template_array_size];
ll c[template_array_size];
string s, t;
ll ans = 0;	

ll dp[2025][2025];

void solve(int tc = 0) {
	cin >> n >> m;
	
	memset(dp, 0, sizeof(dp));
	
	for (ll i = 0; i <= n; i++) dp[0][i] = 1;
	for (ll i = 1; i <= m; i++) {
		ll r = 0;
		for (ll j = 0; j <= n; j++) {
			r = (r + dp[i - 1][j]) % mod;
			dp[i][j] = r;
		}
	}
	
	ll ans = 0;
	
	for (ll j = 1; j < n; j++) {
		ll r = 0;
		for (ll i2 = 1; i2 < m; i2++) {
			r = (r + dp[i2][n - j - 1] * dp[m - i2 - 1][n - j]) % mod;
		}
		
		for (ll i = 0; i < m - 1; i++) {
			r = (r - dp[i + 1][n - j - 1] * dp[m - i - 2][n - j]) % mod;
			r = (r + mod) % mod;
			
			ll v = (dp[i][j] * dp[m - i - 1][j - 1]) % mod;
			
			ans = (ans + v * r) % mod;
		}
	}
	
	for (ll i = 0; i < m - 1; i++) {
		
		ll r = 0;
		for (ll j = 1; j < n; j++) {
			r = (r + dp[m - i - 2][n - j] * dp[m - i - 1][j - 1]) % mod;
			
			ll v = (dp[i][j] * dp[i + 1][n - j - 1]) % mod;
			
			ans = (ans + v * r) % mod;
		}
	}
	ans = (ans * 2) % mod;
	
	cout << ans << '\n';
}

int main() {
	#ifdef galen_colin_local
		auto begin = std::chrono::high_resolution_clock::now();
	#endif
	
	send help
 
	#ifndef galen_colin_local
		// usaco("code");
	#endif
	
	// usaco("cowland");
	
	// freopen("tc.cpp", "r", stdin);
	// freopen("tc2.cpp", "w", stdout);
 		
	cout << setprecision(15) << fixed;
							
	int tc = 1;
	// cin >> tc;
	for (int t = 0; t < tc; t++) solve(t);
	
	#ifdef galen_colin_local
		auto end = std::chrono::high_resolution_clock::now();
		cerr << setprecision(4) << fixed;
		// cerr << "Execution time: " << std::chrono::duration_cast<std::chrono::duration<double>>(end - begin).count() << " seconds" << endl;
	#endif
}