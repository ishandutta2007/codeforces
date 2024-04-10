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
// const ll mod = 1000000007;
// const ll mod = 998244353;
// ll mod;



ll n, m, q, k, l, r, x, y, z;
const ll template_array_size = 1e6 + 14742;
ll a[template_array_size];
ll b[template_array_size];
ll c[template_array_size];
string s, t;
ll ans = 0;	

pair<ll, pair<ll, ll>> p[100005];
map<ll, ll> slopes, res;
vector<pair<ll, ll>> sl;
set<pair<ll, ll>> segs;
vector<pair<ll, ll>> toins;

vector<pair<ll, ll>> ins(pair<ll, ll> x) {
	vector<pair<ll, ll>> ret(1, x);
	
	ll pos = 0;
	while (1) {
		auto it = segs.lower_bound({x.f, -3e9});
		
		if (it == segs.end()) {
			segs.insert({x.s, x.f});
			return ret;
		}
		
		pair<ll, ll> s = {it->s, it->f};
		
		if (s.f > x.s) {
			segs.insert({x.s, x.f});
			return ret;
		}
		
		if (s.f <= x.f && x.s <= s.s) {
			ret.clear();
			return ret;
		}
		
		if (s.s >= x.s) {
			segs.erase(it);
			segs.insert({s.s, x.f});
			
			ret[pos] = {ret[pos].f, s.f};
			return ret;
		}
		
		if (s.f <= x.f) {
			segs.erase(it);
			toins.push_back({s.f, x.s});
			
			ret[pos] = {s.s, ret[pos].s};
			x = ret[pos];
			continue;
		}
		
		segs.erase(it);
		toins.push_back({x.f, s.s});
		
		ret[pos] = {ret[pos].f, s.f};
		x = {s.s, x.s};
		ret.push_back(x);
		++pos;
	}
}

void solve(int tc = 0) {
	cin >> n >> m;
	
	for (ll i = 0; i < m; i++) {
		cin >> p[i].s >> p[i].f;
	}
	
	sort(p, p + m);
	
	for (ll i = 0; i < n; i++) {
		cin >> a[i];
		slopes[a[i]] = 0;
	}
	slopes[2e9] = 0;
	
	for (ll i = 0; i < m; i++) {
		vector<pair<ll, ll>> r = ins(p[i].s);
		reverse(toins.begin(), toins.end());
		for (ll i = 0; i < toins.size(); i++) ins(toins[i]);
		toins.clear();
		
		for (pair<ll, ll> x: r) {
			slopes[p[i].f - x.s]++;
			slopes[p[i].f - x.f]--;
		}
	}
	
	ll curv = 0, curs = 0;
	for (pair<ll, ll> x: slopes) sl.push_back(x);
	for (ll i = 0; i + 1 < sl.size(); i++) {
		res[sl[i].f] = curv;
		
		curs += sl[i].s;
		
		curv += (sl[i + 1].f - sl[i].f) * curs;
	}
	
	for (ll i = 0; i < n; i++) cout << res[a[i]] << '\n';
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
		// cerr << "Execution time: " << std::chrono::duration_cast<std::chrono::duration<double>>(end - begin).count() << " seconds" << endl;
	#endif
}