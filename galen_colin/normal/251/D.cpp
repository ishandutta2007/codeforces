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

struct xor_stuff {
	vector<ll> basis;
	vector<pair<ll, ll>> inds;
	static const int bit_size = 63;
	
	bool insert(ll v, ll i) {
		for (ll x: basis) {
			if (v == 0) break;
			if (__builtin_clzll(x) == __builtin_clzll(v)) v ^= x;
		}
		
		if (v > 0) {
			basis.push_back(v);
			inds.push_back({v, i});
			sort(basis.begin(), basis.end(), greater<ll>());
			return 1;
		}
		return 0;
	}
	
	bool ask(ll v) {
		for (ll x: basis) {
			if (v == 0) break;
			if (__builtin_clzll(x) == __builtin_clzll(v)) v ^= x;
		}
		
		return !v;
	}
	
	static int gauss (vector < bitset<bit_size> > a, ll m, bitset<bit_size> & ans) {
		int n = a.size();
		
		// for (ll i = 0; i < n; i++) cout << a[i] << endl;
		
		vector<int> where (m, -1);
		for (int col=0, row=0; col<m && row<n; ++col) {
			for (int i=row; i<n; ++i)
				if (a[i][col]) {
					swap (a[i], a[row]);
					break;
				}
			if (! a[row][col])
				continue;
			where[col] = row;

			for (int i=0; i<n; ++i)
				if (i != row && a[i][col])
					a[i] ^= a[row];
			++row;
		}
		
		// for (ll i = 0; i < n; i++) cout << a[i] << endl;
		
		for (int i=0; i<m; ++i)
			if (where[i] != -1)
				ans[i] = a[where[i]][m];
		for (int i=0; i<n; ++i) {
			int sum = 0;
			for (int j=0; j<m; ++j)
				sum ^= (ans[j] & a[i][j]);
			if (sum != a[i][m])
				return 0;
		}

		for (int i=0; i<m; ++i)
			if (where[i] == -1)
				return 2;
		return 1;
	}
};

ll n, m, k, q, l, r, x, y, z;
const ll template_array_size = 1e6 + 8432;
ll a[template_array_size];
ll b[template_array_size];
ll c[template_array_size];
string s, t;
ll ans = 0;	

xor_stuff xs;

void solve(int tc = 0) {
	cin >> n;
		
	ll x = 0;
	for (ll i = 0; i < n; i++) {
		cin >> a[i];
		x ^= a[i];
		
		xs.insert(a[i], i);
	}
		
	sort(xs.inds.begin(), xs.inds.end());
	reverse(xs.inds.begin(), xs.inds.end());
	
	vector<pair<ll, ll>> inds = xs.inds;
	
	ll ans = 0;
	for (ll i = 59; i >= 0; i--) {
		xs.basis.clear();
		for (pair<ll, ll> y: inds) {
			xs.insert((ans + (1LL << i)) & y.f, -1);
		}
		sort(xs.basis.begin(), xs.basis.end(), greater<ll>());
		if (!(x & (1LL << i))) {
			if (xs.ask(ans + (1LL << i))) ans += (1LL << i);
		}
	}
	for (ll i = 59; i >= 0; i--) {
		xs.basis.clear();
		for (pair<ll, ll> y: inds) {
			xs.insert((ans + (1LL << i)) & y.f, -1);
		}
		sort(xs.basis.begin(), xs.basis.end(), greater<ll>());
		if (x & (1LL << i)) {
			if (xs.ask(ans + (1LL << i))) ans += (1LL << i);
		}
	}
	
	const ll bs = xor_stuff::bit_size;
	
	// cout << ans << " " << inds << endl;
	
	vector<bitset<bs>> what(bs, bitset<bs>());
	for (ll i = 0; i < bs; i++) what[i][inds.size()] = !!(ans & (1LL << i));
	for (ll i = 0; i < inds.size(); i++) {
		for (ll j = 0; j < bs; j++) {
			what[j][i] = !!(a[inds[i].s] & (1LL << j));
		}
	}
	
	bitset<bs> res;
	ll xv = xor_stuff::gauss(what, inds.size(), res);
	assert(xv > 0);
	// cout << xv << endl;
			
	for (ll i = 0; i < inds.size(); i++) {
		// cout << res[i] << " " << inds[i] << endl;
		if (res[i]) b[inds[i].s] = 1;
	}
		
	for (ll i = 0; i < n; i++) cout << b[i] + 1 << " ";
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