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
 
// const lld pi = 3.14159265358979323846;
// const ll mod = 1000000007;
// const ll mod = 998244353;
// ll mod;


 
ll n, m, q, k, l, r, x, y, z;
const ll template_array_size = 1e6 + 15075;
ll a[template_array_size];
ll b[template_array_size];
ll c[template_array_size];
string s, t;
ll ans = 1e18;

vector<ll> edges[200005];
ll dp[200005][2]; // 0 - inc, 1 - dec

void dfs(ll v, ll p) {
	ll s = 0, ct[2];
	ct[0] = ct[1] = 0;
	vector<ll> at;
	for (ll x: edges[v]) {
		if (x != p) {
			dfs(x, v);
						
			if (b[x] < b[v]) {
				++ct[0];
				s += dp[x][0];
			} else if (b[x] > b[v]) {
				++ct[1];
				s += dp[x][1];
			} else {
				++ct[0];
				s += dp[x][0];
				at.push_back(dp[x][1] - dp[x][0]);
			}
		}
	}
	
	dp[v][0] = dp[v][1] = 1e18;
	
	sort(at.begin(), at.end());
	for (ll i = 0; i <= at.size(); i++) {
		// cout << v << " " << s << " " << a[v] << " " << b[v] << " " << ct[0] << " " << ct[1] << endl;
		if (v == 0) ans = min(ans, s + a[v] * max(ct[0], ct[1]));
		
		dp[v][0] = min(dp[v][0], s + a[v] * (max(ct[0], ct[1]) + (ct[0] <= ct[1])));
		dp[v][1] = min(dp[v][1], s + a[v] * (max(ct[0], ct[1]) + (ct[1] <= ct[0])));
		
		if (i == at.size()) break;
		--ct[0];
		++ct[1];
		s += at[i];
	}
	
	// cout << v << " " << dp[v][0] << " " << dp[v][1] << endl;
}

void solve(int tc = 0) {
	cin >> n;
	for (ll i = 0; i < n; i++) cin >> a[i];
	for (ll i = 0; i < n; i++) cin >> b[i];
	
	for (ll i = 0; i < n - 1; i++) {
		cin >> x >> y;
		--x; --y;
		edges[x].push_back(y);
		edges[y].push_back(x);
	}
	
	ans = 1e18;
	dfs(0, -1);
	
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
	// cin >> tc;
	for (int t = 0; t < tc; t++) solve(t);
	
	#ifdef galen_colin_local
		auto end = std::chrono::high_resolution_clock::now();
		cerr << setprecision(4) << fixed;
		cerr << "Execution time: " << std::chrono::duration_cast<std::chrono::duration<double>>(end - begin).count() << " seconds" << endl;
	#endif
}