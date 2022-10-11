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
const ll mod = 1000000007;
// const ll mod = 998244353;
// ll mod;
 

 
ll n, m, k, l, r, x, y, z;
const ll template_array_size = 1e6 + 15258;
ll a[template_array_size];
ll b[template_array_size];
ll c[template_array_size];
string s, t;



void solve(int tc = 0) {
	vector<ll> a;
	
	cin >> n;
	for (ll i = 0; i < n; i++) cin >> x, a.push_back(x);
	vector<ll> b = a;
	getunique(b);
	
	map<ll, ll> pos;
	for (ll i = 0; i < b.size(); i++) pos[b[i]] = i;
	for (ll& x: a) x = pos[x];
	
	vector<ll> first(n), nxt(n), lst(n);
	for (ll i = a.size() - 1; i >= 0; i--) {
		first[a[i]] = i;
	}
	
	for (ll i = 1; i < b.size(); i++) {
		nxt[i - 1] = i;
		lst[i] = i - 1;
	}
	lst[0] = -1;
	nxt[b.size() - 1] = -1;
	
	// cout << a << endl;
	
	bool res = 1;
	for (ll i = n - 1; i > 0; i--) {
		if (nxt[a[i]] != a[i - 1] && lst[a[i]] != a[i - 1] && a[i] != a[i - 1]) {
			res = 0;
		}
		
		// cout << a[i] << " " << nxt[a[i]] << " " << lst[a[i]] << endl;
		
		if (first[a[i]] == i) {
			ll l = lst[a[i]];
			ll n = nxt[a[i]];
			if (l != -1) nxt[l] = n;
			if (n != -1) lst[n] = l;
		}
	}
	
	cout << (res ? "YES\n" : "NO\n");
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