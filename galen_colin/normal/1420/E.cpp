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
// const ll mod = 1000000007;
const ll mod = 998244353;
// ll mod;
 
 
 
ll n, m, k, q, l, r, x, y, z;
const ll template_array_size = 1e6 + 1600;
ll a[template_array_size];
ll b[template_array_size];
ll c[template_array_size];
string s, t;
ll ans = 0;

// size is:
// number of groups + 1: (MAXN + 2 - 1) + 1 = 82, 
// number of possible balances: 2 * MAXN + 1 = 161,
// number of possible moves: MAXN * (MAXN - 1) / 2 = 3161
ll dp[82][161][3161]; // (position, unfilled + n, #moves) = min # of 0-pairs
 
void solve(int tc = 0) {
	cin >> n;
	
	vector<ll> a = {1};
	ll cnt[2] = {0};
	for (ll i = 0; i < n; i++) {
		cin >> x;
		a.push_back(x);
		++cnt[x];
	}
	a.push_back(1);
	
	vector<ll> groups;
		
	ll pt = 0;
	for (ll i = 1; i < a.size(); i++) {
		if (a[i] == 1) {
			groups.push_back(i - pt - 1);
			pt = i;
		}
	}
	
	ll g = groups.size();
	ll mx = n * (n - 1) / 2;
	
	const ll inf = 1e9;
	
	for (ll i = 0; i <= g; i++) {
		for (ll j = 0; j <= 2 * n; j++) {
			for (ll k = 0; k <= mx; k++) {
				dp[i][j][k] = inf;
			}
		}
	}

	dp[0][n][0] = 0;
	
	for (ll i = 0; i < g; i++) {
		for (ll j = 0; j <= 2 * n; j++) {
			for (ll k = 0; k <= mx; k++) {
				if (dp[i][j][k] != inf) {
					for (ll nval = 0; nval <= n; nval++) {
						ll change = nval - groups[i];
						ll new_unfilled = j - n - change;
						
						if (-n <= new_unfilled && new_unfilled <= n) {
							ll new_moves = k + abs(new_unfilled);
							if (new_moves <= mx) {
								dp[i + 1][new_unfilled + n][new_moves] = min(dp[i + 1][new_unfilled + n][new_moves], dp[i][j][k] + nval * (nval - 1) / 2);
							}
						}
					}
				}
			}
		}
	}
	
	ll pairs_01_10 = cnt[0] * cnt[1];
	ll pairs_11 = cnt[1] * (cnt[1] - 1) / 2;
	ll total_pairs = pairs_01_10 + pairs_11;
		
	ll cur = inf;
	for (ll i = 0; i <= mx; i++) {
		cur = min(cur, dp[g][n][i]);
		cout << n * (n - 1) / 2 - total_pairs - cur << " ";
	}
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