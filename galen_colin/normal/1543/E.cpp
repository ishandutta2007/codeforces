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
ll c[template_array_size];
string s, t;

vector<ll> edges[100005];
bool vis[100005];
ll adj[100005];
ll tag[100005];

vector<ll> merge(vector<ll> a, vector<ll> b) {
	for (ll x: b) a.push_back(x);
	return a;
}

bool cmp(ll a, ll b) {
	return tag[a] < tag[b];
}

vector<ll> rec(ll v, ll d, ll req, ll m) {
	a[v] = m;
	vis[v] = 1;
	for (ll x: edges[v]) {
		++adj[x];
		tag[x] = min(tag[x], m);
	}
	
	// cout << "rec " << v << " " << d << " " << req << " " << m << '\n';
	
	vector<ll> r(1, v);
	if (d == 0) {
		return r;
	}
	
	sort(edges[v].begin(), edges[v].end(), cmp);
		
	ll c = 0;
	for (ll i = 0; i < n && c < d; i++) {
		if (!vis[edges[v][i]] && adj[edges[v][i]] == req) {
			vector<ll> ov = rec(edges[v][i], c, req + 1, m + (1 << c));
			r = merge(r, ov);
			++c;
		}
	}
	return r;
}

void solve(int tc = 0) {
	cin >> n;
	
	ll m = (1 << n);
	
	for (ll i = 0; i < m; i++) {
		edges[i].clear();
	}
	
	for (ll i = 0; i < n * m / 2; i++) {
		cin >> x >> y;
		edges[x].push_back(y);
		edges[y].push_back(x);
	}
	
	for (ll i = 0; i < m; i++) {
		vis[i] = adj[i] = 0;
		tag[i] = 1e9;
	}
	vis[0] = 1;
	
	rec(0, n, 1, 0);
	
	for (ll i = 0; i < m; i++) b[a[i]] = i;
	
	// for (ll i = 0; i < m; i++) {
		// cout << a[i] << " ";
	// }
	// cout << '\n';
	for (ll i = 0; i < m; i++) {
		cout << b[i] << " ";
	}
	cout << '\n';
	
	if (__builtin_popcount(n) > 1) {
		cout << -1 << '\n';
	} else {
		for (ll i = 0; i < m; i++) {
			ll r = 0;
			for (ll j = 0; j < n; j++) {
				r ^= ((a[i] >> j) & 1) * j;
			}
			c[i] = r;
		}
		
		for (ll i = 0; i < m; i++) {
			cout << c[i] << " ";
		}
		cout << '\n';
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
	cin >> tc; 	
	for (int t = 0; t < tc; t++) solve(t);
	
	#ifdef galen_colin_local
		auto end = std::chrono::high_resolution_clock::now();
		cerr << setprecision(4) << fixed;
		cerr << "Execution time: " << std::chrono::duration_cast<std::chrono::duration<double>>(end - begin).count() << " seconds" << endl;
	#endif
}