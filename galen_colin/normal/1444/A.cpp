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
// const ll mod = 1000000007;
// const ll mod = 998244353;
// ll mod;
 
namespace number_theory {
	 
	bool prime[15000105]; 
	void sieve(int n) { 
	  for (ll i = 0; i <= n; i++) prime[i] = 1;
	  for (ll p = 2; p * p <= n; p++) { 
		if (prime[p] == true) { 
		  for (ll i = p * p; i <= n; i += p) 
			prime[i] = false; 
		} 
	  } 
	  prime[1] = prime[0] = 0;
	} 
	 
	vector<ll> primelist;
	bool __primes_generated__ = 0;
	 
	void genprimes(int n) {
	  __primes_generated__ = 1;
	  sieve(n + 1);
	  for (ll i = 2; i <= n; i++) if (prime[i]) primelist.push_back(i);
	}
	 
	vector<ll> factors(ll n) {
	  if (!__primes_generated__) {
		cerr << "Call genprimes you dope" << endl;
		exit(1);
	  }
	  vector<ll> facs;
	 
	  for (ll i = 0; primelist[i] * primelist[i] <= n && i < primelist.size(); i++) {
		if (n % primelist[i] == 0) {
		  while (n % primelist[i] == 0) {
			n /= primelist[i];
			facs.push_back(primelist[i]);
		  }
		}
	  }
	  if (n > 1) {
		facs.push_back(n);
	  }
	  // sort(all(facs));
	  return facs;
	}
}

using namespace number_theory;
 
ll n, m, k, q, l, r, x, y, z;
const ll template_array_size = 1e6 + 3862;
ll a[template_array_size];
ll b[template_array_size];
ll c[template_array_size];
string s, t;
ll ans = 0;


 
void solve(int tc = 0) {
	ll p, q;
	cin >> p >> q;
	
	if (p % q != 0) {
		cout << p << '\n';
		return;
	}
	
	vector<ll> facs = factors(q);
	map<ll, ll> cnt;
	for (ll x: facs) ++cnt[x];
	
	ll ans = p;
	for (pair<ll, ll> x: cnt) {
		ll pow_p = 0;
		ll op = p;
		while (op % x.f == 0) {
			op /= x.f;
			++pow_p;
		}
		
		ll diff = pow_p - x.s + 1;
		
		ll div = 1;
		for (ll i = 0; i < diff; i++) div *= x.f;
		ans = min(ans, div);
	}
	
	cout << p / ans << '\n';
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
 
	genprimes(1e6);
	
	int tc = 1;
	cin >> tc;
	for (int t = 0; t < tc; t++) solve(t);
	
	#ifdef galen_colin_local
		auto end = std::chrono::high_resolution_clock::now();
		cout << setprecision(4) << fixed;
		// cout << "Execution time: " << std::chrono::duration_cast<std::chrono::duration<double>>(end - begin).count() << " seconds" << endl;
	#endif
}