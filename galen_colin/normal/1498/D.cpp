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



ll n, m, q, k, l, r, x, y, z;
const ll template_array_size = 1e6 + 14742;
ll a[template_array_size];
ll b[template_array_size];
ll c[template_array_size];
string s, t;
ll ans = 0;	

ll res[100005];
ll dp[100005];
ll val[100005];
ll pref[100005];
vector<ll> ch[100005];
bool vis[100005];

ll dfs(ll v) {
	if (vis[v]) return val[v];
	vis[v] = 1;
	
	val[v] = -1;
	if (dp[v]) val[v] = y;
	
	for (ll x: ch[v]) {
		val[v] = max(val[v], dfs(x) - 1);
	}
	return val[v];
}

void solve(int tc = 0) {	
	cin >> n >> m;
	
	memset(res, 1, sizeof(res)); // inf
	dp[0] = 1;
	
	for (ll i = 0; i < n; i++) {
		ll t;
		cin >> t >> x >> y;
		if (t == 1) {
			x = (x + 100000 - 1) / 100000;
			memset(pref, 0, sizeof(pref));
			
			for (ll j = 0; j <= m; j++) {
				pref[j % x] += dp[j];
				
				ll exc = j - (y + 1) * x;
				
				if (exc >= 0) pref[exc % x] -= dp[exc];
				
				val[j] = pref[j % x];
			}
			
			for (ll j = 1; j <= m; j++) {
				dp[j] |= (val[j] > 0);
				if (dp[j]) res[j] = min(res[j], i + 1);
			}
		} else {
			for (ll j = 0; j <= m; j++) ch[j].clear();
			
			for (ll j = 0; j <= m; j++) {
				ll par = (j * x + 100000 - 1) / 100000;
				if (par <= m && par > j) {
					ch[par].push_back(j);
				}
			}
			
			memset(vis, 0, sizeof(vis));
			for (ll j = m; j >= 0; j--) {
				if (!vis[j]) {
					dfs(j);
				}
			}
			
			for (ll j = 1; j <= m; j++) {
				dp[j] |= (val[j] >= 0);
				if (dp[j]) res[j] = min(res[j], i + 1);
			}
		}
	}
	
	for (ll i = 1; i <= m; i++) {
		if (res[i] > 1e7) {
			res[i] = -1;
		}
		cout << res[i] << " ";
	}
	cout << '\n';
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
		// cerr << "Execution time: " << std::chrono::duration_cast<std::chrono::duration<double>>(end - begin).count() << " seconds" << endl;
	#endif
}