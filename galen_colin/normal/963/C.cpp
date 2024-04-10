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

namespace number_theory {
	ll gcd(ll x, ll y) {
	  if (x == 0) return y;
	  if (y == 0) return x;
	  return gcd(y, x % y);
	}
	bool isprime(ll n) { 
	  if (n <= 1) return false; 
	  if (n <= 3) return true; 
	  
	  if (n % 2 == 0 || n % 3 == 0) return false; 
	  
	  for (ll i = 5; i * i <= n; i += 6) 
		if (n % i == 0 || n % (i+2) == 0) 
		  return false; 
	  
	  return true; 
	} 
	 
	bool prime[100000105]; 
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
	  sort(facs.begin(), facs.end());
	  return facs;
	}
	
	vector<ll> getdivs(ll n) {
    vector<ll> divs;
    for (ll i = 1; i * i <= n; i++) {
      if (n % i == 0) {
        divs.push_back(i);
        divs.push_back(n / i);
      }
    }

    getunique(divs);
    return divs;
  }
}

using namespace number_theory;

ll n, m, q, k, l, r, x, y, z;
const ll template_array_size = 1e6 + 14742;
ll a[template_array_size];
ll b[template_array_size];
ll c[template_array_size];
string s, t;
ll ans = 0;	

pair<pair<ll, ll>, ll> p[200005];
ll mf[200005], ms[200005], rrev[200005];

void solve(int tc = 0) {
	cin >> n;
	for (ll i = 0; i < n; i++) {
		cin >> p[i];
	}
	
	vector<pair<pair<ll, ll>, ll>> sf, ss;
	vector<ll> divs = getdivs(p[0].s);
	
	{
		map<ll, ll> cmp;
		for (ll i = 0; i < n; i++) cmp[p[i].f.f];
		map<ll, ll> rev;
		ll cur = 0;
		for (pair<ll, ll> x: cmp) rev[x.f] = cur++;
		for (ll i = 0; i < n; i++) p[i].f.f = rev[p[i].f.f];
	}
	map<ll, ll> cmp;
	for (ll i = 0; i < n; i++) cmp[p[i].f.s];
	map<ll, ll> rev;
	ll cur = 0;
	for (pair<ll, ll> x: cmp) {
		rev[x.f] = cur;
		rrev[cur] = x.f;
		++cur;
	}
		
	for (ll i = 0; i < n; i++) p[i].f.s = rev[p[i].f.s];
	
	for (ll i = 0; i < n; i++) {
		if (p[i].f.f == p[0].f.f) sf.push_back(p[i]);
		if (p[i].f.s == p[0].f.s) ss.push_back(p[i]);
	}
	
	{
		map<ll, ll> mf, ms;
		
		for (ll i = 0; i < n; i++) {
			++mf[p[i].f.f];
			++ms[p[i].f.s];
		}
		
		if (mf.size() * ms.size() != n) {
			cout << "0\n";
			return;
		}
		
		for (pair<ll, ll> x: mf) {
			if (x.s != ms.size()) {
				cout << "0\n";
				return;
			}
		}
		
		for (pair<ll, ll> x: ms) {
			if (x.s != mf.size()) {
				cout << "0\n";
				return;
			}
		}
	}
	
	set<ll> res;
	
	for (ll x: divs) {
		ll ox = p[0].s / x;
		ll cur = 0;
		
		for (pair<pair<ll, ll>, ll> y: sf) {
			if (y.s % x != 0) goto bad;
			ms[y.f.s] = y.s / x;
		}
		
		for (pair<pair<ll, ll>, ll> y: ss) {
			if (y.s % ox != 0) goto bad;
			mf[y.f.f] = y.s / ox;
		}
		
		for (ll i = 0; i < n; i++) {
			if (ms[p[i].f.s] * mf[p[i].f.f] != p[i].s) goto bad;
		}
		
		for (ll i = 0; i < sf.size(); i++) cur += rrev[sf[i].f.s] * ms[sf[i].f.s];
		res.insert(cur);
		
		bad: ;
	}
	
	cout << res.size() << '\n';
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