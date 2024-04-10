#include <bits/stdc++.h>
 
using namespace std;
 
#define send {ios_base::sync_with_stdio(false);}
#define help {cin.tie(NULL); cout.tie(NULL);}
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
 
mt19937 rng(std::chrono::steady_clock::now().time_since_epoch().count());
// mt19937 rng(61378913);
/* usage - just do rng() */
 
void usaco(string filename) {
  // #pragma message("be careful, freopen may be wrong")
	freopen((filename + ".in").c_str(), "r", stdin);
	freopen((filename + ".out").c_str(), "w", stdout);
}
 
const lld pi = 3.14159265358979323846;
const ll mod = 1000000007;
// const ll mod = 998244353;
// ll mod;
 


ll n, m, k, q, l, r, x, y, z;
const ll template_array_size = 1e6 + 1101;
ll a[template_array_size];
ll b[template_array_size]; // best starting at i
ll c[template_array_size]; // best ending at i 
string s, t;
ll ans = 0;

ll dp[205][205][205]; // (length, # replacements, # t[0])
const ll inf = 1e9;

void solve(int tc = 0) {	
	cin >> n >> k;
	
	cin >> s >> t;
	
	if (t[0] == t[1]) { // make it so t[0] != t[1]
		ll ct = 0;
		for (ll i = 0; i < n; i++) {
			if (s[i] == t[0]) ++ct;
		}
		
		ll tot = ct + min(n - ct, k);
		
		cout << tot * (tot - 1) / 2 << '\n';
		return;
	}
	
	for (ll i = 0; i <= n; i++) {
		for (ll j = 0; j <= n; j++) {
			for (ll k = 0; k <= n; k++) {
				dp[i][j][k] = -inf;
			}
		}
	}
	
	dp[0][0][0] = 0;
	
	// dp[i][j][k] -> dp[i + 1][j + 1][k]: PUSH DP
	for (ll i = 0; i < n; i++) { // length
		for (ll j = 0; j < n; j++) { // # replace
			for (ll k = 0; k < n; k++) { // # t[0]
				// adding character s[i]
			
				// first transition - don't change -> dp[i + 1][j][?]
				
				if (s[i] == t[0]) {
					// dp[i + 1][j][k + 1]
					
					dp[i + 1][j][k + 1] = max(dp[i + 1][j][k + 1], dp[i][j][k]);
				} else if (s[i] == t[1]) {
					// dp[i + 1][j][k]
					
					dp[i + 1][j][k] = max(dp[i + 1][j][k], dp[i][j][k] + k);
				} else {
					// dp[i + 1][j][k]
					
					dp[i + 1][j][k] = max(dp[i + 1][j][k], dp[i][j][k]);
				}
				
				// second transition - change to t[0] -> dp[i + 1][j + 1][k + 1]
				
				dp[i + 1][j + 1][k + 1] = max(dp[i + 1][j + 1][k + 1], dp[i][j][k]);
				
				// third transition - change to t[1] -> dp[i + 1][j + 1][k]
				
				dp[i + 1][j + 1][k] = max(dp[i + 1][j + 1][k], dp[i][j][k] + k);
			}
		}
	}
	
	// for (ll i = 0; i <= n; i++) {
		// for (ll j = 0; j <= n; j++) {
			// for (ll k = 0; k <= n; k++) {
				// cout << i << " " << j << " " << k << " " << dp[i][j][k] << '\n';
			// }
		// }
	// }
	
	ll ans = 0;
	for (ll i = 0; i <= k; i++) {
		for (ll j = 0; j <= n; j++) {
			ans = max(ans, dp[n][i][j]);
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
		// usaco("cowland");
	#endif
	
	// usaco("cowland");
	
	// freopen("tc.cpp", "r", stdin);
 
	int tc = 1;
	// cin >> tc;
	for (int t = 0; t < tc; t++) solve(t);
	
	#ifdef galen_colin_local
		auto end = std::chrono::high_resolution_clock::now();
		cout << setprecision(4) << fixed;
		// cout << "Execution time: " << std::chrono::duration_cast<std::chrono::duration<double>>(end - begin).count() << " seconds" << endl;
	#endif
}