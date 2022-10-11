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
const ll mod = 1000000007;
// const ll mod = 998244353;
// ll mod;
 

 
ll n, m, q, k, l, r, x, y, z;
const ll template_array_size = 1e6 + 16813;
ll a[template_array_size];
ll b[template_array_size];
ll c[template_array_size];
string s, t;

vector<ll> getc() {
	vector<ll> r;
	
	for (ll i = 0; i < n; i++) b[i] = 0;
	
	for (ll i = 0; i < n; i++) {
		if (!b[i]) {
			ll c = 0;
			
			ll x = i;
			do {
				++c;
				b[x] = 1;
				x = a[x];
			} while (x != i);
			
			r.push_back(c);
		}
	}
	
	return r;
}

ll check(vector<ll> req, vector<ll> x) {
	ll ops = 0;
	bool save = 0;
	
	for (ll y: req) {
		bool f = 0;
		
		for (ll i = 0; i < x.size(); i++) {
			if (x[i] == y) {
				x[i] -= y;
				f = 1;
				break;
			}
		}
		
		if (!f) {
			for (ll i = 0; i < x.size(); i++) {
				if (x[i] >= y && x[i] % 3 == y % 3) {
					f = 1;
					++ops;
					x[i] -= y;
					break;
				}
			}
		}
		
		if (!f) ops = 1e9;
	}	
	
	ops += req.size() - 1;
	
	vector<ll> ct(3, 0);
	
	for (ll y: x) {
		++ct[y % 3];
		ops += (y - 1) / 3;
	}
	ll r = min(ct[1], ct[2]);
	ops += r;
	ct[1] -= r;
	ct[2] -= r;
	
	ops += ct[1] * 2 / 3;
	ops += ct[2];
	
	return ops;
}
 
void solve(int tc = 0) {
	cin >> n;
	for (ll i = 0; i < n; i++) cin >> a[i], --a[i];
	
	vector<ll> x = getc();
		
	ll cnt = 1, ops = 1e9;
	if (n % 3 == 0) {
		for (ll i = 0; i < n / 3; i++) {
			cnt = (cnt * 3) % mod;
		}
		
		ops = check({}, x) + 1;
	} else if (n % 3 == 1) {
		cnt = 4;
		for (ll i = 0; i < (n - 4) / 3; i++) {
			cnt = (cnt * 3) % mod;
		}
		
		vector<ll> cur;
		ll req = 1e9;
		
		vector<vector<ll>> v = {{4}, {3, 1}, {2, 2}, {2, 1, 1}, {1, 1, 1, 1}};
		
		for (vector<ll> y: v) {
			ops = min(ops, check(y, x) - (y[0] <= 2));
		}
	} else {
		cnt = 2;
		for (ll i = 0; i < (n - 2) / 3; i++) {
			cnt = (cnt * 3) % mod;
		}
		
		vector<vector<ll>> v = {{2}, {1, 1}};
		
		for (vector<ll> y: v) {
			ops = min(ops, check(y, x));
		}
	}
	
	cout << cnt << " " << ops << '\n';
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