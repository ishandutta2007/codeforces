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
const ll template_array_size = 1e6 + 16318;
ll a[template_array_size];
ll b[template_array_size];
ll c[template_array_size];
string s, t;
ll ans = 0;

string v[1005];
ll dp[1005][1005]; // dp(i, j) -> last i digits, with j carries
ll lp[1005];
ll sz[1005];

ll d;
bool cmpv(ll a, ll b) {
	ll va = 0;
	if (d < v[a].size()) va = v[a][d];
	ll vb = 0;
	if (d < v[b].size()) vb = v[b][d];
	
	if (va == vb) return lp[a] < lp[b];
	return va > vb;
}

void solve(int tc = 0) {
	cin >> s >> n;
	reverse(s.begin(), s.end());
	
	iota(lp, lp + n, 0);
	
	ll m = s.length();
	
	for (ll i = 0; i < n; i++) {
		cin >> v[i];
		reverse(v[i].begin(), v[i].end());
		m = max(m, ll(v[i].length()));
	}
	
	vector<ll> cost(10);
	for (ll i = 0; i < 10; i++) cin >> cost[i];
	
	++m; // add 0 on end
		
	ll last = -1; // stupid leading zeroes...
	bool val = 0;
	for (ll i = s.length() - 1; i >= 0; i--) {
		if (s[i] != '?' && s[i] != '0') val = 1;
		if (s[i] == '?' && !val) {
			last = i;
			break;
		}
	}
		
	for (ll i = 0; i < n; i++) {
		while (v[i].size() < s.size()) v[i] += '0';
		sz[i] = v[i].size();
	}
	
	for (ll i = 0; i <= m; i++) {
		for (ll j = 0; j <= n; j++) {
			dp[i][j] = -1e13;
		}
	}
	dp[0][0] = 0;
	
	vector<ll> nv(n);
	iota(nv.begin(), nv.end(), 0);
	
	for (ll i = 0; i < m; i++) {
		vector<ll> at(11);
		
		for (ll j = 0; j < n; j++) {
			ll p = nv[j];
			if (i < sz[p]) ++at[v[p][i] - '0'];
		}
				
		for (ll j = 0; j <= n; j++) {
			if (j) {
				ll p = nv[j - 1];
				if (i < sz[p]) {
					--at[v[p][i] - '0'];
					++at[v[p][i] - '0' + 1];
				} else {
					if (i == sz[p]) ++at[1];
				}
			}
			
			for (ll k = 0; k < 10; k++) {
				if (i < s.size() || k == 0) {
					if (i >= s.size() || s[i] == '?' || s[i] - '0' == k) {
						if (k || i != last) {
							ll tot = 0, cnt = 0;
							
							for (ll l = 0; l <= 10; l++) {
								tot += at[l] * cost[(l + k) % 10];
								cnt += at[l] * ((l + k) / 10);
							}
														
							dp[i + 1][cnt] = max(dp[i + 1][cnt], dp[i][j] + tot);
						}
					}
				}
			}
		}
		
		d = i;
		sort(nv.begin(), nv.end(), cmpv);
		
		for (ll j = 0; j < n; j++) {
			lp[nv[j]] = j;
		}
	}
	
	ll ans = 0;
	for (ll i = 0; i <= n; i++) ans = max(ans, dp[m][i]);
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