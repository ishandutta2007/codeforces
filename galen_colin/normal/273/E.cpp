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
 
ll dp[1005][4];
ll cnt[3];

ll gs(ll x) {
	return x * (x + 1) / 2;
}

ll gcnt(ll l, ll r) {
	return k * (r - l + 1) - gs(r) + gs(l - 1);
}
 
void solve(int tc = 0) {
	cin >> n >> k;
	
	vector<pair<ll, ll>> at = {{0, 2}, {1, 1}, {2, 1}, {1, 2}, {2, 2}, {0, 4}, {1, 2}, {2, 4}, {0, 8}, {1, 12}, {2, 1}, {0, 17}, {2, 1}, {1, 23}, {2, 4}, {0, 35}, {2, 1}, {1, 53}, {2, 5}, {0, 76}, {2, 5}, {1, 103}, {2, 19}, {0, 155}, {2, 7}, {1, 236}, {2, 25}, {0, 341}, {2, 23}, {1, 463}, {2, 86}, {0, 697}, {2, 32}, {1, 1060}, {2, 115}, {0, 1532}, {2, 106}, {1, 2081}, {2, 389}, {0, 3136}, {2, 145}, {1, 4769}, {2, 518}, {0, 6892}, {2, 479}, {1, 9364}, {2, 1751}, {0, 14110}, {2, 655}, {1, 21458}, {2, 2333}, {0, 31012}, {2, 2158}, {1, 42137}, {2, 7880}, {0, 63493}, {2, 2950}, {1, 96560}, {2, 10499}, {0, 139552}, {2, 9713}, {1, 189616}, {2, 35461}, {0, 285716}, {2, 13277}, {1, 434518}, {2, 47248}, {0, 627983}, {2, 43709}, {1, 853270}, {2, 159577}, {0, 1285721}, {2, 59747}, {1, 1955329}, {2, 212618}, {0, 2825923}, {2, 196691}, {1, 3839713}, {2, 718099}, {0, 5785742}, {2, 268864}, {1, 8798978}, {2, 956783}, {0, 12716653}, {2, 885110}, {1, 17278708}, {2, 3231446}, {0, 26035837}, {2, 1209890}, {1, 39595399}, {2, 4305526}, {0, 57224936}, {2, 3982997}, {1, 77754184}, {2, 14541509}, {0, 117161266}, {2, 5444506}, {1, 178179293}, {2, 19374869}, {0, 257512210}, {2, 17923489}, {1, 115568295}};
	ll pos = 1;
	for (ll i = 0; i < at.size(); i++) {
		ll nxt = pos + at[i].s;
		
		// cout << at[i] << " " << pos << endl;
		if (nxt < k) {
			cnt[at[i].f] = (cnt[at[i].f] + gcnt(pos, pos + at[i].s - 1)) % mod;
			pos = nxt;
		} else {
			cnt[at[i].f] = (cnt[at[i].f] + gcnt(pos, k)) % mod;
			break;
		}
	}
	
	// cout << cnt[0] << " " << cnt[1] << " " << cnt[2] << endl;
			
	dp[0][0] = 1;
		
	for (ll i = 1; i <= n; i++) {
		for (ll j = 0; j < 4; j++) {
			for (ll v = 0; v < 3; v++) {
				dp[i][j] = (dp[i][j] + dp[i - 1][j ^ v] * cnt[v]) % mod;
			}
		}
	}
	
	cout << (dp[n][1] + dp[n][2] + dp[n][3]) % mod << '\n';
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