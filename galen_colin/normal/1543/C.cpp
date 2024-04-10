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
const ll template_array_size = 1e6 + 16754;
ll a[template_array_size];
ll b[template_array_size];
// ll c[template_array_size];
string s, t;

lld ans = 0;
const ll X = 40000;
const lld eps = 1e-14;

lld dfs(ll c, ll m, ll p, ll v, ll move, ll dep) {
	if (move) swap(c, m);
		
	ll d = min(c, v);
	c -= d;
	if (m > eps) {
		m += d / 2;
		p += d / 2;
	} else {
		p += d;
	}
	
	if (move) swap(c, m);
	
	lld ans = (dep + 2) * (lld(p) / X);
	if (dep == 20) {
		return ans;
	}
	
	return ans + lld(c) / X * dfs(c, m, p, v, 0, dep + 1) + lld(m) / X * dfs(c, m, p, v, 1, dep + 1);
}

void solve(int tc = 0) {
	lld c, m, p, v;
	cin >> c >> m >> p >> v;
	c = round(c * X);
	m = round(m * X);
	p = round(p * X);
	v = round(v * X);
	
	cout << (p / X) + (c / X) * dfs(c, m, p, v, 0, 0) + (m / X) * dfs(c, m, p, v, 1, 0) << '\n';
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