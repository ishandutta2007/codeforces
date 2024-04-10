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

ll seed = std::chrono::steady_clock::now().time_since_epoch().count();
mt19937_64 rng(seed);
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



ll n, m, k, q, l, r, x, y, z;
const ll template_array_size = 1e6 + 8432;
ll a[template_array_size];
ll b[template_array_size];
ll c[template_array_size];
string s, t;
ll ans = 0;	

set<string> widgets;
map<string, vector<string>> edges;
map<string, pair<ll, ll>> sz;
map<string, pair<ll, ll>> vals;
map<string, ll> type;
map<string, ll> ideg;
set<string> memo;

void dfs(string s) {
	if (memo.find(s) != memo.end()) return;
	memo.insert(s);
	ll tx = 0, ty = 0, mx = 0, my = 0, tot = 0;
	for (string t: edges[s]) {
		dfs(t);
		tx += sz[t].f;
		ty += sz[t].s;
		mx = max(mx, sz[t].f);
		my = max(my, sz[t].s);
		++tot;
	}
	
	if (type[s] == 0) {
		return;
	}
	
	if (edges[s].size() == 0) {
		sz[s] = {0, 0};
		return;
	}
		
	if (type[s] == 1) {
		sz[s].f = 2 * vals[s].f + (tot - 1) * vals[s].s + tx;
		sz[s].s = 2 * vals[s].f + my;
	} else {
		sz[s].f = 2 * vals[s].f + mx;
		sz[s].s = 2 * vals[s].f + (tot - 1) * vals[s].s + ty;
	}
}

void solve(int tc = 0) {
	cin >> n;
	for (ll i = 0; i < n; i++) {
		cin >> s;
		if (s == "Widget") {
			cin >> s;
			string t = "";
			ll pt = 0;
			while (s[pt] != '(') t += s[pt++];
			pt++;
			
			string a = "", b = "";
			
			while (s[pt] != ',') a += s[pt++];
			pt++;
			while (s[pt] != ')') b += s[pt++];
			
			widgets.insert(t);
			sz[t] = {stoi(a), stoi(b)};
			type[t] = 0;
		} else if (s == "VBox") {
			cin >> s;
			widgets.insert(s);
			vals[s] = {0, 0};
			type[s] = 2;
		} else if (s == "HBox") {
			cin >> s;
			widgets.insert(s);
			vals[s] = {0, 0};
			type[s] = 1;
		} else {
			ll pt = 0;
			string t, u, v;
			while (s[pt] != '.') t += s[pt++];
			pt++;
			
			while (s[pt] != '(') u += s[pt++];
			pt++;
			
			while (s[pt] != ')') v += s[pt++];
			pt++;
			
			if (u == "pack") {
				edges[t].push_back(v);
				++ideg[v];
			} else if (u == "set_border") {
				vals[t].f = stoi(v);
			} else {
				vals[t].s = stoi(v);
			}
		}
	}
	
	for (string s: widgets) {
		if (ideg[s] == 0) {
			dfs(s);
		}
	}
	
	for (string s: widgets) cout << s << " " << sz[s].f << " " << sz[s].s << '\n';
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
		// usaco("dining");
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