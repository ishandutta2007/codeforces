#include <bits/stdc++.h>
#include <chrono> 
 
using namespace std;
using namespace std::chrono; 
 
// #pragma GCC target ("avx2")
// #pragma GCC optimization ("O3")
// #pragma GCC optimization ("unroll-loops")
// #pragma optimization_level 3
// #pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math,O3")
// #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
 
#define f0r(a, b) for (long long a = 0; a < (b); ++a)
#define f1r(a, b, c) for (long long a = (b); a < (c); ++a)
#define f0rd(a, b) for (long long a = (b); a >= 0; --a)
#define f1rd(a, b, c) for (long long a = (b); a >= (c); --a)
#define ms(arr, v) memset(arr, v, sizeof(arr))
#define pb push_back
#define send {ios_base::sync_with_stdio(false);}
#define help {cin.tie(NULL); cout.tie(NULL);}
#define fix(prec) {cout << setprecision(prec) << fixed;}
#define mp make_pair
#define f first
#define s second
#define all(v) v.begin(), v.end()
#define getunique(v) {sort(all(v)); v.erase(unique(all(v)), v.end());}
#define readgraph(list, edges) for (int i = 0; i < edges; i++) {int a, b; cin >> a >> b; a--; b--; list[a].pb(b); list[b].pb(a);}
#define ai(a, n) for (int ele = 0; ele < n; ele++) cin >> a[ele];
#define ain(a, lb, rb) for (int ele = lb; ele <= rb; ele++) cin >> a[ele];
#define ao(a, n) {for (int ele = 0; ele < (n); ele++) { if (ele) cout << " "; cout << a[ele]; } cout << '\n';}
#define aout(a, lb, rb) {for (int ele = (lb); ele <= (rb); ele++) { if (ele > (lb)) cout << " "; cout << a[ele]; } cout << '\n';}
#define vsz(x) ((long long) x.size())
typedef long long ll;
typedef double ld;
typedef long double lld;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<pii> vpi;
typedef vector<pll> vpl;
 
template<typename A> ostream& operator<<(ostream &cout, vector<A> const &v);
template<typename A, typename B> ostream& operator<<(ostream &cout, pair<A, B> const &p) { return cout << "(" << p.f << ", " << p.s << ")"; }
template<typename A> ostream& operator<<(ostream &cout, vector<A> const &v) {
	cout << "["; for(int i = 0; i < v.size(); i++) {if (i) cout << ", "; cout << v[i];} return cout << "]";
}
template<typename A, typename B> istream& operator>>(istream& cin, pair<A, B> &p) {
	cin >> p.first;
	return cin >> p.second;
}
 
mt19937 rng(steady_clock::now().time_since_epoch().count());
// mt19937 rng(61378913);
/* usage - just do rng() */
 
void usaco(string filename) {
  // #pragma message("be careful, freopen may be wrong")
	freopen((filename + ".in").c_str(), "r", stdin);
	freopen((filename + ".out").c_str(), "w", stdout);
}
 
const lld pi = 3.14159265358979323846;
// const ll mod = 1000000007;
const ll mod = 998244353;
// ll mod;



ll n, m, k, q, l, r, x, y, z;
ll a[1000005];
ll b[1000005];
ll c[1000005];
string s, t;
ll ans = 0;

string mat[2005];

char mat2[4500][4500];
short dp[4500][4500];
pair<short, short> coords[2005][2005];
ll cr, cc;
pair<short, int> v[4000005];

void compressX() {
	f0r(i, n) {
		f0r(j, m) {
			v[i * m + j] = mp(coords[i][j].f, i * m + j);
		}
	}
	int mx = n * m;
	sort(v, v + mx);
	
	ll c = 0;
	f0r(i, mx) {
		if (i > 0 && v[i].f != v[i - 1].f) {
			++c;
		}
		coords[v[i].s / m][v[i].s % m].f = c;
	}
	cr = ++c;
}

void compressY() {
	f0r(i, n) {
		f0r(j, m) {
			v[i * m + j] = mp(coords[i][j].s, i * m + j);
		}
	}
	int mx = n * m;
	sort(v, v + mx);
	
	ll c = 0;
	f0r(i, mx) {
		if (i > 0 && v[i].f != v[i - 1].f) {
			++c;
		}
		coords[v[i].s / m][v[i].s % m].s = c;
	}
	cc = ++c;
}

void solve(int tc) {
	cin >> n >> m;
	ai(mat, n);
	
	f0r(i, 4450) f0r(j, 4450) {
		mat2[i][j] = '=';
	}
	
	f0r(i, n) {
		f0r(j, m) {
			coords[i][j] = mp(m + i - j, i + j);
			// cout << i << " " << j << " " << coords[i][j] << endl;
		}
	}
	
	// compressX();
	// compressY();
	
	cr = cc = n + m;
	
	f0r(i, n) {
		f0r(j, m) {
			mat2[coords[i][j].f][coords[i][j].s] = mat[i][j];
			// cout << i << " " << j << " " << coords[i][j] << endl;
		}
	}
		
	// f0r(i, cr) ao(mat2[i], cc);
	
	f0r(i, cr) f0r(j, cc) dp[i][j] = 10000;
	
	f0r(i, cr) {
		char last = '#';
		short run = 0;
		for (int j = 0; j < cc; j += 2) {
			if (mat2[i][j] == last && (i == 0 || mat2[i - 1][j - 1] == last)) {
				++run;
			} else {
				last = mat2[i][j];
				run = 1;
			}
			dp[i][j] = min(dp[i][j], run);
		}
		last = '#';
		run = 0;
		for (int j = 1; j < cc; j += 2) {
			if (mat2[i][j] == last && (i == 0 || mat2[i - 1][j - 1] == last)) ++run;
			else {
				last = mat2[i][j];
				run = 1;
			}
			dp[i][j] = min(dp[i][j], run);
		}
	}
	
	f0r(i, cc) {
		char last = '#';
		short run = 0;
		for (int j = 0; j < cr; j += 2) {
			if (mat2[j][i] == last && (j == 0 || mat2[j - 1][i - 1] == last)) ++run;
			else {
				last = mat2[j][i];
				run = 1;
			}
			dp[j][i] = min(dp[j][i], run);
		}
		last = '#';
		run = 0;
		for (int j = 1; j < cr; j += 2) {
			if (mat2[j][i] == last && (j == 0 || mat2[j - 1][i - 1] == last)) ++run;
			else {
				last = mat2[j][i];
				run = 1;
			}
			dp[j][i] = min(dp[j][i], run);
		}
	}
	
	f0r(i, cr) {
		f0r(j, cc) {
			if (i > 1 && j > 1) {
				if (mat2[i][j] == mat2[i - 2][j - 2] && mat2[i][j] == mat2[i - 1][j - 1]) {
					dp[i][j] = min(dp[i][j], (short)(1 + dp[i - 2][j - 2]));
				} else {
					dp[i][j] = 1;
				}
			}
		}
	}
	
	// f0r(i, cr) ao(dp[i], cc);
	
	ll ans = 0;
	f0r(i, cr) f0r(j, cc) {
		if (mat2[i][j] != '=') {
			ans += dp[i][j];
		}
	}
	
	cout << ans << '\n';
}



int main() {
	#ifdef galen_colin_local
		auto begin = std::chrono::high_resolution_clock::now();
	#endif
	
	send help

	// usaco("cowland");

	int tc = 1;
	// cin >> tc;
	for (int t = 0; t < tc; t++) solve(t);
	
	#ifdef galen_colin_local
		auto end = std::chrono::high_resolution_clock::now();
		cout << setprecision(4) << fixed;
		// cout << "Execution time: " << std::chrono::duration_cast<std::chrono::duration<double>>(end - begin).count() << " seconds" << endl;
	#endif
}