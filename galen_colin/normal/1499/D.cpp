#include <bits/stdc++.h>
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
// const ll mod = 1000000007;
// const ll mod = 998244353;
// ll mod;

namespace number_theory {
	bool prime[20000105]; 
	ll pf[20000105]; 
	void sieve(int n) { 
	  for (ll i = 0; i <= n; i++) prime[i] = 1;
	  for (ll p = 2; p <= n; p++) { 
		if (prime[p] == true) {
			pf[p] = p;
		  for (ll i = p * p; i <= n; i += p) {
			prime[i] = false;
			if (pf[i] == 0) pf[i] = p;
		  }
		} 
	  } 
	  prime[1] = prime[0] = 0;
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

ll n, m, k, q, l, r, x, y, z;
const ll template_array_size = 1e6 + 14096;
ll a[template_array_size];
ll b[template_array_size];
ll c[template_array_size];
string s, t;
ll ans = 0;	

ll at[20000050];
ll cache[20000050];

void solve(int tc = 0) {
	// cout << "Case #" << tc << ": ";
	
	ll c, d;
	cin >> c >> d >> x;
	
	ll ans = 0;
	vector<ll> a = getdivs(x);
	for (ll y: a) {
		ll b = x / y + d;
		if (b % c == 0) {
			ll e = b / c;
			
			if (cache[e] > 0) {
				ans += cache[e];
				continue;
			}
			
			ll last = -1, cnt = 0;
						
			ll f = e;
			while (f > 1) {
			    if (pf[f] != last) ++cnt;
			    last = pf[f];
				f /= pf[f];
			}
			
			ans += (1 << cnt);
			cache[e] = (1 << cnt);
		}
	}
	
	cout << ans << '\n';
}

// two pointers? maybe
// xor tricks (or general bitwise)
// tutorial on my template

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
	
	sieve(20000010);
						
	int tc = 1;
	cin >> tc;
	for (int t = 0; t < tc; t++) solve(t);
	
	#ifdef galen_colin_local
		auto end = std::chrono::high_resolution_clock::now();
		cerr << setprecision(4) << fixed;
		// cerr << "Execution time: " << std::chrono::duration_cast<std::chrono::duration<double>>(end - begin).count() << " seconds" << endl;
	#endif
}