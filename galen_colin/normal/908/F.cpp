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



ll n, m, k, q, l, r, x, y, z;
const ll template_array_size = 1e6 + 8432;
ll a[template_array_size];
ll b[template_array_size];
ll c[template_array_size];
string s, t;
ll ans = 0;	

vector<ll> at[3];
ll pos[300005];
vector<ll> coord[300005][2];

void solve(int tc = 0) {
	cin >> n;
	
	at[2].push_back(-3e9);
	for (ll i = 0; i < n; i++) {
		char c;
		cin >> x >> c;
		pos[i] = x;
		ll v = 0;
		if (c == 'B') v = 1;
		if (c == 'G') v = 2;
		at[v].push_back(x);
	}
	at[2].push_back(4e9);
	
	// cout << at[0] << " " << at[1] << " " << at[2] << endl;
	
	if (at[2].size() == 2) {
		ll v = 0;
		if (at[0].size() > 0) v += at[0].back() - at[0][0];
		if (at[1].size() > 0) v += at[1].back() - at[1][0];
		cout << v << '\n';
		return;
	}
	
	for (ll i = 0; i < 2; i++) {
		ll pt = 0;
		for (ll j = 0; j < at[i].size(); j++) {
			// cout << i << " " << pt << " " << at[2][pt + 1] << " " << at[i][j] << endl;
			while (at[2][pt + 1] < at[i][j]) ++pt;
			coord[pt][i].push_back(at[i][j]);
		}
	}
	
	ll ans = at[2][at[2].size() - 2] - at[2][1];
	for (ll j = 0; j + 1 < at[2].size(); j++) {
		ll cur = 0;
		ll lb = at[2][j], rb = at[2][j + 1];
		for (ll i = 0; i < 2; i++) {
			if (coord[j][i].size() > 0) {
				if (coord[j][i].size() == 1) {
					cur += min(rb - coord[j][i][0], coord[j][i][0] - lb);
				} else {
					ll v = 1e12;
					for (ll k = 0; k + 1 < coord[j][i].size(); k++) {
						v = min(v, (rb - coord[j][i][k + 1]) + (coord[j][i][k] - lb));
					}
					v = min({v, rb - coord[j][i][0], coord[j][i].back() - lb});
					cur += v;
				}
			}
		}
		if (coord[j][0].size() > 0 && coord[j][1].size() > 0) cur = min(cur, rb - lb);
		ans += cur;
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
	// freopen("tc.cpp", "w", stdout);
 		
	cout << setprecision(12) << fixed;
					
	int tc = 1;
	// cin >> tc;
	for (int t = 0; t < tc; t++) solve(t);
	
	#ifdef galen_colin_local
		auto end = std::chrono::high_resolution_clock::now();
		cerr << setprecision(4) << fixed;
		// cerr << "Execution time: " << std::chrono::duration_cast<std::chrono::duration<double>>(end - begin).count() << " seconds" << endl;
	#endif
}