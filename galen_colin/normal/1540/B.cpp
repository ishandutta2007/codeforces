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
const ll mod = 1000000007;
// const ll mod = 998244353;
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
	
	const ll FACTORIAL_SIZE = 1.1e6;
	ll fact[FACTORIAL_SIZE], ifact[FACTORIAL_SIZE];
	bool __factorials_generated__ = 0;
	void gen_factorial(ll n) {
		__factorials_generated__ = 1;
		fact[0] = fact[1] = ifact[0] = ifact[1] = 1;
		
		for (ll i = 2; i <= n; i++) {
			fact[i] = (i * fact[i - 1]) % mod;
		}
		ifact[n] = minv(fact[n]);
		for (ll i = n - 1; i >= 2; i--) {
			ifact[i] = ((i + 1) * ifact[i + 1]) % mod;
		}
	}
	ll nck(ll n, ll k) {
		if (!__factorials_generated__) {
			cerr << "Call gen_factorial you dope" << endl;
			exit(1);
		}
		if (k < 0 || n < k) return 0;
		ll den = (ifact[k] * ifact[n - k]) % mod;
		return (den * fact[n]) % mod;
	}
}

using namespace modop;
 
ll n, m, q, k, l, r, x, y, z;
const ll template_array_size = 1e6 + 16614;
ll a[template_array_size];
ll b[template_array_size];
ll c[template_array_size];
string s, t;

ll dp[205][205];
ll dist[205][205];
vector<ll> edges[205];

void dfs(ll v, ll p, ll t, ll d) {
	dist[t][v] = d;
	for (ll x: edges[v]) {
		if (x != p) {
			dfs(x, v, t, d + 1);
		}
	}
}

void solve(int tc = 0) {
	cin >> n;
	
	for (ll i = 0; i < n - 1; i++) {
		cin >> x >> y;
		--x; --y;
		edges[x].push_back(y);
		edges[y].push_back(x);
	}
	
	for (ll i = 1; i <= n; i++) {
		dp[i][0] = 0;
		dp[0][i] = 1;
	}
	
	ll m2 = minv(2);
	for (ll i = 1; i <= n; i++) {
		for (ll j = 1; j <= n; j++) {
			dp[i][j] = ((dp[i - 1][j] + dp[i][j - 1]) * m2) % mod;
		}
	}
	
	for (ll i = 0; i < n; i++) dfs(i, -1, i, 0);
	
	ll ans = 0;
	ll mn = minv(n);
	
	for (ll i = 0; i < n; i++) {
		for (ll j = 0; j < i; j++) {
			ll cnt = 0;
			for (ll k = 0; k < n; k++) {
				if (dist[k][i] + dist[i][j] == dist[k][j]) {
					++cnt;
				} else if (dist[k][j] + dist[i][j] != dist[k][i]) {
					ll d = dist[k][i] + dist[k][j] - dist[i][j];
					ll a = dist[k][i] - d / 2;
					ll b = dist[k][j] - d / 2;
					cnt = (cnt + dp[a][b]) % mod;
				}
			}
			ans = (ans + cnt) % mod;
		}
	}
	
	cout << (ans * mn) % mod << '\n';
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