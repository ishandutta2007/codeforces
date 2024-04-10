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

// tested on leetcode https://leetcode.com/problems/sliding-window-maximum... can it be trusted?

template<typename T>
struct sliding_max {
	vector<T> frontv, backv;
	vector<T> frontmx, backmx;
	
	void push(T v) {
		frontv.push_back(v);
		if (frontmx.size()) frontmx.push_back(gcd(frontmx.back(), v)); // combine
		else frontmx.push_back(v);
	}
	
	void pop() {
		if (!backv.size()) {
			while (frontv.size()) {
				backv.push_back(frontv.back());
				if (backmx.size()) backmx.push_back(gcd(backmx.back(), frontv.back())); // combine
				else backmx.push_back(frontv.back());
				frontv.pop_back();
			}
			frontmx.clear();
		}
		if (!backv.size()) return; // popping nothing, btw
		backv.pop_back();
		backmx.pop_back();
	}
	
	T query() {
		if (frontmx.size() && backmx.size()) return gcd(frontmx.back(), backmx.back()); // combine
		if (frontmx.size()) return frontmx.back();
		if (backmx.size()) return backmx.back();
		return T{1000000006}; // sentinel
	}
};

void solve(int tc = 0) {
	cin >> n;
	
	for (ll i = 0; i < n; i++) cin >> a[i];
	
	ll g = a[0];
	for (ll i = 1; i < n; i++) g = gcd(g, a[i]);
	
	ll ans = 0;
	for (ll i = 0; i < n; i++) a[n + i] = a[i];
	
	sliding_max<ll> sm;
	
	ll pt = 0;
	for (ll i = 0; i < 2 * n; i++) {
		sm.push(a[i]);
		
		while (sm.query() <= g) {
			sm.pop();
			++pt;
		}
		
		ans = max(ans, i - pt + 1);
	}
		
	cout << ans << '\n';
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