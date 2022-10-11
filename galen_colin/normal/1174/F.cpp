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
// const ll mod = 1000000007;
const ll mod = 998244353;
// ll mod;
 

 
ll n, m, q, k, l, r, x, y, z;
const ll template_array_size = 1e6 + 17646;
ll a[template_array_size];
ll b[template_array_size];
ll c[template_array_size];
string s, t;

vector<ll> edges[200005];
ll par[200005];
ll sz[200005];
ll dep[200005];

ll init(ll v, ll p, ll d = 0) {
	sz[v] = 1;
	dep[v] = d;
	par[v] = p;
	for (ll x: edges[v]) if (x != p) sz[v] += init(x, v, d + 1);
	return sz[v];
}

ll getp(ll v, ll k) {
	while (v != -1 && k --> 0) v = par[v];
	return v;
}

ll queryd(ll x) {
	cout << "d " << x + 1 << endl;
	cin >> x;
	return x;
}

ll queryc(ll x) {
	cout << "s " << x + 1 << endl;
	cin >> x;
	return x - 1;
}

ll seek(ll v, ll p, ll d) {
	if (d == 0) return v;
	ll bigc = -1, bigv = -1;
	
	for (ll x: edges[v]) if (x != p) {
		if (sz[x] > bigv) {
			bigv = sz[x];
			bigc = x;
		}
	}
	
	if (bigc == -1) return v;
	return seek(bigc, v, d - 1);
}

ll fnot(ll v, ll b) {
	ll sz = 0;
	for (ll x: edges[v]) if (x != par[v]) ++sz;
	
	if (sz == 1 || (b != -1 && sz == 2)) {
		for (ll x: edges[v]) if (x != par[v] && x != b) return x;
	}
	
	return queryc(v);
}
 
void solve(int tc = 0) {	
	cin >> n;
	
	for (ll i = 0; i < n - 1; i++) {
		cin >> x >> y;
		--x; --y;
		edges[x].push_back(y);
		edges[y].push_back(x);
	}
	
	init(0, -1);
	
	ll foc = 0;
	ll D = queryd(foc);
	ll H = D;
	
	for (ll i = 0; i < 18 && D > 0; i++) {
		ll qv = seek(foc, par[foc], D);
		
		ll d = queryd(qv);
		
		if (d == 0) {
			foc = qv;
			break;
		}
		
		ll j = (dep[qv] + H - d - 2 * dep[foc]) / 2;
		D -= j;
		
		ll nfoc = getp(qv, dep[qv] - (dep[foc] + j));
		nfoc = fnot(nfoc, getp(qv, D - 1));
		--D;
		while (edges[nfoc].size() == 2 && D > 0) nfoc = fnot(nfoc, -1), --D; 
		
		foc = nfoc;
	}
	
	cout << "! " << foc + 1 << endl;
}


int main() {
	#ifdef galen_colin_local
		auto begin = std::chrono::high_resolution_clock::now();
	#endif
	
	send help
 
	#ifndef galen_colin_local
		// usaco("evacuation");
	#endif
	
	// usaco("cowland");
	
	// freopen("tc.cpp", "r", stdin);
	// freopen("tc2.cpp", "w", stdout);
	// freopen("in.txt", "r", stdin);
	// freopen("out.txt", "w", stdout);
		
	cout << setprecision(15) << fixed;
 
	
		
	int tc = 1;
	// cin >> tc;
	for (int t = 0; t < tc; t++) {
		solve(t);
	}
	
	#ifdef galen_colin_local
		auto end = std::chrono::high_resolution_clock::now();
		cerr << setprecision(4) << fixed;
		cerr << "Execution time: " << std::chrono::duration_cast<std::chrono::duration<double>>(end - begin).count() << " seconds" << endl;
	#endif
}