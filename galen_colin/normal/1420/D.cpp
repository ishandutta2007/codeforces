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

// #include <atcoder/all>
// using namespace atcoder;
 
const lld pi = 3.14159265358979323846;
// const ll mod = 1000000007;
const ll mod = 998244353;
// ll mod;
 
namespace modop {
	ll madd(ll a, ll b) {
	  return (a + b) % mod;
	}
	ll msub(ll a, ll b) {
	  return (((a - b) % mod) + mod) % mod;
	}
	ll mmul(ll a, ll b) {
	  return ((a % mod) * (b % mod)) % mod;
	}
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
	ll minv(ll base) {
	  return mpow(base, mod - 2);
	}
	ll mdiv(ll a, ll b) {
	  return mmul(a, minv(b));
	}
}

using namespace modop;

ll n, m, k, q, l, r, x, y, z;
const ll template_array_size = 1e6 + 1600;
ll a[template_array_size];
ll b[template_array_size];
ll c[template_array_size];
string s, t;
ll ans = 0;

pair<ll, ll> p[300005];
map<ll, ll> ev;

ll fact[300006], ifact[300006];

ll nck(ll n, ll k) {
	if (n < k) return 0;
	ll dem = (ifact[n - k] * ifact[k]) % mod;
	return (fact[n] * dem) % mod;
}

void solve(int tc = 0) {
	// in school, go away
	
	fact[0] = ifact[0] = fact[1] = ifact[1] = 1;
	
	for (ll i = 2; i < 300004; i++) {
		fact[i] = (i * fact[i - 1]) % mod;
		ifact[i] = minv(fact[i]);
	}
	
	cin >> n >> k;
	
	for (ll i = 0; i < n; i++) cin >> p[i];
	
	sort(p, p + n);
	
	vector<ll> ends;
	for (ll i = 0; i < n; i++) ends.push_back(p[i].s + 1);
	
	sort(ends.begin(), ends.end());
	
	ll pt = 0;
	for (ll i = 0; i < n; i++) {
		while (pt < n && ends[pt] <= p[i].f) ++pt;
		
		ll cnt = i - pt;
		
		ans = (ans + nck(cnt, k - 1)) % mod;
		// cout << i << " " << p[i] << " " << ans << " " << cnt << '\n';
	}
	
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