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

const ll C = 300;
ll blocks;
pair<ll, ll> jump[100005];
ll pt[100005];

void upd(ll b) {
	ll rv = min(n - 1, (b + 1) * C - 1);
	ll lv = b * C;
	for (ll i = rv; i >= lv; i--) {
		ll pos = i + a[i];
		if (pos > rv || pos >= n) {
			jump[i] = make_pair(1, pos);
			pt[i] = i;
		} else {
			jump[i] = make_pair(1 + jump[pos].f, jump[pos].s);
			pt[i] = pt[pos];
		}
	}
}

void solve(int tc = 0) {
	cin >> n >> m;
	
	for (ll i = 0; i < n; i++) cin >> a[i];
	
	blocks = (n + C - 1) / C;
	
	for (ll i = 0; i < blocks; i++) upd(i);
			
	for (ll i = 0; i < m; i++) {
		int t; cin >> t;
		if (t == 0) {
			cin >> x >> y;
			a[--x] = y;
			upd(x / C);
		} else {
			ll ans = 0, cur;
			cin >> cur;
			--cur;
			while (1) {
				ans += jump[cur].f;
				if (jump[cur].s >= n) {
					cout << pt[cur] + 1 << " " << ans << '\n';
					break;
				}
				cur = jump[cur].s;
			}
		}
	}
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