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
// const ll mod = 1000000007;
const ll mod = 998244353;
// ll mod;
 

 
ll n, m, k, q, l, r, x, y, z;
const ll template_array_size = 1e6 + 3794;
ll a[template_array_size];
ll b[template_array_size];
ll c[template_array_size];
string s, t;
ll ans = 0;

vector<ll> f[404];
vector<pair<ll, ll>> id[404];
ll dp[404][404];
ll par1[404][404];
ll par2[404][404];
 
void solve(int tc = 0) {
	#ifndef galen_colin_local
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
	#endif
	
	ll v;
	cin >> n >> v;
	
	for (ll i = 0; i < n; i++) cin >> a[i];
	
	cin >> m;
	
	for (ll i = 0; i < m; i++) {
		cin >> l >> r >> x;
		--l; --r;
		for (ll j = l; j <= r; j++) {
			f[j].push_back(x);
			id[j].push_back(make_pair(x, i + 1));
		}
	}
	
	for (ll i = 0; i < n; i++) if (f[i].size()) {sort(f[i].begin(), f[i].end()), sort(id[i].begin(), id[i].end());}
	
	for (ll i = 0; i <= n; i++) {
		for (ll j = 0; j <= 400; j++) {
			dp[i][j] = -1e9;
		}
	}
		
	dp[0][0] = 0;
	
	for (ll i = 0; i < n; i++) { // day
		ll s = f[i].size();
		ll stop = 0;
		if (i > 0) stop = a[i - 1];
		for (ll j = 0; j <= stop; j++) { // prev
			ll sum = v;
			for (ll k = 0; k <= s; k++) { // # people
				ll next = a[i];
				ll prev = j - sum;
				if (prev < 0) next += prev;
				if (next >= 0) {
					ll val = dp[i][j] + k;
					if (val > dp[i + 1][next]) {
						dp[i + 1][next] = val;
						par1[i + 1][next] = j;
						par2[i + 1][next] = k;
					}
				} else break;
				
				if (k < s) sum += f[i][k];
			}
		}
	}
			
	ll targ = 0;
	for (ll i = 1; i <= 400; i++) if (dp[n][i] > dp[n][targ]) targ = i;
	cout << dp[n][targ] << '\n';
	// cout << targ << endl;
	vector<ll> inds[n];
	for (ll i = n; i > 0; i--) {
		for (ll j = 0; j < par2[i][targ]; j++) inds[i - 1].push_back(id[i - 1][j].s);
		targ = par1[i][targ];
	}
	
	for (ll i = 0; i < n; i++) {
		cout << inds[i].size();
		for (ll j: inds[i]) cout << " " << j;
		cout << '\n';
	}
}

int main() {
	#ifdef galen_colin_local
		auto begin = std::chrono::high_resolution_clock::now();
	#endif
	
	send help
 
	#ifndef galen_colin_local
		// usaco("cowpatibility");
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