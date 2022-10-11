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
// const int mod = 1000000007;
// const ll mod = 998244353;
// ll mod;
 

 
ll n, m, q, k, l, r, x, y, z;
const ll template_array_size = 1e6 + 15258;
ll a[template_array_size];
ll b[template_array_size];
ll c[template_array_size];
string s, t;
 
string mat[500005];

/* 
	try to think a bit more to simplify if sol is complicated
	also look for edge cases, please
*/
void solve(int tc = 0) {
	cin >> n >> m;
		
	for (ll i = 0; i < n; i++) {
		cin >> mat[i];
	}
	
	ll v = 1, h = 1;
	for (ll i = 0; i < m; i++) {
		ll can = 0;
		for (ll it = 0; it < 2; it++) {
			bool pos = 1;
			for (ll j = 0; j < n; j++) {
				ll req = it ^ (j & 1);
				if (!(mat[j][i] == '.' || (req == ('2' <= mat[j][i] && mat[j][i] <= '3')))) pos = 0;
			}
			can += pos;
		}
		v = (v * can) % 1000003;
	}
	
	for (ll i = 0; i < n; i++) {
		ll can = 0;
		for (ll it = 0; it < 2; it++) {
			bool pos = 1;
			for (ll j = 0; j < m; j++) {
				ll req = it ^ (j & 1);
				if (!(mat[i][j] == '.' || (req == (mat[i][j] <= '2')))) pos = 0;
			}
			can += pos;
		}
		h = (h * can) % 1000003;
	}
	cout << (v * h) % 1000003 << '\n';
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