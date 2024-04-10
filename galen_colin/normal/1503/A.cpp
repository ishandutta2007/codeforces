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



void solve(int tc = 0) {	
	cin >> n >> s;
	
	ll cn[2] = {0};
	
	for (char c: s) ++cn[c - '0'];
	
	if (cn[0] % 2 == 1) {
		cout << "NO\n";
		return;
	}
	
	ll tot = cn[0] + 2 * cn[1];
	if (tot < n) {
		cout << "NO\n";
		return;
	}
	
	ll req = cn[1] - (tot - n) / 2;
	
	ll cnt = 0;
	for (ll i = 0; i < n; i++) {
		a[i] = 1;
		
		if (s[i] == '1') {
			if (cnt >= req) {
				a[i] = b[i] = -1;
			} else b[i] = 1;
			++cnt;
		} else b[i] = -a[i];
	}
		
	req = 0;
	for (ll i = 0; i < n; i++) req += a[i];
	
	if (req < 0) {
		cout << "NO\n";
		return;
	}
	
	ll mn = req, r = req;
	for (ll i = n - 1; i > 0; i--) {
		mn = min(mn, r);
		c[i] = mn;
		r -= a[i];
	}
	
	ll off = 0;
	for (ll i = 0; i < n; i++) {
		if (s[i] == '0' && (c[i] - off) > 1 && req > 0) {
			req -= 2;
			off += 2;
			swap(a[i], b[i]);
		}
	}
	
	bool pos = 1;
	r = 0;
	for (ll i = 0; i < n; i++) {
		r += a[i];
		pos &= (r >= 0);
	}
	pos &= (r == 0);
	
	r = 0;
	for (ll i = 0; i < n; i++) {
		r += b[i];
		pos &= (r >= 0);
	}
	pos &= (r == 0);
	
	if (pos) {
		cout << "YES\n";
		for (ll i = 0; i < n; i++) cout << (a[i] > 0 ? '(' : ')');
		cout << '\n';
		for (ll i = 0; i < n; i++) cout << (b[i] > 0 ? '(' : ')');
		cout << '\n';
	} else {
		cout << "NO\n";
	}
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
	cin >> tc;
	for (int t = 0; t < tc; t++) solve(t);
	
	#ifdef galen_colin_local
		auto end = std::chrono::high_resolution_clock::now();
		cerr << setprecision(4) << fixed;
		// cerr << "Execution time: " << std::chrono::duration_cast<std::chrono::duration<double>>(end - begin).count() << " seconds" << endl;
	#endif
}