// --------------------------------------------------<TEMPLATE>--------------------------------------------------
// --------------------<optimizations>--------------------
/*
#pragma GCC optimize("Ofast,unroll-loops")
#pragma GCC target("avx,avx2,fma")
*/
// -------------------</optimizations>--------------------
 
// ---------------<Headers and namespaces>----------------
#include <bits/stdc++.h>
#include <numeric>
using namespace std;
 
/*
#include <ext/pb_ds/assoc_container.hx>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
*/
 
// ---------------</Headers and namespaces>---------------
 
// -----------------<Defines and typedefs>----------------
// typedef tree<int,null_type,less<int>,rb_tree_tag,
// tree_order_statistics_node_update> indexed_set; // use less_equal for multiset
// order_of_key (val): returns the no. of values less than val
// find_by_order (k): returns the iterator to kth largest element.(0-based)
 
typedef long double LD;
typedef long long ll;
#define int ll
 
#define pb push_back
#define mp make_pair
 
#define rep(i,n) for (int i = 0; i < n; i++)
#define ford(i,a,b) for (int i = a; i < b; i++)
#define REPD(i,n) for (int i = n-1; i >= 0; i--)
#define FORD(i,a,b) for (int i = a; i >= b; i--)
 
#define all(v) v.begin(),v.end()
 
typedef map<int, int> mii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int, int> pii;
typedef vector<pii> vpii;
 
#define F first
#define S second
 
#define PQ(type) priority_queue<type>
#define PQD(type) priority_queue<type,vector<type>,greater<type> >
 
#define WL(t) while(t --)
#define SZ(x) ((int)(x).size())
 
#define runtime() ((double)clock() / CLOCKS_PER_SEC)
#define inrange(i,a,b) ((i>=min(a,b)) && (i<=max(a,b)))
 
 
// ----------------<Defines and typedefs>----------------
#define PRECISION(x) cout << fixed << setprecision(x);
#define FAST_IO ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
 
// ----------------</Defines and typedefs>----------------
 
// ------------------------<Consts>-----------------------
const int MAXN = 1000005;
const int SQRTN = 1003;
const int LOGN = 22;
const double PI = acos(-1);
 
#ifdef int
const int INF = 1e18;
#else
const int INF = 1e9;
#endif
 
const int MOD =  1e9 + 7;
const int FMOD = 998244353;
const double eps = 1e-9;
// -----------------------</Consts>-----------------------
 
// -------------------<Debugging stuff>-------------------
void __print(int x) {cerr << x;}
void __print(long x) {cerr << x;}
void __print(unsigned x) {cerr << x;}
void __print(unsigned long x) {cerr << x;}
void __print(unsigned long long x) {cerr << x;}
void __print(float x) {cerr << x;}
void __print(double x) {cerr << x;}
void __print(long double x) {cerr << x;}
void __print(char x) {cerr << '\'' << x << '\'';}
void __print(const char *x) {cerr << '\"' << x << '\"';}
void __print(const string &x) {cerr << '\"' << x << '\"';}
void __print(bool x) {cerr << (x ? "true" : "false");}
 
template<typename T, typename V>
void __print(const pair<T, V> &x) {cerr << '{'; __print(x.first); cerr << ','; __print(x.second); cerr << '}';}
template<typename T>
void __print(const T &x) {int f = 0; cerr << '{'; for (auto &i : x) cerr << (f++ ? "," : ""), __print(i); cerr << "}";}
void _print() {cerr << "]\n";}
template <typename T, typename... V>
void _print(T t, V... v) {__print(t); if (sizeof...(v)) cerr << ", "; _print(v...);}
#ifndef ONLINE_JUDGE
#define debug(x...) cerr << "[" << #x << "] = ["; _print(x)
#else
#define debug(x...)
#endif
// ------------------</Debugging stuff>-------------------
 
 
// -------------------------<RNG>-------------------------
mt19937 RNG(chrono::steady_clock::now().time_since_epoch().count());
#define SHUF(v) shuffle(all(v), RNG);
// Use mt19937_64 for 64 bit random numbers.
 
// ------------------------</RNG>-------------------------
 
 
 
// ----------------------<MATH>---------------------------
template<typename T> T gcd(T a, T b) {if (b == 0) return a; a %= b; return gcd(b, a);}
template<typename T> T lcm(T a, T b) {return (a * (b / gcd(a, b)));}
int add(int a, int b, int c = MOD) {int res = a + b; return (res >= c ? res % c : res);}
int mod_neg(int a, int b, int c = MOD) {int res; if (abs(a - b) < c)res = a - b; else res = (a - b) % c; return (res < 0 ? res + c : res);}
int mul(int a, int b, int c = MOD) {ll res = (ll)a * b; return (res >= c ? res % c : res);}
int muln(int a, int b, int c = MOD) {ll res = (ll)a * b; return ((res % c) + c) % c;}
ll mulmod(ll a, ll b, ll m = MOD) {ll q = (ll)(((LD)a * (LD)b) / (LD)m); ll r = a * b - q * m; if (r > m)r %= m; if (r < 0)r += m; return r;}
template<typename T>T expo(T e, T n) {T x = 1, p = e; while (n) {if (n & 1)x = x * p; p = p * p; n >>= 1;} return x;}
template<typename T>T power(T e, T n, T m = MOD) {T x = 1, p = e; while (n) {if (n & 1)x = mul(x, p, m); p = mul(p, p, m); n >>= 1;} return x;}
template<typename T>T extended_euclid(T a, T b, T &x, T &y) {
	T xx = 0, yy = 1; y = 0; x = 1; while (b) {
		T q = a / b, t = b; b = a % b; a = t; \
		t = xx; xx = x - q * xx; x = t; t = yy; yy = y - q * yy; y = t;
	} return a;
}
template<typename T>T mod_inverse(T a, T n = MOD) {T x, y, z = 0; T d = extended_euclid(a, n, x, y); return (d > 1 ? -1 : mod_neg(x, z, n));}
 
const int FACSZ = 1e4; // Make sure to change this
 
int fact[FACSZ], ifact[FACSZ];
 
void precom(int c = MOD) {
	fact[0] = 1;
	ford(i, 1, FACSZ) fact[i] = mul(fact[i - 1], i, c);
	ifact[FACSZ - 1] = mod_inverse(fact[FACSZ - 1], c);
	REPD(i, FACSZ - 1) {
		ifact[i] = mul(i + 1, ifact[i + 1], c);
	}
}
 
int ncr(int n, int r, int c = MOD) {
	return mul(mul(ifact[r], ifact[n - r], c), fact[n], c);
}
 
// ----------------------</MATH>--------------------------
 
// ------------------------------<MATRIX>-------------------------------
 
const long long MOD2 = static_cast<long long>(MOD) * MOD;
 
struct Matrix
{
	vector< vector<int> > mat;
	int n_rows, n_cols;
 
	Matrix() {}
 
	Matrix(vector< vector<int> > values): mat(values), n_rows(values.size()),
		n_cols(values[0].size()) {}
 
	static Matrix identity_matrix(int n)
	{
		vector< vector<int> > values(n, vector<int>(n, 0));
		for (int i = 0; i < n; i++)
			values[i][i] = 1;
		return values;
	}
 
	Matrix operator*(const Matrix &other) const
	{
		int n = n_rows, m = other.n_cols;
		vector< vector<int> > result(n_rows, vector<int>(n_cols, 0));
		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++) {
				long long tmp = 0;
				for (int k = 0; k < n_cols; k++) {
					tmp += mat[i][k] * 1ll * other.mat[k][j];
					while (tmp >= MOD2)
						tmp -= MOD2;
				}
				result[i][j] = tmp % MOD;
			}
 
		return move(Matrix(move(result)));
	}
 
	inline bool is_square() const
	{
		return n_rows == n_cols;
	}
};
 
// binary exponentiation, returns a^p
Matrix pw(Matrix a, int p) {
	Matrix result = Matrix::identity_matrix(a.n_cols);
	while (p > 0) {
		if (p & 1)
			result = a * result;
		a = a * a;
		p >>= 1;
	}
	return result;
}
 
// ----------------------------</MATRIX>-------------------------------------
 
//DONT FUCKING CODE TILL YOU HAVE THE COMPLETE IDEA!!!!!
//DONT SUBMIT A FUCKING GUESS !!!
 
// --------------------------------------------------</TEMPLATE>--------------------------------------------------
vi v[MAXN];
vi subtree(MAXN);
vi vis(MAXN);
vi parent(MAXN);
int dfs(int node, int par) {
	int sz = 1;
	vis[node] = 1;
	parent[node] = par;
 
	for (auto child : v[node]) {
		if (vis[child] == 0) {
			sz += dfs(child, node);
		}
	}
	subtree[node] = sz;
	return sz;
}
void solvethetestcase() {
	int n;
	cin >> n;
 
	rep(i, MAXN) {
		v[i].clear();
		vis[i] = 0;
		subtree[i] = 0;
		parent[i] = 0;
	}
 
	rep(i, n - 1) {
		int a, b;
		cin >> a >> b;
		v[a].pb(b);
		v[b].pb(a);
 
	}
 
	dfs(1, -1);
	vi x;
	ford(i, 1, n + 1) {
		for (auto child : v[i]) {
			if (child == parent[i]) {continue;}
			x.pb(subtree[child] * (n - subtree[child]) );
 
		}
	}
	sort(all(x));
    for(auto &it:x) it%=MOD;
	reverse(all(x));
 
	int m; cin >> m;
	vi factor(m);
	rep(i, m) {
		cin >> factor[i];
	}
	sort(all(factor));
	reverse(all(factor));
 
 
	debug(x, x.size());
	debug(factor, factor.size());
	if (m == n - 1) {
		int ans = 0;
 
		rep(i, m) {
			ans += (factor[i] % MOD) * (x[i] % MOD);
			ans %= MOD;
		}
		cout << ans << "\n";
	} else if (m > n - 1) {
		int ans = 0;
		int z = 1;
		rep(i, m - n + 2) {
			z *= factor[i]; z %= MOD;
		}
		ans += z * x[0];
		ans %= MOD;
		ford(i, m - n + 2, m) {
			ans += x[i - (m - n + 1)] * factor[i];
			ans %= MOD;
		}
		cout << ans << '\n';
	} else {
		int ans = 0;
		rep(i, m) {
			ans += factor[i] * x[i];
			ans %= MOD;
		}
		ford(i, m, n - 1) {
			ans += x[i];
			ans %= MOD;
		}
		cout << ans << "\n";
	}
}
 
 
 
 
 
 
 
/*
0. Enough array size? Enough array size? integer overflow?
 
1. Think TWICE, Code ONCE!
Are there any counterexamples to your algo?
 
2. Be careful about the BOUNDARIES!
N=1? P=1? Something about 0?
 
3. Do not make STUPID MISTAKES!
Time complexity? Memory usage? Precision error?
*/
 
signed main() {
//comment for kickstart
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	// for getting input frm input1.txt
	freopen("output1.txt", "w", stdout);
	// for getting output frm output1.txt
#else
#endif
	PRECISION(12);
	FAST_IO
	int t = 1;
 
	// (UNCOMMENT FOR MULTIPLE TEST CASES)
	cin >> t;
 
 
 
	ford(testcase, 1, t + 1) {
		//uncomment for kickstart
		//cout << "Case #" << testcase << ": ";
		solvethetestcase();
 
 
 
 
	}
 
 
}