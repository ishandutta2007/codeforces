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
const ll mod = 1000000007;
// const ll mod = 998244353;
// ll mod;
 

 
ll n, m, k, q, l, r, x, y, z;
const ll template_array_size = 1e6 + 5240;
ll a[template_array_size];
ll b[template_array_size];
ll c[template_array_size];
string s, t;
ll ans = 0;

vector<ll> cur;
vector<ll> pr;

void rec(ll v, ll p) {
	if (p == cur.size()) {
		pr.push_back(v);
		return;
	}
		
	ll x = 1;
	while (x * v <= m) {
		rec(x * v, p + 1);
		if (x * v > m / cur[p]) break;
		x *= cur[p];
	}
}

void solve(int tc = 0) {
	cin >> n;
	for (ll i = 0; i < n; i++) cin >> a[i];
	cin >> k;
	
	// shuffle(a, a + n, rng);
	
	ll mp = n / 2;
	if (n > 14) mp = 6;
	// sort(a, a + mp);
	// reverse(a, a + mp);
	// sort(a + mp, a + n);
	// reverse(a + mp, a + n);
	
	m = 3e18 + 9;
	
	cur.clear();
	pr.clear();
	for (ll i = 0; i < mp; i++) cur.push_back(a[i]);
	rec(1, 0);
	vector<ll> v1 = pr;
	sort(v1.begin(), v1.end());
	
	cur.clear();
	pr.clear();
	for (ll i = mp; i < n; i++) cur.push_back(a[i]);
	rec(1, 0);
	vector<ll> v2 = pr;
	sort(v2.begin(), v2.end());
	
	// cout << v1 << " " << v2 << endl;
		
	ll l = 1, r = 1e18 + 7;
	while (l < r) {
		m = (l + r) / 2;
				
		ll ans = 0;
		ll pt = v2.size() - 1;
		for (ll i = 0; i < v1.size(); i++) {
			if (v1[i] > m) break;
			while (v1[i] > m / v2[pt]) --pt;
			ans += pt + 1;
		}
		
		// cout << m << " " << v1 << " " << v2 << " " << ans << endl;
				
		// cout << m << "  ------------------------ " << ans << endl;
		
		if (ans >= k) r = m;
		else l = m + 1;
	}
	cout << l << '\n';
}

int main() {
	#ifdef galen_colin_local
		auto begin = std::chrono::high_resolution_clock::now();
	#endif
	
	send help
 
	#ifndef galen_colin_local
		// usaco("cowpatibility");
	#endif
	
	// usaco("cowland");
	
	// freopen("tc.cpp", "r", stdin);
 		
	cout << setprecision(12) << fixed;
	
	int tc = 1;
	// cin >> tc;
	for (int t = 0; t < tc; t++) solve(t);
	
	#ifdef galen_colin_local
		auto end = std::chrono::high_resolution_clock::now();
		cout << setprecision(4) << fixed;
		cout << "Execution time: " << std::chrono::duration_cast<std::chrono::duration<double>>(end - begin).count() << " seconds" << endl;
	#endif
}