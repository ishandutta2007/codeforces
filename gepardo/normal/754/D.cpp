/**
                      alex256                   
   
   Contest CodeForces Round 390 (Div. 2)         
   
   Task    ?                                     
   
   Date    06.01.2017                            
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

struct Treap {
    int x, y, cnt;
    Treap *l, *r;
    Treap(int x) : x(x), y(rand()), cnt(1), l(0), r(0) {}
    Treap() {}
};
typedef Treap* pTreap;

Treap treaps[200 * 1024 * 1024 / sizeof(Treap)];
pTreap curPtr = treaps;

inline pTreap allocTreap() {
	return curPtr++;
}

inline pTreap newTreap(int x) {
	pTreap treap = allocTreap();
	*treap = Treap(x);
	return treap;
}

int getCnt(pTreap t) {
    return t ? t->cnt : 0;
}

void reCount(pTreap t) {
    if (t)
        t->cnt = getCnt(t->l) + 1 + getCnt(t->r);
}

void split(pTreap t, pTreap &l, pTreap &r, int x) {
    if (!t)
        l = r = NULL;
    else if (x < t->x)
        split(t->l, l, t->l, x), r = t;
    else
        split(t->r, t->r, r, x), l = t;
    reCount(l), reCount(r);
}

void cntSplit(pTreap t, pTreap &l, pTreap &r, int id, int add = 0) {
    if (!t)
        l = r = NULL;
    else {
		int curId = add + getCnt(t->l);
		if (id < curId)
			cntSplit(t->l, l, t->l, id, add), r = t;
		else
			cntSplit(t->r, t->r, r, id, curId + 1), l = t;
		reCount(l), reCount(r);
    }
}

void merge(pTreap &t, pTreap l, pTreap r) {
    if (!l || !r)
        t = l ? l : r;
    else if (l->y > r->y)
        merge(l->r, l->r, r), t = l;
    else
        merge(r->l, l, r->l), t = r;
    reCount(t);
}

void insert(pTreap &t, pTreap it) {
    if (!t)
        t = it;
    else if (it->y > t->y)
        split(t, it->l, it->r, it->x), t = it;
    else
        insert(it->x < t->x ? t->l : t->r, it);
    reCount(t);
}

void erase(pTreap &t, int x) {
    if (!t) return;
    if (t->x != x)
        erase(x < t->x ? t->l : t->r, x);
    else {
        pTreap l = t->l, r = t->r;
        delete t;
        merge(t, l, r);
    }
    reCount(t);
}

pTreap find(pTreap t, int x) {
    if (!t) return nullptr;
    if (t->x == x)
        return t;
    else
        return find(x < t->x ? t->l : t->r, x);
}

inline int getMin(pTreap t) {
	while (t->l) {
		t = t->l;
	}
	return t->x;
}

inline int getMax(pTreap t) {
	while (t->r) {
		t = t->r;
	}
	return t->x;
}

void out(vi& v, pTreap t) {
	if (!t) {
		return;
	}
	out(v, t->l);
	v.pb(t->x);
	out(v, t->r);
}

inline int getKth(pTreap t, int k) {
	pTreap a, b;
	cntSplit(t, a, b, k);
	int res = getMax(a);
	merge(t, a, b);
	return res;
}

int n = get<int>(), k = get<int>();
vpii v = getVector<pii>(n);

signed main() {
	vpii q = v;
	#define v ____
	sort(q.begin(), q.end());
	pTreap t = nullptr;
	int maxCnt = 0, maxPoint = -1;
	for (int i = 0; i < n; i++) {
		insert(t, newTreap(-q[i].S));
		if (getCnt(t) < k) {
			continue;
		}
		int kth = getKth(t, k-1);
		int kurrent = -kth - q[i].F + 1;
		dbg("!!! ", i, " ", kurrent);
		if (kurrent > maxCnt) {
			maxCnt = kurrent;
			maxPoint = i;
		}
	}
	#undef v
	putLn(maxCnt);
	vi ans;
	vector<char> used(n, false);
	if (maxPoint >= 0) {
		vpii opened; 
		for (int i = 0; i < n; i++) {
			if (v[i].F <= q[maxPoint].F) {
				opened.eb(-v[i].S, i);
			}
		}
		sort(opened.begin(), opened.end());
		for (int i = 0; i < min(k, sz(opened)); i++) {
			used[opened[i].S] = true;
			ans.pb(opened[i].S+1);
		}
	}
	for (int i = 0; i < n; i++) {
		if (sz(ans) < k && !used[i]) {
			used[i] = true;
			ans.pb(i+1);
		} 
	}
	putLn(ans);
	return 0;
}