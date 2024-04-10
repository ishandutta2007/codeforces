/*------------------------------------------------+
|                   ( alex256 )                   |
|-------------------------------------------------+
|                 Template v. 1.1.                |
+---------+---------------------------------------+
| Contest | Tinkoff Challenge - Elimination Round |
| Task    | D                                     |
| Date    | 23.04.2017                            |
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

static int dp[80][80][80][2] = {};

struct State {
	int i, j, k, l;
	
	inline int& item() {
		return dp[i][j][k][l];
	}
};

inline bool operator<(State a, State b) {
	return make_tuple(a.i, a.j, a.k, a.l) < make_tuple(b.i, b.j, b.k, b.l);
}

signed main() {
	int n = get<int>(), k = get<int>();
	static int g[80][80] = {};
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			g[i][j] = inf;
		}
	}
	int m = get<int>();
	for (int i = 0; i < m; i++) {
		int a = get<int>() - 1, b = get<int>() - 1, c = get<int>();
		umin(g[a][b], c);
	}	
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			for (int k = 0; k < n; k++) {
				for (int l = 0; l < 2; l++) {
					dp[i][j][k][l] = inf;
				}
			}
		}
	}
	priority_queue< pair<int64_t, State>, vector< pair<int64_t, State> >, 
	  greater< pair<int64_t, State> > > q;
	for (int i = 0; i < n; i++) {
		State s {i, i, k-1, 0};
		s.item() = 0;
		q.emplace(s.item(), s);
		State t {i, i, k-1, 1};
		t.item() = 0;
		q.emplace(t.item(), t);
	}
	while (!q.empty()) {
		int64_t len; State state;
		tie(len, state) = q.top(); q.pop();
		if (len != state.item()) {
			continue;
		}
		if (state.k == 0) {
			putLn(state.item());
			return 0;
		}
		if (state.l == 0) {
			for (int r1 = state.j + 1; r1 < n; r1++) {
				State to {state.i, r1, state.k - 1, 0};
				int64_t way = len + g[r1][state.j];
				if (to.item() > way) {
					to.item() = way;
					q.emplace(to.item(), to);
				}
			}
			for (int l1 = 0; l1 < state.i; l1++) {
				State to {l1, state.j, state.k - 1, 1};
				int64_t way = len + g[l1][state.j];
				if (to.item() > way) {
					to.item() = way;
					q.emplace(to.item(), to);
				}
			}
		} else {
			for (int r1 = state.j + 1; r1 < n; r1++) {
				State to {state.i, r1, state.k - 1, 0};
				int64_t way = len + g[r1][state.i];
				if (to.item() > way) {
					to.item() = way;
					q.emplace(to.item(), to);
				}
			}
			for (int l1 = 0; l1 < state.i; l1++) {
				State to {l1, state.j, state.k - 1, 1};
				int64_t way = len + g[l1][state.i];
				if (to.item() > way) {
					to.item() = way;
					q.emplace(to.item(), to);
				}
			}
		}
	}
	putLn(-1);
	return 0;
}