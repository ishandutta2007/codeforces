/*-------------------( alex256 )--------------------\
|    Contest: Codeforces Round 378 (Div. 2)         |
|       Task: C                                     |
|       Date: 31. 10. 2016                          |
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

map < pair <int, int>, vector < pair <int, int> > > m;

inline void push_map(int a, int b, int c, int d)
{
    m[{min(a, b), max(a, b)}].pb({c, d});
}

inline vector < pair <int, int> >& get_map(int a, int b)
{
    return m[{min(a, b), max(a, b)}];
}

main()
{
    int n = in;
    vector < pair <int, pair <int, int> > > v;
    in.getv(v, n);
    for (int i = 0; i < n; i++)
    {
        push_map(v[i].F, v[i].S.F, v[i].S.S, i);
        push_map(v[i].F, v[i].S.S, v[i].S.F, i);
        push_map(v[i].S.F, v[i].S.S, v[i].F, i);
    }
    for (auto &it: m)
    {
        sort(it.second.begin(), it.second.end());
        reverse(it.second.begin(), it.second.end());
        it.second.push_back({0, -1});
    }
    int best_ans = 0;
    int bestA = -1, bestB = -1;
    for (int i = 0; i < n; i++)
    {
        int a = v[i].F, b = v[i].S.F, c = v[i].S.S;
        #define do(a, b, c) \
            { \
                auto& q = m.count({a, b}) ? m[{a, b}] : m[{b, a}];  \
                int ctr = 0; \
                while (ctr < q.size() && q[ctr].S == i) ctr++; \
                int new_ans = min(min(a, b), c + q[ctr].F); \
                if (new_ans > best_ans) \
                { \
                    best_ans = new_ans; \
                    bestA = i; \
                    bestB = q[ctr].S; \
                } \
            }
        do(v[i].F, v[i].S.F, v[i].S.S);
        do(v[i].F, v[i].S.S, v[i].S.F);
        do(v[i].S.F, v[i].S.S, v[i].F);
        #undef do
    }
    if (bestB < 0)
        out.putLn(1, endl, bestA+1);
    else
        out.putLn(2, endl, bestA+1, ' ', bestB+1);
    return 0;
}