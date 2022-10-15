/*-------------------( alex256 )--------------------\
|    Contest: Codeforces Round 381 (Div. 2)         |
|       Task: C                                     |
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

struct mount
{
    bool dummy;
    int len;
    int neg_l, m_l;
    int pos_r, m_r;
    int m_in;
    mount() : dummy(true) {}
};

inline void merge(const mount& a, const mount& b, mount& c)
{
    if (a.dummy) { c = b; return; }
    if (b.dummy) { c = a; return; }

    c.dummy = false;
    c.len = a.len + b.len;
    c.neg_l = (a.neg_l == a.len) ? (a.len + b.neg_l) : a.neg_l;
    c.pos_r = (b.pos_r == b.len) ? (b.len + a.pos_r) : b.pos_r;

    c.m_l = (a.m_l == a.len) ? (a.len + b.neg_l) : a.m_l;
    if (a.pos_r == a.len) c.m_l = max(c.m_l, a.len + b.m_l);

    c.m_r = (b.m_r == b.len) ? (b.len + a.pos_r) : b.m_r;
    if (b.neg_l == b.len) c.m_r = max(c.m_r, b.len + a.m_r);

    c.m_in = max(max(a.m_in, b.m_in), max(a.m_r + b.neg_l, a.pos_r + b.m_l));
}

inline mount dummy_mount()
{
    mount c;
    c.dummy = true;
    c.m_in = 0;
    return c;
}

inline mount single_el(long long el)
{
    mount c;
    c.dummy = false;
    c.len = 1;
    c.neg_l = el < 0;
    c.pos_r = el > 0;
    c.m_l = c.m_r = c.m_in = el != 0;
    return c;
}

int n = in;
long long a[500000];
mount t[2000000];

void build(int v, int tl, int tr)
{
    if (tl > tr) return;
	if (tl == tr)
		t[v] = single_el(a[tl]);
	else
	{
		int tm = (tl + tr) / 2;
		build(v*2, tl, tm);
		build(v*2+1, tm+1, tr);
		merge(t[v*2], t[v*2+1], t[v]);
	}
}

void update(int v, int tl, int tr, int pos)
{
    if (tl > tr || pos < tl || pos > tr) return;
	if (tl == tr)
		t[v] = single_el(a[pos]);
	else
	{
		int tm = (tl + tr) / 2;
		if (pos <= tm)
			update(v*2, tl, tm, pos);
		else
			update(v*2+1, tm+1, tr, pos);
		merge(t[v*2], t[v*2+1], t[v]);
	}
}

main()
{
    vector <int> b;
    in.getv(b, n);
    for (int i = 1; i < n; i++)
        a[i] = b[i] - b[i-1];
    build(1, 1, n-1);

    int q = in;
    for (int i = 0; i < q; i++)
    {
        int l = in, r = in, d = in;
        a[l-1] += d;
        update(1, 1, n-1, l-1);
        a[r] -= d;
        update(1, 1, n-1, r);
        out = t[1].m_in + 1;
    }
    return 0;
}