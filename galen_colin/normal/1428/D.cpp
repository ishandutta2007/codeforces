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
 

 
ll n, m, k, q, l, r, x, y, z;
const ll template_array_size = 1e6 + 2211;
ll a[template_array_size];
ll b[template_array_size];
ll c[template_array_size];
string s, t;
ll ans = 0;


void solve(int tc = 0) {
	cin >> n;
	for (ll i = 0; i < n; i++) cin >> a[i];
	
	vector<pair<ll, ll>> t;
	
	ll th = 0, tw = 0;
	ll row[n];
	for (ll i = 0; i < n; i++) row[i] = -1;
	
	ll rpt = n - 1;

	for (ll i = 0; i < n; i++) {
		if (a[i] == 1) {
			if (row[i] == -1) row[i] = rpt--;
			t.push_back({row[i], i});
		} else if (a[i] == 2) {
			if (row[i] == -1) row[i] = rpt--;
			while (tw <= i) ++tw;
			while (tw < n && (a[tw] != 1 || row[tw] != -1)) ++tw;
			
			if (tw < n) {
				row[tw] = row[i];
				++tw;
			} else {
				cout << -1 << '\n';
				return;
			}
			t.push_back({row[i], i});
		} else if (a[i] == 3) {
			if (row[i] == -1) row[i] = rpt--;
			while (th <= i) ++th;
			while (th < n && (a[th] == 0 || row[th] != -1)) ++th;
			
			if (th < n) {
				row[th] = rpt--;
				t.push_back({row[i], i});
				t.push_back({row[i], th});
				++th;
			} else {
				cout << -1 << '\n';
				return;
			}
		}
	}
	
	if (rpt < -1) {
		cout << -1 << '\n';
		return;
	}
	
	// for (ll i = 0; i < n; i++) cout << row[i] << '\n';
	
	cout << t.size() << '\n';
	for (pair<ll, ll> x: t) {
		cout << n - x.f << " " << x.s + 1 << '\n';
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