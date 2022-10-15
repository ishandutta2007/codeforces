/*------------------------------------------------+
|                     alex256                     |
+---------+---------------------------------------+
| Contest | Educational CodeForces Round #19      |
| Task    | D                                     |
| Date    | 15.04.2017                            |
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
inline int subMod(int a, int b, int m = mod) { return ((ll)a + m - b) % m; }
inline int mulMod(int a, int b, int m = mod) { return ((ll)a * b) % m; }
inline int divMod(int a, int b, int m = mod) { ll x, y; ll g = extGcd(b, m, x, y); if (g != 1) { dbg("cannot eval ", a, " / ", b, " modulo ", m); exit(42); }  x = (x % m + m) % m; return mulMod(a, x, m); }
/// End of The Template

struct Treap {
	int x, y;
	int size;
	Treap *l, *r;
	
	Treap(int x)
		: x(x), y(rnd()), size(1), l(nullptr), r(nullptr) {
	}
	
	~Treap() {
		if (l != nullptr) {
			delete l;
		}
		if (r != nullptr) {
			delete r;
		}
	}
};
typedef Treap* pTreap;

inline int getSize(pTreap t) {
	return (t != nullptr) ? t->size : 0;
}

inline void update(pTreap t) {
	if (t != nullptr) {
		t->size = getSize(t->l) + 1 + getSize(t->r);
	}
}

void split(pTreap t, pTreap& l, pTreap& r, int x) {
	if (t == nullptr) {
		l = r = nullptr;
	} else if (x <= t->x) {
		split(t->l, l, t->l, x);
		r = t;
	} else {
		split(t->r, t->r, r, x);
		l = t;
	}
	update(l); update(r);
}

void splitSize(pTreap t, pTreap& l, pTreap& r, int count) {
	if (t == nullptr) {
		l = r = nullptr;
	} else if (count <= getSize(t->l)) {
		splitSize(t->l, l, t->l, count);
		r = t;		
	} else {
		splitSize(t->r, t->r, r, count - getSize(t->l) - 1);
		l = t;		
	}
	update(l); update(r);
}

void merge(pTreap& t, pTreap l, pTreap r) {
	if (l == nullptr || r == nullptr) {
		t = (l != nullptr) ? l : r;
	} else if (l->y > r->y) {
		merge(l->r, l->r, r);
		t = l;
	} else {
		merge(r->l, l, r->l);
		t = r;
	}
	update(t);
}

void insert(pTreap& t, pTreap it) {
	if (t == nullptr) {
		t = it;
	} else if (it->y > t->y) {
		split(t, it->l, it->r, it->x);
		t = it;
	} else if (it->x <= t->x) {
		insert(t->l, it);
	} else {
		insert(t->r, it);
	}
	update(t);
}

void erase(pTreap& t, int x) {
	if (t != nullptr) {
		if (x == t->x) {
			pTreap oldT = t;
			merge(t, t->l, t->r);
			oldT->l = oldT->r = nullptr;
			delete oldT;
		} else if (x <= t->x) {
			erase(t->l, x);
		} else {
			erase(t->r, x);
		}
	}
	update(t);
}

void unite(pTreap& t, pTreap l, pTreap r) {
	if (l == nullptr || r == nullptr) {
		t = (l != nullptr) ? l : r;
	} else {
		if (r->y > l->y) {
			swap(l, r);
		}
		pTreap rl, rr;
		split(r, rl, rr, l->x);
		unite(l->l, l->l, rl);
		unite(l->r, l->r, rr);
		t = l;
	}
	update(t);
}

void outItem(pTreap t) {
	put(t->x, ' ');
}

void out(pTreap t) {
	if (t != nullptr) {
		out(t->l);
		outItem(t);
		out(t->r);
	}
}

pTreap nthElement(pTreap t, int n) {
	if (t == nullptr) {
		return nullptr;
	} else if (n == getSize(t->l)) {
		return t;
	} else if (n < getSize(t->l)) {
		return nthElement(t->l, n);
	} else {
		return nthElement(t->r, n - getSize(t->l) - 1);
	}
}

pTreap find(pTreap t, int x) {
	if (t == nullptr) {
		return nullptr;
	} else if (x == t->x) {
		return t;
	} else if (x < t->x) {
		return find(t->l, x);
	} else {
		return find(t->r, x);
	}
}

struct BinTree {
	int value;
	BinTree *l, *r;
	
	BinTree() {
	}
	
	BinTree(int value, BinTree *l, BinTree *r)
		: value(value), l(l), r(r) {
	}
};
typedef BinTree* pBinTree;

map<int, int> knts;

inline int searchCount(pBinTree binTree, pTreap &treap) {
	if (binTree == nullptr) {
		return 0;
	}
	int res = 0;
	if (find(treap, binTree->value) != nullptr) {
		res += knts[binTree->value];
	}
	pTreap l, m, r; 
	split(treap, l, m, binTree->value);
	split(m, m, r, binTree->value + 1);
	res += searchCount(binTree->l, l);
	res += searchCount(binTree->r, r);
	merge(m, m, r);
	merge(treap, l, m);
	return res;
}

signed main() {
	int n = get<int>();
	BinTree *trees = new BinTree[n];
	pTreap treap = nullptr;
	vi noLinks(n, true);
	for (int i = 0; i < n; i++) {
		int val = get<int>(), l = get<int>() - 1, r = get<int>() - 1;
		insert(treap, new Treap(val));
		knts[val]++;
		if (l >= 0) {
			noLinks[l] = false;
		}
		if (r >= 0) {
			noLinks[r] = false;
		}
		pBinTree lSon = (l < 0) ? nullptr : trees + l;
		pBinTree rSon = (r < 0) ? nullptr : trees + r;
		trees[i] = BinTree(val, lSon, rSon);
	}
	for (int i = 0; i < n; i++) {
		if (noLinks[i]) {
			putLn(n - searchCount(trees + i, treap));
		}
	}
	delete treap;
	delete[] trees; 
	return 0;
}