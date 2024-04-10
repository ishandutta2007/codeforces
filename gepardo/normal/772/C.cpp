/*------------------------------------------------+
|                   ( alex256 )                   |
|-------------------------------------------------+
|                 Template v. 1.1.                |
+---------+---------------------------------------+
| Contest | VK Cup - Round 2                      |
| Task    | C                                     |
| Date    | 16.04.2017                            |
+---------+--------------------------------------*/
/// Global defines
#ifndef ONLINE_JUDGE
	#define LOCAL
#endif
//#define USE_LONGLONG
//#define USE_UNORDERED
//#define FILE_IO
//#undef LOCAL
#ifdef FILE_IO
	#define TASK_NAME "taskname"
	#define INPUT_FILE TASK_NAME".in"
	#define OUTPUT_FILE TASK_NAME".out"
#endif
/// Includes 
#include <bits/stdc++.h>
using namespace std;
/// Defines
#ifdef USE_UNORDERED
	#define set unordered_set
	#define map unordered_map
#endif
#if defined(FILE_IO) && (!defined(LOCAL))
	#define cin __new_cin
	#define cout __new_cout
	ifstream cin(INPUT_FILE);
	ofstream cout(OUTPUT_FILE);
#endif
#ifdef USE_LONGLONG
	#define int i64
	#define inf inf64
#endif
#define endl "\n"
#define sz(a) (int)(a.size())
#define here dbg("here!")
#define endless for (;;)
#define F first
#define S second
#define pb push_back
#define eb emplace_back
#define mp make_pair
/// Types
typedef int64_t i64;
typedef uint64_t u64;
typedef long double ld;
typedef vector<int> vi;
typedef pair<int, int> pii;
typedef vector<pii> vpii;
struct ofl { ld value; int precision; inline ofl(ld value, int precision) : value(value), precision(precision) {} };
/// Constants
const int seed = hash<string>()("alex256");
#ifndef USE_LONGLONG
	const int inf = (int)1e9 + 7;
#endif
const i64 inf64 = (i64)2e18 + 256;
const int mod = (int)1e9 + 7;
const ld pi = 3.141592653589793238462643383279502884197169399375105821;
const string luck = "";
const char* errText = "error :(";
const char* pairDelim = " ";
const char* vectorDelim = " ";
/// Iostream extension
template<typename T1, typename T2> inline istream& operator>>(istream& is, pair<T1, T2>& p) { return is >> p.F >> p.S; } 
template<typename T1, typename T2> inline ostream& operator<<(ostream& os, const pair<T1, T2>& p) { return os << p.F << pairDelim << p.S; } 
template<typename T> inline istream& operator>>(istream& is, vector<T>& v) { for (int i = 0; i < sz(v); i++) { is >> v[i]; } return is; }
template<typename T> inline ostream& operator<<(ostream& os, const vector<T>& v) { for (int i = 0; i < sz(v); i++) { if (i) { os << vectorDelim; } os << v[i]; } return os; }
inline ostream& operator<<(ostream& os, const ofl& o) { return os << fixed << setprecision(o.precision) << o.value; }
inline bool iosOptimize() { ios_base::sync_with_stdio(false); return true; }
bool iosOptimized = iosOptimize();
/// Input
template<typename T> inline T get() { T value; cin >> value; return value; }
template<> inline char get() { char c = '\0'; while (c <= ' ') { cin >> c; } return c; }
inline string getLn() { string s; getline(cin, s); return s; }
template<typename T, size_t Count> struct VectorPacker { typedef vector< typename VectorPacker<T, Count-1>::Type > Type; };
template<typename T> struct VectorPacker<T, 0> { typedef T Type; };
template<typename T> inline vector<T> getVector(int size) { vector<T> res(size); cin >> res; return res; }
template<typename T, typename U, typename... Args> inline typename VectorPacker<T, sizeof...(Args)+1>::Type getVector(U size, Args... sizes) { typename VectorPacker<T, sizeof...(Args)+1>::Type res(size); for (int i = 0; i < (int)size; i++) { res[i] = getVector<T>(sizes...); } return res; }
/// Output
inline void put() {}
template<typename T, typename... Args> inline void put(const T& value, const Args&... vals) { cout << value; put(vals...); }
template<typename... Args> inline void putLn(const Args&... vals) { put(vals...); cout << endl; }
/// Debug
#ifdef LOCAL
	template<typename... Args> inline void dbg(const Args&... vals) { putLn(vals...); cout.flush(); }
	#define dbgCode(a...) { a }
#else
	#define dbg(...)
	#define dbgCode(...)
#endif
/// Hash overload for pairs
namespace std { template<typename T1, typename T2> struct hash<pair<T1, T2> > { inline size_t operator()(const pair<T1, T2>& p) const { return hash<T1>()(p.F) ^ hash<T2>()(p.S); } }; };
/// Helpful methods
mt19937_64 rnd(seed);
inline void error(const char* text = errText) { text = text; dbg(text); exit(256); }
template <typename T1, typename T2> inline void umax(T1& a, const T2& b) { if (a < b) { a = b; } }
template <typename T1, typename T2> inline void umin(T1& a, const T2& b) { if (a > b) { a = b; } }
i64 gcd(i64 a, i64 b) { return b ? gcd (b, a % b) : a; }
i64 extGcd(i64 a, i64 b, i64& x, i64& y) { if (!a) { x = 0; y = 1; return b; } i64 x1, y1, d = extGcd(b % a, a, x1, y1); x = y1 - (b / a) * x1; y = x1; return d; }
inline int addMod(int a, int b, int m = mod) { return ((i64)a + b) % m; }
inline int subMod(int a, int b, int m = mod) { return ((i64)a + m - b) % m; }
inline int mulMod(int a, int b, int m = mod) { return ((i64)a * b) % m; }
inline int divMod(int a, int b, int m = mod) { i64 x, y; i64 g = extGcd(b, m, x, y); if (g != 1) { dbg("cannot eval ", a, " / ", b, " modulo ", m); exit(42); }  x = (x % m + m) % m; return mulMod(a, x, m); }
/// End of The Template

inline vector<int64_t> factorize(int64_t n) {
	vector<int64_t> res;
	for (int64_t i = 2; i * i <= n; i++) {
		while (n % i == 0) {
			res.push_back(i);
			n /= i;
		}
	}
	if (n != 1) {
		res.push_back(n);
	}
	return res;
}

inline bool diophantSolve(int64_t a, int64_t b, int64_t c, 
                          int64_t& x, int64_t& y,
                          int64_t& xStep, int64_t& yStep) {
	int64_t g = extGcd(abs(a), abs(b), x, y);
	if (c % g != 0) {
		return false;
	}
	x *= c / g;
	y *= c / g;
	if (a < 0) {
		x *= -1;
	}
	if (b < 0) {
		y *= -1;
	}
	xStep = b / g;
	yStep = -a / g;
	return true;
}

inline i64 ourDivMod(i64 a, i64 b, i64 m) {
	i64 x, y, xStep, yStep;
	if (!diophantSolve(a, m, b, x, y, xStep, yStep)) {
		dbg("a = ", a, " b = ", b, " m = ", m);
		error("Something went wrong...");
	}
	x = (x % m + m) % m;
	return x;
}


template<typename T>
inline set<T> toSet(vector<T> v) {
	return set<T>(v.begin(), v.end());
}

template<typename T>
inline vector<T> toVector(set<T> s) {
	return vector<T>(s.begin(), s.end());
}

signed main() {
	int n = get<int>(), m = get<int>();
	vi can(m, true);
	for (int i = 0; i < n; i++) {
		can[get<int>()] = false;
	}
	vector<vi> gcds(m+1);
	for (int i = 1; i <= m; i++) {
		if (can[i % m]) {
			gcds[gcd(m, i)].pb(i);
		}
	}
	auto divs = factorize(m);
	dbg("divs = ", divs);
	vi dp(m+1, 0), p(m+1, 0);
	dp[1] = sz(gcds[1]);
	p[1] = -1;
	for (int i = 2; i <= m; i++) {
		int bestP = -1;
		int bestVal = -inf;
		for (auto div: divs) {
			if (i % div == 0) {
				int p = i / div;
				if (dp[p] > bestVal) {
					bestVal = dp[p];
					bestP = p;
				}
			}
		}
		dp[i] = bestVal + sz(gcds[i]);
		p[i] = bestP;
	}
	vi prefMuls;
	int ktr = m;
	while (ktr >= 0) {
		for (auto g: gcds[ktr]) {
			prefMuls.pb(g);
		}
		ktr = p[ktr];
	}
	reverse(prefMuls.begin(), prefMuls.end());
	dbg("prefMuls = ", prefMuls);
	int as = sz(prefMuls);
	vi res(as);
	res[0] = prefMuls[0] % m;
	for (int i = 1; i < as; i++) {
		res[i] = ourDivMod(prefMuls[i-1], prefMuls[i], m);
	}
	putLn(as);
	putLn(res);
	return 0;
}