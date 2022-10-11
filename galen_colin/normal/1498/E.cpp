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
const ll mod = 1000000007;
// const ll mod = 998244353;
// ll mod;



ll n, m, q, k, l, r, x, y, z;
const ll template_array_size = 1e6 + 14742;
ll a[template_array_size];
ll b[template_array_size];
ll c[template_array_size];
string s, t;
ll ans = 0;	

bool cmp(pair<ll, ll> b, pair<ll, ll> c) {
	return abs(a[b.f] - a[b.s]) > abs(a[c.f] - a[c.s]);
}

void solve(int tc = 0) {
	cin >> n;
	for (ll i = 0; i < n; i++) cin >> a[i];
	
	memset(b, 0, sizeof(b));
	
	ll cnt = 0;
	while (1) {
		bool can = 0;
		for (ll i = 0; i < n; i++) {
			if (!b[i] && a[i] == 0) {
				for (ll j = 0; j < n; j++) --a[j];
				b[i] = 1;
				++cnt;
				can = 1;
				break;
			}
		}
		if (!can) break;
	}
	
	if (cnt == n) {
		cout << "! 0 0" << endl;
		return;
	}
	
	vector<pair<ll, ll>> v;
	
	for (ll i = 0; i < n; i++) {
		for (ll j = i + 1; j < n; j++) {
			if (!b[i] && !b[j]) {
				v.push_back({i, j});
			}
		}
	}
	sort(v.begin(), v.end(), cmp);
	
	for (pair<ll, ll> x: v) {
		ll b = x.f, c = x.s;
		if (a[b] > a[c]) swap(b, c);
		cout << "? " << c + 1 << " " << b + 1 << endl;
		cin >> s;
		if (s == "Yes") {
			cout << "! " << c + 1 << " " << b + 1 << endl;
			return;
		}
	}
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
		// cerr << "Execution time: " << std::chrono::duration_cast<std::chrono::duration<double>>(end - begin).count() << " seconds" << endl;
	#endif
}