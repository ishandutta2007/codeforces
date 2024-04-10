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

vector<pair<ll, ll>> ops;
ll mat[51][51];
string dir[51];

void op(ll a, ll b) {
	ops.push_back({a, b});
	swap(mat[a][b], mat[a + 1][b + 1]);
}

void makehor(ll i, ll j);

void makever(ll i, ll j) {
	// not possible if this is the rightmost column
	assert(j < m - 1);
		
	// top thing must be horizontal
	assert(mat[i][j] == mat[i][j + 1]);
	
	if (mat[i + 1][j] != mat[i + 1][j + 1]) makehor(i + 1, j);
	op(i, j);
}

void makehor(ll i, ll j) {	
	// not possible if this is the bottommost row
	assert(i < n - 1);
		
	// left thing must be vertical
	assert(mat[i][j] == mat[i + 1][j]);
	
	if (mat[i][j + 1] != mat[i + 1][j + 1]) makever(i, j + 1);
	op(i, j);
}

vector<pair<ll, ll>> f() {
	ops.clear();
	for (ll i = 0; i < n; i++) {
		cin >> dir[i];
	}
	
	ll gr = 0;
	for (ll i = 0; i < n; i++) {
		for (ll j = 0; j < m; j++) {
			if (dir[i][j] == 'U') {
				mat[i][j] = mat[i + 1][j] = gr++;
				dir[i][j] = dir[i + 1][j] = '*';
			} else if (dir[i][j] == 'L') {
				mat[i][j] = mat[i][j + 1] = gr++;
				dir[i][j] = dir[i][j + 1] = '*';
			}
		}
	}
	
	bool flip = 0;
	if (m % 2 == 0) {
		flip = 1;
		
		ll nmat[51][51];
		
		for (ll i = 0; i < n; i++) {
			for (ll j = 0; j < m; j++) {
				nmat[j][i] = mat[i][j];
			}
		}
		
		swap(n, m);
		
		for (ll i = 0; i < n; i++) {
			for (ll j = 0; j < m; j++) {
				mat[i][j] = nmat[i][j];
			}
		}
	}
	
	// now assume even rows, make all vertical
	for (ll i = 0; i < n; i += 2) {
		for (ll j = 0; j < m; j++) {
			if (mat[i][j] != mat[i + 1][j]) {
				makever(i, j);
			}
		}
	}
	
	if (flip) {
		swap(n, m);
		for (ll i = 0; i < ops.size(); i++) swap(ops[i].f, ops[i].s);
	}
	
	return ops;
}

void solve(int tc = 0) {	
	cin >> n >> m;
	
	vector<pair<ll, ll>> a = f();
	vector<pair<ll, ll>> b = f();
	reverse(b.begin(), b.end());
	
	cout << a.size() + b.size() << '\n';
	for (pair<ll, ll> x: a) cout << x.f + 1 << " " << x.s + 1 << '\n';
	for (pair<ll, ll> x: b) cout << x.f + 1 << " " << x.s + 1 << '\n';
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