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
// const ll mod = 1000000007;
const ll mod = 998244353;
// ll mod;
 
#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 
using namespace __gnu_pbds; 

template <typename num_t>
using ordered_set = tree<num_t, null_type, less<num_t>, rb_tree_tag, tree_order_statistics_node_update>;

template <typename num_t>
struct ordered_multiset {
	ordered_set<pair<num_t, ll> > vals;
	set<pair<num_t, ll> > best; /* start at -1 */
	
	/* helper, find the lowest value that represents the element */
	ll findbest(num_t val) {
		return (*best.upper_bound(make_pair(val - 1, 0))).second;
	}
	
	/* is element in set */
	bool contains(num_t val) {
		return vals.find(make_pair(val, -1)) != vals.end();
	}
	
	void insert(num_t val) {
		if (contains(val)) { /* already in, update lowest value and insert a new one */
			ll loc = findbest(val);
			best.erase(make_pair(val, loc));
			best.insert(make_pair(val, loc - 1));
			vals.insert(make_pair(val, loc - 1));
		} else { /* make lowest value -1 and insert it */
			best.insert(make_pair(val, -1));
			vals.insert(make_pair(val, -1));
		}
	}
	
	void erase(num_t val) { /* erases one */
		if (!contains(val)) return; /* not in */
		num_t loc = findbest(val);
		
		/* remove the element and its best */
		best.erase(make_pair(val, loc));
		vals.erase(make_pair(val, loc));
		if (loc != -1) best.insert(make_pair(val, loc + 1)); /* more elements in set, update best */
	}
	
	/* unmodified functions */
	num_t find_by_order(ll k) { return (*vals.find_by_order(k)).first; }
	ll order_of_key(num_t k) { return vals.order_of_key(make_pair(k - 1, 0)); }
	ll size() { return vals.size(); }
	void clear() { vals.clear(); best.clear(); }
};
 
ll n, m, q, k, l, r, x, y, z;
const ll template_array_size = 1e6 + 15258;
ll a[template_array_size];
ll b[template_array_size];
ll c[template_array_size];
string s, t;

ll ans;
ordered_multiset<ll> os[2];
ll alt[2][200005];

ll galt(ll l, ll r, ll t) {
	if (l > r) return 0;
	ll v = alt[t][r];
	if (l > 0) v -= alt[t][l - 1];
	return v;
}

void get(ll p, ll s) {
	for (ll i = p; i < n; i++) s -= a[i];
	if (s > 0) ++ans;
	
	os[0].clear();
	os[1].clear();
	
	ll cs = 0, cc = -2 * a[n - 1];
	for (ll i = n - 1; i > p; i--) {
		s += a[i];
		
		cs += a[i], cc += a[i];
		
		ll val = cs - galt(i, n - 1, !(i % 2));
		
		os[i % 2].insert(val);
		
		val = cc - galt(i, n - 1, !(i % 2));
		
		if (i < n - 1) os[i % 2].insert(val);
				
		ll tot = s + galt(i, n - 1, (i % 2));
		// cout << i << " " << tot << " " << s << " " << ans << '\n';
		ans = (ans + os[!(i % 2)].size() - os[!(i % 2)].order_of_key(-tot + 1)) % mod;
		if (tot > 0) ans = (ans + 1) % mod;
	}
}

void solve(int tc = 0) {
	cin >> n;
	for (ll i = 0; i < n; i++) cin >> a[i];
	
	for (ll t = 0; t < 2; t++) {
		ll r = 0;
		for (ll i = 0; i < n; i++) {
			if ((i % 2) == (t % 2)) r += a[i];
			else r -= a[i];
			
			alt[t][i] = r;
		}
	}
	
	ans = 1; // all P
	ll s = 0;
	for (ll i = 0; i < n; i++) s += a[i];
	
	for (ll i = n - 1; i >= 2; i--) { // change s[i] = C
		s -= 2 * a[i];
		if (s <= 0) break;
		++ans;
	}
		
	if (n > 1) get(1, a[0]);	
	get(0, 0);
	
	cout << (ans % mod) << '\n';
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
	cin >> tc;
	for (int t = 0; t < tc; t++) solve(t);
	
	#ifdef galen_colin_local
		auto end = std::chrono::high_resolution_clock::now();
		cerr << setprecision(4) << fixed;
		cerr << "Execution time: " << std::chrono::duration_cast<std::chrono::duration<double>>(end - begin).count() << " seconds" << endl;
	#endif
}