/*------------------------------------------------+
|                   ( alex256 )                   |
|-------------------------------------------------+
|                 Template v. 1.1.                |
+---------+---------------------------------------+
| Contest | CodeForces Round 419 (Div. 2)         |
| Task    | D                                     |
| Date    | 17.06.2017                            |
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

class SegmentTree {
	private:
		int n;
		vector<int64_t> tree;
		vector<int64_t> tree2;
		vector<char> isLazy;
		vector<int64_t> lazy;
		
		inline void push(int x, int tl, int tr) {
			if (isLazy[x]) {
				tree[x] = lazy[x] * (tr - tl + 1);
				tree2[x] = lazy[x];
				if (tl != tr) {
					isLazy[x*2] = true;
					lazy[x*2] = lazy[x];
					isLazy[x*2+1] = true;
					lazy[x*2+1] = lazy[x];
				}
				isLazy[x] = false;
			}
		}
		
		void update(int x, int tl, int tr, int l, int r, int64_t val) {
			if (l > r) {
				push(x, tl, tr);
			} else if (l == tl && r == tr) {
				isLazy[x] = true;
				lazy[x] = val;
				push(x, tl, tr);
			} else {
				push(x, tl, tr);
				int tm = (tl + tr) / 2;
				update(x*2, tl, tm, l, min(r, tm), val);
				update(x*2+1, tm+1, tr, max(l, tm+1), r, val);
				tree[x] = tree[x*2] + tree[x*2+1];
				tree2[x] = min(tree2[x*2], tree2[x*2+1]);
			}
		}
		
		int64_t sum(int x, int tl, int tr, int l, int r) {
			if (l > r) {
				return 0;
			} else if (l == tl && r == tr) {
				push(x, tl, tr);
				return tree[x];
			} else {
				push(x, tl, tr);
				int tm = (tl + tr) / 2;
				return sum(x*2, tl, tm, l, min(r, tm)) +
				       sum(x*2+1, tm+1, tr, max(l, tm+1), r);
			}
		}
		
		inline int lowerBound(int x, int tl, int tr, int64_t val) {
			push(x, tl, tr);
			if (tl == tr) {
				if (tree[x] <= val) {
					return tl;
				} else {
					return tl+1;
				}
			} else {
				int tm = (tl + tr) / 2;
				push(x*2, tl, tm);
				if (tree2[x*2] <= val) {
					return lowerBound(x*2, tl, tm, val);
				} else {
					return lowerBound(x*2+1, tm+1, tr, val);
				}
			}
		}
	public:
		inline int lowerBound(int64_t val) {
			return lowerBound(1, 0, n-1, val-1);
		}
		
		inline void tryUpdate(int idx, int64_t val) {
			if (sum(idx, idx) >= val) {
				return;
			}
			int l = lowerBound(val), r = idx;
			update(l, r, val);
		}
		
		inline void update(int l, int r, int64_t val) {
			update(1, 0, n-1, l, r, val);
		}
		
		inline int64_t sum(int l, int r) {
			return sum(1, 0, n-1, l, r);
		}
		
		SegmentTree(int n)
			: n(n), tree(4*n, 0), tree2(4*n, 0), isLazy(4*n, false), lazy(4*n) {
		}
};

signed main() {
	int n = get<int>(), p = get<int>(), q = get<int>(), r = get<int>();
	vector< vector< pair<int, int> > > byGroup(p);
	priority_queue< pair<int, int> > bs, cs;
	for (int i = 0; i < n; i++) {
		int a = get<int>() - 1, b = get<int>() - 1, c = get<int>() - 1;
		byGroup[a].emplace_back(b, c);
		bs.emplace(b, a);
		cs.emplace(c, a);
	}
	bs.emplace(-1, inf);
	cs.emplace(-1, inf);
	int64_t ans = 0;
	SegmentTree st(q);
	st.update(0, q-1, -1);
	for (int i = 0; i < p; i++) {
		int b = bs.top().first, c = cs.top().first;
		int stays = max(b+1, st.lowerBound(c));
		int64_t iceberg = (int64_t)(stays - b - 1) * (r - 1) - st.sum(b+1, stays-1);
		int64_t hidden = (int64_t)(q - stays) * (r - 1 - c); 
		ans += iceberg + hidden;
		for (auto it : byGroup[i]) {
			int b, c; tie(b, c) = it;
			st.tryUpdate(b, c);
		}
		while (bs.top().second <= i) {
			bs.pop();
		}
		while (cs.top().second <= i) {
			cs.pop();
		}
	}
	putLn(ans);
	return 0;
}