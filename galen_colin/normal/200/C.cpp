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
 


ll n, m, k, q, l, r, x, y, z;
const ll template_array_size = 1e6 + 6884;
ll a[template_array_size];
ll b[template_array_size];
ll c[template_array_size];
string s, t;
ll ans = 0;	

struct game {
	string a, b;
	ll sa, sb;
} g[6];

bool eval() {
	map<string, pair<ll, pair<ll, ll>>> mp;
	
	for (ll i = 0; i < 6; i++) {
		mp[g[i].a].s.f += g[i].sa;
		mp[g[i].a].s.s += g[i].sb;
		mp[g[i].b].s.f += g[i].sb;
		mp[g[i].b].s.s += g[i].sa;
		
		if (g[i].sa > g[i].sb) mp[g[i].a].f += 3;
		else if (g[i].sa < g[i].sb) mp[g[i].b].f += 3;
		else {
			mp[g[i].a].f += 1;
			mp[g[i].b].f += 1;
		}
	}
	
	vector<pair<pair<ll, ll>, pair<ll, string>>> ord;
	for (pair<string, pair<ll, pair<ll, ll>>> x: mp) {
		ord.push_back(make_pair(make_pair(-x.s.f, x.s.s.s - x.s.s.f), make_pair(-x.s.s.f, x.f)));
	}
	sort(ord.begin(), ord.end());
	for (ll i = 0; i < 2; i++) {
		if (ord[i].s.s == "BERLAND") return 1;
	}
	return 0;
}

bool cmp(pair<ll, ll> a, pair<ll, ll> b) {
	if (a.f - a.s == b.f - b.s) return a.s < b.s;
	return a.f - a.s < b.f - b.s;
}

void solve(int tc = 0) {
	map<string, ll> cnt;
	for (ll i = 0; i < 5; i++) {
		char c;
		cin >> g[i].a >> g[i].b >> g[i].sa >> c >> g[i].sb;
		++cnt[g[i].a];
		++cnt[g[i].b];
	}
	
	for (pair<string, ll> x: cnt) {
		if (x.s == 2 && x.f != "BERLAND") t = x.f;
	}
	g[5].a = "BERLAND";
	g[5].b = t;
	
	const ll MX = 100;
	vector<pair<ll, ll>> ans;
	for (ll i = 0; i < MX; i++) {
		for (ll j = 0; j < MX; j++) {
			g[5].sa = i, g[5].sb = j;
			if (i > j && eval()) ans.push_back(make_pair(i, j));
		}
	}
	
	sort(ans.begin(), ans.end(), cmp);
	
	if (ans.size() == 0) cout << "IMPOSSIBLE\n";
	else cout << ans[0].f << ":" << ans[0].s << '\n';
}

int main() {
	#ifdef galen_colin_local
		auto begin = std::chrono::high_resolution_clock::now();
	#endif
	
	send help
 
	#ifndef galen_colin_local
		// usaco("photo");
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
		cout << setprecision(4) << fixed;
		// cout << "Execution time: " << std::chrono::duration_cast<std::chrono::duration<double>>(end - begin).count() << " seconds" << endl;
	#endif
}