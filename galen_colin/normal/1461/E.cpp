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
const ll template_array_size = 1e6 + 6304;
ll a[template_array_size];
ll b[template_array_size];
ll c[template_array_size];
string s, t;
ll ans = 0;

ll worst[1000005];
bool vis[1000005];

void end(bool b) {
	cout << (b ? "Yes\n" : "No\n");
	exit(0);
}

void solve(int tc = 0) {
	ll t;
	cin >> k >> l >> r >> t >> x >> y;
	
	if (x > y) {
		if (k + y <= r) k += y;
		ll m = x - y;
		ll v = l - (l % m) + (k % m);
		if (v >= l) v -= m;
		end((k - (v + x)) / m >= t);
	}
		
	for (ll i = 0; i < x; i++) {
		ll v = l - (l % x) + i;
		if (v < l) v += x;
		worst[i] = v;
	}
	
	memset(vis, 0, sizeof(vis));
	
	ll tot = 0;
	while (1) {
		ll m = k % x;
		if (vis[m]) end(1);
		vis[m] = 1;
		
		tot += (k - worst[m]) / x;
		k = worst[m];
		if (k + y > r) end(tot >= t);
		k += y;
	}
}

int main() {
	#ifdef galen_colin_local
		auto begin = std::chrono::high_resolution_clock::now();
	#endif
	
	send help
 
	#ifndef galen_colin_local
		// usaco("cowpatibility");
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
		cout << setprecision(4) << fixed;
		// cout << "Execution time: " << std::chrono::duration_cast<std::chrono::duration<double>>(end - begin).count() << " seconds" << endl;
	#endif
}