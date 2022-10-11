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
const ll template_array_size = 1e6 + 17403;
ll a[template_array_size];
ll b[template_array_size];
ll c[template_array_size];
string s, t;

vector<ll> at[11];
ll dp[15][3];

ll get(ll x) {
	memset(dp, 1, sizeof(dp));
	dp[0][0] = dp[0][1] = dp[0][2] = 0;
		
	ll r = n, dig = 1, dv = 0;
	while (r > 0) {		
		ll k = r % 10;
		
		for (ll j = 0; j < 10; j++) {
			if ((x >> j) & 1) {
				if (j > k) {
					for (ll p = 0; p < 3; p++) {
						dp[dv + 1][2] = min(dp[dv + 1][2], dig * j + dp[dv][p]);
					}
				} else if (j == k) {
					for (ll p = 0; p < 3; p++) {
						dp[dv + 1][p] = min(dp[dv + 1][p], dig * j + dp[dv][p]);
					}
				} else {
					for (ll p = 0; p < 3; p++) {
						dp[dv + 1][0] = min(dp[dv + 1][0], dig * j + dp[dv][p]);
					}
				}
			}
		}
				
		dig *= 10;
		r /= 10;
		++dv;
	}
	
	// cout << v << endl;
	
	return min(dp[dv][1], dp[dv][2]);
}

ll eval(vector<ll> x) {
	ll v = 0;
	for (ll y: x) v |= (1 << y);
	return v;
}
 
void solve(int tc = 0) {
	cin >> n >> k;
	// n = 102333334, k = 10;
	
	vector<ll> dig;
	ll v = n;
	while (v > 0) {
		dig.push_back(v % 10);
		v /= 10;
	}
	reverse(dig.begin(), dig.end());
		
	vector<ll> vd;
	vector<bool> vis(10);
	
	ll ans = 1e12;
	
	for (ll x: dig) {
		if (!vis[x]) {
			vd.push_back(x);
			vis[x] = 1;
		}
		
		bool add = 0;
		if (vd.size() < k) add = 1;
		if (add) vd.push_back(0);
		
		ans = min(ans, get(eval(vd)));
		
		for (ll i = 0; i < vd.size(); i++) {
			if (vd[i] < 9) {
				++vd[i];
				ans = min(ans, get(eval(vd)));
				--vd[i];
			}
		}
		
		if (add) vd.pop_back();
		
		if (vd.size() == k) break;
	}
	
	cout << ans << '\n';
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
		
	cout << setprecision(15) << fixed;
 
	
				
	int tc = 1;
	cin >> tc; 	
	for (int t = 0; t < tc; t++) {
		solve(t);
	}
	
	#ifdef galen_colin_local
		auto end = std::chrono::high_resolution_clock::now();
		cerr << setprecision(4) << fixed;
		cerr << "Execution time: " << std::chrono::duration_cast<std::chrono::duration<double>>(end - begin).count() << " seconds" << endl;
	#endif
}