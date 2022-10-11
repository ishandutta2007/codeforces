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

using vl = vector<ll>;
#define pb push_back
#define all(x) x.begin(), x.end()
 
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
	 
	bool prime[15000105]; 
	void sieve(int n) { 
	  for (ll i = 0; i < n + 1; i++) prime[i] = 1;
	  for (ll p = 2; p * p <= n; p++) { 
		if (prime[p] == true) { 
		  for (ll i = p * p; i <= n; i += p) 
			prime[i] = false; 
		} 
	  } 
	  prime[1] = prime[0] = 0;
	} 
	 
	vl primelist;
	bool __primes_generated__ = 0;
	 
	void genprimes(int n) {
	  __primes_generated__ = 1;
	  sieve(n + 1);
	  for (ll i = 2; i < n + 1; i++) if (prime[i]) primelist.pb(i);
	}
	 
	vl factors(ll n) {
	  if (!__primes_generated__) {
		cerr << "Call genprimes you dope" << endl;
		exit(1);
	  }
	  vl facs;
	 
	  for (ll i = 0; primelist[i] * primelist[i] <= n && i < primelist.size(); i++) {
		if (n % primelist[i] == 0) {
		  while (n % primelist[i] == 0) {
			n /= primelist[i];
			facs.pb(primelist[i]);
		  }
		}
	  }
	  if (n > 1) {
		facs.pb(n);
	  }
	  sort(all(facs));
	  return facs;
	}
	
	vl getdivs(ll n) {
    vl divs;
    for (ll i = 1; i * i <= n; i++) {
      if (n % i == 0) {
        divs.pb(i);
        divs.pb(n / i);
      }
    }

    getunique(divs);
    return divs;
  }
}

using namespace number_theory;

ll n, m, k, q, l, r, x, y, z;
const ll template_array_size = 1e6 + 1389;
ll a[template_array_size];
ll b[template_array_size];
ll c[template_array_size];
string s, t;
ll ans = 0;

const ll sqrtn = 100;
vector<ll> pr;
bool alive[100005];

ll expected_val(ll a) {
	ll tot = 0;
	for (ll i = a; i <= n; i += a) {
		tot += alive[i];
	}
	return tot;
}

void kill(ll a) {
	for (ll i = a; i <= n; i += a) {
		alive[i] = 0;
	}
}

ll queryA(ll a) {
	cout << "A " << a << endl;
	cin >> x;
	return x;
}

ll queryB(ll a) {
	cout << "B " << a << endl;
	kill(a);
	
	cin >> x;
		
	return x;
}

void solve(int tc = 0) {
	genprimes(2e5);
	
	cin >> n;
	
	while (primelist.size() && primelist.back() > n) {
		primelist.pop_back();
	}
		
	ll stop = min(sqrtn, (ll)primelist.size());
	
	ll tot = 1 + primelist.size();
	
	for (ll i = 0; i < n; i++) alive[i] = 1;
	
	for (ll i = 0; i < stop; i++) {
		queryB(primelist[i]);
		--tot;
	}
	
	bool maybe_composite = 0;
	for (ll i = 0; i < stop; i++) {
		ll x = queryB(primelist[i]);
		if (x > 0) maybe_composite = 1;
	}
	
	if (maybe_composite) {
		ll prod = 1;
		for (ll x: primelist) {
			ll cur = 1;
			ll y = x;
			while (y <= n) {
				ll a = expected_val(y);
				ll b = queryA(y);
				if (a != b) cur = y;
				else break;
				y *= x;
			}
			prod *= cur;
		}
		cout << "C " << prod << endl;
		return;
	}
	
	ll lpt = 0;
	while (1) {
		ll mid = (lpt + primelist.size() + 1) / 2;
		
		if (lpt == mid) {
			cout << "C 1\n";
			return;
		}
		
		for (ll i = lpt; i < mid; i++) {
			queryB(primelist[i]);
		}
		
		ll a = expected_val(1);
		ll b = queryA(1);
		
		if (a != b) {
			for (ll i = lpt; i < mid; i++) {
				if (queryA(primelist[i]) == 1) {
					cout << "C " << primelist[i] << '\n';
					return;
				}
			}
		}
		
		lpt = mid;
	}
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