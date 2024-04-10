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
// const ll mod = 998244353;
// ll mod;



ll n, m, q, k, l, r, x, y, z;
const ll template_array_size = 1e6 + 14742;
ll a[template_array_size];
ll b[template_array_size];
ll c[template_array_size];
string s, t;
ll ans = 0;	

ll cost[105][105];
ll dp[105][105][105];

void solve(int tc = 0) {	
	cin >> n >> m >> k;
	
	for (ll i = 0; i < n; i++) cin >> a[i];
	
	memset(dp, 1, sizeof(dp));
	ll sent = dp[0][0][0];
	
	dp[0][m + 1][0] = 0;
	for (ll i = 0; i < n; i++) {
		for (ll j = 0; j < m; j++) cin >> cost[i][j];
		
		for (ll prev = 0; prev <= m + 1; prev++) {
			for (ll pk = 0; pk <= k; pk++) {
				// cout << i << " " << prev << " " << pk << " " << dp[i][prev][pk] << endl;
				if (a[i] > 0) {
					ll cur = pk + (prev != a[i]);
					
					ll tcost = dp[i][prev][pk];
					
					dp[i + 1][a[i]][cur] = min(dp[i + 1][a[i]][cur], tcost);
				} else {
					for (ll nv = 1; nv <= m; nv++) {
						ll cur = pk + (nv != prev);
					
						ll tcost = dp[i][prev][pk] + cost[i][nv - 1];
						dp[i + 1][nv][cur] = min(dp[i + 1][nv][cur], tcost);
					}
				}
			}
		}
	}
	
	ll ans = sent;
	for (ll i = 1; i <= m; i++) ans = min(ans, dp[n][i][k]);
	
	if (ans == sent) ans = -1;
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
		// cerr << "Execution time: " << std::chrono::duration_cast<std::chrono::duration<double>>(end - begin).count() << " seconds" << endl;
	#endif
}