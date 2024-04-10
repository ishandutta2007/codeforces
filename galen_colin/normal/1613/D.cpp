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
// const ll mod = 1000000007;
const ll mod = 998244353;
// ll mod;
 

 
ll n, m, q, k, l, r, x, y, z;
const ll template_array_size = 1e6 + 17646;
ll a[template_array_size];
ll b[template_array_size];
ll c[template_array_size];
string s, t;

ll dp[500007][2]; // [mex][do you have (mex + 1) in sequence]
 
void solve(int tc = 0) {
	cin >> n;
	for (ll i = 0; i < n; i++) cin >> a[i];
	for (ll i = 0; i < n + 5; i++) for (ll j = 0; j < 2; j++) dp[i][j] = 0;
	
	dp[0][0] = 1;
	for (ll i = 0; i < n; i++) {
		// do these in an order so that you don't change a value before you push it
		
		if (a[i] > 0) {
			// (a[i] - 1, 1) -> (a[i] - 1, 1)
			dp[a[i] - 1][1] = (dp[a[i] - 1][1] + (dp[a[i] - 1][1])) % mod;
			
			// (a[i] - 1, 0) -> (a[i] - 1, 1)
			dp[a[i] - 1][1] = (dp[a[i] - 1][1] + (dp[a[i] - 1][0])) % mod;
		}
		
		// (a[i] + 1, 0) -> (a[i] + 1, 0)
		dp[a[i] + 1][0] = (dp[a[i] + 1][0] + (dp[a[i] + 1][0])) % mod;
		
		// (a[i] + 1, 1) -> (a[i] + 1, 1)
		dp[a[i] + 1][1] = (dp[a[i] + 1][1] + (dp[a[i] + 1][1])) % mod;
		
		// (a[i], 0) -> (a[i] + 1, 0)
		dp[a[i] + 1][0] = (dp[a[i] + 1][0] + (dp[a[i]][0])) % mod;
		
		// (a[i], 1) -> (a[i] + 2, 0)... this is INVALID, a[i] + 2 is 2 away from a[i]
		// so no transition here
	}
	
	ll ans = 0;
	for (ll i = 0; i < n + 3; i++) for (ll j = 0; j < 2; j++) {
		ans = (ans + dp[i][j]) % mod;
	}
	ans = (ans - 1 + mod) % mod;
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