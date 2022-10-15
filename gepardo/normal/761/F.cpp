/**
                      alex256                   
   
   Contest CodeForces Round 394 (Div. 2)         
   
   Task    F                                     
   
   Date    31.01.2017                            
   **/
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
	#define int ll
	#define inf llInf
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
typedef int64_t ll;
typedef uint64_t ull;
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
const ll llInf = (ll)2e18 + 256;
const int mod = (int)1e9 + 7;
const ld pi = 3.141592653589793238462643383279502884197169399375105821;
const string luck = "";
const char* errText = "error :(";
/// Iostream extension
template<typename T1, typename T2> inline istream& operator>>(istream& is, pair<T1, T2>& p) { return is >> p.F >> p.S; } 
template<typename T1, typename T2> inline ostream& operator<<(ostream& os, const pair<T1, T2>& p) { return os << p.F << " " << p.S; } 
template<typename T> inline istream& operator>>(istream& is, vector<T>& v) { for (int i = 0; i < sz(v); i++) { is >> v[i]; } return is; }
template<typename T> inline ostream& operator<<(ostream& os, const vector<T>& v) { for (int i = 0; i < sz(v); i++) { if (i) { os << " "; } os << v[i]; } return os; }
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
#else
	#define dbg(...)
#endif
/// Hash overload for pairs
namespace std { template<typename T1, typename T2> struct hash<pair<T1, T2> > { inline size_t operator()(const pair<T1, T2>& p) const { return hash<T1>()(p.F) ^ hash<T2>()(p.S); } }; };
/// Helpful methods
mt19937_64 rnd(seed);
inline void error(const char* text = errText) { dbg(text); exit(256); }
template <typename T1, typename T2> inline void umax(T1& a, const T2& b) { if (a < b) { a = b; } }
template <typename T1, typename T2> inline void umin(T1& a, const T2& b) { if (a > b) { a = b; } }
ll gcd(ll a, ll b) { return b ? gcd (b, a % b) : a; }
ll extGcd(ll a, ll b, ll& x, ll& y) { if (!a) { x = 0; y = 1; return b; } ll x1, y1, d = extGcd(b % a, a, x1, y1); x = y1 - (b / a) * x1; y = x1; return d; }
inline int addMod(int a, int b, int m = mod) { return ((ll)a + b) % m; }
inline int subMod(int a, int b, int m = mod) { return ((ll)a + mod - b) % m; }
inline int mulMod(int a, int b, int m = mod) { return ((ll)a * b) % m; }
inline int divMod(int a, int b, int m = mod) { ll x, y; ll g = extGcd(b, m, x, y); if (g != 1) { dbg("cannot eval ", a, " / ", b, " modulo ", mod); exit(42); }  x = (x % m + m) % m; return mulMod(a, x); }
/// End of The Template

struct Photo {
	int a, b, c, d;
	char e;
};

istream& operator>>(istream& is, Photo& p) {
	is >> p.a >> p.b >> p.c >> p.d;
	p.e = '\0';
	while (p.e <= ' ') {
		is >> p.e;
	}
	return is;
}

int n = get<int>(), m = get<int>(), k = get<int>(), K = k;
vector<string> v = getVector<string>(n);
vector<Photo> photos = getVector<Photo>(k);
vector<ll> curSegs(k), sumSegs(k), intrDifs(k);
ll allDif = 0;

ll rectCount[26][1002][1002];
ll rectCnt[1002][1002];
ll otherAdd[26][1002][1002];

inline void initRectCount() {
	for (int i = 0; i < 26; i++) {
		for (int j = 0; j <= n+1; j++) {
			for (int k = 0; k <= m+1; k++) {
				rectCount[i][j][k] = rectCnt[j][k] = 0;
			}
		}
	}
	for (int i = 0; i < k; i++) {
		Photo cur = photos[i];
		rectCount[cur.e - 'a'][cur.c+1][cur.d+1]  ++;
		rectCount[cur.e - 'a'][cur.a]  [cur.d+1]  --;
		rectCount[cur.e - 'a'][cur.c+1][cur.b]--;
		rectCount[cur.e - 'a'][cur.a]  [cur.b]++;		
	}
	for (int i = 0; i < 26; i++) {
		for (int j = 0; j <= n+1; j++) {
			for (int k = 0; k <= m+1; k++) {
				if (j != 0) {
					rectCount[i][j][k] += rectCount[i][j-1][k];
				}
				if (k != 0) {
					rectCount[i][j][k] += rectCount[i][j][k-1];
				}
				if (j != 0 && k != 0) {
					rectCount[i][j][k] -= rectCount[i][j-1][k-1];
				}
				rectCnt[j][k] += rectCount[i][j][k];
			}
		}
	}
}

inline void cleanArr() {
	for (int i = 0; i < 26; i++) {
		for (int j = 0; j <= n+1; j++) {
			for (int k = 0; k <= m+1; k++) {
				otherAdd[i][j][k] = 0;
			}
		}
	}
}

inline void applyPrefSum() {
	for (int i = 0; i < 26; i++) {
		for (int j = 1; j <= n; j++) {
			for (int k = 1; k <= m; k++) {
				otherAdd[i][j][k] += (
					+ otherAdd[i][j-1][k] 
					+ otherAdd[i][j][k-1] 
					- otherAdd[i][j-1][k-1]
				);
			}
		}
	}
}

inline void calcCurSegs() {
	cleanArr();
	for (int i = 0; i < 26; i++) {
		for (int j = 1; j <= n; j++) {
			for (int k = 1; k <= m; k++) {
				otherAdd[i][j][k] = (K - rectCnt[j][k]) * abs(i + 'a' - v[j-1][k-1]);
			}
		}
	}
	applyPrefSum();
	for (int i = 0; i < k; i++) {
		Photo cur = photos[i];
		curSegs[i] = (
			+ otherAdd[cur.e - 'a'][cur.c]  [cur.d]
			- otherAdd[cur.e - 'a'][cur.a-1][cur.d]
			- otherAdd[cur.e - 'a'][cur.c]  [cur.b-1]
			+ otherAdd[cur.e - 'a'][cur.a-1][cur.b-1]
		);
	}
}

inline void calcSumSegs() {
	cleanArr();
	for (int i = 0; i < 26; i++) {
		for (int j = 1; j <= n; j++) {
			for (int k = 1; k <= m; k++) {
				otherAdd[i][j][k] = rectCount[i][j][k];
			}
		}
	}
	applyPrefSum();
	for (int i = 0; i < k; i++) {
		Photo cur = photos[i];
		sumSegs[i] = 0;
		for (int j = 0; j < 26; j++) {
			sumSegs[i] += abs(j + 'a' - cur.e) * (
				+ otherAdd[j][cur.c]  [cur.d]
				- otherAdd[j][cur.a-1][cur.d]
				- otherAdd[j][cur.c]  [cur.b-1]
				+ otherAdd[j][cur.a-1][cur.b-1]
			);
		}
	}
}

inline void calcIntrDifs() {
	cleanArr();
	for (int i = 0; i < 26; i++) {
		for (int j = 1; j <= n; j++) {
			for (int k = 1; k <= m; k++) {
				otherAdd[i][j][k] = rectCount[i][j][k] * abs(i + 'a' - v[j-1][k-1]);
			}
		}
	}
	applyPrefSum();
	for (int i = 0; i < k; i++) {
		Photo cur = photos[i];
		intrDifs[i] = 0;
		for (int j = 0; j < 26; j++) {
			intrDifs[i] += (
				+ otherAdd[j][cur.c]  [cur.d]
				- otherAdd[j][cur.a-1][cur.d]
				- otherAdd[j][cur.c]  [cur.b-1]
				+ otherAdd[j][cur.a-1][cur.b-1]
			);
		}
	}
	for (int i = 0; i < 26; i++) {
		allDif += otherAdd[i][n][m];
	}
}

signed main() {
	initRectCount();
	calcCurSegs();
	calcSumSegs();
	calcIntrDifs();
	ll bestAns = llInf;
	for (int i = 0; i < k; i++) {
		ll bFon = curSegs[i];
		ll cFon = allDif - intrDifs[i];
		ll bC = sumSegs[i];
		ll curAns = bFon + cFon + bC;
		umin(bestAns, curAns);
	}
	putLn(bestAns);
	return 0;
}