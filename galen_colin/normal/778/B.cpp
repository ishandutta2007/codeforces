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
// const ll mod = 998244353;
// ll mod;


 
ll n, m, q, k, l, r, x, y, z;
const ll template_array_size = 1e6 + 16318;
ll a[template_array_size];
ll b[template_array_size];
ll c[template_array_size];
string s, t;
ll ans = 0;

string op[5005];
string val[5005];
pair<ll, ll> dep[5005];
map<string, ll> rev;
ll dp[5005];

ll check(ll x, ll p, ll t) {
	if (x == -1) return t;
	if (dp[x] != -1) return dp[x];
	
	if (op[x] == "=") return dp[x] = val[x][p] - '0';
	else if (op[x] == "OR") return dp[x] = check(dep[x].f, p, t) | check(dep[x].s, p, t);
	else if (op[x] == "AND") return dp[x] = check(dep[x].f, p, t) & check(dep[x].s, p, t);
	else return dp[x] = check(dep[x].f, p, t) ^ check(dep[x].s, p, t);
}

void solve(int tc = 0) {
	cin >> n >> m;
	string v;
	getline(cin, v);
	
	rev["?"] = -1;
	
	for (ll i = 0; i < n; i++) {
		vector<string> x;
		getline(cin, v);
		istringstream is(v);
		while (is >> v) {
			x.push_back(v);
		}
		
		rev[x[0]] = i;
		
		if (x.size() == 3) {
			op[i] = "=";
			val[i] = x[2];
		} else {
			op[i] = x[3];
			dep[i] = {rev[x[2]], rev[x[4]]};
		}
	}
	
	string rmin = "", rmax = "";
	
	for (ll i = 0; i < m; i++) {
		ll c0 = 0, c1 = 0;
		
		memset(dp, -1, sizeof(dp));
		for (ll j = 0; j < n; j++) {
			c0 += check(j, i, 0);
		}
		
		memset(dp, -1, sizeof(dp));
		for (ll j = 0; j < n; j++) {
			c1 += check(j, i, 1);
		}
		
		if (c0 == c1) {
			rmin += "0";
			rmax += "0";
		} else if (c0 < c1) {
			rmin += "0";
			rmax += "1";
		} else {
			rmin += "1";
			rmax += "0";
		}
	}

	cout << rmin << '\n' << rmax << '\n';
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