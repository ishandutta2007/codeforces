#include <bits/stdc++.h>
using namespace std;
 
#define send {ios_base::sync_with_stdio(false);}
#define help {cin.tie(NULL); cout.tie(NULL);}
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
 
mt19937 rng(std::chrono::steady_clock::now().time_since_epoch().count());
// mt19937 rng(61378913);
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
 
struct bit {
  int n;
  vector<ll> a;
 
  void init(int s) {
    a = vector<ll>(s + 1, 0);
    n = s;
  }
 
  void add(int loc, ll x) {
    if (loc <= 0) return;
    while (loc <= n) {
      a[loc] += x;
      loc += loc & (-loc);
    }
  }
 
  ll query(int loc) {
    ll sum = 0;
    while (loc > 0) {
      sum += a[loc];
      loc -= loc & (-loc);
    }
    return sum;
  }
  
  #pragma message("BITs are 1-indexed, be careful")
};
 
ll n, m, k, q, l, r, x, y, z;
const ll template_array_size = 1e6 + 2211;
ll a[template_array_size];
ll b[template_array_size];
ll c[template_array_size];
string s, t;
ll ans = 0;
 

 
void solve(int tc = 0) {
	cin >> n >> k;
	
	ll l[n], r[n], a[n];
	
	for (ll i = 0; i < n; i++) cin >> l[i] >> r[i] >> a[i];
	
	ll inf = 1e17;
	ll dp[n], ans = inf;
	
	for (ll i = 0; i < n; i++) dp[i] = inf;
	dp[0] = 0;
	
	for (ll i = 0; i < n; i++) {
		if (dp[i] != inf) {
			ll run = k;
			ll tot = dp[i];
			bool pos = 1;
			
			for (ll j = i; j < n; j++) {
				ll x = (a[j] - run + k - 1) / k;
				
				// cout << x << '\n';
				
				ll p = l[j] + x;
				
				if (p > r[j]) {
					pos = 0;
					break;
				}
				
				tot += a[j];
				run = (run - a[j]) % k;
				run = (run + k) % k;
				
				if (j < n - 1 && p < l[j + 1]) {
					dp[j + 1] = min(dp[j + 1], tot + run);
				}
			}
			
			if (pos) {
				ans = min(ans, tot);
			}
			// cout << i << " " << tot << '\n';
		}
		// cout << i << " " << dp[i] << '\n';
	}
	
	if (ans == inf) ans = -1;
	
	cout << ans << '\n';
}
 
int main() {
	#ifdef galen_colin_local
		auto begin = std::chrono::high_resolution_clock::now();
	#endif
	
	send help
 
	#ifndef galen_colin_local
		// usaco("moop");
	#endif
	
	// usaco("cowland");
	
	// freopen("tc.cpp", "r", stdin);
 
	
	
	int tc = 1;
	// cin >> tc;
	for (int t = 0; t < tc; t++) solve(t);
	
	#ifdef galen_colin_local
		auto end = std::chrono::high_resolution_clock::now();
		cout << setprecision(4) << fixed;
		// cout << "Execution time: " << std::chrono::duration_cast<std::chrono::duration<double>>(end - begin).count() << " seconds" << endl;
	#endif
}