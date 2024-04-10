#include <bits/stdc++.h>
using namespace std;
 
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
 
mt19937 rng(std::chrono::steady_clock::now().time_since_epoch().count());
// mt19937 rng(61378913);
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
 
 
 
ll n, m, k, q, l, r, x, y, z;
const ll template_array_size = 1e6 + 3280;
ll a[template_array_size];
ll b[template_array_size];
ll c[template_array_size];
string s, t;
ll ans = 0;
 
ll fact[1005];
 
void solve(int tc = 0) {
	ll p;
	cin >> n >> x >> p;
	
	fact[0] = fact[1] = 1;
	for (ll i = 2; i <= n; i++) {
		fact[i] = (i * fact[i - 1]) % mod;
	}
	
	ll l = 0, r = n;
	ll le = x - 1, gr = n - x;
	ll ans = 1;
	
	ll cnt = n;
	while (l < r) {
		ll m = (l + r) / 2;
		if (m == p) {
			// ans = (ans * fact[cnt - 1]) % mod;
			// break;
			l = m + 1;
		} else if (p > m) {
			ans = (ans * le) % mod;
			--le;
			l = m + 1;
		} else {
			ans = (ans * gr) % mod;
			--gr;
			r = m;
		}
		--cnt;
	}
	
	if (cnt > 0) ans = (ans * fact[cnt]) % mod;
	
	cout << ans << '\n';
}
 
int main() {
	#ifdef galen_colin_local
		auto begin = std::chrono::high_resolution_clock::now();
	#endif
	
	send help
 
	#ifndef galen_colin_local
		// usaco("moop");
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