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
const ll template_array_size = 1e6 + 14742;
int a[template_array_size];
int b[template_array_size];
int c[template_array_size];
string s, t;
ll ans = 0;	
 
vector<ll> at[2];
ll cnt = 0;

ll c2(ll x) {
	if (x < 2) return 0;
	return x * (x - 1) / 2;
}

ll f(ll x) {
	map<ll, ll> cnt;
	for (ll y: at[x]) ++cnt[y];
	
	if (cnt.size() == 1) {
		return m * (m - 1) * (m - 2) / 6;
	}
	
	ll a = at[x][0], b = at[x].back();
	
	return c2(cnt[a]) * cnt[b] + cnt[a] * c2(cnt[b]) + cnt[a] * cnt[b] * (m - cnt[a] - cnt[b]);
}

ll count(ll p) { // p !p p
	map<ll, ll> cnt[2];
	vector<ll> coords;
	
	for (ll x: at[0]) {
		coords.push_back(x);
		++cnt[0][x];
	}
	for (ll x: at[1]) {
		coords.push_back(x);
		++cnt[1][x];
	}
	getunique(coords);
	
	ll ct[2] = {0}, ans = 0;
	
	for (ll x: coords) {
		ans += c2(cnt[p][x]) * cnt[!p][x];
		
		ct[!p] += cnt[!p][x] * ct[p];
		ans += cnt[p][x] * ct[!p];
		
		ct[!p] += cnt[p][x] * cnt[!p][x];
		ct[p] += cnt[p][x];
	}
	
	return ans;
}

void solve(int tc = 0) {
	cin >> n >> m;
	
	for (ll i = 0; i < m; i++) {
		cin >> x >> y;
		at[x].push_back(y);
	}
	
	sort(at[0].begin(), at[0].end());
	sort(at[1].begin(), at[1].end());
		
	if (!at[0].size()) {
		cout << f(1) << '\n';
		return;
	} else if (!at[1].size()) {
		cout << f(0) << '\n';
		return;
	}
	
	cnt += count(0);
	cnt += count(1);
	
	if (cnt > 0) {
		cout << cnt << '\n';
		return;
	}
	
	if (at[0][0] > at[1][0]) swap(at[0], at[1]);
	
	map<ll, ll> cnt;
	for (ll i = 0; i < 2; i++) {
		for (ll x: at[i]) ++cnt[x];
	}
	
	ll a = at[0].back(), b = at[1][0];
	cout << c2(cnt[a]) * cnt[b] + cnt[a] * c2(cnt[b]) + cnt[a] * cnt[b] * (m - cnt[a] - cnt[b]) << '\n';
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