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
 
const lld pi = 3.14159265358979323846;
const ll mod = 1000000007;
// const ll mod = 998244353;
// ll mod;
 


ll n, m, k, q, l, r, x, y, z;
const ll template_array_size = 1e6 + 923;
ll a[template_array_size];
ll b[template_array_size];
ll c[template_array_size];
string s, t;
ll ans = 0;

ll dp[1000005][2];
const ll inf = 3e18;
ll suf[1000005];

void solve(int tc = 0) {	
	cin >> n >> x >> y >> z >> k;
	
	for (ll i = 0; i < n; i++) cin >> a[i];
	
	for (ll i = 0; i < n; i++) {
		b[i] = min({x * (a[i] + 2), x + y, x * a[i] + z});
		// cout << b[i] << " ";
	}
	// cout << endl;
	
	ll r = 0;
	for (ll i = n - 1; i >= 0; i--) {
		r += b[i];
		suf[i] = r;
		suf[i] -= b[n - 1];
		
		ll c1 = inf;
		if (i < n - 1) c1 = 2 * k * (n - 1 - i);
		ll c2 = 2 * k + k * (n - 1 - i);
		suf[i] = min(suf[i] + min(c1, c2) + b[n - 1], suf[i] + x * a[n - 1] + z + k * (n - 1 - i));
		// cout << suf[i] << " ";
	}
	// cout << endl;
	
	for (ll i = 0; i <= n; i++) {
		for (ll j = 0; j < 2; j++) {
			dp[i][j] = inf;
		}
	}
	
	dp[0][0] = 0;
	
	for (ll i = 0; i < n; i++) {
		// case 1 - kill boss
		
		ll c = x * a[i] + z;
		dp[i + 1][0] = min(dp[i + 1][0], dp[i][0] + c);
		dp[i + 1][0] = min(dp[i + 1][0], dp[i][1] + c);
		dp[i + 1][1] = min(dp[i + 1][1], dp[i][0] + c + 2 * k);
		
		// case 2 - don't
		
		c = min(x * (a[i] + 2), x + y);
		dp[i + 1][0] = min(dp[i + 1][0], dp[i][0] + c + 2 * k);
		dp[i + 1][0] = min(dp[i + 1][0], dp[i][1] + c);
		dp[i + 1][1] = min(dp[i + 1][1], dp[i][0] + c + 2 * k);
		dp[i + 1][1] = min(dp[i + 1][1], dp[i][1] + c + 2 * k);
		
		// cout << i << " " << dp[i][0] << " " << dp[i][1] << " " << suf[i] << endl;
	}
	
	ll ans = k * (n - 1);
	
	ll best = inf;
	for (ll i = 0; i < n; i++) {
		// ll c = 0;
		// if (i < n - 1) c = suf[i];
		best = min(best, dp[i][0] + suf[i]);
	}
	
	cout << ans + best << '\n';
}
 
int main() {
	#ifdef galen_colin_local
		auto begin = std::chrono::high_resolution_clock::now();
	#endif
	
	send help
 
	#ifndef galen_colin_local
		// usaco("cowland");
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