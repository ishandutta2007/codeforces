/*-------------------( alex256 )--------------------\
|    Contest: Codeforces Round 371 (Div. 1)         |
|       Task: B                                     |
|       Date: 13. 09. 2016                          |
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
/*
int n = 8;
int x1, y1, x2, y2, x3, y3, x4, y4;
int cnt = 0;

#include <random>
mt19937 rnd(time(NULL));

void genRand()
{
    x1 = rnd() % n + 1, y1 = rnd() % n + 1,
    x2 = rnd() % n + 1, y2 = rnd() % n + 1,
    x3 = rnd() % n + 1, y3 = rnd() % n + 1,
    x4 = rnd() % n + 1, y4 = rnd() % n + 1;

    if (x1 > x2) swap(x1, x2);
    if (y1 > y2) swap(y1, y2);
    if (x3 > x4) swap(x3, x4);
    if (y3 > y4) swap(y3, y4);

    out.putLn("genRand = (", x1, ", ", y1, ", ", x2, ", ", y2, ") ",
                       "(", x3, ", ", y3, ", ", x4, ", ", y4, ")");

}

int getAns(int l1, int r1, int l2, int r2)
{
    if (l1 > l2 || r1 > r2) return 0;
    int ans = 0;
    if (l1 <= x1 && x2 <= l2 &&
        r1 <= y1 && y2 <= r2)
        ans++;
    if (l1 <= x3 && x4 <= l2 &&
        r1 <= y3 && y4 <= r2)
        ans++;

    //out.putLn("getAns = ", l1, ' ', r1, ' ', l2, ' ', r2, " == ", ans);

    cnt++;
    return ans;
}

void tryAns(int _x1, int _y1, int _x2, int _y2, int _x3, int _y3, int _x4, int _y4)
{
    out.putLn("tryAns = (", _x1, ", ", _y1, ", ", _x2, ", ", _y2, ") ",
                       "(", _x3, ", ", _y3, ", ", _x4, ", ", _y4, ")");

    if (x1 == _x1 && y1 == _y1 && x2 == _x2 && y2 == _y2 &&
        x3 == _x3 && y3 == _y3 && x4 == _x4 && y4 == _y4) return;
    if (x1 == _x3 && y1 == _y3 && x2 == _x4 && y2 == _y4 &&
        x3 == _x1 && y3 == _y1 && x4 == _x2 && y4 == _y2) return;

    out = "bugs!!!";
    exit(0);
}
*/

int n = in;

int getAns(int l1, int r1, int l2, int r2)
{
    if (l1 > l2 || r1 > r2) return 0;
    out.putLn("? ", l1, ' ', r1, ' ', l2, ' ', r2);
    cout.flush();
    return (int)in;
}

void tryAns(int _x1, int _y1, int _x2, int _y2, int _x3, int _y3, int _x4, int _y4)
{
    out.putLn("! ", _x1, " ", _y1, " ", _x2, " ", _y2, " ",
                    _x3, " ", _y3, " ", _x4, " ", _y4);
    cout.flush();
}

int checkR(int v) { return getAns(1, 1, v, n); }
int checkL(int v) { return getAns(n-v+1, 1, n, n); }
int checkU(int v) { return getAns(1, 1, n, v); }
int checkD(int v) { return getAns(1, n-v+1, n, n); }

template <typename T>
int binsearch_beg(int l, int r, int num, T checker)
{
    while (l < r)
    {
        int m = (l + r) / 2;
        if (checker(m) == num) r = m; else l = m+1;
    }
    return l;
}

template <typename T>
void binsearch_all(int l, int r, int& r1, int& r2, T checker)
{
    if (l == r) { r1 = r2 = l; return; }
    int m = (l + r) / 2;
    int cnt = checker(m);
    if (cnt == 0)
        binsearch_all(m+1, r, r1, r2, checker);
    if (cnt == 1)
    {
        r1 = binsearch_beg(l, m, 1, checker);
        r2 = binsearch_beg(m+1, r, 2, checker);
    }
    if (cnt == 2)
        binsearch_all(l, m, r1, r2, checker);
}

main()

{
    int rx1, rx2, lx1, lx2, ly1, ly2, ry1, ry2;
    binsearch_all(1, n, rx1, rx2, checkR);
    binsearch_all(1, n, lx1, lx2, checkL);
    binsearch_all(1, n, ry1, ry2, checkU);
    binsearch_all(1, n, ly1, ly2, checkD);
    lx1 = n - lx1 + 1; lx2 = n - lx2 + 1;
    ly1 = n - ly1 + 1; ly2 = n - ly2 + 1;

    if (getAns(lx1, 1, rx1, n) == 0) swap(lx1, lx2);
    if (getAns(1, ly1, n, ry1) == 0) swap(ly1, ly2);
    if (getAns(lx1, ly1, rx1, ry1) == 0) { swap(lx1, lx2); swap(rx1, rx2); }

    tryAns(lx1, ly1, rx1, ry1, lx2, ly2, rx2, ry2);
    return 0;
}