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
// const ll mod = 1000000007;
const ll mod = 998244353;
// ll mod;




ll n, m, q, k, l, r, x, y, z;
const ll template_array_size = 1e6 + 19180;
ll a[template_array_size];
ll b[template_array_size];
ll c[template_array_size];
string s, t;

ll dp[41][41][41][41];
array<ll, 3> par[41][41][41][41];

void solve(int tc = 0) {
	memset(dp, 0, sizeof(dp));
	
	ll n, A, B;
	cin >> n >> A >> B >> s;
	
	dp[0][0][0][0] = 1;
	
	for (ll i = 0; i < n; i++) {
		for (ll r = 0; r <= i; r++) {
			for (ll a = 0; a < A; a++) {
				for (ll b = 0; b < B; b++) {
					if (dp[i][r][a][b]) {
						// take red
						ll nv = (a * 10 + (s[i] - '0')) % A;
						dp[i + 1][r + 1][nv][b] = 1;
						par[i + 1][r + 1][nv][b] = {1, a, b};
					
						// take black
						nv = (b * 10 + (s[i] - '0')) % B;
						dp[i + 1][r][a][nv] = 1;
						par[i + 1][r][a][nv] = {0, a, b};
					}
				}
			}
		}
	}
	
	ll ans = 1e9, targ = -1;
	for (ll i = 1; i < n; i++) {
		if (dp[n][i][0][0]) {
			ll r = abs(i - (n - i));
			if (r < ans) {
				ans = r;
				targ = i;
			}
		}
	}
	
	if (targ == -1) cout << -1 << '\n';
	else {
		string s = "";
		ll c = targ, a = 0, b = 0;
		for (ll i = n; i > 0; i--) {
			array<ll, 3> x = par[i][c][a][b];
			s.push_back(x[0] ? 'R' : 'B');
			c -= x[0];
			a = x[1];
			b = x[2];
		}
		
		reverse(s.begin(), s.end());
		cout << s << '\n';
	}
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
	// freopen("in.txt", "r", stdin);
	// freopen("out.txt", "w", stdout);
		
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