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
// const ll mod = 1000000007;
const ll mod = 998244353;
// ll mod;



ll n, m, k, q, l, r, x, y, z;
const ll template_array_size = 1e6 + 14096;
ll a[template_array_size];
ll b[template_array_size];
ll c[template_array_size];
string s, t;
ll ans = 0;	

template<class T>
void add(T& a, ll b) {
	a += b;
	while (a < 0) a += mod;
	while (a >= mod) a -= mod;
}

ll dp[5005][5005];
vector<ll> edges[5005];
ll sz[5005];

void dfs(ll v, ll p) {
	vector<ll> e;
	
	sz[v] = 1;
	
	for (ll x: edges[v]) {
		if (x != p) {
			dfs(x, v);
			e.push_back(x);
			sz[v] += sz[x];
		}
	}
	
	dp[v][0] = 1;
	
	for (ll i = 0; i < e.size(); i++) {
		ll x = e[i];
		dp[v][0] = (dp[v][0] * dp[x][k]) % mod;
		for (ll j = 0; j < min(sz[x] + 1, k); j++) {
			ll p = dp[x][j];
			if (j > 0) add(p, -dp[x][j - 1]);
			for (ll y = 0; y < i; y++) {
				ll req = min(j - 1, k - (j + 1) - 1);
				ll v = dp[e[y]][k];
				if (req >= 0) add(v, dp[e[y]][req]);
				p = (p * v) % mod;
			}
			for (ll y = i + 1; y < e.size(); y++) {
				ll req = min(j, k - (j + 1) - 1);
				ll v = dp[e[y]][k];
				if (req >= 0) add(v, dp[e[y]][req]);
				p = (p * v) % mod;
			}
			add(dp[v][j + 1], p);			
		}
	}
	
	for (ll i = 1; i <= k; i++) add(dp[v][i], dp[v][i - 1]);
}

void solve(int tc = 0) {
	cin >> n >> k;
	
	for (ll i = 0; i < n - 1; i++) {
		cin >> x >> y;
		--x; --y;
		edges[x].push_back(y);
		edges[y].push_back(x);
	}
	
	dfs(0, -1);
	
	ll ans = 0;
	cout << dp[0][k] << '\n';
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