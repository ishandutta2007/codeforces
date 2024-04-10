/*-------------------( alex256 )--------------------\
|    Contest: Codeforces Round 381 (Div. 2)         |
|       Task: B                                     |
|       Date: 23. 11. 2016                          |
\--------------------------------------------------*/
// Includes
#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <iomanip>
#include <iostream>
#include <map>
#include <set>
#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <ctime>
#include <random>
// Defines
#define ar(a) a[maxN]
#define pb push_back
#define F first
#define S second
#define sz(x) (int)x.size()
#define debug(v) makeDebugInfo(#v, v)
#define dbg(v) out.put(makeDebugInfo(#v, v)), cout.flush()
#define here out = "here"; cout.flush()
#define endless for (;;)
// Other defines
#define Actually true
#define yes ;
#define alex256 2048
#define rating(n) n
using namespace std;
// Types
typedef long long LL;
typedef unsigned long long ULL;
typedef long double LD;
struct outFloat { int precision; LD value; outFloat(LD v, int p) : precision(p), value(v) {} }; typedef outFloat ofl;
template <typename T> struct debugInfo { string name; T val; debugInfo(const char* n, T v) : name(n), val(v) {}; };
template <typename T> debugInfo<T> makeDebugInfo(const char* n, T v) { return debugInfo<T>(n, v); }
// Constants
const int inf = 123456789;
const LL llInf = 123456789012345678LL;
const LD pi = 3.14159265358979323846;
const int maxN = 2000000;
// Input / Output
int init() { ios_base::sync_with_stdio(0); srand(time(NULL)); return 0; } int initializer = init();
template <typename T1, typename T2> istream& operator>>(istream& is, pair<T1, T2> &p) { is >> p.first >> p.second; return is; }
template <typename T> istream& operator>>(istream& is, vector<T> &p) { for (int i = 0; i < p.size(); i++) is >> p[i]; return is; }
class inputer
{
    private: istream* istr; public:
    inputer(istream &is) : istr(&is) {}
    template <typename T> void get(T &n) { (*istr) >> n; }
    template <typename T, typename... Args> void get(T &n, Args&... args) { get(n); get(args...); }
    template <typename... Args> void getLn(Args&... args) { get(args...); getLn(); }
    template <typename T> operator T() { T n; get(n); return n; }
    void getLn() { string s; getline(cin, s); }
    template <typename T> void getv(vector <T> &v, int size) { v.resize(size); (*istr) >> v; }
};
#define endl "\n"
string delim = " ";
template <typename T1, typename T2> ostream& operator<<(ostream& os, const pair<T1, T2> &p) { os << p.first << delim << p.second; return os; }
template <typename T> ostream& operator<<(ostream& os, const vector<T> &p) { for (int i = 0; i < p.size(); i++) { if (i != 0) os << delim; os << p[i]; } return os; }
ostream& operator<<(ostream& os, const outFloat &of) { os << setprecision(of.precision) << of.value; return os; }
template <typename T> ostream& operator<<(ostream& os, const debugInfo<T> &dbg) { os << "\"" << dbg.name << "\" = \"" << dbg.val << "\"" << endl; }
class outputer
{
    private: ostream* ostr; public:
    outputer(ostream &os) : ostr(&os) {}
    template <typename T> void put(const T &n) { (*ostr) << n; }
    template <typename T, typename... Args> void put(const T &n, const Args&... args) { put(n); put(args...); }
    template <typename... Args> void putLn(const Args&... args) { put(args...); putLn(); }
    template <typename T> outputer& operator=(const T &n) { putLn(n); return *this; }
    void putLn() { (*ostr) << endl; }
    template <typename T> void putv(vector <T> v, int size, string delim) { for (int i = 0; i < size; i++) { if (i != 0) (*ostr) << delim; (*ostr) << v[i]; } }
};
inputer in(cin);
outputer out(cout);
char getChar() { char c = 0; while (c <= ' ') cin >> c; return c; }
// Other methods
bool willItBeAC() { return Actually yes; } int getMyRating() { return rating(alex256); }
bool prime(LL n) { for (LL i = 2; i * i <= n; i++) if (n % i == 0) return false; return true; }
vector <LL> divs(LL n) { vector <LL> v; LL i = 2; while (i * i <= n) if (n % i == 0) { n /= i; v.pb(i); } else i++; v.pb(n); return v; }
LL gcd(LL a, LL b) { return b ? gcd (b, a % b) : a; }
LL extGcd(LL a, LL b, LL &x, LL &y) { if (a == 0) { x = 0; y = 1; return b; } LL x1, y1, d = extGcd(b % a, a, x1, y1); x = y1 - (b / a) * x1; y = x1; return d; }
template <typename T> class fenwick
{
    private: vector<T> t; int n; public:
    fenwick(int nn) { init(nn); }
    void init(int nn) { n = nn; t.assign(n, 0); }
    T sum(int r) { T result = 0; for (; r >= 0; r = (r & (r + 1)) - 1) result += t[r]; return result; }
    void inc(int i, T delta) { for (; i < n; i = (i | (i + 1))) t[i] += delta; }
    T sum(int l, int r) { return sum(r) - sum(l - 1); }
    T get(int i) { return sum(i, i); }
    void put(int i, T v) { inc(i, v - sum(i, i)); }
    int size() { return n; }
};
//End of template

#define int long long

int n = in;
vector <int> a(n);
vector < vector < pair<int, int> > > g(n);
vector <int> res(n);

struct item
{
	int key;
	signed prior;
	signed cnt;
	item *l, *r;
	item() {}
	item(int key, int prior) : key(key), prior(prior), cnt(0), l(NULL), r(NULL) {}
};
typedef item* pitem;

inline int cnt (pitem t) { return t ? t->cnt : 0; }
inline void upd_cnt (pitem t) { if (t) t->cnt = 1 + cnt(t->l) + cnt (t->r); }

const int sz = 1000000;

item items[sz];
int item_cnt = 0;

mt19937 rnd(42985749);

inline pitem new_item(int key, int prior)
{
    items[item_cnt] = item(key, prior);

    if (item_cnt > sz) exit(256);

    return &items[item_cnt++];
}

void split(pitem t, int key, pitem& l, pitem& r)
{
	if (!t) l = r = NULL;
        else if (key < t->key) split (t->l, key, l, t->l), r = t;
            else split (t->r, key, t->r, r), l = t;
    upd_cnt(l); upd_cnt(r);
}

void insert(pitem& t, pitem it)
{
	if (!t) t = it;
        else if (it->prior > t->prior) split (t, it->key, it->l, it->r),  t = it;
            else insert (it->key < t->key ? t->l : t->r, it);
    upd_cnt(t);
}

void merge(pitem& t, pitem l, pitem r)
{
	if (!l || !r) t = l ? l : r;
        else if (l->prior > r->prior) merge (l->r, l->r, r),  t = l;
            else merge (r->l, l, r->l),  t = r;
    upd_cnt(t);
}

void erase(pitem& t, int key)
{
	if (t->key == key) merge (t, t->l, t->r);
        else erase (key < t->key ? t->l : t->r, key);
    upd_cnt(t);
}

pitem unite(pitem l, pitem r)
{
	if (!l || !r)  return l ? l : r;
	if (l->prior < r->prior) swap(l, r);
	pitem lt, rt;
	split (r, l->key, lt, rt);
	l->l = unite (l->l, lt);
	l->r = unite (l->r, rt);
	upd_cnt(l);
	return l;
}

void out_(pitem t)
{
    if (!t) return;
    out_(t->l);
    cout << t->key << " ";
    out_(t->r);
}

void dfs(int v, int p, int& d_up, pitem& tree)
{
    tree = NULL;
    for (int i = 0; i < g[v].size(); i++)
    {
        int to = g[v][i].F;
        if (to == p) continue;
        d_up += g[v][i].S;
        pitem new_tree;
        dfs(to, v, d_up, new_tree);
        tree = unite(tree, new_tree);
        d_up -= g[v][i].S;
    }
    pitem l, r;
    split(tree, -d_up-1, l, r);
    res[v] = cnt(r);
    merge(tree, l, r);
    insert(tree, new_item(a[v] - d_up, rnd()));

}

main()
{
    in.getv(a, n);
    for (int i = 1; i < n; i++)
    {
        int v = (int)in - 1, way = in;
        g[v].push_back({i, way});
        g[i].push_back({v, way});
    }
    pitem tree; int d_up;
    dfs(0, -1, d_up, tree);
    out = res;
    return 0;
}