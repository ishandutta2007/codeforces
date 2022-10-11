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
const ll template_array_size = 1e6 + 1101;
ll a[template_array_size];
ll b[template_array_size]; // best starting at i
ll c[template_array_size]; // best ending at i 
string s, t;
ll ans = 0;

pair<ll, ll> comp[200005];
ll pref[200005];
ll suf[200005];

void solve(int tc = 0) {	
	cin >> n >> k;
	
	for (ll i = 0; i < n; i++) cin >> a[i];
	
	for (ll i = 0; i < n; i++) {
		ll useless_variable_that_i_disrespect;
		cin >> useless_variable_that_i_disrespect;
	}
	
	map<ll, ll> count;
	for (ll i = 0; i < n; i++) {
		++count[a[i]];
	}
	
	ll m = 0;
	for (pair<ll, ll> x: count) { // (location, count)
		comp[m++] = x;
	}
	
	ll cnt = 0;
	ll rpt = 0;
	for (ll i = 0; i < m; i++) {
		while (rpt < m && comp[rpt].f <= comp[i].f + k) {
			cnt += comp[rpt].s;
			++rpt;
		}
		b[i] = cnt;
		cnt -= comp[i].s;
	}
	
	cnt = 0;
	ll lpt = m - 1;
	for (ll i = m - 1; i >= 0; i--) {
		while (lpt >= 0 && comp[i].f - k <= comp[lpt].f) {
			cnt += comp[lpt].s;
			--lpt;
		}
		c[i] = cnt;
		cnt -= comp[i].s;
	}
	
	ll r = 0;
	for (ll i = 0; i < m; i++) {
		r = max(r, c[i]);
		pref[i] = r;
	}
	
	r = 0;
	for (ll i = m - 1; i >= 0; i--) {
		r = max(r, b[i]);
		suf[i] = r;
	}
	
	ll ans = max(suf[0], pref[m - 1]);
	for (ll i = 0; i < m - 1; i++) {
		ans = max(ans, pref[i] + suf[i + 1]);
	}
	
	// for (ll i = 0; i < m; i++) {
		// cout << b[i] << " " << c[i] << '\n';
	// }
	
	cout << ans << '\n';
}
 
int main() {
	#ifdef galen_colin_local
		auto begin = std::chrono::high_resolution_clock::now();
	#endif
	
	send help
 
	#ifndef galen_colin_local
		// usaco("cowland");
	#endif
	
	// usaco("cowland");
	
	// freopen("tc.cpp", "r", stdin);
 
	int tc = 1;
	cin >> tc;
	for (int t = 0; t < tc; t++) solve(t);
	
	#ifdef galen_colin_local
		auto end = std::chrono::high_resolution_clock::now();
		cout << setprecision(4) << fixed;
		// cout << "Execution time: " << std::chrono::duration_cast<std::chrono::duration<double>>(end - begin).count() << " seconds" << endl;
	#endif
}