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
 

 
ll n, m, k, q, l, r, x, y, z;
const ll template_array_size = 1e6 + 1389;
ll a[template_array_size];
ll b[template_array_size];
ll c[template_array_size];
string s, t;
ll ans = 0;

multiset<ll> difs;
set<ll> vals;

void answer() {
	if (vals.size() == 0) {
		cout << 0 << '\n';
		return;
	}
	ll ans = *vals.rbegin() - *vals.begin();
	
	ll dif = 0;
	if (difs.size() > 0) {
		dif = *difs.rbegin();
	}
	
	cout << ans - dif << '\n';
}

void ins(ll x) {
	auto next = vals.upper_bound(x);
	
	if (vals.size() > 0) {
		if (next != vals.end()) {
			difs.insert(*next - x);
		}
		
		if (next != vals.begin()) {
			difs.insert(x - *prev(next));
		}
		
		if (next != vals.end() && next != vals.begin()) {
			ll v = *next;
			--next;
			difs.erase(difs.find(v - *next));
		}
	}
	
	vals.insert(x);
}

void del(ll x) {
	vals.erase(x);
		
	if (vals.size() == 0) return;
	
	auto next = vals.upper_bound(x);
	
	if (next != vals.end()) {
		difs.erase(difs.find(*next - x));
	}
	
	if (next != vals.begin()) {
		difs.erase(difs.find(x - *prev(next)));
	}
	
	if (next != vals.end() && next != vals.begin()) {
		ll v = *next;
		--next;
		difs.insert(v - *next);
	}
}
 
void solve(int tc = 0) {
	cin >> n >> q;
	
	for (ll i = 0; i < n; i++) {
		cin >> a[i];
	}
	
	sort(a, a + n);
	
	for (ll i = 0; i < n; i++) {
		if (i > 0) {
			difs.insert(a[i] - a[i - 1]);
		}
		vals.insert(a[i]);
	}
	
	answer();
	
	for (ll i = 0; i < q; i++) {
		cin >> x >> y;
		if (x == 0) {
			del(y);
		} else {
			ins(y);
		}
		
		answer();
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