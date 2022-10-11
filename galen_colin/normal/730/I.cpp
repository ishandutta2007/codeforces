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
const ll template_array_size = 1e6 + 1193;
ll a[template_array_size];
ll b[template_array_size];
ll c[template_array_size];
string s, t;
ll ans = 0;

pair<pair<ll, ll>, ll> p[3005];
ll dp[3005][3005];
bool trans[3005][3005];
const ll inf = 2e17;

void solve(int tc = 0) {
	cin >> n >> m >> k;
	
	for (ll i = 0; i < n; i++) cin >> p[i].f.f;
	for (ll i = 0; i < n; i++) cin >> p[i].f.s;
	for (ll i = 0; i < n; i++) p[i].s = i + 1;
	
	sort(p, p + n);
	reverse(p, p + n);
	
	for (ll i = 0; i <= n; i++) {
		for (ll j = 0; j <= n; j++) {
			dp[i][j] = 0;
		}
	}
	
	for (ll i = 0; i < n; i++) {
		for (ll j = 0; j <= i; j++) {
			ll taken_first = i - j;
			ll val = 0;
			if (taken_first < m) {
				val = p[i].f.f;
			}
			if (dp[i][j] + val > dp[i + 1][j]) {
				dp[i + 1][j] = dp[i][j] + val;
				trans[i + 1][j] = 0;
			}
			
			if (dp[i][j] + p[i].f.s > dp[i + 1][j + 1]) {
				dp[i + 1][j + 1] = dp[i][j] + p[i].f.s;
				trans[i + 1][j + 1] = 1;
			}
		}
	}
	
	cout << dp[n][k] << '\n';
	
	vector<ll> prog, sport;
	ll cur = k;
	for (ll i = n; i > 0; i--) {
		if (trans[i][cur] == 0) {
			ll taken_first = i - cur;
			if (taken_first <= m) {
				prog.push_back(p[i - 1].s);
			}
		} else {
			sport.push_back(p[i - 1].s);
			--cur;
		}
	}
	
	for (ll x: prog) cout << x << " ";
	cout << '\n';
	for (ll x: sport) cout << x << " ";
	cout << '\n';
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