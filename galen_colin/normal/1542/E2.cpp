#include "bits/stdc++.h"
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
// const ll mod = 998244353;
ll mod;


 
ll n, m, q, k, l, r, x, y, z;
const ll template_array_size = 1e6 + 16614;
ll a[template_array_size];
ll b[template_array_size];
ll c[template_array_size];
string s, t;

ll dp[2][140000];
ll f[150000];
ll g[150000];
const ll B = 1200;
inline void add(ll& a, ll b) {
	a += b;
	if (a >= mod) a -= mod;
	if (a < 0) a += mod;
}

void solve(int tc = 0) {
	cin >> n >> mod;
	
	ll ans = 0;
	
	const ll huge = 137000;
	
	for (ll i = 0; i <= huge + B; i++) dp[0][i] = 1;
	
	stack<ll> fact;
	ll r = 1;
	for (ll i = n; i > 0; i--) {
		fact.push(r);
		r = (r * i) % mod;
	}
	
	for (ll i = 0; i < n; i++) {
		ll p = i & 1;
		
		memset(f, 0, sizeof(f));
		memset(g, 0, sizeof(g));
		
		for (ll x = 0; x < huge; x++) {
			ll y = x + B;
			
			ll v = dp[p][x];
			if (x > 0) add(v, -dp[p][x - 1]);
			
			add(f[y - (i + 1)], v);
			add(f[y - 1], -v);
			add(g[y - 1], -(i * v) % mod);
		}
		
		ll r = 0, slope = 0, cur = 0;
		for (ll j = 0; j <= huge + B + 7; j++) {
			add(slope, f[j]);
			add(r, g[j]);
			add(r, slope);
						
			if (j >= B) cur = (cur + r * dp[p][j - B]) % mod;
		}
		
		ans = (ans + cur * fact.top()) % mod;
		fact.pop();
				
		memset(dp[!p], 0, sizeof(dp[!p]));
		
		for (ll j = 0; j < huge; j++) {
			add(dp[!p][j], dp[p][j]);

			if (j - (i + 1) >= 0) {
				add(dp[!p][j], -dp[p][j - (i + 1)]);
			}
		}
				
		for (ll j = 1; j < huge; j++) {
			add(dp[!p][j], dp[!p][j - 1]);
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
		cerr << "Execution time: " << std::chrono::duration_cast<std::chrono::duration<double>>(end - begin).count() << " seconds" << endl;
	#endif
}