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

vector<vector<pair<ll, ll>>> ops;
ll mat[105][105];
vector<pair<ll, ll>> cur;

void flip(ll r, ll c) {
	mat[r][c] ^= 1;
	cur.push_back({r, c});
	if (cur.size() == 3) {
		ops.push_back(cur);
		cur.clear();
	}
}

void pr() {
	for (ll i = 0; i < n; i++) {
		for (ll j = 0; j < m; j++) {
			cout << mat[i][j];
		}
		cout << '\n';
	}
}

void square(ll r, ll c) {
	ll cnt = 0;
	for (ll rr = r; rr < r + 2; rr++) {
		for (ll cc = c; cc < c + 2; cc++) {
			cnt += mat[rr][cc];
		}
	}
	
	if (cnt >= 3) {
		cnt -= 3;
		for (ll rr = r; rr < r + 2; rr++) {
			for (ll cc = c; cc < c + 2; cc++) {
				if (mat[rr][cc] && (rr > r || cc > c || !cnt)) flip(rr, cc);
			}
		}
	}
	
	if (cnt == 0) return;
	
	ll vis[2][2];
	memset(vis, 0, sizeof(vis));
	
	cnt = 1;
	ll tot = 1;
	for (ll rr = r; rr < r + 2; rr++) {
		for (ll cc = c; cc < c + 2; cc++) {
			if (mat[rr][cc]) {
				if (cnt > 0) {
					flip(rr, cc);
					vis[rr - r][cc - c] = 1;
				}
				--cnt;
			}
		}
	}
	
	for (ll rr = r; rr < r + 2; rr++) {
		for (ll cc = c; cc < c + 2; cc++) {
			if (!mat[rr][cc] && !vis[rr - r][cc - c]) {
				if (tot++ < 3) flip(rr, cc);
				--cnt;
			}
		}
	}
	
	square(r, c);
}

void solve(int tc = 0) {
	ops.clear();
	
	cin >> n >> m;
	
	for (ll i = 0; i < n; i++) {
		cin >> s;
		for (ll j = 0; j < m; j++) {
			mat[i][j] = s[j] - '0';
		}
	}
	
	// make extra row/col 0 if odd
	if (n % 2 == 1 && m % 2 == 1 && mat[n - 1][m - 1]) {
		flip(n - 2, m - 1);
		flip(n - 1, m - 2);
		flip(n - 1, m - 1);
	}
	if (n % 2 == 1) { // extra row
		for (ll i = 0; i < m; i += 2) {
			if (mat[n - 1][i] || mat[n - 1][i + 1]) {
				if (mat[n - 1][i]) flip(n - 1, i);
				if (mat[n - 1][i + 1]) flip(n - 1, i + 1);
				flip(n - 2, i);
				if (cur.size() == 2) flip(n - 2, i + 1);
			}
		}
	}
	if (m % 2 == 1) { // extra col
		for (ll i = 0; i < n; i += 2) {
			if (mat[i][m - 1] || mat[i + 1][m - 1]) {
				if (mat[i][m - 1]) flip(i, m - 1);
				if (mat[i + 1][m - 1]) flip(i + 1, m - 1);
				flip(i, m - 2);
				if (cur.size() == 2) flip(i + 1, m - 2);
			}
		}
	}
	
	// handle each 2x2 square
	for (ll i = 0; i < n; i += 2) {
		for (ll j = 0; j < m; j += 2) {
			square(i, j);
		}
	}
	
	cout << ops.size() << '\n';
	for (vector<pair<ll, ll>> x: ops) {
		for (pair<ll, ll> y: x) {
			cout << y.f + 1 << " " << y.s + 1 << " ";
		}
		cout << '\n';
	}
	// pr();
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
	cin >> tc;
	for (int t = 0; t < tc; t++) solve(t);
	
	#ifdef galen_colin_local
		auto end = std::chrono::high_resolution_clock::now();
		cerr << setprecision(4) << fixed;
		// cerr << "Execution time: " << std::chrono::duration_cast<std::chrono::duration<double>>(end - begin).count() << " seconds" << endl;
	#endif
}