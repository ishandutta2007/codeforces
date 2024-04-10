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
 
// mt19937_64 rng(std::chrono::steady_clock::now().time_since_epoch().count());
mt19937_64 rng(61378913);
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
const ll template_array_size = 1e6 + 8331;
ll a[template_array_size];
ll b[template_array_size];
ll c[template_array_size];
string s, t;
ll ans = 0;	

vector<ll> child[200005];
vector<ll> edges[200005];
vector<ll> at[200005];
ll dp[200005];

ll maxd;

void dfs(ll v, ll p, ll d) {
	maxd = max(maxd, d);
	at[d].push_back(v);
	for (ll x: edges[v]) {
		if (x != p) {
			dfs(x, v, d + 1);
			child[v].push_back(x);
		}
	}
}

void solve(int tc = 0) {
	cin >> n;
	
	for (ll i = 0; i < n; i++) {
		child[i].clear();
		edges[i].clear();
		at[i].clear();
	}
	
	for (ll i = 0; i < n - 1; i++) {
		cin >> x;
		--x;
		edges[i + 1].push_back(x);
		edges[x].push_back(i + 1);
	}
	
	a[0] = 0;
	for (ll i = 1; i < n; i++) cin >> a[i];
	
	maxd = 0;
	dfs(0, -1, 0);
	++maxd;
	
	// for (ll i = 0; i < maxd; i++) cout << at[i] << endl;
	
	for (ll i = 0; i < n; i++) dp[i] = 0;
	
	for (ll i = 0; i + 1 < maxd; i++) {
		ll mn = 2e9, mx = -1;
		for (ll j: at[i + 1]) {
			mn = min(mn, a[j]);
			mx = max(mx, a[j]);
		}
		
		for (ll j: at[i]) {
			for (ll k: child[j]) {
				ll far = max(a[k] - mn, mx - a[k]);
				
				dp[k] = max(dp[k], dp[j] + far);
			}
		}
		
		mn = 1e17, mx = -1e17;
		for (ll j: at[i]) {
			ll mv = 2e9, xv = -2e9;
			for (ll k: child[j]) {
				mv = min(mv, a[k]);
				xv = max(xv, a[k]);
			}
			mn = min(mn, mv - dp[j]);
			mx = max(mx, dp[j] + xv);
		}
		
		for (ll j: at[i + 1]) {
			dp[j] = max({dp[j], mx - a[j], a[j] - mn});
		}
	}
	
	// cout << "DP ";
	// for (ll i = 0; i < n; i++) cout << dp[i] << " ";
	// cout << endl;
	
	ll ans = 0;
	for (ll x: at[maxd - 1]) ans = max(ans, dp[x]);
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
	// freopen("tc.cpp", "w", stdout);
 		
	cout << setprecision(12) << fixed;
					
	int tc = 1;
	cin >> tc;
	for (int t = 0; t < tc; t++) solve(t);
	
	#ifdef galen_colin_local
		auto end = std::chrono::high_resolution_clock::now();
		cerr << setprecision(4) << fixed;
		// cerr << "Execution time: " << std::chrono::duration_cast<std::chrono::duration<double>>(end - begin).count() << " seconds" << endl;
	#endif
}