#include <bits/stdc++.h>
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
 
// mt19937_64 rng(std::chrono::steady_clock::now().time_since_epoch().count());
mt19937_64 rng(61378913);
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



ll n, m, k, q, l, r, x, y, z;
const ll template_array_size = 1e6 + 8432;
ll a[template_array_size];
ll b[template_array_size];
ll c[template_array_size];
string s, t;
ll ans = 0;	

ll p;

map<pair<ll, ll>, pair<ll, ll>> dp;
map<ll, vector<ll>> edges;

ll geth(ll l, ll r) {
	return l * s.length() + r;
}

pair<ll, ll> unh(ll x) {
	return make_pair(x / s.length(), x % s.length());
}

void rec(ll l, ll r) {
	ll id = geth(l, r);
	
	if (s[l] == '(') ++l;
	if (s[r] == ')') --r;
		
	if (l == r) return;
	
	ll cnt = 0, targ = l;
	for (ll i = l; i <= r; i++) {
		if (s[i] == '(') ++cnt;
		if (s[i] == ')') --cnt;
		if (s[i] == '?' && cnt == 0) {
			rec(targ, i - 1);
			edges[id].push_back(geth(targ, i - 1));
			targ = i + 1;
		}
	}
		
	rec(targ, r);
	edges[id].push_back(geth(targ, r));
}

void solve(ll x) {
	if (edges[x].size() == 0) {
		dp[{x, 0}] = make_pair(s[unh(x).s] - '0', s[unh(x).s] - '0');
		return;
	}
		
	ll mx = min(p, m) + 1;
	
	pair<ll, ll> dp2[mx + 1];
	
	ll ct = 0;
	for (ll y: edges[x]) {
		solve(y);
		pair<ll, ll> ndp[mx + 1];
		for (ll i = 0; i < mx; i++) ndp[i] = make_pair(1e18, -1e18);
		
		pair<ll, ll> at[mx + 1];
		for (ll i = 0; i < mx; i++) {
			if (dp.find({y, i}) == dp.end()) at[i] = make_pair(1e18, -1e18);
			else at[i] = dp[{y, i}];
		}
		
		if (ct++ == 0) {
			for (ll i = 0; i < mx; i++) dp2[i] = at[i];
			continue;
		}
				
		ll it = (p > m);
		for (ll i = 0; i < mx; i++) {
			for (ll j = 0; i + j < mx; j++) {
				if (at[j].f > 1e17) continue;
				ndp[i + j + !it].s = max(ndp[i + j + !it].s, dp2[i].s + at[j].s);
				ndp[i + j + !it].f = min(ndp[i + j + !it].f, dp2[i].f + at[j].f);
				ndp[i + j + it].s = max(ndp[i + j + it].s, dp2[i].s - at[j].f);
				ndp[i + j + it].f = min(ndp[i + j + it].f, dp2[i].f - at[j].s);
			}
		}
		
		for (ll i = 0; i < mx; i++) dp2[i] = ndp[i];
	}
	
	for (ll i = 0; i < mx; i++) dp[{x, i}] = dp2[i];
}

void solve(int tc = 0) {
	cin >> s >> p >> m;
	
	rec(0, s.length() - 1);
	
	ll lv = 0, rv = s.length() - 1;
	ll id = geth(lv, rv);
	
	solve(id);
	
	cout << dp[{id, min(p, m)}].s << '\n';
}

// two pointers? maybe
// xor tricks (or general bitwise)
// tutorial on my template

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
	// freopen("tc.cpp", "w", stdout);
 		
	cout << setprecision(12) << fixed;
					
	int tc = 1;
	// cin >> tc;
	for (int t = 0; t < tc; t++) solve(t);
	
	#ifdef galen_colin_local
		auto end = std::chrono::high_resolution_clock::now();
		cerr << setprecision(4) << fixed;
		// cerr << "Execution time: " << std::chrono::duration_cast<std::chrono::duration<double>>(end - begin).count() << " seconds" << endl;
	#endif
}