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
 
ll mpow(ll base, ll exp) {
  ll res = 1;
  while (exp) {
	if (exp % 2 == 1){
		res = (res * base) % mod;
	}
	exp >>= 1;
	base = (base * base) % mod;
  }
  return res;
}
 
ll n, m, k, q, l, r, x, y, z;
const ll template_array_size = 1e6 + 6304;
ll a[template_array_size];
ll b[template_array_size];
ll c[template_array_size];
string s, t;
ll ans = 0;

ll f[100005], g[100005];
// ll c[100005];
ll mx = 100000;

void solve(int tc = 0) {
	cin >> n;
	
	memset(c, 0, sizeof(c));
	
	for (ll i = 0; i < n; i++) {
		cin >> a[i];
		++c[a[i]];
	}
	
	for (ll i = 1; i <= mx; i++) {
		ll cnt = 0;
		for (ll j = i; j <= mx; j += i) { // counting multiples of i
			cnt += c[j];
		}
		
		g[i] = (mpow(2, cnt) - 1) % mod; // [-mod + 1, mod)
		g[i] = (g[i] + mod) % mod; // [-mod + 1, mod) -> [1, 2 * mod)
	}
	
	for (ll i = mx; i >= 1; i--) {
		f[i] = g[i];
		for (ll j = 2 * i; j <= mx; j += i) { //multiples of i
			f[i] = (f[i] - f[j]) % mod;
			f[i] = (f[i] + mod) % mod;
		}
	}
	
	cout << f[1] << '\n';
}

int main() {
	#ifdef galen_colin_local
		auto begin = std::chrono::high_resolution_clock::now();
	#endif
	
	send help
 
	#ifndef galen_colin_local
		// usaco("cowpatibility");
	#endif
	
	// usaco("cowland");
	
	// freopen("tc.cpp", "r", stdin);
 		
	cout << setprecision(12) << fixed;
	
	int tc = 1;
	// cin >> tc;
	for (int t = 0; t < tc; t++) solve(t);
	
	#ifdef galen_colin_local
		auto end = std::chrono::high_resolution_clock::now();
		cout << setprecision(4) << fixed;
		// cout << "Execution time: " << std::chrono::duration_cast<std::chrono::duration<double>>(end - begin).count() << " seconds" << endl;
	#endif
}