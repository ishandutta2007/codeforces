#include "bits/stdc++.h"
using namespace std;
#pragma GCC target("avx2")
#pragma GCC optimization ("unroll-loops")
 
/* 
find my code templates at https://github.com/galencolin/cp-templates
also maybe subscribe please thanks 
*/
 
#define send {ios_base::sync_with_stdio(false);}
#define help {cin.tie(NULL);}
#define f first
#define s second
#define getunique(v) {sort(v.begin(), v.end()); v.erase(unique(v.begin(), v.end()), v.end());}
typedef int ll;
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
const ll template_array_size = 1e6 + 15258;
ll a[template_array_size];
ll b[template_array_size];
ll c[template_array_size];
string s, t;
 
ll ans[505][505];
ll rv[505][505], dv[505][505];
pair<ll, ll> at[1005];
ll dp[505][505][12];
ll medge[505][505];

void solve(int tc = 0) {
	cin >> n >> m >> k;
	
	for (ll i = 0; i < n; i++) {
		for (ll j = 0; j < m - 1; j++) {
			cin >> rv[i][j];
			// rv[i][j] = rng() % 1000000;
		}
	}
	
	for (ll i = 0; i < n - 1; i++) {
		for (ll j = 0; j < m; j++) {
			cin >> dv[i][j];
			// dv[i][j] = rng() % 1000000;
		}
	}
	
	for (ll i = 0; i < n; i++) {
		for (ll j = 0; j < m; j++) {
			ll x = 1e9;
			if (i > 0) x = min(x, dv[i - 1][j]);
			if (i < n - 1) x = min(x, dv[i][j]);
			if (j > 0) x = min(x, rv[i][j - 1]);
			if (j < m - 1) x = min(x, rv[i][j]);
			medge[i][j] = x;
		}
	}
	
	if (k % 2 == 1) {
		for (ll i = 0; i < n; i++) {
			for (ll j = 0; j < m; j++) {
				cout << -1 << " ";
			}
			cout << '\n';
		}
		return;
	}
	
	ll v = k / 2;
	
	for (ll i = 0; i < n; i++) {
		for (ll j = 0; j < m; j++) {
			ll res = 1e9;
			
			ll ev = 0;
			for (ll ii = max(0, i - v); ii <= min(n - 1, i + v); ii++) {
				for (ll jj = max(0, j - v); jj <= min(m - 1, j + v); jj++) {
					ll d = abs(ii - i) + abs(jj - j);
					
					if (d < v) {
						at[ev++] = {ii, jj};
					}
				}
			}
			
			const ll sent = 1e9;
			for (ll ii = 0; ii < ev; ii++) {
				pair<ll, ll> x = at[ii];
				for (ll j = 0; j < v; j++) {
					dp[x.f][x.s][j] = sent;
				}
			}
			
			dp[i][j][0] = 0;
			
			for (ll j = 0; j < v; j++) {
				for (ll ii = 0; ii < ev; ii++) {
					pair<ll, ll> x = at[ii];
					
					if (dp[x.f][x.s][j] != sent) {
						res = min(res, 2 * (dp[x.f][x.s][j] + (v - j) * medge[x.f][x.s]));
						
						// cout << j << " " << x << " " << dp[x.f][x.s][j] << " " << medge[x.f][x.s] << " " << endl;
					}
				}
				
				if (j == v - 1) break;
				
				for (ll ii = 0; ii < ev; ii++) {
					pair<ll, ll> x = at[ii];
					
					if (dp[x.f][x.s][j] != sent) {
						if (x.f > 0) dp[x.f - 1][x.s][j + 1] = min(dp[x.f - 1][x.s][j + 1], dv[x.f - 1][x.s] + dp[x.f][x.s][j]);
						if (x.f < n - 1) dp[x.f + 1][x.s][j + 1] = min(dp[x.f + 1][x.s][j + 1], dv[x.f][x.s] + dp[x.f][x.s][j]);
						if (x.s > 0) dp[x.f][x.s - 1][j + 1] = min(dp[x.f][x.s - 1][j + 1], rv[x.f][x.s - 1] + dp[x.f][x.s][j]);
						if (x.s < m - 1) dp[x.f][x.s + 1][j + 1] = min(dp[x.f][x.s + 1][j + 1], rv[x.f][x.s] + dp[x.f][x.s][j]);
					}
				}
			}
			
			ans[i][j] = res;
		}
	}
	
	for (ll i = 0; i < n; i++) {
			for (ll j = 0; j < m; j++) {
			cout << ans[i][j] << " ";
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
	// cin >> tc;
	for (int t = 0; t < tc; t++) solve(t);
	
	#ifdef galen_colin_local
		auto end = std::chrono::high_resolution_clock::now();
		cerr << setprecision(4) << fixed;
		cerr << "Execution time: " << std::chrono::duration_cast<std::chrono::duration<double>>(end - begin).count() << " seconds" << endl;
	#endif
}